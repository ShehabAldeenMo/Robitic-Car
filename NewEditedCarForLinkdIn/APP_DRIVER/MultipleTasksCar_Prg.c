/*
 * MultipleTasksCar_Prg.c
 *
 *  Created on: 18/12/2022
 *  Author: ENG/Shehab aldeen
 */

/*     Libraries    */
   /******************/

/* Lower Layer Interface Files*/
    /* no needed */

/* Own Driver Files*/
#include "MultipleTasksCar_Private.h"



/*
 Name        : MultipleTasksCar_VidInit
 Input       : void
 Output      : void
 Description : to initialize the states of the car
*/
void MultipleTasksCar_VidInit(){
	/*****************************************/
	BluetoothInit();
	DcMotor_VidInit();
	IR_Init();
	SERVO_VidInitOCR1B();
	Ultrasonic_init();

	/* Global Interrupt Enable */
	GIE_VidEnable();
}



/*
 Name        : MultipleTasksCar_SetCarVelocity
 Input       : u8
 Output      : void
 Description : to set the number velocity of car
*/
void MultipleTasksCar_SetCarVelocity (u8 VelocityPercentage){
	switch (VelocityPercentage){
	case '1' :	MultipleTasksCar_DCMotorVelocity(QUARTER_PERCENTAGE);         break ;
	case '2' : 	MultipleTasksCar_DCMotorVelocity(HALF_PERCENTAGE);            break ;
	case '3' :  MultipleTasksCar_DCMotorVelocity(THREE_QUARTER_PERCENTAGE);   break ;
	case '4' :  MultipleTasksCar_DCMotorVelocity(FULL_PERCENTAGE);            break ;
	}
}

/*
 Name        : MultipleTasksCar_GetDirections
 Input       : void
 Output      : void
 Description : to set the directions of the car
 steps       : determine derctions by press numbers that u wanted
               up ^    down ^'   right >    left <    stop 'select'

*/
void MultipleTasksCar_GetDirections(){
	/*Take direction*/
	 u8 direction = Bluetooth_U32Getnumber() ;

	 /*Act accroding to direction*/
	 switch (direction){
		 case UP :
				DcMotor_VidRotate_Wheels1(ANTI_CLK_WISE);
				DcMotor_VidRotate_Wheels2(ANTI_CLK_WISE);
				break ;
		 case DOWN :
				DcMotor_VidRotate_Wheels1(CLK_WISE);
				DcMotor_VidRotate_Wheels2(CLK_WISE);
				break ;
		 case RIGHT :
				DcMotor_VidRotate_Wheels1(STOP);
				DcMotor_VidRotate_Wheels2(CLK_WISE);
				break ;
		 case LEFT :
				DcMotor_VidRotate_Wheels1(CLK_WISE);
				DcMotor_VidRotate_Wheels2(STOP);
				break ;
		 case NO_THING :
				DcMotor_VidRotate_Wheels1(STOP);
				DcMotor_VidRotate_Wheels2(STOP);
				break ;
     }//end switch
}



/*
 Name        : MultipleTasksCar_DCMotorVelocity
 Input       : void
 Output      : void
 Description : to set the percentage of the velocity of car
*/
void MultipleTasksCar_DCMotorVelocity(u8 CopyVelocityPercentage){
	Timer2_VidSETDUTY(CopyVelocityPercentage);
}




/*
 Name        : MultipleTasksCar_GetMode
 Input       : void
 Output      : u8
 Description : to return the type of mode
*/
u8   MultipleTasksCar_GetMode(){
	return Bluetooth_U32Getnumber() ;
}




/*
 Name        : MultipleTasksCar_LineFollower
 Input       : void
 Output      : void
 Description : to Follow the black line
*/
void MultipleTasksCar_LineFollower(){
	/* To detect black line */
    u8 IRRight   = DIO_U8GetPinValue(IR_PORT,IR_PIN_RIGHT);
    u8 IRLeft    = DIO_U8GetPinValue(IR_PORT,IR_PIN_LEFT);

	 if (! IRRight && ! IRLeft){
		DcMotor_VidRotate_Wheels1(ANTI_CLK_WISE);
		DcMotor_VidRotate_Wheels2(ANTI_CLK_WISE);
	 }
	 else if ( IRRight && ! IRLeft ){
		DcMotor_VidRotate_Wheels1(ANTI_CLK_WISE);
		DcMotor_VidRotate_Wheels2(CLK_WISE);
	 }
	 else if (! IRRight && IRLeft) {
		DcMotor_VidRotate_Wheels1(CLK_WISE);
		DcMotor_VidRotate_Wheels2(ANTI_CLK_WISE);
	 }
	 else {
		DcMotor_VidRotate_Wheels1(STOP);
		DcMotor_VidRotate_Wheels2(STOP);
	 }
}





