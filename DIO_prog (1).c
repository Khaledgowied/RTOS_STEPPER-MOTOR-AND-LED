/*
 * DIO_prog.c
 *
 *  Created on: Jun 2, 2018
 *
 */
#include"../lib/std_types.h"
#include"../lib/macros.h"
#include"DIO_interface.h"
#include<avr/io.h>
void DIO_voidSetPinDir(u8 Port, u8 Pin, u8 Dir)
{
	switch (Port){

	case 0:
		if (Dir==0){
			CLEAR_BIT(DDRA,Pin);
		}else{
			SET_BIT(DDRA,Pin);
		}
		break;
	case 1:
		if (Dir==0){
			CLEAR_BIT(DDRB,Pin);
		}else{
			SET_BIT(DDRB,Pin);
		}
		break;
	case 2:
		if (Dir==0){
			CLEAR_BIT(DDRC,Pin);
		}else{
			SET_BIT(DDRC,Pin);
		}
		break;
	case 3:
		if (Dir==0){
			CLEAR_BIT(DDRD,Pin);
		}else{
			SET_BIT(DDRD,Pin);
		}
		break;
	}
}
void DIO_voidSetPinValue(u8 Port,u8 Pin,u8 Val)
{
	switch (Port){

	case 0:
		if (Val==0){
			CLEAR_BIT(PORTA,Pin);
		}else{
			SET_BIT(PORTA,Pin);
		}
		break;
	case 1:
		if (Val==0){
			CLEAR_BIT(PORTB,Pin);
		}else{
			SET_BIT(PORTB,Pin);
		}
		break;
	case 2:
		if (Val==0){
			CLEAR_BIT(PORTC,Pin);
		}else{
			SET_BIT(PORTC,Pin);
		}
		break;
	case 3:
		if (Val==0){
			CLEAR_BIT(PORTD,Pin);
		}else{
			SET_BIT(PORTD,Pin);
		}
		break;

	}
}
u8 DIO_u8GetPinValue(u8 Port,u8 Pin)
{
	switch(Port)
	{
	case 0 :
		return GET_BIT(PINA,Pin);
		break;
	case 1 :
		return GET_BIT(PINB,Pin);
		break;
	case 2 :
		return GET_BIT(PINC,Pin);
		break;
	case 3 :
		return GET_BIT(PIND,Pin);
		break;
	}
	return 255;
}
void DIO_voidTogglePinValue(u8 Port,u8 Pin){
	switch(Port)
	{
	case 0 :
		 TOGGLE_BIT(PORTA,Pin);
		break;
	case 1 :
		 TOGGLE_BIT(PORTB,Pin);
		break;
	case 2 :
		 TOGGLE_BIT(PORTC,Pin);
		break;
	case 3 :
		 TOGGLE_BIT(PORTD,Pin);
		break;
	}
}


