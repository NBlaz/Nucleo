#include "uart.h"

USART_TypeDef *USART_InitStructure = USART1;

void USART1_Configuration(void)
{
    uint32_t tmpreg = 0x00, apbclock = 0x00;
    uint32_t integerdivider = 0x00;
    uint32_t fractionaldivider = 0x00;
    uint32_t BaudRate=9600;
    RCC_ClocksTypeDef RCC_ClocksStatus;

  /* USARTx configuration ------------------------------------------------------*/
  /* USARTx configured as follow:
        - BaudRate = 115200 baud
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */

  /*---------------------------- USART BRR Configuration -----------------------*/
    /* Configure the USART Baud Rate */
    RCC_GetClocksFreq(&RCC_ClocksStatus);

    apbclock = RCC_ClocksStatus.PCLK2_Frequency;


    /* Determine the integer part */
    if ((USART_InitStructure->CR1 & USART_CR1_OVER8) != 0)
    {
      /* Integer part computing in case Oversampling mode is 8 Samples */
      integerdivider = ((25 * apbclock) / (2 * (BaudRate)));
    }
    else /* if ((USARTx->CR1 & USART_CR1_OVER8) == 0) */
    {
      /* Integer part computing in case Oversampling mode is 16 Samples */
      integerdivider = ((25 * apbclock) / (4 * (BaudRate)));
    }
    tmpreg = (integerdivider / 100) << 4;

    /* Determine the fractional part */
    fractionaldivider = integerdivider - (100 * (tmpreg >> 4));

    /* Implement the fractional part in the register */
    if ((USART_InitStructure->CR1 & USART_CR1_OVER8) != 0)
    {
      tmpreg |= ((((fractionaldivider * 8) + 50) / 100)) & ((uint8_t)0x07);
    }
    else /* if ((USARTx->CR1 & USART_CR1_OVER8) == 0) */
    {
      tmpreg |= ((((fractionaldivider * 16) + 50) / 100)) & ((uint8_t)0x0F);
    }

    /* Write to USART BRR register */
  USART_InitStructure->BRR = (uint16_t)tmpreg;
  USART_InitStructure->CR1 = 0x2000;
  USART_InitStructure->CR2 = 0x0000;
  USART_InitStructure->CR3 = 0x0000;
  USART_InitStructure->GTPR = 0x0000;
  USART_InitStructure->CR1 |= 0x0008;
}

void UARTPutc(char a)
{
    int i;
    if((USART_InitStructure->SR & 0x0080 )!=0)
        USART_InitStructure->DR = a;
    while ((USART_InitStructure->SR & 0x80)==0);
}

void printu(char * line)
{
    while(*line!='\0')
    {
        UARTPutc(*line);
        line++;
    }
    UARTPutc('\0');
}
