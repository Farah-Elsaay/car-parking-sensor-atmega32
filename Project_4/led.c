/*
 * led.c
 *
 *  Created on: 12 Oct 2024
 *      Author: farah
 */
#include"led.h"
#include"gpio.h"

/*
 * Description
 * Initialises all LEDs (red, green, blue) pins direction
 * Turn off all the LEDs
 */
void LEDS_init(void)
{
	 /*set the LEDs as output pins*/
	 GPIO_setupPinDirection( RED_LED_PORT_ID, RED_LED_PIN_ID , PIN_OUTPUT);
	 GPIO_setupPinDirection( GREEN_LED_PORT_ID, GREEN_LED_PIN_ID , PIN_OUTPUT);
	 GPIO_setupPinDirection( BLUE_LED_PORT_ID, BLUE_LED_PIN_ID , PIN_OUTPUT);
     /*turn off the LEDs*/
	 GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID , LED_OFF);
	 GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID , LED_OFF);
	 GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID , LED_OFF);
}
/*
 * Description :
 * Turns on the specified LED.
 */
void LED_on(LED_ID id)
{
	 switch(id)
	 {
	 case RED_LED:
		 GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID , LED_ON);
		 break;
	 case GREEN_LED:
		 GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID , LED_ON);
		 break;
	 case BLUE_LED:
		 GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID , LED_ON);
		 break;
	 }
}
/*
 * Description :
 * Turns off the specified LED.
 */
void LED_off(LED_ID id)
{
	 switch(id)
	 {
	 case RED_LED:
		 GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID , LED_OFF);
		 break;
	 case GREEN_LED:
		 GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID , LED_OFF);
		 break;
	 case BLUE_LED:
		 GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID , LED_OFF);
		 break;
	 }


}


