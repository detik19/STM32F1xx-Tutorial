//*****************************************************************************
//
//! \file main.c
//! \brief main application
//! \version 1.0.0.0
//! \date $Creat_time$
//! \author $Creat_author$
//! \copy
//!
//! Copyright (c) 2014 CooCox.  All rights reserved.
//
//! \addtogroup project
//! @{
//! \addtogroup main
//! @{
//*****************************************************************************


#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

GPIO_InitTypeDef GPIO_InitStructure;

void gpio_setup(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_12;
	GPIO_Init(GPIOB, &GPIO_InitStructure);


	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);




}

int main(void)
{
	gpio_setup();

    while(1)
    {
	//	GPIO_ResetBits(GPIOC, GPIO_Pin_13); //ON
    	if(!(GPIO_ReadInputData(GPIOB)& GPIO_Pin_12)){
    		GPIO_ResetBits(GPIOC, GPIO_Pin_13); //ON
    	}else{
    		GPIO_SetBits(GPIOC, GPIO_Pin_13); //OFF
    	}
    }
}
//! @}
//! @}
