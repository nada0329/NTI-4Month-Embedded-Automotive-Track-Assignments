/*
 * GccApplication1.c
 *
 * Created: 2/24/2023 9:34:22 AM
 * Author : Nada
 */ 


#include "LED.h"
#include "DIO.h"
#include "kit_cnfg.h"
#include "TIMR1_int.h"
#include "TIMR1_priv.h"
#include "TIMR1_config.h"
#include "GlobalINT.h"

/* to test the code use timer in mode TMR1_FASTPWM_ICR_MODE with prescalar 1 */

int main(void)
{
	
	DIO_voidSetPinDir(DPORT,Pin5,output);
	DIO_voidSetPinDir(DPORT,Pin4,output);
	
	Timer1_Init();
	
	while (1)
	{
		/*uncomment the one you want to try chanal A or B*/
		//Timer1_PWMfastA_dutyCyc_freq(30,10);
		Timer1_PWMfastB_dutyCyc_freq(30,10);

		
	}
}