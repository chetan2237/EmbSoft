/**
 * @file project_main.c
 * @author Chetan ()
 * @brief Project to Blink an LED at 1000ms ON when the heater is on.
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "project_config.h"

#include "user_utils.h"
#include "blinky.h"

/**
 * @brief Initialize all the Peripherals and pin configurations
 * 
 */
void peripheral_init(void)
{
	/* Configure LED Pin */
	DDRB =DDRB | (1<<4);  
    DDRC =DDRC & ~(1<<0);
}

void change_led_state(uint8_t state)
{
	 
        if(PINC & (1<<0))  // if pin 0 of port C is high
        {
            PORTB= PORTB | (1<<4);
             // then pin 4 of port B is high
        }
        else   // if above condition is not true
        {
            PORTB= PORTB & ~(1<<4);  // pin 4 of port B remain constant
        }
}


/**
 * @brief Main function where the code execution starts
 * 
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