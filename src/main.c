#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"
#include "misc.h"

//Functions prototypes
void TM_delay_init(void);
void TM_DelayMillis(uint32_t millis);

void LedSequence1(void);
void LedSequence2(void);
void Ledsequence3(void);
void TM_DelayS(uint32_t millis);

//Global vars
uint32_t multiplier;
uint32_t freqq;
int mode=0;

int main(void)
{
	// BOOt Chip
	SystemInit();


	TM_delay_init();


	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);



	// IniT Pin 1 GPIO for LED drive
	GPIO_InitTypeDef Gpiostruct;
	Gpiostruct.GPIO_Mode=GPIO_Mode_OUT;
	Gpiostruct.GPIO_OType=GPIO_OType_PP;
	Gpiostruct.GPIO_Pin=GPIO_Pin_0;
	Gpiostruct.GPIO_PuPd=GPIO_PuPd_UP;
	Gpiostruct.GPIO_Speed=GPIO_Speed_100MHz;

	GPIO_Init(GPIOA,&Gpiostruct);

	TM_delay_init();


    while(1)
    {

    	TM_DelayMillis(500);
    	GPIO_ToggleBits(GPIOA,GPIO_Pin_0);



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



void LedSequence1(void)
{
			TM_DelayMillis(1000);
			TM_DelayMillis(1000);
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_0);
	    	TM_DelayMillis(30);
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_0);
	    	TM_DelayMillis(10);

	    	TM_DelayMillis(10);
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_1);
	    	TM_DelayMillis(10);
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_1);
	    	TM_DelayMillis(15);
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_1);
	    	TM_DelayMillis(20);
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_1);
	    	TM_DelayMillis(30);
	    	TM_DelayMillis(30);

	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_4);
	    	TM_DelayMillis(15);
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_4);


}

void LedSequence2(void)
{
	int i;

	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_0);


	    	TM_DelayMillis(10);
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_4);

	    	TM_DelayMillis(10);
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_1);
	    	TM_DelayMillis(15);
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_4);



	        TM_DelayMillis(10);
	        GPIO_ToggleBits(GPIOA,GPIO_Pin_1);
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_0);

	    	for(i=0;i<3;i++)
	    	{
	    		TM_DelayMillis(1000);

			}
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_0);
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_1);
	        TM_DelayMillis(20);
	        GPIO_ToggleBits(GPIOA,GPIO_Pin_1);
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_0);
	    	TM_DelayMillis(10);
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_0);
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_1);
	        TM_DelayMillis(15);
	        GPIO_ToggleBits(GPIOA,GPIO_Pin_1);
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_0);
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_4);
	        TM_DelayMillis(15);
	    	GPIO_ToggleBits(GPIOA,GPIO_Pin_4);



}
void Ledsequence3(void)
{
	int i;



		    	TM_DelayMillis(10);
		    	GPIO_ToggleBits(GPIOA,GPIO_Pin_4);
		    	GPIO_ToggleBits(GPIOA,GPIO_Pin_1);
		    	GPIO_ToggleBits(GPIOA,GPIO_Pin_0);
		    	TM_DelayMillis(10);
		    	GPIO_ToggleBits(GPIOA,GPIO_Pin_4);
		    	GPIO_ToggleBits(GPIOA,GPIO_Pin_1);
		    	GPIO_ToggleBits(GPIOA,GPIO_Pin_0);

		    	for(i=0;i<3;i++)
		    	{
		    		TM_DelayMillis(500);

				}
		    	GPIO_ToggleBits(GPIOA,GPIO_Pin_1);

		        TM_DelayMillis(20);
		        GPIO_ToggleBits(GPIOA,GPIO_Pin_1);
		        TM_DelayMillis(7);
		        GPIO_ToggleBits(GPIOA,GPIO_Pin_1);
		        TM_DelayMillis(10);
		        GPIO_ToggleBits(GPIOA,GPIO_Pin_1);
		        TM_DelayMillis(7);
		        GPIO_ToggleBits(GPIOA,GPIO_Pin_1);
		        TM_DelayMillis(10);
		        GPIO_ToggleBits(GPIOA,GPIO_Pin_1);
		        TM_DelayMillis(15);
		        GPIO_ToggleBits(GPIOA,GPIO_Pin_0);
		        TM_DelayMillis(10);
		        GPIO_ToggleBits(GPIOA,GPIO_Pin_0);
		    	GPIO_ToggleBits(GPIOA,GPIO_Pin_4);
		    	TM_DelayMillis(10);
		    	GPIO_ToggleBits(GPIOA,GPIO_Pin_4);
		    	TM_DelayMillis(15);
				GPIO_ToggleBits(GPIOA,GPIO_Pin_0);
				GPIO_ToggleBits(GPIOA,GPIO_Pin_4);
		    	TM_DelayMillis(10);
		    	GPIO_ToggleBits(GPIOA,GPIO_Pin_0);

		    	TM_DelayMillis(10);
		    	GPIO_ToggleBits(GPIOA,GPIO_Pin_4);


}
