  /**
 * @file Activity1.c
 * @author Chetan()
 * @brief To blink the led when a person occuipes seat and switch on the heater
 * @date 2021-04-23
 */
#include "Activity1.h"

/*header files*/

/**
 * @brief Initialize all the Peripherals and pin configurations
 */
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

int main(void)
{
	/* Initialize Peripherals */
	peripheral_init();

	while (1)
	{
        change_led_state(0x01);
		delay_ms(1000);
	}
	return 0;
}