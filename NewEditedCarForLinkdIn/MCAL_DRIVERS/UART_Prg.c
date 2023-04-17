/*
 * UART_Prg.c
 * Created on: 18/12/2022
 *  Author: ENG/Shehab aldeen
 */

/*     Libraries    */
#include "../Serivecs_driver/STD_TYPES.h"
#include "../Serivecs_driver/BIT_MATH.h"

/* Lower Layer Interface Files*/
#include "UART_Private.h"
#include "avr/delay.h"

/* Own Driver Files*/
#include "DIO_interface.h"

static void (*UART_Ptr)(void) = NULL ;

void UART_SetCallBack(  void (*ptr)(void) ){
	UART_Ptr = ptr ;
}

void UART_VidInit (){
	/* to define pins of TX RX */
	DIO_VidSetPinDirection(3,0,0);
	DIO_VidSetPinDirection(3,1,1);

	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
	CLR_BIT(UCSRB,UCSZ2);

	u8 UCSRC_help = 0b10000000 ;
	CLR_BIT(UCSRC_help,UMSEL);
	CLR_BIT(UCSRC_help,UPM1);
	CLR_BIT(UCSRC_help,UPM0);
	CLR_BIT(UCSRC_help,USBS);
	SET_BIT(UCSRC_help,UCSZ1);
	SET_BIT(UCSRC_help,UCSZ0);
	CLR_BIT(UCSRC_help,UCPOL);
	UCSRC = UCSRC_help ;

	UBRRH = 0 ;
	UBRRL = 51 ;
}

void UART_VidInitUsingInterrupt () {
	/* to define pins of TX RX */
	DIO_VidSetPinDirection(3,0,0);
	DIO_VidSetPinDirection(3,1,1);

	SET_BIT(UCSRB,RXCIE);
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
	CLR_BIT(UCSRB,UCSZ2);

	u8 UCSRC_help = 0b10000000 ;
	CLR_BIT(UCSRC_help,UMSEL);
	CLR_BIT(UCSRC_help,UPM1);
	CLR_BIT(UCSRC_help,UPM0);
	CLR_BIT(UCSRC_help,USBS);
	SET_BIT(UCSRC_help,UCSZ1);
	SET_BIT(UCSRC_help,UCSZ0);
	CLR_BIT(UCSRC_help,UCPOL);
	UCSRC = UCSRC_help ;

	UBRRH = 0 ;
	UBRRL = 51 ;
}
void UART_VidSendData(u8 Copy_U8Data){
	while ( !GET_BIT(UCSRA,UDRE) );
	UDR = Copy_U8Data ;
}

u8 UART_VidRecieveDataForInterruptPurpose(){
	return UDR ;
}

u8 UART_VidRecieveData(){
	while ( !GET_BIT(UCSRA,RXC) );
	return UDR ;
}

void UART_VidSendString (u8 Copy_U8String[]){
	u8 i = 0 ;
	while (Copy_U8String[i] != '\0'){
		UART_VidSendData(Copy_U8String[i]);
		i++ ;
	}
}

void __vector_13(void){
	UART_Ptr();
}//end ISR FUNC
