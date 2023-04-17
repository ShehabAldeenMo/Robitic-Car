/*
 * TIMER_Interface.h
 *
 * Created on: 18/12/2022
 *  Author: ENG/Shehab aldeen
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#include "../MCAL_DRIVERS/TIMER_CFG.h"
#include "../MCAL_DRIVERS/TIMER_Private.h"
#include "../Serivecs_driver/STD_TYPES.h"

/*********************  For all functions  **************************/
void TIMER_VidSetCallBack (u8 Copy_NumOfINT , void (*ptr)(void));     //use to point on excuted function in ISR





/************************* Specific for TIMER0 FUNC *******************************/

void TIMER0_VidInitialize (void) ;                                    //use to initialize TIMER0

/*For PWM mode*/
void Timer0_VidSETDUTY (u8 duty ) ;                                   //to select specific duty in timer0

/*For timing mode*/
void TIMER0_Set_Time_S (u8 Copy_U8Time);                                     //to set wanted time
void TIMER0_Set_Time_mS (u16 Copy_U8Time);                                   //to set wanted time
void TIMER_VidSetCallBack (u8 Copy_NumOfINT , void (*ptr)(void));     //use to point on excuted function in ISR


/*********************************************************************************/







/************************* TIMER1 FUNC ******************************************/


/*For PWM mode 14*/
void TIMER1_VidInitializeMode14();
void Timer1_VidSETDUTY (u16 Copy_U8DutyA , u16 Copy_U8DutyB ) ;              //to select specific duty in timer0
void Timer1_VidSetFrequency () ;

/*For Mode 15*/
void TIMER1_VidInitializeMode15(u8 Mode,u8 ModelA,u8 ModelB);
void TIMER1_VidSetOCR1A(u16 CopyOCR1A);
void TIMER1_VidSetOCR1B(u16 CopyOCR1B);
void TIMER1_VidSetICR1(u16 Copy_ICR1);

/*for ICU mode*/
void Timer1Icu_init();
void Timer1Icu_setCallBack(void(*a_ptr)(void));
void Timer1Icu_setEdgeDetectionType(u8 Copy_u8EdgeType);
u16 Timer1Icu_getInputCaptureValue(void);
void Timer1Icu_clearTimerValue(void);

/*********************************************************************************/









/************************* TIMER2 FUNC *******************************************/

void TIMER2_VidInitialize (void) ;                                    //use to initialize TIMER0

/*For PWM Mode*/
void Timer2_VidSETDUTY (u8 duty ) ;                                   //to select specific duty in timer0

/*For Timing Mode*/
void TIMER2_Set_Time_S (u8 Copy_U8Time);                                     //to set wanted time
void TIMER2_Set_Time_mS (u16 Copy_U8Time);                                   //to set wanted time

#endif /* TIMER_INTERFACE_H_ */
