/*
 * TIMER_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define NO_PRE   1
#define PRE_8    2
#define PRE_64   3
#define PRE_256  4
#define PRE_1024 5

#define OV                                  1
#define COMPARE                             2
#define FAST_PWM                            3
#define ICU_HARDWARE                        4

#define DISABLE_MODULE_VALUE               0x00
#define PRESCLR1_VALUE                     0x01
#define ZER0_INITIALIZER                   0x00

#define RISING_EDGY  1
#define FALLING_EDGY 0

#define ICP_PORT    3
#define ICP_PIN     6

/*  7 $00C TIMER1 CAPT Timer/Counter1 Capture Event
	8 $00E TIMER1 COMPA Timer/Counter1 Compare Match A
	9 $010 TIMER1 COMPB Timer/Counter1 Compare Match B
	10 $012 TIMER1 OVF Timer/Counter1 Overflow    */

void __vector_11(void)    __attribute__((signal));                           //overflow mode in timer 0
void __vector_9(void)    __attribute__((signal));                            //overflow mode in timer 1
void __vector_8(void)    __attribute__((signal));                            //COMB mode in timer 1
void __vector_7(void)    __attribute__((signal));                            //COMA mode in timer 1
void __vector_6(void)    __attribute__((signal));                            //CAPT mode in timer 1

void __vector_5(void)    __attribute__((signal));                           //overflow mode in timer 2
void __vector_4(void)    __attribute__((signal));                           //compare mode in timer 2

/************************** TIMER0 *****************************/

#define TCCR0 *((volatile u8*)(0x53))
#define FOC0  7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02  2
#define CS01  1
#define CS00  0

#define TCNT0 *((volatile u8*)(0x52))
#define TIMSK *((volatile u8*)(0x59))
#define OCIE0 1
#define TOIE0 0

#define OCR0 *((volatile u8*)(0x5C))

/********************* TIMER1 ****************************/

#define FAST_PWM_ICR1 14
#define FAST_PWM_OCR1A 15

#define Normal 0
#define Toggle 1
#define CLEAR 2
#define SET 3

#define TCCR1A   *((volatile u8*)(0x4F))
#define COM1A1 7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4
#define FOC1A  3
#define FOC1B  2
#define WGM11  1
#define WGM10  0

#define TCCR1B *((volatile u8*)(0x4E))
#define ICNC1 7
#define ICES1 6
#define WGM13 4
#define WGM12 3
#define CS12  2
#define CS11  1
#define CS10  0

#define TIMSK *((volatile u8*)(0x59))
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2

#define OCR1AH *((volatile u8*)(0x4B))
#define OCR1AL *((volatile u8*)(0x4A))

#define OCR1BH *((volatile u8*)(0x49))
#define OCR1BL *((volatile u8*)(0x48))

#define ICR1H *((volatile u8*)(0x47))
#define ICR1L *((volatile u8*)(0x46))
#define ICR1 *((volatile u16*)(0x46))

#define TCNT1H *((volatile u8*)(0x4D))
#define TCNT1L *((volatile u8*)(0x4C))
#define TCNT1 *((volatile u16*)(0x4C))

/******************** TIMER2 ********************************/

#define TCCR2 *((volatile u8*)(0x45))
#define FOC2  7
#define WGM20 6
#define COM21 5
#define COM20 4
#define WGM21 3
#define CS22  2
#define CS21  1
#define CS20  0

#define TCNT2 *((volatile u8*)(0x44))

#define OCIE2 7
#define TOIE2 6

#define OCR2 *((volatile u8*)(0x43))

#endif /* TIMER_PRIVATE_H_ */
