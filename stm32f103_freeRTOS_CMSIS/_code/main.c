#include "config.h"

/******************runtim cal*****************************/
void main_init(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
    key_init();
    
    osKernelInitialize();
    task_mode_creat();
    task_com1_creat();
    osKernelStart();
}

int main(void){
    main_init();
}

unsigned int test,test2 = 0;
void vApplicationIdleHook(void){
    test = 1;
}
void vApplicationTickHook(void){
    test2++;
}