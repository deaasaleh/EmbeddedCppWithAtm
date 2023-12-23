#include "gpio.h"
#include "rcc.h"



uint8_t highPin=8;
uint8_t u8GPIO_ONE=1;

GPIO_TypeDef*	GPIO_RegArr[GPIO_PORT_MAX] = {GPIOA,GPIOB,GPIOC};
rcc RCC_GPIO_PortStart;


GPIO_PinConfigs::GPIO_PinConfigs()
{
	PinConfigsErr = GPIO_NOK;
	PinInitErr		= GPIO_NOK;

}

GPIO_ErrorType_t 	GPIO_PinConfigs::GPIO_PinConfigsIsOK()
{	
	GPIO_ErrorType_t errReturn = GPIO_NOK;
	
	if((PinNumber<GPIO_PIN_MAX)&&(PortName<GPIO_PORT_MAX))
	{
		PinConfigsErr = GPIO_OK;
		errReturn 		= GPIO_OK;
	}
	else
	{
		PinConfigsErr = GPIO_NOK;
		errReturn 		= GPIO_NOK;
	}
	return errReturn;
}

gpio::gpio(GPIO_PortName_t	PortName)
{
	gpioErr= GPIO_NOK;
	if(RCC_GPIO_PortStart.rccErr == RCC_OK)
	{
		switch(PortName)
		{	
			case GPIO_PORT_A:
			case GPIO_PORT_B:
			case GPIO_PORT_C:
				RCC_GPIO_PortStart.RCC_gpioPortInit((RCC_GpioPortName_t)PortName);
				GPIO_PortReg=GPIO_RegArr[PortName];
				RCC_GPIO_PortStart.rccErr=RCC_OK;
			  gpioErr=GPIO_OK;
			break;
			case GPIO_PORT_MAX:
			default:
					 RCC_GPIO_PortStart.rccErr=RCC_NOK;
						gpioErr=GPIO_NOK;
			break;
		}
	}
	else
	{
	
	}
}

GPIO_ErrorType_t gpio::GPIO_PinInit	(GPIO_PinConfigs* pinConfigs)
{
	
	GPIO_ErrorType_t errReturn = GPIO_DEFAULT_ERR;
	
	if ((pinConfigs!=(GPIO_PinConfigs*)NULL) && (gpioErr == GPIO_OK) && (pinConfigs->GPIO_PinConfigsIsOK()==GPIO_OK))
	{
		uint8_t Local_u8PinNumber = (pinConfigs->PinNumber)%8;
			if( pinConfigs->PinNumber <= 7 )
			{//low
				
				GPIO_PortReg->CRL &= ~((modeMask)<<((pinConfigs->PinNumber)*mul));// R M W
				GPIO_PortReg->CRL	|=(( pinConfigs->PinMode  << ((pinConfigs->PinNumber) * mul )));

			}
			else if(pinConfigs->PinNumber <=15 )
			{//high				
				
				GPIO_PortReg->CRH &= ~(modeMask<<Local_u8PinNumber * mul);
				GPIO_PortReg->CRH |=( pinConfigs->PinMode ) << (Local_u8PinNumber * mul );
			}

	}
}

GPIO_PinState_t		gpio::GPIO_PinStateGet		(GPIO_PinConfigs* pinConfigs)
{
	GPIO_PinState_t pinState = GPIO_PIN_STATE_DEFAULT;
	if((pinConfigs != (GPIO_PinConfigs*)NULL) && (pinConfigs->PinInitErr == GPIO_OK))
	{
		pinState = (GPIO_PinState_t) ((GPIO_PortReg->IDR >> pinConfigs->PinNumber  )& u8GPIO_ONE);
	}
	else 
	{
		pinState = GPIO_PIN_STATE_DEFAULT;
	}
	return pinState;
}

GPIO_ErrorType_t	gpio::GPIO_PinStateSet		(GPIO_PinConfigs*	pinConfigs,GPIO_PinState_t pinState)
{	
	GPIO_ErrorType_t errReturn = GPIO_DEFAULT_ERR;
	if((pinConfigs != (GPIO_PinConfigs*)NULL) && (pinConfigs->PinInitErr == GPIO_OK))
	{
		if(pinState == GPIO_PIN_STATE_LOW)
		{
			GPIO_PortReg->ODR &= (uint32_t)(~(u8GPIO_ONE<<pinConfigs->PinNumber));
		}
		else if(pinState == GPIO_PIN_STATE_HIGH)
		{
			GPIO_PortReg->ODR |= (uint32_t)(~(u8GPIO_ONE<<pinConfigs->PinNumber));
		}
	
	}
	else
	{
			errReturn = GPIO_DEFAULT_ERR;
	}
	return errReturn;
}

GPIO_ErrorType_t	gpio::GPIO_PinStateToggle	(GPIO_PinConfigs*	pinConfigs)
{
	GPIO_ErrorType_t errReturn = GPIO_DEFAULT_ERR;
	if((pinConfigs != (GPIO_PinConfigs*)NULL) && (pinConfigs->PinInitErr == GPIO_OK))
	{
		GPIO_PortReg->ODR ^= (uint32_t)(u8GPIO_ONE<<pinConfigs->PinNumber);
	}
	else
	{
		errReturn = GPIO_DEFAULT_ERR;
	}
	return errReturn;
}


