/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
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
#include "DIO.h"
#include "Mcu_Hw.h"
#include "Bit_Math.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
cb_type DIO_Callback_Ptr = NULL_PTR;
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

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
* \Syntax          : DIO_LevlType DIO_ReadChannel(DIO_ChannelType ChannelId)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId 
* \Parameters (in) : PortID                                                     
* \Return value:   : DIO_LevelType                                
*******************************************************************************/
DIO_LevelType DIO_ReadChannel(DIO_PortType PortID, DIO_ChannelType ChannelId)
{
	DIO_LevelType ChannelLevel;
	ChannelLevel = GET_BIT(GPIODATA(PortID),ChannelId);
	return ChannelLevel;
}

/******************************************************************************
* \Syntax          : void DIO_WriteChannel(DIO_ChannelType ChannelId, DIO_LevelType Level)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId 
* \Parameters (in) : Level                                                     
* \Return value:   : void                                
*******************************************************************************/
void DIO_WriteChannel(DIO_PortType PortID, DIO_ChannelType ChannelId, DIO_LevelType Level)
{
	if (Level == DIO_HIGH)
	{
		SET_BIT(GPIODATA(PortID),ChannelId);
	}
	else
	{
		CLEAR_BIT(GPIODATA(PortID),ChannelId);
	}	
}

/******************************************************************************
* \Syntax          : DIO_LevelType DIO_FlipChannel(DIO_PortType PortID, DIO_ChannelType ChannelId)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PortID 
* \Parameters (in) : ChannelId                                                     
* \Return value:   : void                                
*******************************************************************************/
void DIO_FlipChannel(DIO_PortType PortID, DIO_ChannelType ChannelId)
{
	TOGGLE_BIT(GPIODATA(PortID),ChannelId);
}

/******************************************************************************
* \Syntax          : void Register_GPIO_cb (cb_type ptr)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ptr                                                    
* \Return value:   : void                                
*******************************************************************************/
void Register_GPIO_cb (cb_type ptr)
{
	if (ptr != NULL_PTR)
	{
		DIO_Callback_Ptr = ptr;
	}
}

/******************************************************************************
* \Syntax          : void GPIOF_Handler (void)       
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : void                                                    
* \Return value:   : void                                
*******************************************************************************/
void GPIOF_Handler(void)
{
	if (DIO_Callback_Ptr != NULL_PTR)
	{
		DIO_Callback_Ptr();
	}
	
	/* Clear interrupt flags */
	if(GET_BIT(GPIORIS(DIO_PORT_F), DIO_CHANNEL_0) == DIO_HIGH)
	{
		CLEAR_BIT(GPIOICR(DIO_PORT_F),DIO_CHANNEL_0);
	}
	if (GET_BIT(GPIORIS(DIO_PORT_F), DIO_CHANNEL_0) == DIO_HIGH)
	{
		CLEAR_BIT(GPIOICR(DIO_PORT_F),DIO_CHANNEL_4);
	}
}


/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/
