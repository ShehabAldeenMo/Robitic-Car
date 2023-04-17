/*
 * main.c
 *
 *  Created on: 18/12/2022
 *  Author: ENG/Shehab aldeen
 */

/*****************************************************************************
 *****************************************************************************
 *        😊😊🤎                                      Welcome               😊😊🤎
 *
 * This Project is made by  : Eng/Shehab aldeen mohammed abdalah & Eng/Ahmed Yassin .
 *
 * What'sapp Number         : +20114864494     &   +01226132737
 *
 * We are students in Electronics and Commiuncations department in Cairo University 🤖🤖 .
 *
 * The target from this project :
 *
 * 1)The goal of the project was to design and implement an autonomous car that could
 * navigate through a course without any human intervention .
 *
 * 2)To achieve this, we used a variety of embedded systems such as sensors and
 * actuators to create a sophisticated control system that could process inputs
 * from the environment and make decisions in real-time.
 *
 * 3)And We used algorithms to improve the car's ability to recognize and respond to different situations.
 *
 *
 ******************************************************************************
 ******************************************************************************/

#include "APP_DRIVER/MultipleTasksCar_Interface.h"


/* steps : 1 ) determine velocity 2) determine mode */

void main (){
	/* initializiation function of car  */
	MultipleTasksCar_VidInit();

	/* to set the mode & velocity of the car */
	u8 mode , velocity ;

	while (1){
		velocity = MultipleTasksCar_GetMode() ;

		if (velocity <= '4' && velocity >= '1')
			break ;
	}//end while (1)

	MultipleTasksCar_SetCarVelocity(velocity) ;

	/* to select mode */
	while (1){
		mode = MultipleTasksCar_GetMode() ;

		if (mode <= '4' && mode >= '1')
			break ;
	}//end while (1)

	/* to implemnet ur target mode */
	while (1){
		switch (mode){
		case '1' :  MultipleTasksCar_GetDirections() ;          break ;
		case '2' :  MultipleTasksCar_LineFollower()  ;          break ;
		case '3' :  MultipleTasksCar_UltraSonic()    ;          break ;
		case '4' :  MultipleTasksCar_MapLine()       ;          break ;
		}
	}
}
