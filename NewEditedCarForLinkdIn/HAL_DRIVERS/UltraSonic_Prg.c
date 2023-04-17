/*
 * UltraSonic_Prg.c
 *
 * Created on: 18/12/2022
 *  Author: ENG/Shehab aldeen
 */

#include "../MCAL_DRIVERS/DIO_interface.h"
#include "../MCAL_DRIVERS/TIMER_Interface.h"
#include "../MCAL_DRIVERS/INTERRUPT_Interface.h"

#include "UltraSonic_Interface.h"
#include "UltraSonic_Private.h"
#include <util/delay.h>

static u8 g_edgeCount = 0;
static u16 g_timeHigh = 0;
static u8 g_distance = 0;

/*
 * Description :
 * Call-Back Function used to calculate g_timeHigh for the Ultrasonic pulse
 */
static void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;

	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		Timer1Icu_clearTimerValue();

		/* Detect falling edge */
		Timer1Icu_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		/* Store the High time value */
		g_timeHigh = Timer1Icu_getInputCaptureValue();

		/* Detect rising edge */
		Timer1Icu_setEdgeDetectionType(RISING);
	}
}


/*
 * Description :
 * Function send trigger pulse for Ultrasonic sensor to start measurements
 */
static void Ultrasonic_Trigger(void)
{
	/* Send the Trigger pulse */
	DIO_VidSetPinValue(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,1);
	_delay_us(10);
	DIO_VidSetPinValue(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,0);
}

/*
 * Description :
 * Initialize the Ultrasonic driver by:
 * 1. Initialize the Trigger pin direction
 * 2. Initialize the ICU driver and Its Call back function.
 */
void Ultrasonic_init(void)
{
	GIE_VidEnable();
	Timer1Icu_init();
	DIO_VidSetPinDirection(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,1);
	Timer1Icu_setCallBack( &Ultrasonic_edgeProcessing );
}

/*
 * Description :
 * Function calculates the distance measured by the Ultrasonic sensor by:
 * 1. Clear all the variables from the previous read operation.
 * 2. Clear the ICU timer register
 * 3. Send the Trigger to the Ultrasonic by call Ultrasonic_Trigger function
 * 4. Wait for the measurements to be done by the ICU. We need two edges raising and falling.
 * 5. Calculate the distance in Centimeter value.
 */
u16 Ultrasonic_readDistance(void)
{
	/* Clear all variables as they may have values from previous read operation */
	g_distance  = 0;
	g_edgeCount = 0;
	g_timeHigh  = 0;

	/* Clear the timer counter register to start measurements once trigger is sent */
	Timer1Icu_clearTimerValue();

	/* Send the trigger to activate the Ultra-sonic sensor (Start measurements) */
	Ultrasonic_Trigger();

	/* Wait until the ICU measures the pulse in the ECHO pin */
	while(g_edgeCount != ULTRASONIC_NUM_OF_DETECTED_EDGES);

	/* Calculate the distance in Centimeter value */
	g_distance = g_timeHigh / 58;

	return g_distance;
}

