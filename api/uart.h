#ifndef __UART
#define __UART

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"

void USART1_Configuration(void);
void UARTPutc(char a);
void printu(char * line);

#endif
