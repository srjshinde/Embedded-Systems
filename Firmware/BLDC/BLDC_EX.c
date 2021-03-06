#include "stm32f10x.h"
#include "GPIO.h"

#define TIMER_CLOCK_ADVANCED  72000000
void delay(void)
{
   int i;
  for(i = 0; i <= 5000; i++)
  {

  }

}
int main (void)
 {
    int seq = 1;


	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_TIM1EN;

	GPIOA->CRH |= GPIO_CRH_CNF8_1 | GPIO_CRH_MODE8_1 | GPIO_CRH_MODE8_0;
	GPIOB->CRH |= GPIO_CRH_CNF13_1 | GPIO_CRH_MODE13_1 | GPIO_CRH_MODE13_0;
    	GPIOA->CRH |= GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9_1 | GPIO_CRH_MODE9_0;
	GPIOB->CRH |= GPIO_CRH_CNF14_1 | GPIO_CRH_MODE14_1 | GPIO_CRH_MODE14_0;
    	GPIOA->CRH |= GPIO_CRH_CNF10_1 | GPIO_CRH_MODE10_1 | GPIO_CRH_MODE10_0;
	GPIOB->CRH |= GPIO_CRH_CNF15_1 | GPIO_CRH_MODE15_1 | GPIO_CRH_MODE15_0;



	TIM1 -> PSC = ((72000000) / ((1000)*(100)))-1;
	TIM1->ARR = 100;

	TIM1->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1PE;
    	TIM1->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2PE;
	TIM1->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3PE;


	TIM1->BDTR |= 191;
	TIM1->BDTR |= TIM_BDTR_MOE;
	TIM1 -> BDTR |= TIM_BDTR_OSSR | TIM_BDTR_OSSI ;

	TIM1->CCER |= TIM_CCER_CC1E | TIM_CCER_CC1NE | TIM_CCER_CC1NP;
        TIM1->CCER |= TIM_CCER_CC2E | TIM_CCER_CC2NE | TIM_CCER_CC2NP;
	TIM1->CCER |= TIM_CCER_CC3E | TIM_CCER_CC3NE | TIM_CCER_CC3NP;

TIM1->CCER |= (TIM_CCER_CC1NP | TIM_CCER_CC2NP | TIM_CCER_CC3NP);


	TIM1->CR1 |= TIM_CR1_ARPE;
        TIM1->EGR |= TIM_EGR_UG;
	TIM1->CR1 |= TIM_CR1_CEN;
    TIM1 -> CCR1 = (uint16_t)90;
    TIM1 -> CCR2 = (uint16_t)90;
    TIM1 -> CCR3 = (uint16_t)90;

   while (1)
   {


	switch (seq) {
		case 1:
		{
			TIM1->CCER |= TIM_CCER_CC2E;
			TIM1->CCER |= TIM_CCER_CC3NE;
		   TIM1->BDTR |= TIM_BDTR_MOE;

				TIM1 -> CCR2 = 50;
				TIM1 -> CCR3 = 50;
			TIM1->CCER &= ~TIM_CCER_CC2E;
			TIM1->CCER &= ~TIM_CCER_CC3NE;

		}
		++seq;
			break;

		case 2:
		{
			TIM1->CCER |= TIM_CCER_CC2E;
			TIM1->CCER |= TIM_CCER_CC1NE;
		   TIM1->BDTR |= TIM_BDTR_MOE;

				TIM1 -> CCR2 = 50;
				TIM1 -> CCR1 = 50;
			TIM1->CCER &= ~TIM_CCER_CC2E;
			TIM1->CCER &= ~TIM_CCER_CC1NE;

		}
		++seq;
			break;

		case 3:
		{
			TIM1->CCER |= TIM_CCER_CC3E;
			TIM1->CCER |= TIM_CCER_CC1NE;
		   TIM1->BDTR |= TIM_BDTR_MOE;

				TIM1 -> CCR1 = 50;
				TIM1 -> CCR3 = 50;
			TIM1->CCER &= ~TIM_CCER_CC3E;
			TIM1->CCER &= ~TIM_CCER_CC1NE;

		}
		++seq;
			break;

		case 4:
		{
			TIM1->CCER |= TIM_CCER_CC2NE;
			TIM1->CCER |= TIM_CCER_CC3E;
		   TIM1->BDTR |= TIM_BDTR_MOE;

				TIM1 -> CCR2 = 50;
				TIM1 -> CCR3 = 50;
			TIM1->CCER &= ~TIM_CCER_CC2NE;
			TIM1->CCER &= ~TIM_CCER_CC3E;

		}
		++seq;
			break;

		case 5:
		{
			TIM1->CCER |= TIM_CCER_CC1E;
			TIM1->CCER |= TIM_CCER_CC2NE;
		   TIM1->BDTR |= TIM_BDTR_MOE;

				TIM1 -> CCR2 = 50;
				TIM1 -> CCR1 = 50;
			TIM1->CCER &= ~TIM_CCER_CC1E;
			TIM1->CCER &= ~TIM_CCER_CC2NE;

		}
		++seq;
			break;

		case 6:
		{
			TIM1->CCER |= TIM_CCER_CC1E;
			TIM1->CCER |= TIM_CCER_CC3NE;
		   TIM1->BDTR |= TIM_BDTR_MOE;

				TIM1 -> CCR1 = 50;
				TIM1 -> CCR3 = 50;
			TIM1->CCER &= ~TIM_CCER_CC1E;
			TIM1->CCER &= ~TIM_CCER_CC3NE;

		}
		++seq;
			break;



	}
	if( seq == 6) seq = 1;

      }
   return 0;
 }

