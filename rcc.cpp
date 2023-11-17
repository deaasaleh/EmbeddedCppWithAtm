#include "rcc.h"


RCC_TypeDef* RCC_MemoryMapBase = (RCC_TypeDef*) RCC_BASE;

rcc::rcc()
{
	rccErr = RCC_OK;
}

RCC_ErrorType_t rcc::RCC_gpioPortInit(RCC_GpioPortName_t gpioPortName)
{
	RCC_ErrorType_t errReturn = RCC_DEFAULT_ERR;
	switch(gpioPortName)
	{
		case RCC_GPIO_PORT_A:
			RCC_MemoryMapBase->APB2ENR |= RCC_APB2ENR_IOPAEN;
				errReturn = RCC_OK;
			break;
		case RCC_GPIO_PORT_B:
			RCC_MemoryMapBase->APB2ENR |= RCC_APB2ENR_IOPBEN;
				errReturn = RCC_OK;
			break;
		case RCC_GPIO_PORT_C:
			RCC_MemoryMapBase->APB2ENR |= RCC_APB2ENR_IOPCEN;
				errReturn = RCC_OK;
			break;

		default:
				errReturn = RCC_DEFAULT_ERR;
			break;
	}

	return errReturn;
}

