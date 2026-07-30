#include "config.h"

/* TASK1 任务 配置
 * 包括: 任务句柄 任务优先级 堆栈大小 创建任务
 */
#define TASK_MODE_PRIO      osPriorityAboveNormal        /* 任务优先级 */
#define TASK_MODE_STK_SIZE  128                     /* 任务堆栈大小(4字节为单位) */
osThreadId_t            Task_mode_ID;               /* 任务ID */

void task_mode_creat(void){
    osThreadAttr_t attr = {0};
    attr.name       = "task_mode";
    attr.stack_size = TASK_MODE_STK_SIZE * 4;
    attr.priority   = TASK_MODE_PRIO;
    Task_mode_ID = osThreadNew(task_mode, NULL, &attr);
}
unsigned int testtick;
void task_mode(void *pvParameters){
    unsigned char flag = 0;
    uint32_t tick = osKernelGetTickCount();
    while(1){
        key_func();

        if(keyXvalread(0,KEY_VAL_FLAG)){
            flag ^=1;
        }
        testtick++;
        tick += 1;
        osDelayUntil(tick);
    }
}
