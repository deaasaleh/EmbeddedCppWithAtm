#include "rcc.h"

rcc RCC_Object;
RCC_GpioPortName_t	UsedPort = RCC_GPIO_PORT_A;

int main()
{
	
	RCC_Object.RCC_gpioPortInit(UsedPort);
	
	while(1);

}