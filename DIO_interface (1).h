/*
 * DIO_interface.h
 *
 *  Created on: Jun 2, 2018
 *     
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

void DIO_voidSetPinValue(u8 Port,u8 Pin,u8 Val);
void DIO_voidSetPinDir(u8 Port, u8 Pin, u8 Dir);
u8 DIO_u8GetPinValue(u8 Port,u8 Pin);
void DIO_voidTogglePinValue(u8 Port,u8 Pin);
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN_0 0
#define DIO_PIN_1 1
#define DIO_PIN_2 2
#define DIO_PIN_3 3
#define DIO_PIN_4 4
#define DIO_PIN_5 5
#define DIO_PIN_6 6
#define DIO_PIN_7 7

#define DIO_INPUT 0
#define DIO_OUTPUT 1

#define DIO_LOW 0
#define DIO_HIGH 1

#define  PORT_INPUT    0
#define  PORT_OUTPUT  0xff

#endif /* DIO_INTERFACE_H_ */
