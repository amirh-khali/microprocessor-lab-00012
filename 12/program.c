/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 5/29/2022
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

// Graphic Display functions
#include <glcd.h>

// Font used for displaying text
// on the graphic display
#include <font5x7.h>

#include <delay.h>

// Declare your global variables here
int vx = 2;
int vy = 2;
int x = 64;
int y = 32;

void main(void) {
    // Declare your local variables here
    // Variable used to store graphic display
    // controller initialization data
    GLCDINIT_t glcd_init_data;

    // Input/Output Ports initialization
    // Port A initialization
    // Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
    DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
    // State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
    PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

    // Port B initialization
    // Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
    DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
    // State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
    PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

    // Port C initialization
    // Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
    DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
    // State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
    PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

    // Port D initialization
    // Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
    DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
    // State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
    PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

    // Graphic Display Controller initialization
    // The KS0108 connections are specified in the
    // Project|Configure|C Compiler|Libraries|Graphic Display menu:
    // DB0 - PORTA Bit 0
    // DB1 - PORTA Bit 1
    // DB2 - PORTA Bit 2
    // DB3 - PORTA Bit 3
    // DB4 - PORTA Bit 4
    // DB5 - PORTA Bit 5
    // DB6 - PORTA Bit 6
    // DB7 - PORTA Bit 7
    // E - PORTB Bit 0
    // RD /WR - PORTB Bit 1
    // RS - PORTB Bit 2
    // /RST - PORTB Bit 3
    // CS1 - PORTB Bit 4
    // CS2 - PORTB Bit 5

    // Specify the current font for displaying text
    glcd_init_data.font=font5x7;
    // No function is used for reading
    // image data from external memory
    glcd_init_data.readxmem=NULL;
    // No function is used for writing
    // image data to external memory
    glcd_init_data.writexmem=NULL;

    glcd_init(&glcd_init_data);
    
    // Section 1
    glcd_clear();                        
    glcd_moveto(5,0);
    glcd_outtext("AmirHossein Ahmadi");
    glcd_moveto(5,55);
    glcd_outtext("97522292");
    delay_ms(2000);
    
    // Section 2
    glcd_clear();     
    glcd_line(30,54,98,54); 
    glcd_line(98,54,98,32); 
    glcd_line(30,32,30,54);
    glcd_line(20,32,30,32);
    glcd_line(98,32,108,32);
    glcd_line(108,32,64,5);
    glcd_line(64,5,40,20);
    glcd_line(40,20,40,10);
    glcd_line(40,10,45,10);
    glcd_line(45,10,45,5);
    glcd_line(45,5,25,5);
    glcd_line(25,5,25,10);
    glcd_line(25,10,30,10);
    glcd_line(30,10,30,25);
    glcd_line(30,25,20,32);
    delay_ms(2000);
        
    while (1) {
        glcd_clear();
        glcd_circle(x, y, 2);
        if (x == 2 || x == 126) {
            vx = -vx;
        }
        if (y == 2 || y == 62) {
            vy = -vy;
        }
        x += vx;
        y += vy;
        delay_ms(70);

    }
}
