
#include "IntCtrl.h"
#include "PORT.h"
#include "DIO.h"

/*- LOCAL MACROS
-------------------------------------*/

/*- GLOBAL STATIC VARIABLES
-------------------------------------*/

/*- GLOBAL EXTERN VARIABLES
-------------------------------------*/
extern const Port_ConfigType STR_PortsConfig[PORT_PINS_NUM];


/*- APIs IMPLEMENTATION
-------------------------------------*/


int main (void)
{
	IntCrtl_Init();
		
	Port_Init(STR_PortsConfig);
	
//	DIO_ReadChannel(DIO_PORT_B, DIO_CHANNEL_1);	
	DIO_WriteChannel(DIO_PORT_F, DIO_CHANNEL_3, DIO_LOW);
	DIO_FlipChannel(DIO_PORT_F, DIO_CHANNEL_3);
	DIO_WriteChannel(DIO_PORT_F, DIO_CHANNEL_3, DIO_HIGH);
	DIO_FlipChannel(DIO_PORT_F, DIO_CHANNEL_3);
	while(1)
	{
		
	}
}