#include "main.h"
#include "3310_routines.h"
#int_RTCC
void  RTCC_isr(void) //Hora de actualizar la pantalla
{

}

#int_TIMER1
void  TIMER1_isr(void) //Hora de mover los inveiders
{

}

void pic_init(){
   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF);
   setup_spi(SPI_MASTER|SPI_L_TO_H|SPI_CLK_DIV_4);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_128);
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);
   setup_timer_2(T2_DISABLED,0,1);
   enable_interrupts(INT_RTCC);
   enable_interrupts(INT_TIMER1);
   //enable_interrupts(GLOBAL); Esta me da mala espina cuate
//Setup_Oscillator parameter not selected from Intr Oscillotar Config tab
}

void main()
{


   // TODO: USER CODE!!

}
