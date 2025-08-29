/*
 * main.c
 *
 *  Created on: 12 Oct 2024
 *      Author: farah
 */
#include"ultrasonic.h"
#include"buzzer.h"
#include"lcd.h"
#include"icu.h"
#include"led.h"
#include<util/delay.h>
#include<avr/io.h>

uint16 distance =0;
uint8 alarm_flag=0;

void distance_on_lcd(void)
{

	       LCD_displayStringRowColumn(0,1,"Distance=");
	        if(distance >= 10)
	        	{
	        		LCD_intgerToString(distance);
	        		LCD_displayString("cm ");
	        	}
	        else
	        	{
	        		LCD_intgerToString(distance);
	        		/* In case the digital value is two or one digits print space in the next digit place */

	        		LCD_displayCharacter(' ');
	        		LCD_displayString("cm ");
	        	}
}


void alarm(void)
{
	    alarm_flag=1;
        while(alarm_flag)
        {
			Buzzer_on();
			LCD_displayStringRowColumn(1,6,"STOP!");
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_on(BLUE_LED);
			_delay_ms(50);
			LED_off(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);
			_delay_ms(50);
			Ultrasonic_Trigger();
			distance=Ultrasonic_readDistance();
			distance_on_lcd();
			if(distance>5)
			{
				alarm_flag=0;
			}
        }
        Buzzer_off();
        LCD_displayStringRowColumn(1,6,"     ");
}

int main(void)
{

	Buzzer_init();
	LCD_init();

	Ultrasonic_init();
	LEDS_init();
    distance_on_lcd();
    /* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);
	LCD_clearScreen();
	while(1)
	{

		Ultrasonic_Trigger();
        distance=Ultrasonic_readDistance();

        distance_on_lcd();

		if(distance<=5)
		{
			alarm();
		}
		else if(distance<=10)
		{
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_on(BLUE_LED);

		}
		else if(distance<=15)
		{
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_off(BLUE_LED);

		}
		else if(distance<=20)
		{
			LED_on(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);

		}
		else
		{
		    LED_off(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);

		}
	}

}
