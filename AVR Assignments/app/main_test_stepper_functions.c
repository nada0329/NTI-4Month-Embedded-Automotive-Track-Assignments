#include "type.h"
#include "bit.h"
#include "STPR_int.h"
#include "STPR_conf.h"
#include "STPR_priv.h"

#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	StprMotor_voidInit();
	while(1)
	{
		/*StprMotor_voidRotateClkwiseFullstep(0);
		_delay_ms(1000);
		StprMotor_voidRotateAntiClkwiseFullstep(0);
		_delay_ms(1000);*/
		
		StprMotor_voidRotateClkwiseHalfstep(0);
		_delay_ms(1000);
		StprMotor_voidRotateAntiClkwiseHalfstep(0);
		_delay_ms(1000);
		StprMotor_voidStop(0);
		_delay_ms(1000);


	}

}

