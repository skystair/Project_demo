#include "config.h" 

/* TASK1 任务 配置
 * 包括: 任务句柄 任务优先级 堆栈大小 创建任务
 */
#define TASK_MODE_PRIO      8                   /* 任务优先级 */
#define TASK_MODE_STK_SIZE  128                 /* 任务堆栈大小 */
TaskHandle_t            Task_mode_Handler;  /* 任务句柄 */

void task_mode_creat(void){
    /* 创建任务1 */
    xTaskCreate((TaskFunction_t )task_mode,                 /* 任务函数 */
                (const char*    )"task_mode",               /* 任务名称 */
                (uint16_t       )TASK_MODE_STK_SIZE,        /* 任务堆栈大小 */
                (void*          )NULL,                  /* 传入给任务函数的参数 */
                (UBaseType_t    )TASK_MODE_PRIO,            /* 任务优先级 */
                (TaskHandle_t*  )&Task_mode_Handler);   /* 任务句柄 */
}

extern TimerHandle_t           Timer1Timer_Handler;/* 定时器1句柄 */

void taskinfo(void);
void task_mode(void *pvParameters){
    unsigned char flag = 0;
    while(1){
        key_func();
        
        if(keyXvalread(0,KEY_VAL_FLAG)){
            flag ^=1;
//            if(flag){
//                 xTimerStart((TimerHandle_t  )Timer1Timer_Handler,   /* 待启动的定时器句柄 */
//                                (TickType_t     )portMAX_DELAY);        /* 等待系统启动定时器的最大时间 */
//            }else{
//                 xTimerStop((TimerHandle_t  )Timer1Timer_Handler,   /* 待启动的定时器句柄 */
//                                (TickType_t     )portMAX_DELAY);        /* 等待系统启动定时器的最大时间 */
//            }

            taskinfo();
        }
        
//        if(flag){
//            GPIO_SetBits(GPIOA,GPIO_Pin_8);
//        }else{
//            GPIO_ResetBits(GPIOA,GPIO_Pin_8);
//        }
//        vTaskDelay(500);
//        flag ^=1;

        vTaskDelay(1);
    }
}
