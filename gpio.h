#ifndef _GPIO_H
#define _GPIO_H

#include "stm32f10x.h"
#include <stdio.h>


#define NULL			  0
#define mul 				4
#define modeMask	0xF

enum GPIO_ErrorType_t
{
	GPIO_OK,
	GPIO_NOK,
	GPIO_DEFAULT_ERR=0xFF
};

enum GPIO_PortName_t
{
	GPIO_PORT_A,
	GPIO_PORT_B,
	GPIO_PORT_C,
	GPIO_PORT_MAX
};

enum GPIO_PinState_t
{
	GPIO_PIN_STATE_LOW=0,
	GPIO_PIN_STATE_HIGH,
	GPIO_PIN_STATE_DEFAULT=0xFF
};

enum GPIO_PinMode_t
{
	GPIO_PinMode__INPUT_ANALOG  							= 0x0,						//0b0000
	GPIO_PinMode_OUTPUT_PP_2MHZ 							= 0x1,						//0b0001
	GPIO_PinMode_OUTPUT_PP_10MHZ							= 0x2, 						//0b0010
	GPIO_PinMode_OUTPUT_PP_50MHZ							= 0x3,						//0b0111
	GPIO_PinMode_INPUT_FLOATING 							= 0x4,					  //0b0100
	GPIO_PinMode_OUTPUT_OD_2MHZ 							= 0x5,						//0b0101
	GPIO_PinMode_OUTPUT_OD_10MHZ							= 0x6, 						//0b0110
	GPIO_PinMode_OUTPUT_OD_50MHZ							= 0x7,						//0b0111
	GPIO_PinMode_INPUT_PUP_PDN  						 	= 0x8,						//0b1000
	GPIO_PinMode_ALTERNATE_FUNCTION_PP_2MHZ	  = 0x9,						//0b1001
	GPIO_PinMode_ALTERNATE_FUNCTION_PP_10MHZ  = 0xA,						//0b1010
	GPIO_PinMode_ALTERNATE_FUNCTION_PP_50MHZ 	= 0xB,						//0b1011
	GPIO_PinMode_ALTERNATE_FUNCTION_OD_2MHZ	  = 0xD,						//0b1101
	GPIO_PinMode_ALTERNATE_FUNCTION_OD_10MHZ  = 0xE,						//0b1110
	GPIO_PinMode_ALTERNATE_FUNCTION_OD_50MHZ 	= 0xF							//0b1111
};

enum GPIO_PinNumber_t
{
	GPIO_PIN_0,GPIO_PIN_1,GPIO_PIN_2,GPIO_PIN_3,
	GPIO_PIN_4,GPIO_PIN_5,GPIO_PIN_6,GPIO_PIN_7,
	GPIO_PIN_8,GPIO_PIN_9,GPIO_PIN_10,GPIO_PIN_11,
	GPIO_PIN_12,GPIO_PIN_13,GPIO_PIN_14,GPIO_PIN_15,GPIO_PIN_MAX
};

enum GPIO_PinAltFunc_t
{
	GPIO_PinAltFunc_AF0=0,
	GPIO_PinAltFunc_AF1,
	GPIO_PinAltFunc_AF2,
	GPIO_PinAltFunc_AF3,
	GPIO_PinAltFunc_AF4,
	GPIO_PinAltFunc_AF5,
	GPIO_PinAltFunc_AF6,
	GPIO_PinAltFunc_AF7,
	GPIO_PinAltFunc_AF8,
	GPIO_PinAltFunc_AF9,
	GPIO_PinAltFunc_AF10,
	GPIO_PinAltFunc_AF11,
	GPIO_PinAltFunc_AF12,
	GPIO_PinAltFunc_AF13,
	GPIO_PinAltFunc_AF14,
	GPIO_PinAltFunc_AF15
	
};

class GPIO_PinConfigs
{
	public:
		GPIO_PinConfigs();
	  GPIO_ErrorType_t 	GPIO_PinConfigsIsOK();
		GPIO_ErrorType_t 	PinConfigsErr;
		GPIO_ErrorType_t 	PinInitErr;
		GPIO_PortName_t		PortName;
		GPIO_PinNumber_t	PinNumber;
		GPIO_PinState_t		PinState ; //=	GPIO_PIN_STATE_LOW;
		GPIO_PinMode_t		PinMode  ; //=	GPIO_PinMode_OUTPUT_OD;
		GPIO_PinAltFunc_t	PinAltFunc;
	
	private:

};

class gpio
{
	public:
		gpio(GPIO_PortName_t	GPIO_PortName);
		GPIO_ErrorType_t	gpioErr;
		GPIO_TypeDef*	GPIO_PortReg;
		GPIO_ErrorType_t	GPIO_PinInit					(GPIO_PinConfigs*	PinConfigs);
		GPIO_PinState_t		GPIO_PinStateGet		(GPIO_PinConfigs*	PinConfigs);
		GPIO_ErrorType_t	GPIO_PinStateSet		(GPIO_PinConfigs*	PinConfigs,GPIO_PinState_t PinState);
		GPIO_ErrorType_t	GPIO_PinStateToggle	(GPIO_PinConfigs*	PinConfigs);

	private:
	
};

#endif



