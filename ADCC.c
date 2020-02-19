/*
 * ADCC.c
 *
 *  Created on: Feb 18, 2020
 *      Author: Ra4ad
 */

#include "ADCC.h"
volatile uint16 g_adc_result=0;

ISR(ADC_vect)
{
	g_adc_result=ADC;
}

void ADC_Init(const ADC_Configtype *Config_Ptr)
{
	ADMUX=( ( Config_Ptr -> Referance ) << 6);

	SET_BIT(ADCSRA,ADEN);

	ADCSRA|=( (Config_Ptr -> Mode) << ADIE);

	ADCSRA=(ADCSRA & 0xF8) | ( (Config_Ptr -> Presclar) & 0x07);
}
uint16 ADC_ReadChannel(const ADC_Configtype *Config_Ptr)
{
	ADMUX=(( Config_Ptr->Channel));

	SET_BIT(ADCSRA,ADSC);

	if((Config_Ptr -> Mode) == POLLING)
	{
		while(BIT_IS_CLEAR(ADCSRA,ADIF))
		{
			SET_BIT(ADCSRA ,ADIF);
		}
	}

	else
	{
	}

	return ADC;
}
