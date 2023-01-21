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
	DIO_LevelType ChannelLevel;
	ChannelLevel = DIO_ReadChannel(PortID,ChannelId);
	
	if(ChannelLevel == DIO_LOW)
	{
		DIO_WriteChannel(PortID, ChannelId, DIO_HIGH);
	}
	else
	{
		DIO_WriteChannel(PortID, ChannelId, DIO_LOW);
	}
}

/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/
