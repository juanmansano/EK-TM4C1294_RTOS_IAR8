#include "system_tm4c1294.h" // CMSIS-Core
#include "driverleds.h" // device drivers
#include "cmsis_os2.h" // CMSIS-RTOS

osThreadId_t thread1_id, thread2_id, thread3_id, thread4_id;

//FUNÇÃO PARA EXECUÇÃO DO EXERCÍCIO 5.
/*void threadEX5(void *arg){
  uint8_t state = 0;
  uint8_t led = (uint32_t)arg;
  
  while(1){
    state ^= led;
    LEDWrite(led, state);
    osDelay(100);
  } // while
} // threadEX5*/

//FUNÇÃO PARA EXECUÇÃO DO EXERCÍCIO 6.
/*
typedef struct estruturaLED
{
  uint8_t led;
  uint32_t frequencia;
}ESTRUTURALED;

void threadEX6(void *arg){
  uint8_t state = 0;
  ESTRUTURALED* led_selecionado = (ESTRUTURALED*) arg;
  uint8_t led = led_selecionado->led;
  uint32_t frequencia = led_selecionado->frequencia;
  
  while(1){
    state ^= led;
    LEDWrite(led, state);
    osDelay(frequencia);
  } // while
} // threadEX6*/

//FUNÇÃO PARA EXECUÇÃO DO EXERCÍCIO 7.

typedef struct estruturaLED
{
  uint8_t led;
  uint32_t frequencia;
}ESTRUTURALED;

void threadEX7(void *arg){
  uint8_t state = 0;
  ESTRUTURALED* led_selecionado = (ESTRUTURALED*) arg;
  uint8_t led = led_selecionado->led;
  uint32_t frequencia = led_selecionado->frequencia;
  
  while(1){
    state ^= led;
    LEDWrite(led, state);
    osDelay(frequencia);
  } // while
} // threadEX7

void main(void){
  LEDInit(LED2 | LED1 | LED3 | LED4);
  
  //FUNÇÃO PARA EXECUÇÃO DO EXERCICIO 6
  /*
  ESTRUTURALED led1, led2;
  led1.led = LED1;
  led2.led = LED2;
  led1.frequencia = 100;
  led2.frequencia = 100;*/
  
  ESTRUTURALED led1, led2, led3, led4;
  led1.led = LED1;
  led2.led = LED2;
  led3.led = LED3;
  led4.led = LED4;
  led1.frequencia = 200;
  led2.frequencia = 300;
  led3.frequencia = 500;
  led4.frequencia = 700;

  osKernelInitialize();
  
  //FUNÇÃO PARA EXECUÇÃO DO EXERCICIO 5
  /*
  thread1_id = osThreadNew(threadEX5, (void *)LED1, NULL);
  thread2_id = osThreadNew(threadEX5, (void *)LED2, NULL);
  */
  
  //FUNÇÃO PARA EXECUÇÃO DO EXERCICIO 6
  /*
  thread1_id = osThreadNew(threadEX6, &led1, NULL);
  thread2_id = osThreadNew(threadEX6, &led2, NULL);
  */
  
  thread1_id = osThreadNew(threadEX7, &led1, NULL);
  thread2_id = osThreadNew(threadEX7, &led2, NULL);
  thread3_id = osThreadNew(threadEX7, &led3, NULL);
  thread4_id = osThreadNew(threadEX7, &led4, NULL);

  if(osKernelGetState() == osKernelReady)
    osKernelStart();

  while(1);
} // main
