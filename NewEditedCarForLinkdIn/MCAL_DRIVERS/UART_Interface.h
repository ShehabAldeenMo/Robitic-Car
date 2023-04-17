/*
 * UART_Interface.h
 *
 *  Created on: 18/12/2022
 *  Author: ENG/Shehab aldeen
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/*     Libraries    */
#include "../Serivecs_driver/STD_TYPES.h"
#include "../Serivecs_driver/BIT_MATH.h"

void UART_SetCallBack(  void (*ptr)(void) );

void UART_VidInitUsingInterrupt();
void UART_VidInit () ;
void UART_VidSendData(u8 Copy_U8Data);
u8   UART_VidRecieveData();
void UART_VidSendString (u8 Copy_U8String[]);
u8   UART_VidRecieveDataForInterruptPurpose();

#endif /* UART_INTERFACE_H_ */
