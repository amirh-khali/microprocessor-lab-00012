/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 4/24/2022
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
#include <alcd.h>
#include <delay.h>      
#include <stdlib.h>

#define KEYPAD_R1 PORTD.0
#define KEYPAD_R2 PORTD.1
#define KEYPAD_R3 PORTD.2
#define KEYPAD_R4 PORTD.3
#define KEYPAD_C1 PIND.4
#define KEYPAD_C2 PIND.5
#define KEYPAD_C3 PIND.6
#define KEYPAD_C4 PIND.7

#define KEYPAD_NUM0 0
#define KEYPAD_NUM1 1
#define KEYPAD_NUM2 2
#define KEYPAD_NUM3 3
#define KEYPAD_NUM4 4
#define KEYPAD_NUM5 5
#define KEYPAD_NUM6 6
#define KEYPAD_NUM7 7
#define KEYPAD_NUM8 8
#define KEYPAD_NUM9 9
#define KEYPAD_DIV  10
#define KEYPAD_MUL  11
#define KEYPAD_PLS  12
#define KEYPAD_MNS  13
#define KEYPAD_EQU  14
#define KEYPAD_ON   15

unsigned char keypad_scan();
float first, second, res;
char operand;
int state;
char show[12];

void main(void) {
    unsigned char key_res;  
    DDRC=0xFF;
    DDRD=0x0F;
    PORTC=0x00;

    lcd_init(16);
    lcd_clear();
    lcd_gotoxy(1,0);
    lcd_puts("KEYPAD AND LCD");
    lcd_gotoxy(5,1);
    lcd_puts("PROJECT");
    delay_ms(2000);
    lcd_clear();

    while (1) {
        key_res = keypad_scan();
        if(key_res != 255) { 
            while(keypad_scan() != 255);
            delay_ms(20);
            
            if (key_res == KEYPAD_ON) {
                lcd_clear();
                lcd_gotoxy(0,0);
                first = 0;   
                second = 0;
                res = 0;  
                operand = '';
                state = 0;
            } 
            
            if (state == 0) { // get first number 
                if (key_res < 10) {
                    lcd_clear();
                    lcd_gotoxy(0,0);
                    first = 0;   
                    second = 0;
                    res = 0;  
                    operand = '';
                    lcd_putchar(key_res + 48);
                    first *= 10;
                    first += key_res;
                    state = 1;
                }                                               
            } else if (state == 1) { // get operand
                if (key_res < 10) {
                    lcd_putchar(key_res + 48);
                    first *= 10;
                    first += key_res;
                } else if (key_res == KEYPAD_DIV) {
                    lcd_putchar('%');
                    operand = '%';
                    state = 2;
                } else if (key_res == KEYPAD_MUL) {
                    lcd_putchar('*');
                    operand = '*';   
                    state = 2;
                } else if (key_res == KEYPAD_MNS) {
                    lcd_putchar('-');
                    operand = '-';   
                    state = 2;
                } else if (key_res == KEYPAD_PLS) {
                    lcd_putchar('+');
                    operand = '+';   
                    state = 2;
                }
            } else if (state == 2) { // get second number 
                if (key_res < 10) {
                    lcd_putchar(key_res + 48);
                    second *= 10;
                    second += key_res;
                    state = 3;
                }
            } else if (state == 3) { // get equal
                if (key_res < 10) {
                    lcd_putchar(key_res + 48);
                    second *= 10;
                    second += key_res;
                } else if (key_res == KEYPAD_EQU) {
                    lcd_putchar('=');
                    if(operand == '%')         
                        res = first / second;
                    else if(operand == '*')
                        res = first * second;
                    else if(operand == '-')        
                        res = first - second;
                    else if(operand == '+')
                        res = first + second;
                    ftoa(res,2,show);  
                    lcd_puts(show);
                    state = 0; 
                }
            }
        }
    }
}


unsigned char keypad_scan() {
    unsigned char result=255;
    ////////////////////////  ROW1 ////////////////////////
    KEYPAD_R1 = 1; KEYPAD_R2 = 0;  KEYPAD_R3 = 0;  KEYPAD_R4 = 0; //set Row1 for Keypad
    delay_ms(5);
    if (KEYPAD_C1)
    result = KEYPAD_NUM7;
    else if (KEYPAD_C2)
    result = KEYPAD_NUM8;
    else if (KEYPAD_C3)
    result = KEYPAD_NUM9;
    else if (KEYPAD_C4)
    result = KEYPAD_DIV;

    ////////////////////////  ROW2 ////////////////////////
    KEYPAD_R1 = 0; KEYPAD_R2 = 1;  KEYPAD_R3 = 0;  KEYPAD_R4 = 0; //set Row2 for Keypad
    delay_ms(5);
    if (KEYPAD_C1)
    result = KEYPAD_NUM4;
    else if (KEYPAD_C2)
    result = KEYPAD_NUM5;
    else if (KEYPAD_C3)
    result = KEYPAD_NUM6;
    else if (KEYPAD_C4)
    result = KEYPAD_MUL;

    ////////////////////////  ROW3 ////////////////////////
    KEYPAD_R1 = 0; KEYPAD_R2 = 0;  KEYPAD_R3 = 1;  KEYPAD_R4 = 0; //set Row3 for Keypad
    delay_ms(5);
    if (KEYPAD_C1)
    result = KEYPAD_NUM1;
    else if (KEYPAD_C2)
    result = KEYPAD_NUM2;
    else if (KEYPAD_C3)
    result = KEYPAD_NUM3;
    else if (KEYPAD_C4)
    result = KEYPAD_MNS;

    ////////////////////////  ROW4 ////////////////////////
    KEYPAD_R1 = 0; KEYPAD_R2 = 0;  KEYPAD_R3 = 0;  KEYPAD_R4 = 1; //set Row4 for Keypad
    delay_ms(5);
    if (KEYPAD_C1)
    result = KEYPAD_ON;
    else if (KEYPAD_C2)
    result = KEYPAD_NUM0;
    else if (KEYPAD_C3)
    result = KEYPAD_EQU;
    else if (KEYPAD_C4)
    result = KEYPAD_PLS;

    return result;
} 