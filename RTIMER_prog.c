/*
 * RTIMER_prog.c
 *
 *  Created on: Aug 3, 2018
 *   
 */
/*
 * TIMER_prog.c
 *
 *  Created on: Jul 6, 2018
 *      Author: Sedra Frimware
 */
#include"../lib/std_types.h"
#include"../lib/macros.h"
#include"DIO_interface.h"
#include<avr/io.h>
#include<avr/interrupt.h>
#define F_CPU 12000000

typedef enum{
	coil_1=1,
	coil_2,
	coil_3,
	coil_4
}coil_type;

coil_type coil=coil_1;

void Timer_Inits(void){

	CLEAR_BIT(TCCR0,7);
	CLEAR_BIT(TCCR0,6);
	CLEAR_BIT(TCCR0,5);
	CLEAR_BIT(TCCR0,4); // ALL NORMAL MODE
	CLEAR_BIT(TCCR0,3);
	CLEAR_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);      // NO PRESCALING

	CLEAR_BIT(TIMSK,1);
	SET_BIT(TIMSK,0);     //PIE  -> INTERRUPT

	SET_BIT(TIFR,0);     //PIF  -> INTERRUPT OV FLAG

    TCNT0=32;          //ERROR DEGREE
}
void ToggleLed2 (void){
	DIO_voidTogglePinValue(DIO_PORTD , DIO_PIN_6);
}

void ToggleLed1 (void){
	DIO_voidTogglePinValue(DIO_PORTD , DIO_PIN_7);
}

void STM (void){
	switch(coil){
	case coil_1:
		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_0,DIO_HIGH);
		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_1,DIO_LOW);
		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_2,DIO_LOW);
	    DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_3,DIO_LOW);
	    coil=coil_2;
	    break;
	case coil_2:
		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_0,DIO_LOW);
		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_1,DIO_HIGH);
		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_2,DIO_LOW);
		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_3,DIO_LOW);
		 coil=coil_3;
			    break;

	case coil_3:
		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_0,DIO_LOW);
		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_1,DIO_LOW);
		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_2,DIO_HIGH);
		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_3,DIO_LOW);
		 coil=coil_4;
		 break;

	case coil_4:
		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_0,DIO_LOW);
		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_1,DIO_LOW);
		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_2,DIO_LOW);
		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_3,DIO_HIGH);
		 coil=coil_4;
			break;
	}



}

