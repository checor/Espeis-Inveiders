//********************************************************
//******  Rutinas para Nokia 3310 LCD - 3310pic.c  *******
//********************************************************
//Microcontrolador:   PIC16F88 (Tentativo)
//Compilador:      GSC C
//Autor original:   CC Dharmani, Chennai (India)
//Fecha:         Septiembre 2008
//********************************************************

//Modified to fit this project with permission of the author.

//#include "3310_routines.h"

//Nuevas rutinas de la pija
void set_dc_pin(void)
{
   bit_set(PORTC, 2)
}
void clear_dc_pin(void)
{
   bit_clear(PORTC, 2);
}
void set_sce_pin(void)
{
   bit_set(PORTC, 1);
}
void clear_sce_pin(void){
   bit_clear(PORTC, 1);
}
void set_rst_pin(void){
   //
}
void clear_rst_pin(void){
   //
}



/*--------------------------------------------------------------------------------------------------
  Name         :  spi_init
  Description  :  Initialising Pic SPI for using with 3310 LCD
  Argument(s)  :  None.
  Return value :  None.
--------------------------------------------------------------------------------------------------*/
//SPI initialize
//clock rate: 250000hz
void spi_init(void)
{
 //Need to check the GSC C commando for this!!!
 //SPCR = 0x58; //setup SPI
}

void LCD_init ( void )
{
    
   delay_ms(100);
   
   clear_sce_pin();    //Enable LCD
    
   clear_rst_pin();   //reset LCD
    delay_ms(100);
    set_rst_pin();
   
   SET_SCE_PIN;   //disable LCD

    LCD_writeCommand( 0x21 );  // LCD Extended Commands.
    LCD_writeCommand( 0xE0 );  // Set LCD Vop (Contrast).
    LCD_writeCommand( 0x04 );  // Set Temp coefficent.
    LCD_writeCommand( 0x13 );  // LCD bias mode 1:48.
    LCD_writeCommand( 0x20 );  // LCD Standard Commands, Horizontal addressing mode.
    LCD_writeCommand( 0x0c );  // LCD in normal mode.

    LCD_clear();
}

/*--------------------------------------------------------------------------------------------------
  Name         :  LCD_writeCommand
  Description  :  Sends command to display controller.
  Argument(s)  :  command -> command to be sent
  Return value :  None.
--------------------------------------------------------------------------------------------------*/
void LCD_writeCommand ( unsigned char command )
{
    CLEAR_SCE_PIN();     //enable LCD
   
   CLEAR_DC_PIN();     //set LCD in command mode
   
    //  Send data to display controller.
    SPDR = command;

    //  Wait until Tx register empty.
    while ( !(SPSR & 0x80) );

    SET_SCE_PIN();       //disable LCD
}

/*--------------------------------------------------------------------------------------------------
  Name         :  LCD_writeData
  Description  :  Sends Data to display controller.
  Argument(s)  :  Data -> Data to be sent
  Return value :  None.
--------------------------------------------------------------------------------------------------*/
void LCD_writeData ( unsigned char Data )
{
    clear_sce_pin();     //enable LCD
   
   set_dc_pin();     //set LCD in Data mode
   
    //  Send data to display controller.
    SPDR = Data;

    //  Wait until Tx register empty.
    while ( !(SPSR & 0x80) );

    SET_SCE_PIN();       //disable LCD
}

/*--------------------------------------------------------------------------------------------------
  Name         :  LCD_clear
  Description  :  Clears the display
  Argument(s)  :  None.
  Return value :  None.
--------------------------------------------------------------------------------------------------*/
void LCD_clear ( void )
{
    int i,j;
   
   LCD_gotoXY (0,0);     //start with (0,0) position

    for(i=0; i<8; i++)
     for(j=0; j<90; j++)
        LCD_writeData( 0x00 );
   
    LCD_gotoXY (0,0);   //bring the XY position back to (0,0)
      
}

/*--------------------------------------------------------------------------------------------------
  Name         :  LCD_gotoXY
  Description  :  Sets cursor location to xy location corresponding to basic font size.
  Argument(s)  :  x - range: 0 to 84
                   y -> range: 0 to 5
  Return value :  None.
--------------------------------------------------------------------------------------------------*/
void LCD_gotoXY ( unsigned char x, unsigned char y )
{
    LCD_writeCommand (0x80 | x);   //column
   LCD_writeCommand (0x40 | y);   //row
}


//Editar esta para lo �nico que la necesitamos
//Mostrar la pantalla de Inicio

/*--------------------------------------------------------------------------------------------------
  Name         :  LCD_writeChar
  Description  :  Displays a character at current cursor location and increment cursor location.
  Argument(s)  :  ch   -> Character to write.
  Return value :  None.
--------------------------------------------------------------------------------------------------*/
void LCD_writeChar (unsigned char ch)
{
   unsigned char j;
  
   LCD_writeData(0x00);
   
   for(j=0; j<5; j++)
     LCD_writeData( smallFont [(ch-32)*5 + j] );
    
   LCD_writeData( 0x00 );
} 

/*--------------------------------------------------------------------------------------------------
  Name         :  LCD_drawBorder
  Description  :  Draws rectangle border on the display
  Argument(s)  :  None
  Return value :  None
--------------------------------------------------------------------------------------------------*/

void LCD_drawBorder (void )
{
  unsigned char i, j;  
    
  for(i=0; i<7; i++)
  {
    LCD_gotoXY (0,i);
   
   for(j=0; j<84; j++)
   {
     if(j == 0 || j == 83)
      LCD_writeData (0xff);      // first and last column solid fill to make line
     else if(i == 0)
       LCD_writeData (0x08);      // row 0 is having only 5 bits (not 8)
     else if(i == 6)
       LCD_writeData (0x04);      // row 6 is having only 3 bits (not 8)
     else
       LCD_writeData (0x00);
   }
  }
}   

/*--------------------------------------------------------------------------------------------------
                                         End of file.
--------------------------------------------------------------------------------------------------*/