/*
 Name        : MultipleTasksCar_UltraSonic
 Input       : void
 Output      : void
 Description : to detect obtacles and move accroding to the states
 state 1 : up   - check on obtacle ------no obtacle----> up
                                   ------an obtacle---->state 2
 state 2 : stop - check on obtacle ------no obtacle---->left , delay , up
                                   ------an obtacle---->state 3
 state 3 : stop - check on obtacle ------no obtacle---->right , delay , up
                                   ------an obtacle---->stop for 10 seconds then state 1
 state 4 : all directions are blocked ----> stop for 4 seconds
*/
void MultipleTasksCar_UltraSonic(){
	/* variable for directions */
    static u16 distance ;

    /* to move in suitable velocity */
    MultipleTasksCar_DCMotorVelocity(HALF_PERCENTAGE);

	/* to make servo forward */
    ServoSetAngleOCR1B(ANGLE_ZERO);

	/* to go forward */
    DcMotor_VidRotate_Wheels1(ANTI_CLK_WISE);
	DcMotor_VidRotate_Wheels2(ANTI_CLK_WISE);

	/* to trig ultrasonic pin and get new distance*/
    distance = Ultrasonic_readDistance();

	if (distance < MIN_DISTANCE){
		DcMotor_VidRotate_Wheels1(STOP);
		DcMotor_VidRotate_Wheels2(STOP);

		/* 0 : -90 */
		_delay_ms(500); /* to notice car is stop */
		SetAngleOfServo(ANGLE_ZERO,ANGLE_NEGTIVE90);
		_delay_ms(500);
		ServoSetAngleOCR1B(ANGLE_NEGTIVE90);

		/* update on distance */
		_delay_ms(500); /* to saturate */
		distance = Ultrasonic_readDistance();

		if (distance < MIN_DISTANCE ){
			/* -90 : +90 */
			SetAngleOfServo(ANGLE_NEGTIVE90,ANGLE_POSITIVE90);
			_delay_ms(500);
			ServoSetAngleOCR1B(ANGLE_POSITIVE90);

			/* update on distance */
			_delay_ms(500); /* to saturate */
			distance = Ultrasonic_readDistance();

			if (distance < MIN_DISTANCE ){
				UltraSonicStopAction();
			}//end if left blocked
			else {
				UltraSonicLeftAction();
			}//end else left true
		}//end if right blocked
		else {
			UltraSonicRightAction();
		}//end else right true
	}
}





/*
 Name        : UltraSonicRightAction
 Input       : void
 Output      : void
 Description : if the opposit is blocked go right at first option
*/
void UltraSonicRightAction () {
	SetAngleOfServo(ANGLE_NEGTIVE90,ANGLE_ZERO);
	_delay_ms(500); /* to notice the movement of servo */

	/* to go back and turn Right direction */
	DcMotor_VidRotate_Wheels1(CLK_WISE);
	DcMotor_VidRotate_Wheels2(CLK_WISE);
	_delay_ms(200);
	Timer2_VidSETDUTY(THREE_QUARTER_PERCENTAGE);
	DcMotor_VidRotate_Wheels1(STOP);
	DcMotor_VidRotate_Wheels2(CLK_WISE);
	_delay_ms(400);
	DcMotor_VidRotate_Wheels1(STOP);
	DcMotor_VidRotate_Wheels2(STOP);
}



