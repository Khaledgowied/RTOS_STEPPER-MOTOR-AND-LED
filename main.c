/*
 * main.c
 *
 *  Created on: Aug 3, 2018
 *      Author: Sedra Frimware
 */
/*
 * main.c
 *
 *  Created on: Jul 6, 2018
 *      Author: Sedra Frimware
 */
#include<avr/io.h>                          // timer
#include"../lib/std_types.h"
#include"../lib/macros.h"
#include"DIO_interface.h"
#include<avr/interrupt.h>
#include "RTIMER_interface.h"
#define F_CPU 12000000

typedef struct{
	u32 First_delay;
	u32 Priodicty;
	void(*codeptr)(void);
}Task_type;

Task_type * tasks[10];
u32 ov_count=0;

int main(void){

	//Task_type led1;

	Task_type stepper;

	DIO_voidSetPinDir(DIO_PORTA, DIO_PIN_0, DIO_OUTPUT);
	DIO_voidSetPinDir(DIO_PORTA, DIO_PIN_1, DIO_OUTPUT);
	DIO_voidSetPinDir(DIO_PORTA, DIO_PIN_2, DIO_OUTPUT);
	DIO_voidSetPinDir(DIO_PORTA, DIO_PIN_3, DIO_OUTPUT);

	stepper.First_delay=0;
	stepper.Priodicty=2;
	stepper.codeptr=STM;
	tasks[0]=&stepper;

	Timer_Inits();
	SET_BIT(SREG,7);
	while(1);
	return 0;
}

ISR(TIMER0_OVF_vect){

	ov_count++;           //number of over flows
	if(ov_count==47){   // reach to 1sec by equation
		ov_count=0;        // for another second because will return to main normal oper.
		TCNT0=32;        // addtion the error
		Scheduler();
	}

}

void Scheduler(void){
	u8 i ;
	for(i=0;i<1;i++){
		if(tasks[i]->First_delay==0){
			(tasks[i]->codeptr)();
			tasks[i]->First_delay=tasks[i]->Priodicty-1;     //??????

		}
		else{
			tasks[i]->First_delay--;
		}
	}

}

