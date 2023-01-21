/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PORT_PINS_NUM		3

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
	PORT_A = 0,
	PORT_B,
	PORT_C,
	PORT_D,
	PORT_E,
	PORT_F
}Port_NumType;

typedef enum
{
	PORT_PIN_0,
	PORT_PIN_1,
	PORT_PIN_2,
	PORT_PIN_3,
	PORT_PIN_4,
	PORT_PIN_5,
	PORT_PIN_6,
	PORT_PIN_7
}Port_PinType;

typedef enum
{
	PORT_DEN,
	PORT_AMSEL,
	PORT_AF_1,
	PORT_AF_2,
	PORT_AF_3,
	PORT_AF_4,
	PORT_AF_5,
	PORT_AF_6,
	PORT_AF_7,
	PORT_AF_8,
	PORT_AF_9,
	PORT_AF_14,
	PORT_AF_15
}Port_PinModeType;

typedef enum
{
	PORT_PIN_INPUT,
	PORT_PIN_OUTPUT
}Port_PinDirectionType;

typedef enum
{
	PORT_PIN_LOW,
	PORT_PIN_HIGH
}Port_PinLevelType;

typedef enum
{
	PORT_PIN_PUR,
	PORT_PIN_PDR,
	PORT_PIN_ODR
}Port_PinInternalAttachType;	

typedef enum
{
	PORT_PIN_CUR_2MA,
	PORT_PIN_CUR_4MA,
	PORT_PIN_CUR_8MA	
}Port_PinOutputCurrentType;

typedef enum
{
	PORT_PIN_EXT_INT_DISABLE,
	PORT_PIN_EXT_INT_ENABLE
}Port_PinExtIntEnableType;

typedef enum
{
	PORT_PIN_EVENT_NONE,
	PORT_PIN_EVENT_RISING_EDGE,
	PORT_PIN_EVENT_FALLING_EDGE,
	PORT_PIN_EVENT_BOTH_EDGES,
	PORT_PIN_EVENT_LEVEL
}Port_PinExtIntEventType;

typedef struct
{
	Port_NumType									PortNum;
	Port_PinType									PortPin;
	Port_PinModeType							PortPinMode;
	Port_PinDirectionType 				PortPinDirection;
	Port_PinLevelType							PortPinLevel;
	Port_PinInternalAttachType		PortPinInternalAttach;
	Port_PinOutputCurrentType			PortPinOutputCurrent;
	Port_PinExtIntEnableType			PortPinExtIntEnable;
	Port_PinExtIntEventType				PortPinExtIntEvent;
	
}Port_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* PORT_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Cfg.h
 *********************************************************************************************************************/
