  /**
 * @file Activity1.c
 * @author Chetan()
 * @brief To blink the led when a person occuipes seat and switch on the heater
 * @date 2021-04-23
 */
#include "Activity1.h"
#include "Activity2.h"

/*header files*/

/**
 * @brief Initialize all the Peripherals and pin configurations
 */
void InitADC()
{
    ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN) | (7<<ADPS0);
}
void peripheral_init(void)
{
	/* Configure LED Pin */
	DDRB =DDRB | (1<<4);  
    DDRC =DDRC & ~(1<<0);
}

void change_led_state(uint8_t state)
{
	 
        if(PINC & (1<<0))  
        {
            PORTB= PORTB | (1<<4);
        }
        else  
        {
            PORTB= PORTB & ~(1<<4);  
        }
}

/**
 * @brief Main function where the code execution starts
 * @return int Return 0 if the program completes successfully
 * @note  if pin 0 of port C is high then pin 4 of port B is high
 * @note if above condition is not true then pin 4 of port B remain constant
 */

uint16_t ReadADC(uint8_t ch)
{
    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;
    ADCSRA|=(1<<ADSC);
    while(!(ADCSRA & (1<<ADIF)));
    ADCSRA|=(1<<ADIF);
    return(ADC);
}

int main(void)
{
	/* Initialize Peripherals */
  InitADC();
    uint16_t temp;
	peripheral_init();

	while (1)
	{
        change_led_state(0x01);
		delay_ms(1000);
         temp=ReadADC(0);
	}
	return 0;
}