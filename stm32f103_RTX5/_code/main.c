#include "config.h"

void main_init(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
    key_init();
}

int main(void){
    main_init();

    osKernelInitialize();

    task_mode_creat();
    task_com1_creat();

    osKernelStart();

    while(1){
        ;
    }
}
