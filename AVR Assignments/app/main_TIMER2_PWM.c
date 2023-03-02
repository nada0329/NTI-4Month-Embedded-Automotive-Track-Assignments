/*
 * GccApplication1.c
 *
 * Created: 2/24/2023 9:34:22 AM
 * Author : Nada
 */ 


#include "LED.h"
#include "DIO.h"
#include "kit_cnfg.h"
#include "TIMR2_int.h"
#include "TIMR2_priv.h"
#include "TIMR2_config.h"
#include "GlobalINT.h"



int main(void)
{
	DIO_voidSetPinDir(DPORT,Pin7,output);
	TIMER2_void_Init();
	
	while (1)
	{
		/*uncomment the one you want to try*/
		Timer2_PWMPhase_dutyCyc(75);
		//Timer2_PWMfast_dutyCyc(25);

		
	}
}

