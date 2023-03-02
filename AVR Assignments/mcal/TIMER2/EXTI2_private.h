/*
 * EXTI2_private.h
 *
 * Created: 3/2/2023 7:22:20 PM
 *  Author: Nada
 */ 


#ifndef EXTI2_PRIVATE_H_
#define EXTI2_PRIVATE_H_

#define	NULL	(0)

#define MCUCR		*((volatile u8 * ) (0X55))
#define MCUCSR      *((volatile u8 * ) (0X54))
#define GICR        *((volatile u8 * ) (0X5B))
#define GIFR        *((volatile u8 * ) (0X5A))

/** Linker Problem solved */
void __vector_3(void) __attribute__(( signal , used ));



#endif /* EXTI2_PRIVATE_H_ */