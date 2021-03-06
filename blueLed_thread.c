#include "cmsis_os.h" // CMSIS RTOS header file
#include "stm32f4xx_hal.h"
 
void blueLedThread (void const *argument);           // thread function
//osThreadId tid_Thread;                              // thread id
osThreadDef (blueLedThread, osPriorityNormal, 1, 0); // thread object

int init_blueLedThread (void) 
{
  osThreadId tid_Thread;                              // thread id
  tid_Thread = osThreadCreate (osThread(blueLedThread), NULL);
  if (!tid_Thread) return(-1);
  return(0);
}

void blueLedThread (void const *argument) 
{
 osStatus status;    // capture the return status
 uint32_t delayTime; // delay time in milliseconds
  
 delayTime = 1500;   // delay 1 second
  
  while (1) 
  {
    HAL_GPIO_TogglePin (GPIOD, BLUE_LED_Pin);
    //HAL_Delay(1000); // Insert thread code here...
    status = osDelay (delayTime); // suspend thread execution
    //osThreadYield (); // suspend thread
  }
}
