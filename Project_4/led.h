/*
 * led.h
 *
 *  Created on: 12 Oct 2024
 *      Author: farah
 */

#ifndef LED_H_
#define LED_H_

#include "std_types.h"

#define POSITIVE_LOGIC /*if the LEDs connection is negative logic change it to negative logic*/

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define RED_LED_PORT_ID                 PORTC_ID
#define RED_LED_PIN_ID                  PIN0_ID

#define GREEN_LED_PORT_ID                 PORTC_ID
#define GREEN_LED_PIN_ID                  PIN1_ID

#define BLUE_LED_PORT_ID                 PORTC_ID
#define BLUE_LED_PIN_ID                  PIN2_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	RED_LED,GREEN_LED,BLUE_LED
}LED_ID;


#ifdef POSITIVE_LOGIC /*POSITIVE LOGIC ON=1,OFF=0*/
typedef enum
{
	LED_OFF,LED_ON
}LED_STATE;


#else /*NEGATIVE LOGIC ON=0,OFF=1*/
typedef enum
{
	LED_ON,LED_OFF
}LED_STATE;
#endif

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Initialises all LEDs (red, green, blue) pins direction
 * Turn off all the LEDs
 */
void LEDS_init(void);

/*
 * Description :
 * Turns on the specified LED.
 */
void LED_on(LED_ID id);
/*
 * Description :
 * Turns off the specified LED.
 */
void LED_off(LED_ID id);



#endif /* LED_H_ */
