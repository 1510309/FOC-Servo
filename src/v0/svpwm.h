#ifndef __SVPWM_H__
#define __SVPWM_H__

#include "misc.h"
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_adc.h"
#include "stm32f4xx_gpio.h"

#include "foc.h"

#define CKTIM			( 168000000>>1 )
#define PWM_FREQ		( 16000 )

#define PWM_PRSC		( (u8)0 )
/* Resolution: 1Hz */
#define PWM_PERIOD		( (u16) (CKTIM / (u32)(2 * PWM_FREQ *(PWM_PRSC+1))) ) // ~2600

#define REP_RATE		10
#define DEADTIME		5

void svpwmInit(void);

void DMAInit(void);
void svpwmInitADC( void );
void svpwmInitTIM( void );
void svpwmInitGPIO( void );

void mcFocSVPWM(LP_MC_FOC lpFoc);
void mcFocSVPWM1(LP_MC_FOC lpFoc);
void mcFocSVPWM2(LP_MC_FOC lpFoc);
void mcFocSVPWM3(LP_MC_FOC lpFoc);
void mcFocSVPWM4(LP_MC_FOC lpFoc);
void mcFocSVPWM5(LP_MC_FOC lpFoc);

void RCC_Configuration_Adc1( void );
void RCC_Configuration_Adc2( void );
void GPIO_Configuration_Adc1( void );
void GPIO_Configuration_Adc2( void );

#endif