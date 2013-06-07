//********************************************************
//******  Rutinas para Nokia 3310 LCD - 3310pic.h  *******
//********************************************************
//Microcontrolador:   PIC16F88 (Tentativo)
//Compilador:      GSC C
//Autor original:   CC Dharmani, Chennai (India)
//Autor del port:   Sergio Urbina (Mexico)
//Fecha:         Junio 2013
//Version:         0.0 experimental
//********************************************************


//Cambios importantes en esta librería
//- No contiene todas las letras y librerías, sólo lo necesario
//  para el juego "Espies Invadeiders"

#ifndef _3310_ROUTINES_H_

#define _3310_ROUTINES_H_

//Need to redefine this
/*#define SET_DC_PIN                 PORTB |= 0x01  
#define CLEAR_DC_PIN               PORTB &= ~0x01 
#define SET_SCE_PIN                PORTB |= 0x04
#define CLEAR_SCE_PIN              PORTB &= ~0x04
#define SET_RST_PIN                PORTB |= 0x10
#define CLEAR_RST_PIN              PORTB |= 0x10*/

//Sacadas de la manga
void set_dc_pin(void);
void clear_dc_pin(void);
void set_sce_pin(void);
void clear_sce_pin(void);
void set_rst_pin(void);
void clear_rst_pin(void);


void LCD_init ( void );
void LCD_clear ( void );
void LCD_gotoXY ( unsigned char x, unsigned char y );
void LCD_writeChar ( unsigned char character );
void LCD_writeData ( unsigned char data );
void LCD_writeCommand ( unsigned char command );
//void LCD_writeString_F ( const unsigned char *string);
void LCD_setPixel ( unsigned char x, unsigned char y);
void LCD_drawLine ( unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2 );
void LCD_drawBorder (void );

//Fuentes de 5x7

static const unsigned char smallFont[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00,   // sp
    0x7F, 0x49, 0x49, 0x49, 0x41,   // E
    0x46, 0x49, 0x49, 0x49, 0x31,   // S
    0x7F, 0x09, 0x09, 0x09, 0x06,   // P
    0x00, 0x41, 0x7F, 0x41, 0x00,   // I
    0x7F, 0x04, 0x08, 0x10, 0x7F,   // N
    0x1F, 0x20, 0x40, 0x20, 0x1F,   // V
    0x7F, 0x41, 0x41, 0x22, 0x1C,   // D
    0x7F, 0x09, 0x19, 0x29, 0x46,   // R
    0x42, 0x61, 0x51, 0x49, 0x46,   // 2
    0x3E, 0x51, 0x49, 0x45, 0x3E,   // 0
    0x00, 0x42, 0x7F, 0x40, 0x00,   // 1
    0x21, 0x41, 0x45, 0x4B, 0x31,   // 3
   //Falta por agregar "Los pelucas"
}

#endif  //  _3310_ROUTINES_H_
