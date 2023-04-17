/*
 * TIMER_CFG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#include "../MCAL_DRIVERS/TIMER_Private.h"

#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_

/*
	no_prescalar   "NO_PRE"
	clkI/O/8       "PRE_8"
	clkI/O/64      "PRE_64"
	clkI/O/256     "PRE_256"
	clkI/O/1024    "PRE_1024"
*/

//be aware to make pre_scalar in PRE_8 to make time by ms
#define PRE_TYPE_TIMER0 PRE_8
#define PRE_TYPE_TIMER1 PRE_8
#define PRE_TYPE_TIMER2 PRE_8

/*
"OV"       1
"COMPARE"  2
"FAST_PWM" 3
*/

/*
  BE SURE THAT YOU USE OV MODE TO COUNT TIME ACCURATE IN S             "preferred"
  BE SURE THAT YOU USE PRE_SCALAR /8 TO COUNT TIME ACCURATE IN mS      "FORCED"

 */
#define TIMER0_MODE OV
#define TIMER2_MODE FAST_PWM

/*
"PWM"
"ICU_HARDWARE"
*/

#define TIMER1_MODE ICU_HARDWARE

/*
I make timer0/timer2 for timing mode and also wanted PWM with variable duty
I make timer1 for PWM with variable top and variable duty , for Hardware ICU

we need to make timer1  for Hardware ICU
 */

#endif /* TIMER_CFG_H_ */