/*
 Name        : UltraSonicLeftAction
 Input       : void
 Output      : void
 Description : if the opposit is blocked go right at second option
*/
void UltraSonicLeftAction () {
	SetAngleOfServo(ANGLE_POSITIVE90,ANGLE_ZERO);
	_delay_ms(500); /* to notice the movement of servo */

	/* to go back and turn left direction */
	DcMotor_VidRotate_Wheels1(CLK_WISE);
	DcMotor_VidRotate_Wheels2(CLK_WISE);
	_delay_ms(200);
	Timer2_VidSETDUTY(THREE_QUARTER_PERCENTAGE);
	DcMotor_VidRotate_Wheels1(CLK_WISE);
	DcMotor_VidRotate_Wheels2(STOP);
	_delay_ms(450);
	DcMotor_VidRotate_Wheels1(STOP);
	DcMotor_VidRotate_Wheels2(STOP);
}

/*
 Name        : UltraSonicStopAction
 Input       : void
 Output      : void
 Description : To stop if all directions is blocked
*/
void UltraSonicStopAction () {
    ServoSetAngleOCR1B(ANGLE_ZERO);
	DcMotor_VidRotate_Wheels1(STOP);
	DcMotor_VidRotate_Wheels2(STOP);
	_delay_ms(DWSTOP);
}




/*
 Name        : MultipleTasksCar_MapLine
 Input       : void
 Output      : void
 Description : to get into another selected point
*/

void MultipleTasksCar_MapLine(){
	/* flags */
	u8 YaxisFlag       = HIGH ;           //to count on Yaxis
	u8 XaxisFlag       = LOW  ;           //to count on Xaxis
	u8 UpStairFlag_Y   = HIGH ;           //to determine the direction of move on Yaxis
	u8 DownStairFlag_Y = LOW  ;           //to determine the direction of move on Yaxis
	u8 UpStairFlag_X   = HIGH ;           //to determine the direction of move on Xaxis
	u8 DownStairFlag_X = LOW  ;           //to determine the direction of move on Xaxis
	u8 TurnYflag       = HIGH ;           //to determine turning on Yaxis
	u8 TurnXflag       = HIGH ;           //to determine turning on Xaxis
	u8 Stop            = LOW  ;           //to stop moving

	/* setup point */
	static u8 TargerPoint[2] ;
	static u8 ActualPoint[2] ;


	/*  To stack programme to enter the target axises X then Y  */

	/* to enter x axis */
	while (1){
		TargerPoint[0] = MultipleTasksCar_GetMode()  ;

		if (TargerPoint[0] <='4' && TargerPoint[0] >= '0' ){
			TargerPoint[0] = TargerPoint[0] - '0' ;
			break ;
		}//end if

	}//end while

	/* to enter y axis */
	while (1){
		TargerPoint[1] = MultipleTasksCar_GetMode()  ;

		if (TargerPoint[1] <='4' && TargerPoint[1] >= '0' ){
			TargerPoint[1] = TargerPoint[1] - '0' ;
			break ;
		}//end if

	}//end while

    /************************************************************/

	/* To edit car if point under the acual point */
	if ( TargerPoint[Y_AXIS] <  ActualPoint[Y_AXIS] && TurnYflag ){
		/* to turn 180 degree */
		MultipleTasksCar_TurnBack();

		/* to raise down stair flag */
		DownStairFlag_Y = HIGH ;
		UpStairFlag_Y   = LOW  ;
	}
	/************************************************/

	/* To edit car if point under the acual point */
	if ( TargerPoint[X_AXIS] <  ActualPoint[X_AXIS] && TurnXflag ){
		/* to raise down stair flag */
		DownStairFlag_X = HIGH ;
		UpStairFlag_X   = LOW  ;

		TurnXflag = LOW ;
	}
	/************************************************/

	if ( (UpStairFlag_Y && UpStairFlag_X ) || (!UpStairFlag_Y && !UpStairFlag_X ) ){
		TurnYflag = HIGH ;
	}
	else if ((UpStairFlag_Y && !UpStairFlag_X ) || (!UpStairFlag_Y && UpStairFlag_X ) ){
		TurnYflag = LOW ;
	}

	/*  To Runing car  */
	while (Stop != HIGH ){

		/*  get IR conditon  */
		u8 IRRight   = DIO_U8GetPinValue(IR_PORT,IR_PIN_RIGHT);
		u8 IRLeft    = DIO_U8GetPinValue(IR_PORT,IR_PIN_LEFT);
		/*********************/

		/* to walk up  */
		DcMotor_VidRotate_Wheels1(ANTI_CLK_WISE);
		DcMotor_VidRotate_Wheels2(ANTI_CLK_WISE);

		 /* if detect black line by two ir sensor*/
		 if ( IRRight &&  IRLeft ){
			 /* to stop motors to observe the movement*/
			 MultipleTasksCar_StopActionDelayed();

			 if (YaxisFlag){
				 /* to increment or decrement actual point */
				 if (UpStairFlag_Y){
					ActualPoint[Y_AXIS]++ ;
				 }
				 else if (DownStairFlag_Y){
					 ActualPoint[Y_AXIS]-- ;
				 }
			 }
			 else {
				 /* to increment or decrement actual point */
				 if (UpStairFlag_X){
					ActualPoint[X_AXIS]++ ;
				 }
				else if (DownStairFlag_X){
					 ActualPoint[X_AXIS]-- ;
				 }
			 }

			if (ActualPoint[Y_AXIS] == TargerPoint[Y_AXIS] && YaxisFlag ){
				if (TurnYflag){
					/*  right action  */
					MultipleTasksCar_RightAction();
				}
				else {
					/*  left action  */
					MultipleTasksCar_LeftAction();
				}

				/* To enable turn right or left one time */
				YaxisFlag = LOW ;
				XaxisFlag = HIGH;
			}


			if (ActualPoint[X_AXIS] == TargerPoint[X_AXIS] && XaxisFlag ){
				if (TurnXflag){
					/*  left action  */
					MultipleTasksCar_LeftAction();
				}
				else {
					/*  right action  */
					MultipleTasksCar_RightAction();
				}

				/* rising stop flag  */
				Stop = HIGH ;
			}

		 }//end else if
	}//end while(1)
}




