/*
 * Excutable.c
 *
 *  Created on: Feb 18, 2020
 *      Author: Ra4ad
 */

#include "ADCC.h"
#include "lcd.h"

int main(void)
{

	uint32 temp;
	/* initialize LCD driver */
	LCD_init();
	/* Create configuration structure for ADC driver */
	ADC_Configtype Configtype ={Internal,ADC2 ,POLLING , F_CPU_8};
	/* initialize ADC driver */
	ADC_Init(&Configtype);
	/* clear LCD at the beginning */
	LCD_clearScreen();
	/* display this string "ADC0 Value = " only once at LCD */

	LCD_displayString("Temp = ");
	LCD_goToRowColumn(0,10);
	/* display character 'C' on the screen "Temp =   C" */
	LCD_displayCharacter('C');

	while(1)
	{
		/* display the number every time at this position */
		LCD_goToRowColumn(0,7);
		/* choose ADC0 to where the first potentiometer is connect */
		Configtype.Channel=ADC2;
		/* read the selected channel */
		g_adc_result=ADC_ReadChannel(&Configtype);
		/* display the ADC0 value on LCD screen */
		temp = ((uint32)g_adc_result*150*2.56)/(1023*1.5); /* calculate the temp from the ADC value*/
		LCD_intgerToString(temp); /* display the temp on LCD screen */
	}

}

