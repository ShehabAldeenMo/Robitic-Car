/*
 * IR_Prg.c
 *
 *  Created on: 18/12/2022
 *  Author: ENG/Shehab aldeen
 */

/*     Libraries    */
#include "../Serivecs_driver/STD_TYPES.h"
#include "../Serivecs_driver/BIT_MATH.h"

/* Lower Layer Interface Files*/
#include <util/delay.h>

/* Own Driver Files*/
#include "../MCAL_DRIVERS/DIO_interface.h"
#include "IR_Interface.h"

void IR_Init(){
	DIO_VidSetPinDirection(IR_PORT,IR_PIN_LEFT,LOW);
	DIO_VidSetPinDirection(IR_PORT,IR_PIN_RIGHT,LOW);
}


