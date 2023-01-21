/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PORT.c
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
#include "PORT.h"
#include "Bit_Math.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define GPIOLOCK_WRITE_VALUE		0x4C4F434B
#define GPIOPCTL_PMC_0_OFFSET		0U
#define GPIOPCTL_PMC_1_OFFSET		4U
#define GPIOPCTL_PMC_2_OFFSET		8U
#define GPIOPCTL_PMC_3_OFFSET		12U
#define GPIOPCTL_PMC_4_OFFSET		16U
#define GPIOPCTL_PMC_5_OFFSET		20U
#define GPIOPCTL_PMC_6_OFFSET		24U
#define GPIOPCTL_PMC_7_OFFSET		28U

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern const Port_ConfigType STR_PortsConfig[PORT_PINS_NUM];
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
* \Syntax          : void Port_Init(const Port_ConfigType	* ConfigPtr)       
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr                        
* \Return value:   : None                                
*******************************************************************************/
void Port_Init(const Port_ConfigType	* ConfigPtr)
{
	uint8 PinCounter;
	
	if(ConfigPtr != NULL_PTR)
	{
		for(PinCounter=0; PinCounter<PORT_PINS_NUM; PinCounter++)
		{
			/* Enable port clock */
			SET_BIT(RCGCGPIO, STR_PortsConfig[PinCounter].PortNum);
			
			/* Set GPIO Pin direction */
			switch(STR_PortsConfig[PinCounter].PortPinDirection)
			{
				case PORT_PIN_OUTPUT:
					/* Configure pin as output */
					SET_BIT(GPIODIR(STR_PortsConfig[PinCounter].PortNum), STR_PortsConfig[PinCounter].PortPin);
					
					/* Write Data to pin */
					switch(STR_PortsConfig[PinCounter].PortPinLevel)
					{
						case PORT_PIN_LOW:
							CLEAR_BIT(GPIODATA(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
							break;
						case PORT_PIN_HIGH:
							SET_BIT(GPIODATA(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
							break;
						default:
							/* Invalid Pin level */
							break;						
					}
					
					/* Configure Pin output current */
					switch(STR_PortsConfig[PinCounter].PortPinOutputCurrent)
					{
						case PORT_PIN_CUR_2MA:
							SET_BIT(GPIODR2R(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
							break;
						case PORT_PIN_CUR_4MA:
							SET_BIT(GPIODR4R(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
							break;
						case PORT_PIN_CUR_8MA:
							SET_BIT(GPIODR8R(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
							break;
						default:
							/* Invalid current configuration */
							break;
					}					
					break;
					
				case PORT_PIN_INPUT:
					/* Configure pin as input */
					CLEAR_BIT(GPIODIR(STR_PortsConfig[PinCounter].PortNum), STR_PortsConfig[PinCounter].PortPin);
					break;
				default:
					/* Invalid direction */
					break;
			}
			
			/* Configure Pin mode */
			switch(STR_PortsConfig[PinCounter].PortPinMode)
			{
				case PORT_DEN:
					/* Enable digital pin function */
					SET_BIT(GPIODEN(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
					/* Configure pin to be used as GPIO */
					CLEAR_BIT(GPIOAFSEL(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
					/* Disable analog pin function */
					CLEAR_BIT(GPIOAMSEL(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
					break;
				case PORT_AMSEL:
					/* Enable analog pin function */
					SET_BIT(GPIOAMSEL(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
					CLEAR_BIT(GPIODEN(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
					CLEAR_BIT(GPIOAFSEL(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
					break;
				case PORT_AF_1:
					/* Enable alternate function 1 */
					SET_BIT(GPIOAFSEL(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
					CLEAR_BIT(GPIODEN(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
					CLEAR_BIT(GPIOAMSEL(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
					if(STR_PortsConfig[PinCounter].PortPin == PORT_PIN_3)
					{
						GPIOPCTL(STR_PortsConfig[PinCounter].PortNum) |= (1<<GPIOPCTL_PMC_3_OFFSET);					
					}
					else
					{
						/*Insert corresponding pin offset */
					}
					break;
				case PORT_AF_2:
					/* Enable alternate function 1 */
					SET_BIT(GPIOAFSEL(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
					CLEAR_BIT(GPIODEN(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
					CLEAR_BIT(GPIOAMSEL(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
					if(STR_PortsConfig[PinCounter].PortPin == PORT_PIN_3)
					{
						GPIOPCTL(STR_PortsConfig[PinCounter].PortNum) |= (2<<GPIOPCTL_PMC_3_OFFSET);					
					}
					else
					{
						/*Insert corresponding pin offset */
					}
					break;
				default:
					break;
			}
			
			/* Configure internal pull up, pull down or open drain */
			switch(STR_PortsConfig[PinCounter].PortPinInternalAttach)
			{
				case PORT_PIN_PUR:
					/* Unlock pull up register */
					GPIOLOCK(STR_PortsConfig[PinCounter].PortNum) = GPIOLOCK_WRITE_VALUE;
					SET_BIT(GPIOCR(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
					/* Enable Internal pull up resistor */
					SET_BIT(GPIOPUR(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
					break;
				case PORT_PIN_PDR:
					/* Unlock pull down register */
					GPIOLOCK(STR_PortsConfig[PinCounter].PortNum) = GPIOLOCK_WRITE_VALUE;
					SET_BIT(GPIOCR(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
					/* Enable Internal pull down resistor */
					SET_BIT(GPIOPDR(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
					break;
				case PORT_PIN_ODR:
					/* Configure pin as open drain */
					SET_BIT(GPIOODR(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);					
					break;
				default:
					/* Invalid configuration */
					break;
			}
			
			/* Configure External interrupt settings on pin */
			if(STR_PortsConfig[PinCounter].PortPinExtIntEnable == PORT_PIN_EXT_INT_ENABLE)
			{
				switch (STR_PortsConfig[PinCounter].PortPinExtIntEvent)
				{
					case PORT_PIN_EVENT_RISING_EDGE:
						CLEAR_BIT(GPIOIS(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
						SET_BIT(GPIOIEV(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
						break;
					
					case PORT_PIN_EVENT_FALLING_EDGE:
						CLEAR_BIT(GPIOIS(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);						
						CLEAR_BIT(GPIOIEV(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
						break;
					
					case PORT_PIN_EVENT_BOTH_EDGES:
						CLEAR_BIT(GPIOIS(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
						SET_BIT(GPIOIBE(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
						break;
					
					case PORT_PIN_EVENT_LEVEL:
						SET_BIT(GPIOIS(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
						break;
					
					default:
						/* Invalid event configuration */
						break;
				}
				/* Enable Extrnal interrupt */
				SET_BIT(GPIOIM(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
			}
			else
			{
				/* Disable Extrnal interrupt */
				CLEAR_BIT(GPIOIM(STR_PortsConfig[PinCounter].PortNum),STR_PortsConfig[PinCounter].PortPin);
			}
		}
	}
}

/**********************************************************************************************************************
 *  END OF FILE: PORT.c
 *********************************************************************************************************************/
