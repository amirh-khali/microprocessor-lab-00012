/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 4/4/2022
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

const unsigned char image_code[70]=
{
	0x00,	//	0001		. . . . . . . . 
	0x00,	//	0002		. . . . . . . . 
	0x00,	//	0003		. . . . . . . . 
	0x00,	//	0004		. . . . . . . . 
	0x00,	//	0005		. . . . . . . . 
	0x00,	//	0006		. . . . . . . . 
	0x00,	//	0007		. . . . . . . . 
	0x00,	//	0008		. . . . . . . . 
	0x00,	//	0009		. . . . . . . . 
	0x00,	//	000A		. . . . . . . . 
	0x00,	//	000B		. . . . . . . . 
	0x00,	//	000C		. . . . . . . . 
	0x00,	//	000D		. . . . . . . . 
	0x00,	//	000E		. . . . . . . . 
	0x00,	//	000F		. . . . . . . . 
	0x7F,	//	0010		. # # # # # # # 
	0x09,	//	0011		. . . . # . . # 
	0x09,	//	0012		. . . . # . . # 
	0x09,	//	0013		. . . . # . . # 
	0x01,	//	0014		. . . . . . . # 
	0x00,	//	0015		. . . . . . . . 
	0x00,	//	0016		. . . . . . . . 
	0x7F,	//	0017		. # # # # # # # 
	0x49,	//	0018		. # . . # . . # 
	0x49,	//	0019		. # . . # . . # 
	0x49,	//	001A		. # . . # . . # 
	0x41,	//	001B		. # . . . . . # 
	0x00,	//	001C		. . . . . . . . 
	0x00,	//	001D		. . . . . . . . 
	0x7F,	//	001E		. # # # # # # # 
	0x41,	//	001F		. # . . . . . # 
	0x41,	//	0020		. # . . . . . # 
	0x41,	//	0021		. # . . . . . # 
	0x3E,	//	0022		. . # # # # # . 
	0x00,	//	0023		. . . . . . . . 
	0x00,	//	0024		. . . . . . . . 
	0x3E,	//	0025		. . # # # # # . 
	0x41,	//	0026		. # . . . . . # 
	0x41,	//	0027		. # . . . . . # 
	0x41,	//	0028		. # . . . . . # 
	0x22,	//	0029		. . # . . . # . 
	0x00,	//	002A		. . . . . . . . 
	0x00,	//	002B		. . . . . . . . 
	0x7F,	//	002C		. # # # # # # # 
	0x49,	//	002D		. # . . # . . # 
	0x49,	//	002E		. # . . # . . # 
	0x49,	//	002F		. # . . # . . # 
	0x36,	//	0030		. . # # . # # . 
	0x00,	//	0031		. . . . . . . . 
	0x00,	//	0032		. . . . . . . . 
	0x7C,	//	0033		. # # # # # . . 
	0x12,	//	0034		. . . # . . # . 
	0x11,	//	0035		. . . # . . . # 
	0x12,	//	0036		. . . # . . # . 
	0x7C,	//	0037		. # # # # # . . 
	0x00,	//	0038		. . . . . . . . 
	0x00,	//	0039		. . . . . . . . 
	0x00,	//	003A		. . . . . . . . 
	0x00,	//	003B		. . . . . . . . 
	0x00,	//	003C		. . . . . . . . 
	0x00,	//	003D		. . . . . . . . 
	0x00,	//	003E		. . . . . . . . 
	0x00,	//	003F		. . . . . . . . 
	0x00,	//	0040		. . . . . . . . 
	0x00,	//	0041		. . . . . . . . 
	0x00,	//	0042		. . . . . . . . 
	0x00,	//	0043		. . . . . . . . 
	0x00,	//	0044		. . . . . . . . 
	0x00,	//	0045		. . . . . . . . 
	0x00 	//	0046		. . . . . . . . 
};

char PORT[16] = {1,2,4,8,16,32,64,128, 0, 0, 0, 0, 0, 0, 0, 0};
int c, t, i;

void main(void)
{
    // PortB as output 
    PORTB=0x00;
    DDRB=0xFF;

    // PortC as output
    PORTC=0x00;
    DDRC=0xFF;

    // PortD as output 
    PORTD=0x00;
    DDRD=0xFF;

    // Settings
    TCCR0=0x00;
    TCNT0=0x00;
    OCR0=0x00;

    TCCR1A=0x00;
    TCCR1B=0x00;
    TCNT1H=0x00;
    TCNT1L=0x00;
    ICR1H=0x00;
    ICR1L=0x00;
    OCR1AH=0x00;
    OCR1AL=0x00;
    OCR1BH=0x00;
    OCR1BL=0x00;

    ASSR=0x00;
    TCCR2=0x00;
    TCNT2=0x00;
    OCR2=0x00;

    TIMSK=0x00;

    while (1) {
        for(i = 0; i < 55; ++i) {
            for(t = 0; t < 15; ++t) {              
                for (c = 0; c < 8; ++c) {
                    PORTD = PORT[c];                             
                    PORTC = ~image_code[54 - i + c]; 
                    delay_ms(1);
                }
                PORTD = 0;         
                for (c = 0; c < 8; ++c) {               
                    PORTB = PORT[c]; 
                    PORTC = ~image_code[54 - i + c + 8];       
                    delay_ms(1);   
                }
                PORTB = 0; 
            }
        }
    };
} 