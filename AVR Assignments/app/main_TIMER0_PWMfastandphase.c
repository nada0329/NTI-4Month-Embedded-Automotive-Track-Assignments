/*
 * GccApplication1.c
 *
 * Created: 2/24/2023 9:34:22 AM
 * Author : Nada
 */ 


#include "DIO.h"
#include "kit_cnfg.h"
#include "TIMR0_int.h"
#include "TIMR00_priv.h"
#include "TIMR0_config.h"



int main(void)
{
	DIO_voidSetPinDir(BPORT,Pin3,output);
	TIMER0_void_Init();
	
	while (1)
	{
		/*uncomment the one you want to try*/
		Timer0_PWMPhase_dutyCyc(25);
		//Timer0_PWMfast_dutyCyc(25);

		
	}
}