/*
 Name        : MultipleTasksCar_RightAction
 Input       : void
 Output      : void
 Description :
*/
void MultipleTasksCar_RightAction()        {
	DcMotor_VidRotate_Wheels1(ANTI_CLK_WISE);
	DcMotor_VidRotate_Wheels2(ANTI_CLK_WISE);
	_delay_ms(DFHVUD);    //for Three Quarter velocity
	DcMotor_VidRotate_Wheels1(ANTI_CLK_WISE);
	DcMotor_VidRotate_Wheels2(CLK_WISE);
	_delay_ms(DFHVRL);    //for Three Quarter velocity
	DcMotor_VidRotate_Wheels1(STOP);
	DcMotor_VidRotate_Wheels2(STOP);
}



/*
 Name        : MultipleTasksCar_LeftAction
 Input       : void
 Output      : void
 Description :
*/
void MultipleTasksCar_LeftAction()         {
	DcMotor_VidRotate_Wheels1(ANTI_CLK_WISE);
	DcMotor_VidRotate_Wheels2(ANTI_CLK_WISE);
	_delay_ms(DFHVUD);    //for Three Quarter velocity
	DcMotor_VidRotate_Wheels1(CLK_WISE);
	DcMotor_VidRotate_Wheels2(ANTI_CLK_WISE);
	_delay_ms(DFHVRL+25);    //for Half velocity
	DcMotor_VidRotate_Wheels1(STOP);
	DcMotor_VidRotate_Wheels2(STOP);
}



/*
 Name        : MultipleTasksCar_TurnBack
 Input       : void
 Output      : void
 Description :
*/
void MultipleTasksCar_TurnBack()         {
	DcMotor_VidRotate_Wheels1(ANTI_CLK_WISE);
	DcMotor_VidRotate_Wheels2(CLK_WISE);
	_delay_ms(DFHVBACK);    //for Three Quarter velocity
	DcMotor_VidRotate_Wheels1(STOP);
	DcMotor_VidRotate_Wheels2(STOP);
}




/*
 Name        : MultipleTasksCar_StopActionDelayed
 Input       : void
 Output      : void
 Description :
*/
void MultipleTasksCar_StopActionDelayed()  {
	DcMotor_VidRotate_Wheels1(STOP);
	DcMotor_VidRotate_Wheels2(STOP);
	_delay_ms(200);
}

