#include "rcc.h"
#include "gpio.h"

int main()
{
	
	GPIO_PinConfigs	gpio_gpio_Obj;
	gpio_gpio_Obj.PinNumber=GPIO_PIN_13;
	gpio_gpio_Obj.PinMode=GPIO_PinMode_OUTPUT_PP_2MHZ;				//GPIO_PinMode_OUTPUT_OD  Value Correction
	gpio_gpio_Obj.PinState=GPIO_PIN_STATE_HIGH;

	gpio gpio_objBuiltIntLed(GPIO_PORT_C);
	gpio_objBuiltIntLed.GPIO_PinInit(&gpio_gpio_Obj);
	gpio_objBuiltIntLed.GPIO_PinStateSet(&gpio_gpio_Obj,GPIO_PIN_STATE_LOW);
	
	while(1)
	{

	}

}


