/*
 * MultipleTasksCar_Private.h
 *
 *
 *  Created on: 18/12/2022
 *  Author: ENG/Shehab aldeen
 */

/*     Libraries    */
#include "../Serivecs_driver/STD_TYPES.h"
#include "../Serivecs_driver/BIT_MATH.h"
#include "avr/delay.h"

/* Lower Layer Interface Files*/
#include "../HAL_DRIVERS/Bluetooth_Interface.h"
#include "../HAL_DRIVERS/DCMOTOR_Interface.h"
#include "../HAL_DRIVERS/Servo_Inteface.h"
#include "../HAL_DRIVERS/ULTRASONIC_Interface.h"
#include "../HAL_DRIVERS/IR_Interface.h"

#include "../MCAL_DRIVERS/DIO_interface.h"
#include "../MCAL_DRIVERS/TIMER_Interface.h"
#include "../MCAL_DRIVERS/INTERRUPT_Interface.h"


/* Own Driver Files*/
    /* no needed */

#ifndef APP_DRIVER_MULTIPLETASKSCAR_PRIVATE_H_
#define APP_DRIVER_MULTIPLETASKSCAR_PRIVATE_H_

#define TRIAL 5

#define UP       'a'
#define DOWN     'b'
#define RIGHT    'c'
#define LEFT     'd'
#define NO_THING 'e'

/************************************/

#define FIRST_LINE 'a'
#define SEC_LINE 'b'
#define THIRD_LINE 'c'
#define FORTH_LINE 'd'


/************************************/

#define HIGH 1
#define LOW 0



/************************************/

//define wanted states
#define STOP 0
#define CLK_WISE 1
#define ANTI_CLK_WISE 2


/************************************/

//define PORT
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3


/************************************/

#define HALF_PERCENTAGE          50
#define FULL_PERCENTAGE          100
#define QUARTER_PERCENTAGE       25
#define THREE_QUARTER_PERCENTAGE 75


/************************************/

#define ANGLE_ZERO       1500
#define ANGLE_NEGTIVE90  400
#define ANGLE_POSITIVE90 2400


/************************************/

#define MIN_DISTANCE      20

/************************************/

#define Y_AXIS             1
#define X_AXIS             0

/************************************/

#define DEFAULT            0

/************************************/

#define ENTER_VALUE1      'a'
#define ENTER_VALUE2      'b'



/************************************/
#define DFHVUD              130        /* DFHVUD   : Delay For Three Quarter Velocity Up and Down    */
#define DFHVRL              630       /* DFHVRL   : Delay For Three Quarter Velocity Right and Left */
#define DFHVBACK            1305       /* DFHVBACK : Delay For Three Quarter Velocity  to go back    */
#define DWSTOP              2000      /* DWSTOP   : Delay while stopping                   */


/************************************/
/* private functions  */
void MultipleTasksCar_DCMotorVelocity(u8 CopyVelocityPercentage);
void MultipleTasksCar_RightAction        ();
void MultipleTasksCar_LeftAction         ();
void MultipleTasksCar_TurnBack           ();
void MultipleTasksCar_StopActionDelayed  ();
void UltraSonicRightAction               ();
void UltraSonicLeftAction                ();
void UltraSonicStopAction                ();

#endif /* APP_DRIVER_MULTIPLETASKSCAR_PRIVATE_H_ */
