/*
 * BlueTooth_prg.c
 *
 * Created on: 18/12/2022
 *  Author: ENG/Shehab aldeen
 */

#include "../MCAL_DRIVERS/UART_Interface.h"
#include "../Serivecs_driver/STD_TYPES.h"
#include "../Serivecs_driver/BIT_MATH.h"

void BluetoothInit(){
	UART_VidInit () ;
}

u32 Bluetooth_U32Getnumber(){
	return UART_VidRecieveData();
}

/**********************/
void BluetoothInitInterrupt(){
	UART_VidInitUsingInterrupt () ;
}
u32 Bluetooth_U32GetnumberInterrupt(){
	return UART_VidRecieveDataForInterruptPurpose();
}
/************************/

void Bluetooth_VidSendData(u8 Copy_U8Data){
	 UART_VidSendData(Copy_U8Data);
}
void BluetoothVidSendString (u8 Copy_U8String[]){
	UART_VidSendString(Copy_U8String);
}

void Bluetooth_SetCallBack(  void (*ptr)(void) ){
	UART_SetCallBack(ptr);
}
