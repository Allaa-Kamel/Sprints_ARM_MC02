/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
#define APINT_VECTKEY						0x05FA
#define APINT_VECTKEY_MASK			16U
#define APINT_PRIGROUP_MASK			8U
#define PRI_INTA_MASK						5U
#define PRI_INTB_MASK						13U
#define PRI_INTC_MASK						21U
#define PRI_INTD_MASK						29U

#define MAX_NUM_OF_INTERRUPTS		155U

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern IntCtrl_UserInput UserInputType[155];

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static void IntCtrl_SetPriorityGrouping (void);
static void IntCtrl_SetPriority (IntCtrl_InterruptType InterruptNum, uint8 u8Priority);
static void IntCtrl_EnableInterrupt (IntCtrl_InterruptType InterruptNum);
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/


static void IntCtrl_SetPriorityGrouping (void)
{
  APINT = (APINT_VECTKEY << APINT_VECTKEY_MASK) | (INTCTRL_PRIGROUP << APINT_PRIGROUP_MASK);
}

static void IntCtrl_SetPriority (IntCtrl_InterruptType InterruptNum, uint8 u8Priority)
{
	switch(InterruptNum)
	{
		case IntCtrl_GPIOPortA:
			PRI0 |= (u8Priority << PRI_INTA_MASK);
		break;
		
		case IntCtrl_GPIOPortB:
			PRI0 |= (u8Priority << PRI_INTB_MASK);
		break;
		
		case IntCtrl_GPIOPortC:
			PRI0 |= (u8Priority << PRI_INTC_MASK);
		break;		
		
		case IntCtrl_GPIOPortD:
			PRI0 |= (u8Priority << PRI_INTD_MASK);
		break;
		
		case IntCtrl_GPIOPortF:
			PRI7 |= (u8Priority << PRI_INTC_MASK);
			break;
		default:
			/* Set interrupt priority in the corresponding register */
		break;
	}
}

static void IntCtrl_EnableInterrupt (IntCtrl_InterruptType InterruptNum)
{
	if ((0 <= InterruptNum) && (InterruptNum <= 31))
	{
		EN0 |= (1 << InterruptNum);
	}
	else
	{
		/* Check the next ranges for interrupt number */
	}
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{
	uint8 IntNum;
	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
  IntCtrl_SetPriorityGrouping();  
	
  /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
	IntCtrl_GetUserConfig();
	
	for (IntNum =0; IntNum<MAX_NUM_OF_INTERRUPTS; IntNum++)
	{
		if(UserInputType[IntNum].u8IsEnabled == TRUE)
		{
			IntCtrl_SetPriority(IntNum, UserInputType[IntNum].u8priority);
			
			/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
			IntCtrl_EnableInterrupt(IntNum);
		}
	}
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
