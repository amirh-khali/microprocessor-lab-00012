/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 3/13/2022
Author  : 
Company : 
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <mega32.h>
#include <delay.h>
         
unsigned int time[] = {2, 3, 5, 8, 0, 0};

unsigned int counter = 0; 

char number[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F} ;

// Timer 0 output compare interrupt service routine
interrupt [TIM0_COMP] void timer0_comp_isr(void) {
    counter++;
    counter %= 6;
}

// Timer1 output compare A interrupt service routine
interrupt [TIM1_COMPA] void timer1_compa_isr(void) {
    time[5] += 1;                
    if(time[5] == 10) {
        time[5] = 0;
        time[4] += 1;
        if(time[4] == 6) { 
            time[4] = 0;
            time[3] += 1;
            if (time[3] == 10) {
                time[3] = 0;      
                time[2] += 1; 
                if (time[2] == 6) {
                    time[2] = 0;      
                    time[1] += 1;   
                    if (time[1] == 4 && time[0] == 2) {
                        time[1] = 0;      
                        time[0] = 0;
                    } else if (time[1] == 10) {
                        time[1] = 0;      
                        time[0] += 1;
                    }
                }
            }
        } 
    }
}

// Declare your global variables here
void main(void) {

    PORTA=0x00;
    DDRA=0x00;

    PORTB=0x00;
    DDRB=0x00;

    PORTC=0x00;
    DDRC=0xFF;

    PORTD=0x00;
    DDRD=0xFF;

    TCCR0=0x0C;
    TCNT0=0x00;
    OCR0=0x63;

    TCCR1A=0x00;
    TCCR1B=0x0C;
    TCNT1H=0x00;
    TCNT1L=0x00;
    ICR1H=0x00;
    ICR1L=0x00;
    OCR1AH=0x7A;
    OCR1AL=0x12;
    OCR1BH=0x00;
    OCR1BL=0x00;

    TCCR2=0x00;
    TCNT2=0x00;
    OCR2=0x00;

    MCUCR=0x00;
    MCUCSR=0x00;

    TIMSK=0x12;

    // Analog Comparator initialization
    ACSR=0x80;
    SFIOR=0x00;

    // Global enable interrupts
    #asm("sei")

    while (1) {
        
        int dot = 0;
        if (time[5] % 2 == 0) {
            dot = 0x80;
        }
    
        if(counter == 0) {
            PORTD = 0b11111110;
            PORTC = number[time[0]];
        } else if(counter == 1) { 
            PORTD = 0b11111101;
            PORTC = number[time[1]] | dot;
        } else if(counter == 2) {
            PORTD = 0b11111011;
            PORTC = number[time[2]];
        } else if(counter == 3) {
            PORTD = 0b11110111;
            PORTC = number[time[3]] | dot;
        } else if(counter == 4) {
            PORTD = 0b11101111;
            PORTC = number[time[4]];
        } else if(counter == 5){
            PORTD = 0b11011111;
            PORTC = number[time[5]] | dot;
        }
    }
}
