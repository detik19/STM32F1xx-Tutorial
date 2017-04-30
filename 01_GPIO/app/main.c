//*****************************************************************************
//
//! \file main.c
//! \brief main application
//! \version 1.0.0.0
//! \date $Creat_time$
//! \author Tedy Tri Saputro
//! \copy
//!
//! Copyright (c) 2014 CooCox.  All rights reserved.
//
//! \addtogroup project
//! @{
//! \addtogroup main
//! @{
//*****************************************************************************
#include "stm32f10x.h"
void wait_ms(int t){
	volatile int i;
	for (i=0;i<t*2000;i++);
}

void gpioSetup(){
	//RCC->APB2ENR=0x0010;
	RCC->APB2ENR|=RCC_APB2ENR_IOPCEN;
	GPIOC->CRH|=0x00300000;

}
int main(void)
{
	gpioSetup();

    while(1)
    {
    	//GPIOC->ODR=0x0000;
    	GPIOC->BRR=(1<<13);
    	wait_ms(1000);
//    					   //5432 1098 7654 3210
    	//GPIOC->ODR=0x2000;//0010 0000 0000 0000
    	GPIOC->BSRR=(1<<13);
    	wait_ms(1000);

    }
}
//! @}
//! @}
