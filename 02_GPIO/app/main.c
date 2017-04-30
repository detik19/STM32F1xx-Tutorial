#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

GPIO_InitTypeDef GPIO_InitStructure;
void wait_ms(int t){
	volatile int i;
	for (i=0;i<t*2000;i++);
}
void setup_gpio(){
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_All ;
	  GPIO_Init(GPIOC, &GPIO_InitStructure);
}

int main(void){
  setup_gpio();
  while(1){
    GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_SET);
    wait_ms(1000);
    GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_RESET);
    wait_ms(1000);

  }
}
