/*
 * MultipleTasksCar_Interface.h
 *
 *  Created on: 18/12/2022
 *  Author: ENG/Shehab aldeen
 */

/*     Libraries    */
#include "../Serivecs_driver/STD_TYPES.h"

/* Lower Layer Interface Files*/
    /* no needed */

/* Own Driver Files*/
#include "../APP_DRIVER/MultipleTasksCar_Private.h"


/**********************************************************************
 **********************************************************************
 **********************************************************************
 * The target from each function there's in MultipleTasksCar_prg.c file
 **********************************************************************
 **********************************************************************
 **********************************************************************
 * */


#ifndef APP_DRIVER_MULTIPLETASKSCAR_INTERFACE_H_
#define APP_DRIVER_MULTIPLETASKSCAR_INTERFACE_H_

void MultipleTasksCar_VidInit       ()                     ;
void MultipleTasksCar_GetDirections ()                     ;
void MultipleTasksCar_LineFollower  ()                     ;
void MultipleTasksCar_SetCarVelocity(u8 VelocityPercentage);
void MultipleTasksCar_UltraSonic    ()                     ;
void MultipleTasksCar_MapLine       ()                     ;
u8   MultipleTasksCar_GetMode       ()                     ;

#endif /* APP_DRIVER_MULTIPLETASKSCAR_INTERFACE_H_ */
