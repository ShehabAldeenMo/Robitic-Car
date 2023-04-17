/*
 * Servo_Inteface.h
 *
 * Created on: 18/12/2022
 *  Author: ENG/Shehab aldeen
 */

#include "../Serivecs_driver/STD_TYPES.h"

#ifndef SERVO_INTEFACE_H_
#define SERVO_INTEFACE_H_

void SERVO_VidInitOCR1A(void);
void SERVO_VidInitOCR1B(void);
void ServoSetAngleOCR1A(u32 Angle);
void ServoSetAngleOCR1B(u32 Angle);
void SetAngleOfServo(u16 InitialAngle , u16 LastAngle );         /* to set the angle of servo */

#endif /* SERVO_INTEFACE_H_ */
