/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;

typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS		0xE000E000

/***********************************************/
/******* SYSTEM CONTROL BLOCK RESGISTERS *******/
/***********************************************/
#define APINT						*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
	
/***********************************************/
/************** NVIC RESGISTERS ****************/
/***********************************************/
#define INTCTRL         *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define PRI0						*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x0400))
#define	EN0				      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x0100))

/***********************************************/
/************** GPIO RESGISTERS ****************/
/***********************************************/
#define GPIO_APB

#ifdef GPIO_APB

#define GPIO_PORT_BASE(x)				(x<4?((0x40004000)+((x)*0x1000)):((0x40020000)+((x)*0x1000)))

//#define GPIO_PORT_A_BASE			0x40004000
//#define GPIO_PORT_B_BASE			0x40005000
//#define GPIO_PORT_C_BASE			0x40006000
//#define GPIO_PORT_D_BASE			0x40007000
//#define GPIO_PORT_E_BASE			0x40024000
//#define GPIO_PORT_F_BASE			0x40025000

#elif GPIO_AHB

#define GPIO_PORT_BASE(x)			((0x40058000)+((x)*0x1000)) 
//#define GPIO_PORT_A_BASE			0x40058000
//#define GPIO_PORT_B_BASE			0x40059000
//#define GPIO_PORT_C_BASE			0x4005A000
//#define GPIO_PORT_D_BASE			0x4005B000
//#define GPIO_PORT_E_BASE			0x4005C000
//#define GPIO_PORT_F_BASE			0x4005D000

#endif

#define GPIODATA(x)			*((volatile uint32*)(GPIO_PORT_BASE(x)+0x3FC))
#define GPIODIR(x)			*((volatile uint32*)(GPIO_PORT_BASE(x)+0x400))
#define GPIOAFSEL(x)		*((volatile uint32*)(GPIO_PORT_BASE(x)+0x420))
#define GPIODR2R(x)			*((volatile uint32*)(GPIO_PORT_BASE(x)+0x500))
#define GPIODR4R(x)			*((volatile uint32*)(GPIO_PORT_BASE(x)+0x504))
#define GPIODR8R(x)			*((volatile uint32*)(GPIO_PORT_BASE(x)+0x508))
#define GPIOODR(x)			*((volatile uint32*)(GPIO_PORT_BASE(x)+0x50C))
#define GPIOPUR(x)			*((volatile uint32*)(GPIO_PORT_BASE(x)+0x510))
#define GPIOPDR(x)			*((volatile uint32*)(GPIO_PORT_BASE(x)+0x514))
#define GPIODEN(x)			*((volatile uint32*)(GPIO_PORT_BASE(x)+0x51C))
#define GPIOAMSEL(x)		*((volatile uint32*)(GPIO_PORT_BASE(x)+0x528))
#define GPIOLOCK(x)			*((volatile uint32*)(GPIO_PORT_BASE(x)+0x520))
#define GPIOCR(x)				*((volatile uint32*)(GPIO_PORT_BASE(x)+0x524))
#define GPIOPCTL(x)			*((volatile uint32*)(GPIO_PORT_BASE(x)+0x52C))

/***********************************************/
/********* SYSTEM CONTROL RESGISTERS ***********/
/***********************************************/
#define SYSTEM_CONTROL_BASE			0x400FE000

#define RCGCGPIO								*((volatile uint32*)(SYSTEM_CONTROL_BASE+0x608))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
