/*******************************************************
This program was created by the CodeWizardAVR V3.43 
Automatic Program Generator
? Copyright 1998-2021 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro

Project : Azmayesh_6
Version : 
Date    : 5/7/2021
Author  : mohammad yarmogahdam
Company : IUST
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <mega32.h>
#include <alcd.h>
#include <stdio.h>

int h = 23;
int m = 58;
int s = 0;
int ms = 0;

interrupt [TIM1_COMPA] void timer1_compa_isr(void) {
    ms++;
    if (ms == 10) {
        ms = 0;
        s++;
        if (s == 60) {
            s = 0;
            m++;
            if (m == 60) {
                m = 0;
                h++;
                if (h == 24) {
                    h = 0;
                }
            }
        }
    }
}

char buffer[32];

void main(void) {
    
    // PortC as output
    PORTC=0x00;
    DDRC=0xFF;
    DDRC=0x00; 
    
    // Timer 1 config
    TCCR1A=0x00;
    TCCR1B=0x02;
    TCNT1H=0xCF;
    TCNT1L=0x2C;
    ICR1H=0x00;
    ICR1L=0x00;
    OCR1AH=0x00;
    OCR1AL=0x00;
    OCR1BH=0x00;
    OCR1BL=0x00;
    
    TIMSK = 0x12;
    
    // Characters/line: 16
    lcd_init(16);
    lcd_gotoxy(4,0);
    lcd_puts("LCD Clock");

    // Global enable interrupts
    #asm("sei")

    while (1) {
        // hour
        lcd_gotoxy(3,1);
        sprintf(buffer, "%d ", h);
        lcd_puts(buffer);
        
        lcd_gotoxy(5,1);
        lcd_putchar(':');

        // minute
        lcd_gotoxy(6,1);
        sprintf(buffer, "%d ", m);
        lcd_puts(buffer);
        
        lcd_gotoxy(8,1);
        lcd_putchar(':');

        // second
        lcd_gotoxy(9,1);
        sprintf(buffer, "%d ", s);
        lcd_puts(buffer);
        
        lcd_gotoxy(11,1);
        lcd_putchar('.');

        // milisecond
        lcd_gotoxy(12,1);
        sprintf(buffer, "%d", ms % 10);
        lcd_puts(buffer);
    }
}
