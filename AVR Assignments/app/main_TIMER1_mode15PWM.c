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

/* to test the code use timer in mode TMR1_FASTPWM_OCR_MODE with prescalar 1 */

int main(void)
{
	
	DIO_voidSetPinDir(DPORT,Pin4,output);
	
	Timer1_Init();
	
	while (1)
	{
		/*output on chanal  B*/
		Timer1_PWMfast_dutyCyc_freq(25,10 );
		
	}
}