/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	IntCtrl_Reset = 1,
	IntCtrl_NMI,
	IntCtrl_HardFault,
	IntCtrl_MemManagementFault,
	IntCtrl_BusFault,
	IntCtrl_UsageFault,
	IntCtrl_SVCall = 11,
	IntCtrl_DebugMonitor,
	IntCtrl_PendSV = 14,
	IntCtrl_SysTick
	
}IntCtrl_ExceptionType;

typedef enum
{
	IntCtrl_GPIOPortA = 0,
	IntCtrl_GPIOPortB,
	IntCtrl_GPIOPortC,
	IntCtrl_GPIOPortD,
	IntCtrl_GPIOPortE,
	IntCtrl_UART0,
	IntCtrl_UART1,
	IntCtrl_SSI0,
	IntCtrl_I2C0,
	IntCtrl_PWM0Fault,
	IntCtrl_PWM0Generator0,
	IntCtrl_PWM0Generator1,
	IntCtrl_PWM0Generator2,
	IntCtrl_QEI0,
	IntCtrl_ADC0Sequence0,
	IntCtrl_ADC0Sequence1,
	IntCtrl_ADC0Sequence2,
	IntCtrl_ADC0Sequence3,
	IntCtrl_WatchdogTimers0_1,
	IntCtrl_Timer0A_16_32,
	IntCtrl_Timer0B_16_32,
	IntCtrl_Timer1A_16_32,
	IntCtrl_Timer1B_16_32,
	IntCtrl_Timer2A_16_32,
	IntCtrl_Timer2B_16_32,
	IntCtrl_AnalogComparator0,
	IntCtrl_AnalogComparator1,
	IntCtrl_SystemControl = 28,
	IntCtrl_Flash_EEPROM_Control, 
	IntCtrl_GPIOPortF,
	IntCtrl_UART2 = 33,
	IntCtrl_SSI1,
	IntCtrl_Timer3A_16_32,
	IntCtrl_Timer3B_16_32,
	IntCtrl_I2C1,
	IntCtrl_QEI1,
	IntCtrl_CAN0,
	IntCtrl_CAN1,
	IntCtrl_HibernationModule = 43,
	IntCtrl_USB,
	IntCtrl_PWMGenerator3,
	IntCtrl_DMASoftware,
	IntCtrl_DMAError,
	IntCtrl_ADC1Sequence0,
	IntCtrl_ADC1Sequence1,
	IntCtrl_ADC1Sequence2,
	IntCtrl_ADC1Sequence3,
	IntCtrl_SSI2 = 57,
	IntCtrl_SSI3,
	IntCtrl_UART3,
	IntCtrl_UART4,
	IntCtrl_UART5,
	IntCtrl_UART6,
	IntCtrl_UART7,
	IntCtrl_I2C2 = 68,
	IntCtrl_I2C3,
	IntCtrl_Timer4A_16_32,
	IntCtrl_Timer4B_16_32,
	IntCtrl_Timer5A_16_32 = 92,
	IntCtrl_Timer5B_16_32,
	IntCtrl_Timer0A_32_64,
	IntCtrl_Timer0B_32_64,
	IntCtrl_Timer1A_32_64,
	IntCtrl_Timer1B_32_64,
	IntCtrl_Timer2A_32_64,
	IntCtrl_Timer2B_32_64,
	IntCtrl_Timer3A_32_64,
	IntCtrl_Timer3B_32_64,
	IntCtrl_Timer4A_32_64,
	IntCtrl_Timer4B_32_64,
	IntCtrl_Timer5A_32_64,
	IntCtrl_Timer5B_32_64,
	IntCtrl_SystemException,
	IntCtrl_PWM1Generator0 = 134,
	IntCtrl_PWM1Generator1,
	IntCtrl_PWM1Generator2,
	IntCtrl_PWM1Generator3,
	IntCtrl_PWM1Fault
	
}IntCtrl_InterruptType;

 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
