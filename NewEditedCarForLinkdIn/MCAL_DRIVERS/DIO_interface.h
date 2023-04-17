/*
 *  File : DIO_interface.h
 *  DATE: 6/9/2022
 *  Author: Shehab aldeen
 *  Version : V1
 *  Describtion : --------------
 */

/*     Libraries    */
#include "../Serivecs_driver/STD_TYPES.h"
#include "../Serivecs_driver/BIT_MATH.h"

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

void DIO_VidSetPinDirection (u8 Copy_U8Port , u8 Copy_U8Pin , u8 Copy_U8Dir ) ;
void DIO_VidSetPortDirection (u8 Copy_U8Port , u8 Copy_U8Dir ) ;
void DIO_VidSetPinValue (u8 Copy_U8Port , u8 Copy_U8Pin , u8 Copy_U8Val ) ;
void DIO_VidSetPortValue (u8 Copy_U8Port , u8 Copy_U8Val ) ;
void DIO_VidTogglePinValue (u8 Copy_U8Port , u8 Copy_U8Pin ) ;
u8 DIO_U8GetPinValue (u8 Copy_U8Port , u8 Copy_U8Pin ) ;

#endif
