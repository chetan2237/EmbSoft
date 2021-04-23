#ifndef _BLINKY_H
#define _BLINKY_H
/**
 * @file blinky.h
 * @author Bharath.G ()
 * @brief Project to Blink an LED connected to AVR328 MCU GPIO Pin
 * @version 0.1
 * @date 2021-04-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * Include files
 */ 
#include <avr/io.h>

/**
 * Function Definitions
 */

/**
 * @brief Change the state of the LED Pin according to the value of state
 * 
 * @param state Pin level to which the LED Pin should be set
 */
void change_led_state(uint8_t state);


#endif /** _BLINKY_H */