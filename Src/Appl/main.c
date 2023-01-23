
#include "Platform_Types.h"
#include "IntCtrl.h"
#include "PORT.h"
#include "DIO.h"
#include "SysTick.h"

/*- LOCAL MACROS
-------------------------------------*/

/*- GLOBAL STATIC VARIABLES
-------------------------------------*/
uint8 ON_Time = 5;
uint8 OFF_Time = 5;
uint8 counter = 0;

/*- GLOBAL EXTERN VARIABLES
-------------------------------------*/
extern const Port_ConfigType STR_PortsConfig[PORT_PINS_NUM];

/*- FUNCTIONS PROTOTYPES
-------------------------------------*/
void Handle_SysTick_isr (void);
void Handle_GPIO_isr (void);

/*- APIs IMPLEMENTATION
-------------------------------------*/
/****** SYSTICK INT APP HANDLER ******/
void Handle_SysTick_isr (void)
{
	if (counter == 0)
	{
		SysTick_UpdateReloadValue(ON_Time);
	}
	else
	{
		SysTick_UpdateReloadValue(OFF_Time);
		counter = 0;
	}
	DIO_FlipChannel(DIO_PORT_F, DIO_CHANNEL_1);
	
}

/******* GPIO INT APP HANDLER ********/
void Handle_GPIO_isr (void)
{
	if(DIO_ReadChannel(DIO_PORT_F, DIO_CHANNEL_0) == DIO_HIGH)
	{
		ON_Time++;
	}
	
	if(DIO_ReadChannel(DIO_PORT_F, DIO_CHANNEL_4) == DIO_HIGH)
	{
		OFF_Time++;
	}
	
}

/**************** Main Function ********************/
int main (void)
{
	IntCrtl_Init();
		
	Port_Init(STR_PortsConfig);
	
	SysTick_Init();
	
	Register_SysTick_cb(Handle_SysTick_isr);

	Register_GPIO_cb(Handle_GPIO_isr);
		
	SysTick_StartTimer();
	
	
	while(1)
	{
		
	}
}