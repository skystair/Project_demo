#include "config.h"


//TimerHandle_t           Timer1Timer_Handler;/* 定时器1句柄 */
//unsigned int testtick = 0;
//void Timer1Callback(TimerHandle_t xTimer){
//    testtick++;
//}
//void task_timer_creat(void){
//    /* 定时器1创建为周期定时器 */
//    Timer1Timer_Handler = xTimerCreate((const char*  )"Timer1",                 /* 定时器名 */
//                                      (TickType_t   )1000,                      /* 定时器超时时间 */
//                                      (UBaseType_t  )pdTRUE,                    /* 周期定时器 */
//                                      (void*        )1,                         /* 定时器ID */
//                                      (TimerCallbackFunction_t)Timer1Callback); /* 定时器回调函数 */
//}

/******************runtim cal*****************************/
char runtimeinfo[200];
char* info = runtimeinfo;
void taskinfo(void){
    vTaskGetRunTimeStats(info);             /* 获取任务运行时间信息 */
}
uint32_t FreeRTOSRunTimeTicks;          /* FreeRTOS时间统计所用的节拍计数器 */
void ConfigureTimeForRunTimeStats(void)
{
    FreeRTOSRunTimeTicks = 0;           /* 节拍计数器初始化为0 */
    
    /*统计定时器*/
    TIM_TimeBaseInitTypeDef TIM_InitStr;
    TIM_InitStr.TIM_ClockDivision = 1;
    TIM_InitStr.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_InitStr.TIM_Period = 100-1;
    TIM_InitStr.TIM_Prescaler = 72-1;
//    TIM_InitStr.TIM_RepetitionCounter = XX;
    
    TIM_TimeBaseInit(TIM3,&TIM_InitStr);
    
    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
    
    __NVIC_SetPriority(TIM3_IRQn,10);
    __NVIC_EnableIRQ(TIM3_IRQn);
    
}
void TIM3_IRQHandler(void){
    if(TIM_GetITStatus(TIM3, TIM_IT_Update)){
        TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
        FreeRTOSRunTimeTicks++;
    }
}
/******************runtim cal*****************************/
void main_init(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
    key_init();
    
    task_mode_creat();
    task_com1_creat();
//    task_timer_creat();
}

int main(void){
    main_init();
    ConfigureTimeForRunTimeStats();
    vTaskStartScheduler();
    while(1){
//        if(keyXvalread(KEY_CH_test,KEY_VAL_KEEP)){
//            
//        }else{
//            
//        }
        ;
    }
}

unsigned int test,test2 = 0;
void vApplicationIdleHook(void){
    test = 1;
}
void vApplicationTickHook(void){
    test2++;
}
//void prvTimerTask(void){
//    test = 2;
//}


//systick**************************************************************
#if defined(SysTick)
#undef SysTick_Handler

/* CMSIS SysTick interrupt handler prototype */
extern void SysTick_Handler     (void);
/* FreeRTOS tick timer interrupt handler prototype */
extern void xPortSysTickHandler (void);

/*
  SysTick handler implementation that also clears overflow flag.
*/
void SysTick_Handler (void) {
#if (configUSE_TICKLESS_IDLE == 0)
  /* Clear overflow flag */
  SysTick->CTRL;
#endif

  if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED) {
    /* Call tick handler */
    xPortSysTickHandler();
  }
  
  //usr tick
  key_tick();
}
#endif /* SysTick */
//systick**************************************************************