#include "config.h" 

/* TASK2 任务 配置
 * 包括: 任务句柄 任务优先级 堆栈大小 创建任务
 */
#define TASK_com1_PRIO      8                   /* 任务优先级 */
#define TASK_com1_STK_SIZE  128                 /* 任务堆栈大小 */
TaskHandle_t            Task_com1_Handler;  /* 任务句柄 */

void task_com1_creat(void){
    xTaskCreate((TaskFunction_t )task_com1,                 /* 任务函数 */
                (const char*    )"task_com1",               /* 任务名称 */
                (uint16_t       )TASK_com1_STK_SIZE,        /* 任务堆栈大小 */
                (void*          )NULL,                  /* 传入给任务函数的参数 */
                (UBaseType_t    )TASK_com1_PRIO,            /* 任务优先级 */
                (TaskHandle_t*  )&Task_com1_Handler);   /* 任务句柄 */
}

void task_com1(void *pvParameters){
    unsigned char flag = 0;
    while(1){
        if(flag){
            GPIO_SetBits(GPIOA,GPIO_Pin_8);
        }else{
            GPIO_ResetBits(GPIOA,GPIO_Pin_8);
        }
        vTaskDelay(500);
        flag ^=1;
    }
}