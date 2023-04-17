/*
 *  File : DIO_prg.c
 *  DATE: 6/9/2022
 *  Author: Shehab aldeen
 *  Version : V1
 *  Describtion : --------------
 */

/*     Libraries    */
#include "../Serivecs_driver/STD_TYPES.h"
#include "../Serivecs_driver/BIT_MATH.h"

/* Lower Layer Interface Files*/
#include"DIO_private.h"

void DIO_VidSetPinDirection (u8 Copy_U8Port , u8 Copy_U8Pin , u8 Copy_U8Dir ) {
	if ( 1 == Copy_U8Dir ){
		switch (Copy_U8Port){
			case 0 : 
			    SET_BIT(DDRA,Copy_U8Pin);
			    break ;  
			case 1 : 
			    SET_BIT(DDRB,Copy_U8Pin);
			    break ;			
			case 2 : 
			    SET_BIT(DDRC,Copy_U8Pin);
			    break ;  
			case 3 : 
			    SET_BIT(DDRD,Copy_U8Pin);
			    break ; 
		}//end switch
	}//end if
	else if ( 0 == Copy_U8Dir ) {
		switch (Copy_U8Port){
			case 0 : 
			    CLR_BIT(DDRA,Copy_U8Pin);
			    break ;  
			case 1 : 
			    CLR_BIT(DDRB,Copy_U8Pin);
			    break ;			
			case 2 : 
			    CLR_BIT(DDRC,Copy_U8Pin);
			    break ;  
			case 3 : 
			    CLR_BIT(DDRD,Copy_U8Pin);
			    break ; 
		}//end switch
	}//end else if 
}//end FUNC DIO_VidSetPinDirection
void DIO_VidSetPortDirection (u8 Copy_U8Port , u8 Copy_U8Dir ) {
    switch (Copy_U8Port){
		case 0 : 
			DDRA = Copy_U8Dir ;
			break ;  
		case 1 : 
			DDRB = Copy_U8Dir ;
			break ;			
		case 2 : 
			DDRC = Copy_U8Dir ;
			break ;  
		case 3 : 
			DDRD = Copy_U8Dir ;
			break ; 
		}//end switch
}// end FUNC DIO_VidSetPortDirection
void DIO_VidSetPinValue (u8 Copy_U8Port , u8 Copy_U8Pin , u8 Copy_U8Val ) {
	if ( 1 == Copy_U8Val ){
		switch (Copy_U8Port){
			case 0 : 
			    SET_BIT(PORTA,Copy_U8Pin);
			    break ;  
			case 1 : 
			    SET_BIT(PORTB,Copy_U8Pin);
			    break ;			
			case 2 : 
			    SET_BIT(PORTC,Copy_U8Pin);
			    break ;  
			case 3 : 
			    SET_BIT(PORTD,Copy_U8Pin);
			    break ; 
		}//end switch
	}//end if
	else if ( 0 == Copy_U8Val){
		switch (Copy_U8Port){
			case 0 : 
			    CLR_BIT(PORTA,Copy_U8Pin);
			    break ;  
			case 1 : 
			    CLR_BIT(PORTB,Copy_U8Pin);
			    break ;			
			case 2 : 
			    CLR_BIT(PORTC,Copy_U8Pin);
			    break ;  
			case 3 : 
			    CLR_BIT(PORTD,Copy_U8Pin);
			    break ; 
		}//end switch
	}//end else if
}// end FUNC DIO_VidSetPinValue
void DIO_VidSetPortValue (u8 Copy_U8Port , u8 Copy_U8Val ) {
    switch (Copy_U8Port){
		case 0 : 
			PORTA = Copy_U8Val ;
			break ;  
		case 1 : 
			PORTB = Copy_U8Val ;
			break ;			
		case 2 : 
			PORTC = Copy_U8Val ;
			break ;  
		case 3 : 
			PORTD = Copy_U8Val ;
			break ; 
		}//end switch
}//end FUNC DIO_VidSetPortValue
void DIO_VidTogglePinValue (u8 Copy_U8Port , u8 Copy_U8Pin ) {
	switch ( Copy_U8Port ) {
		case 0 : 
		    TOGGLE_BIT( PORTA , Copy_U8Pin ) ;
			break ;  
		case 1 : 
			TOGGLE_BIT( PORTB , Copy_U8Pin ) ;
			break ;			
		case 2 : 
			TOGGLE_BIT( PORTC , Copy_U8Pin ) ;
			break ;  
		case 3 : 
			TOGGLE_BIT( PORTD , Copy_U8Pin ) ;
			break ; 
	}//end switch
}//end FUNC DIO_VidTogglePinValue

u8 DIO_U8GetPinValue (u8 Copy_U8Port , u8 Copy_U8Pin ) {
	switch ( Copy_U8Port ) {
		case 0 : 
		   return GET_BIT( PINA , Copy_U8Pin ) ;
		case 1 : 
			return GET_BIT( PINB , Copy_U8Pin ) ;
		case 2 : 
			return GET_BIT( PINC , Copy_U8Pin ) ;
		case 3 : 
			return GET_BIT( PIND , Copy_U8Pin ) ;
	}//end switch	
}//end FUNC DIO_VidU8PinValue 
