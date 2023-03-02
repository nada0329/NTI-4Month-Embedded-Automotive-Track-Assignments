/*
 * kit_cnfg.h
 *
 * Created: 2/22/2023 1:45:37 PM
 *  Author: Nada
 */ 


#ifndef KIT_CNFG_H_
#define KIT_CNFG_H_

//#define F_CPU 8000000UL

// LED
#define LED_RED_PORT		BPORT
#define LED_RED_PIN			Pin7
#define LED_BLUE_PORT		APORT
#define LED_BLUE_PIN		Pin5
#define LED_GREEN_PORT		APORT
#define LED_GREEN_PIN		Pin4
#define LED_YELLOW_PORT		APORT
#define LED_YELLOW_PIN		Pin6
// SW
#define SW_1_PORT			CPORT
#define SW_2_PORT			CPORT
#define SW_3_PORT			APORT
#define SW_4_PORT			BPORT
#define SW_5_PORT			APORT
#define SW_6_PORT			APORT
#define SW_7_PORT			APORT
#define SW_8_PORT			DPORT
#define SW_1_PIN			Pin6
#define SW_2_PIN			Pin7
#define SW_3_PIN			Pin7
#define SW_4_PIN			Pin7
#define SW_5_PIN			Pin4
#define SW_6_PIN			Pin5
#define SW_7_PIN			Pin6
#define SW_8_PIN			Pin4
// PB
#define PB_1_PORT			DPORT
#define PB_2_PORT			DPORT
#define PB_3_PORT			DPORT
#define PB_4_PORT			DPORT
#define PB_1_PIN			Pin7
#define PB_2_PIN			Pin6
#define PB_3_PIN			Pin5
#define PB_4_PIN			Pin3
// 7SEG
#define SSD_A_PORT			BPORT
#define SSD_A_PIN			Pin0
#define SSD_B_PORT			BPORT
#define SSD_B_PIN			Pin1
#define SSD_C_PORT			BPORT
#define SSD_C_PIN			Pin2
#define SSD_D_PORT			BPORT
#define SSD_D_PIN			Pin4
#define SSD_COM1_PORT		APORT
#define SSD_COM1_PIN		Pin3
#define SSD_COM2_PORT		APORT
#define SSD_COM2_PIN		Pin2
#define SSD_COM3_PORT		BPORT
#define SSD_COM3_PIN		Pin5
#define SSD_COM4_PORT		BPORT
#define SSD_COM4_PIN		Pin6
// LCD
#define DATAPORT			BPORT
#define PIN4_LCD			Pin0
#define PIN5_LCD			Pin1
#define PIN6_LCD			Pin2
#define PIN7_LCD			Pin4
#define RS_PORT				BPORT//A
#define E_PORT				BPORT//A
#define RS					Pin3
#define E					Pin5//2





#endif /* KIT_CNFG_H_ */