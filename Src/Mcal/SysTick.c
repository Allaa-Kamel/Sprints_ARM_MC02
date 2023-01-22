/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysTick.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h" 
#include "SysTick.h"
#include "Bit_Math.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define STCTRL_ENABLE_OFFSET		0U
#define STCTRL_INTEN_OFFSET			1U
#define	SYSTICK_CPU_CLK					16000000U
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern const SysTick_ConfigType STR_SysTickConfig;

cb_type Callback_Ptr = NULL_PTR;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void SysTick_ClearCurrentCount(void)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : void                     
* \Parameters (out): void                                 
*******************************************************************************/
void SysTick_ClearCurrentCount(void)
{
	STCURRENT = 0x00;
}

/******************************************************************************
* \Syntax          : void SysTick_Init(void)       
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : void                    
* \Parameters (out): void                                 
*******************************************************************************/
void SysTick_Init(void)
{
	STRELOAD = STR_SysTickConfig.SysTick_ReloadValue;
	SysTick_ClearCurrentCount();
	if(STR_SysTickConfig.SysTick_IntEnable)
	{
		SET_BIT(STCTRL,STCTRL_INTEN_OFFSET);
	}
}

/******************************************************************************
* \Syntax          : void SysTick_StartTimer(void)       
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : void                     
* \Parameters (out): void                                 
*******************************************************************************/
void SysTick_StartTimer(void)
{
	SET_BIT(STCTRL,STCTRL_ENABLE_OFFSET);
}

/******************************************************************************
* \Syntax          : void SysTick_UpdateReloadValue(SysTick_ReloadValueType SysTick_ReloadValue)       
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : SysTick_Seconds                   
* \Parameters (out): void                               
*******************************************************************************/
void SysTick_UpdateReloadValue(uint32 SysTick_Seconds)
{
	SysTick_ReloadValueType SysTick_ReloadValue;
	
	SysTick_ReloadValue = SysTick_Seconds * SYSTICK_CPU_CLK;
	
	SysTick_ClearCurrentCount();
	STRELOAD = SysTick_ReloadValue;
}

/******************************************************************************
* \Syntax          : void Register_SysTick_cb(cb_type ptr)      
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ptr                   
* \Parameters (out): void                               
*******************************************************************************/
void Register_SysTick_cb(cb_type ptr)
{
	if (ptr != NULL_PTR)
	{
		Callback_Ptr = ptr;
	}
}

/******************************************************************************
* \Syntax          : void SysTick_Handler(void)      
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : void                   
* \Parameters (out): void                               
*******************************************************************************/
void SysTick_Handler(void)
{
	if (Callback_Ptr != NULL_PTR)
	{
		Callback_Ptr();
	}
}

/**********************************************************************************************************************
 *  END OF FILE: SysTick.c
 *********************************************************************************************************************/
