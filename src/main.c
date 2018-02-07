#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"
#include "misc.h"
#include "uart.h"

//Functions prototypes
void TM_delay_init(void);
void TM_DelayMillis(uint32_t millis);
void TM_DelayS(uint32_t millis);

//Global vars
uint32_t multiplier;
uint32_t freqq;

int main(void)
{
	char *a;
	a="a";
	// BOOt Chip
	SystemInit();
	TM_delay_init();
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	/* USART2 clock enable */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	// IniT Pin 5 GPIO for LED drive
	GPIO_InitTypeDef Gpiostruct;
	Gpiostruct.GPIO_Mode=GPIO_Mode_OUT;
	Gpiostruct.GPIO_OType=GPIO_OType_PP;
	Gpiostruct.GPIO_Pin=GPIO_Pin_5;
	Gpiostruct.GPIO_PuPd=GPIO_PuPd_UP;
	Gpiostruct.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_Init(GPIOA,&Gpiostruct);


     /*-------------------------- GPIO Configuration ----------------------------*/
	GPIO_InitTypeDef UartGPIO;
    UartGPIO.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10; // PA.2 USART2_TX, PA.3 USART2_RX
    UartGPIO.GPIO_Mode = GPIO_Mode_AF;
    UartGPIO.GPIO_OType = GPIO_OType_PP;
    UartGPIO.GPIO_PuPd = GPIO_PuPd_NOPULL;
    UartGPIO.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(GPIOA, &UartGPIO);

    /* Connect USART pins to AF */
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);

    TM_delay_init();
	USART2_Configuration();

    while(1)
    {
		a="a";
		UARTPutc(a);
		a="b";
    	//TM_DelayMillis(500);
    	GPIO_ToggleBits(GPIOA,GPIO_Pin_5);
    }
}




void TM_delay_init(void)
{
	RCC_ClocksTypeDef rcc_clock;
	RCC_GetClocksFreq(&rcc_clock);
	multiplier=rcc_clock.SYSCLK_Frequency/4;

}
void TM_DelayMillis(uint32_t millis) {
    /* Multiply millis with multipler */
    /* Substract 10 */

    millis =multiplier*millis/1000;
    /* 4 cycles for one loop */
    while (millis--);
}
void TM_DelayS(uint32_t millis) {
    /* Multiply millis with multipler */
    /* Substract 10 */

    millis =multiplier*millis;
    /* 4 cycles for one loop */
    while (millis--);
}
