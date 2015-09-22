/**
  ******************************************************************************
  * @file    TIM_Time_Base/main.c 
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    11-October-2013
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"
#include "stm32f0308_discovery.h"

/** @addtogroup STM32F0308_Discovery_Peripheral_Examples
  * @{
  */

/** @addtogroup TIM_Time_Base
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
__IO uint16_t CCR3_Val = 72;//13654;
__IO uint16_t CCR1_Val = 72;//6826;
__IO uint16_t CCR2_Val = 72;//6826;
uint16_t PrescalerValue = 0;

extern enum STATE next_state;
extern uint32_t Led_data;

extern enum STATE next_state2;
extern uint32_t Led_data2;

extern enum STATE next_state3;
extern uint32_t Led_data3;

extern enum STATE{NONE = 0, INTERVAL, START1, START2, DATA1, DATA2};
/* Private function prototypes -----------------------------------------------*/
static void TIM_Config(void);


static __IO uint32_t TimingDelay;

/* Private function prototypes -----------------------------------------------*/
void Delay(__IO uint32_t nTime);
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in milliseconds.
  * @retval None
  */
void Delay(__IO uint32_t nTime)
{ 
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}

void LEDStripe_init()
{
//*
  next_state = INTERVAL;
  Led_data = 0x0 << 20 | 0xf << 12 | 0xf << 8 | 0x0 << 4 | 0x0; 
  TIM_Cmd(TIM3, ENABLE);
  
  while((TIM3->CR1 & TIM_CR1_CEN));
  
  next_state = INTERVAL;
  Led_data = 0x1 << 20 | 0xf << 12 | 0x0 << 8 | 0xf << 4 | 0x0;
  TIM_Cmd(TIM3, ENABLE);
  
  while((TIM3->CR1 & TIM_CR1_CEN));

  next_state = INTERVAL;
  Led_data = 0x2 << 20 | 0xf << 12 | 0x0 << 8 | 0x0 << 4 | 0xf;
  TIM_Cmd(TIM3, ENABLE);
//*/  

//*
  next_state2 = INTERVAL;
  Led_data2 = 0x0 << 20 | 0xf << 12 | 0xf << 8 | 0x0 << 4 | 0x0; 
  TIM_Cmd(TIM16, ENABLE);
  
  while((TIM16->CR1 & TIM_CR1_CEN));  

  next_state2 = INTERVAL;
  Led_data2 = 0x1 << 20 | 0xf << 12 | 0x0 << 8 | 0xf << 4 | 0x0;
  TIM_Cmd(TIM16, ENABLE);
  
  while((TIM16->CR1 & TIM_CR1_CEN));

  next_state2 = INTERVAL;
  Led_data2 = 0x2 << 20 | 0xf << 12 | 0x0 << 8 | 0x0 << 4 | 0xf;
  TIM_Cmd(TIM16, ENABLE);
//*/

//*
  next_state3 = INTERVAL;
  Led_data3 = 0x0 << 20 | 0xf << 12 | 0xf << 8 | 0x0 << 4 | 0x0; 
  TIM_Cmd(TIM17, ENABLE);
  
  while((TIM17->CR1 & TIM_CR1_CEN));

  next_state3 = INTERVAL;
  Led_data3 = 0x1 << 20 | 0xf << 12 | 0x0 << 8 | 0xf << 4 | 0x0;
  TIM_Cmd(TIM17, ENABLE);
  
  while((TIM17->CR1 & TIM_CR1_CEN));

  next_state3 = INTERVAL;
  Led_data3 = 0x2 << 20 | 0xf << 12 | 0x0 << 8 | 0x0 << 4 | 0xf;
  TIM_Cmd(TIM17, ENABLE);
//*/  
}

void ChangeLEDColor(uint32_t color)
{
//*
  next_state = INTERVAL;
  Led_data = 0x0 << 20 | 0xf << 12 | color; 
  TIM_Cmd(TIM3, ENABLE);
  
  while((TIM3->CR1 & TIM_CR1_CEN));
  
  next_state = INTERVAL;
  Led_data = 0x1 << 20 | 0xf << 12 | color;
  TIM_Cmd(TIM3, ENABLE);
  
  while((TIM3->CR1 & TIM_CR1_CEN));

  next_state = INTERVAL;
  Led_data = 0x2 << 20 | 0xf << 12 | color;
  TIM_Cmd(TIM3, ENABLE);
//*/  

//*
  next_state2 = INTERVAL;
  Led_data2 = 0x0 << 20 | 0xf << 12 | color; 
  TIM_Cmd(TIM16, ENABLE);
  
  while((TIM16->CR1 & TIM_CR1_CEN));  

  next_state2 = INTERVAL;
  Led_data2 = 0x1 << 20 | 0xf << 12 | color;
  TIM_Cmd(TIM16, ENABLE);
  
  while((TIM16->CR1 & TIM_CR1_CEN));

  next_state2 = INTERVAL;
  Led_data2 = 0x2 << 20 | 0xf << 12 | color;
  TIM_Cmd(TIM16, ENABLE);
//*/

//*
  next_state3 = INTERVAL;
  Led_data3 = 0x0 << 20 | 0xf << 12 | color; 
  TIM_Cmd(TIM17, ENABLE);
  
  while((TIM17->CR1 & TIM_CR1_CEN));

  next_state3 = INTERVAL;
  Led_data3 = 0x1 << 20 | 0xf << 12 | color;
  TIM_Cmd(TIM17, ENABLE);
  
  while((TIM17->CR1 & TIM_CR1_CEN));

  next_state3 = INTERVAL;
  Led_data3 = 0x2 << 20 | 0xf << 12 | color;
  TIM_Cmd(TIM17, ENABLE);
//*/  
  
}

/////////////////////////////////////////////////////////////////////////////
// Marquee LED

int32_t i = 0, j = 0;
int32_t i2 = 0, j2 = 0;
int32_t i3 = 0, j3 = 0;

void MarqueeLed()
{
    Delay(50);
    // LED3
    //*
    if(! (TIM3->CR1 & TIM_CR1_CEN)){
      //Delay(50);
      switch(i)
      {
      case 0:
        Led_data = 0x2 << 20 | 0xf << 12 | 0xf0;
        break;
      case 1:
        Led_data = 0x1 << 20 | 0xf << 12 | 0xf00;
        break;
      case 2:
        Led_data = 0x0 << 20 | 0xf << 12 | 0xf;
        break;
      case 3:
        Led_data = 0x2 << 20 | 0xf << 12 | 0xf00;
        break;
      case 4:
        Led_data = 0x1 << 20 | 0xf << 12 | 0xf;
        break;
      case 5:
        Led_data = 0x0 << 20 | 0xf << 12 | 0xf0;
        break;
      case 6:
        Led_data = 0x2 << 20 | 0xf << 12 | 0xf;
        break;
      case 7:
        Led_data = 0x1 << 20 | 0xf << 12 | 0xf0;
        break;
      case 8:
        Led_data = 0x0 << 20 | 0xf << 12 | 0xf00;
        break;
      }
      next_state = INTERVAL;
      TIM_Cmd(TIM3, ENABLE);
      i++;
      if(i>8) i = 0;
        
    }
    //*/

    // LED4
    //*
    if(! (TIM16->CR1 & TIM_CR1_CEN)){
      //Delay(50);
      switch(i2)
      {
      case 0:
        Led_data2 = 0x2 << 20 | 0xf << 12 | 0xf0;
        break;
      case 1:
        Led_data2 = 0x1 << 20 | 0xf << 12 | 0xf00;
        break;
      case 2:
        Led_data2 = 0x0 << 20 | 0xf << 12 | 0xf;
        break;
      case 3:
        Led_data2 = 0x2 << 20 | 0xf << 12 | 0xf00;
        break;
      case 4:
        Led_data2 = 0x1 << 20 | 0xf << 12 | 0xf;
        break;
      case 5:
        Led_data2 = 0x0 << 20 | 0xf << 12 | 0xf0;
        break;
      case 6:
        Led_data2 = 0x2 << 20 | 0xf << 12 | 0xf;
        break;
      case 7:
        Led_data2 = 0x1 << 20 | 0xf << 12 | 0xf0;
        break;
      case 8:
        Led_data2 = 0x0 << 20 | 0xf << 12 | 0xf00;
        break;
      }
      next_state2 = INTERVAL;
      TIM_Cmd(TIM16, ENABLE);
      i2++;
      if(i2>8) i2 = 0;
        
    }
    //*/
    
    // LED5
    //*
    if(! (TIM17->CR1 & TIM_CR1_CEN)){
      //Delay(50);
      switch(i3)
      {
      case 0:
        Led_data3 = 0x2 << 20 | 0xf << 12 | 0xf0;
        break;
      case 1:
        Led_data3 = 0x1 << 20 | 0xf << 12 | 0xf00;
        break;
      case 2:
        Led_data3 = 0x0 << 20 | 0xf << 12 | 0xf;
        break;
      case 3:
        Led_data3 = 0x2 << 20 | 0xf << 12 | 0xf00;
        break;
      case 4:
        Led_data3 = 0x1 << 20 | 0xf << 12 | 0xf;
        break;
      case 5:
        Led_data3 = 0x0 << 20 | 0xf << 12 | 0xf0;
        break;
      case 6:
        Led_data3 = 0x2 << 20 | 0xf << 12 | 0xf;
        break;
      case 7:
        Led_data3 = 0x1 << 20 | 0xf << 12 | 0xf0;
        break;
      case 8:
        Led_data3 = 0x0 << 20 | 0xf << 12 | 0xf00;
        break;
      }
      next_state3 = INTERVAL;
      TIM_Cmd(TIM17, ENABLE);
      i3++;
      if(i3>8) i3 = 0;
        
    }
    //*/ 
}

//////////////////////////////////////////////////////////////////////////////
// Breathing LED
void BreathingLed()
{    
#define brightness_step 5
#define brightness_max_val 250
#define brightness_min_val 5    
 
    Delay(10);
    if(!(TIM3->CR1 & TIM_CR1_CEN)){
      Led_data = 0x03f << 20 | i << 12; 
      next_state = INTERVAL;
      TIM_Cmd(TIM3, ENABLE);
      i = i + j;
      if(i > brightness_max_val) j = -brightness_step;
      if(i < brightness_min_val) j = brightness_step;
    }        
    
    if(!(TIM16->CR1 & TIM_CR1_CEN)){
      Led_data2 = 0x03f << 20 | i2 << 12; 
      next_state2 = INTERVAL;
      TIM_Cmd(TIM16, ENABLE);
      i2 = i2 + j2;
      if(i2 > brightness_max_val) j2 = -brightness_step;
      if(i2 < brightness_min_val) j2 = brightness_step;
    }        

    if(!(TIM17->CR1 & TIM_CR1_CEN)){
      Led_data3 = 0x03f << 20 | i3 << 12; 
      next_state3 = INTERVAL;
      TIM_Cmd(TIM17, ENABLE);
      i3 = i3 + j3;
      if(i3 > brightness_max_val) j3 = -brightness_step;
      if(i3 < brightness_min_val) {
        j3 = brightness_step;
        if(j3 < 0)
          ChangeLEDColor((250-i3)*10);
        else
          ChangeLEDColor((250-i3));
      }
    }           
}


int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f0xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f0xx.c file
     */
  
  if (SysTick_Config(SystemCoreClock / 1000))
  { 
    // Capture error 
    while (1);
  }  
  
  /* Initialize Leds mounted on STM32F030-Discovery */
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);
  STM_EVAL_LEDInit(LED5);
    
  TIM_Config();
  
  LEDStripe_init();

  /* Infinite loop */

  while(1)
  {
    //MarqueeLed();
    BreathingLed();
    
    /*
    Delay(2);
    if(! (TIM3->CR1 & TIM_CR1_CEN)){
      if(i > 2){
        i = 0;
        if(j == 0)
          Led_data = 0xf00;
        else if (j == 1)
          Led_data = 0x0f0;
        else if (j == 2)
          Led_data = 0xf;
        if(j++ > 2) j = 0;
      }

      Led_data = i << 20 | 0xf << 12 | (Led_data & 0xfff);
      next_state = INTERVAL;
      TIM_Cmd(TIM3, ENABLE);
      i++;
        
    }
    //*/

    
    /*
    if(! (TIM3->CR1 & TIM_CR1_CEN)){
      if(i==0){
        Led_data = 0x0 << 20 | 0xf << 12;// | 0xf << 8 | 0x0 << 4 | 0x0; 
      }
      else if(i==1) {
        Led_data = 0x1 << 20 | 0xf << 12;// | 0x0 << 8 | 0xf << 4 | 0x0; 
      }
      else if (i==2){
        Led_data = 0x2 << 20 | 0xf << 12;// | 0x0 << 8 | 0x0 << 4 | 0xf; 
      }
      Led_data = Led_data | 0xf << j;
      i = i + 1;
      if(j<8) j = j + 4;
      if(j>8) j = j - 4;
      if(i > 2) i = 0;
      next_state = INTERVAL;
      TIM_Cmd(TIM3, ENABLE);
    }
    Delay(100);
    //*/
  }
}

/**
  * @brief  Configure the TIM IRQ Handler.
  * @param  None
  * @retval None
  */
static void TIM_Config(void)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;

  /* TIM3 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

  /* Enable the TIM3 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
  /* -----------------------------------------------------------------------
    TIM3 Configuration: Output Compare Timing Mode:
    
    In this example TIM3 input clock (TIM3CLK) is set to APB1 clock (PCLK1),  
      => TIM3CLK = PCLK1 = SystemCoreClock = 48 MHz
          
    To get TIM3 counter clock at 6 MHz, the prescaler is computed as follows:
       Prescaler = (TIM3CLK / TIM3 counter clock) - 1
       Prescaler = (PCLK1 /6 MHz) - 1
                                                  
    CC3 update rate = TIM3 counter clock / CCR3_Val = 439.4 Hz
    ==> Toggling frequency = 219.7 Hz
    
    CC4 update rate = TIM3 counter clock / CCR4_Val = 878.9 Hz
    ==> Toggling frequency = 439.4 Hz

    Note: 
     SystemCoreClock variable holds HCLK frequency and is defined in system_stm32f2xx.c file.
     Each time the core clock (HCLK) changes, user had to call SystemCoreClockUpdate()
     function to update SystemCoreClock variable value. Otherwise, any configuration
     based on this variable will be incorrect.    
  ----------------------------------------------------------------------- */   

  /* Compute the prescaler value */
  PrescalerValue = (uint16_t) (SystemCoreClock  / 6000000) - 1;

  /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Period = 65535;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

  /* Prescaler configuration */
  TIM_PrescalerConfig(TIM3, PrescalerValue, TIM_PSCReloadMode_Immediate);

  /* Output Compare Timing Mode configuration: Channel1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

  /* Output Compare Timing Mode configuration: Channel3 */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR3_Val;

  TIM_OC3Init(TIM3, &TIM_OCInitStructure);

  TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Disable);
  
  // Output Compare Timing Mode configuration: Channel1
  /*
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR1_Val;
  TIM_OC1Init(TIM3, &TIM_OCInitStructure);
  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Disable);
  //*/
  
    // Output Compare Timing Mode configuration: Channel2
  /*
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR2_Val;
  TIM_OC2Init(TIM3, &TIM_OCInitStructure);
  TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Disable);
  //*/
   
  // TIM Interrupts enable 
  //TIM_ITConfig(TIM3, TIM_IT_CC3 | TIM_IT_CC1 | TIM_IT_CC2, ENABLE);
  

 
  // TIM Channel 3 interrupt enable
  TIM_ITConfig(TIM3, TIM_IT_CC3, ENABLE);

  /* TIM3 enable counter */
  TIM_Cmd(TIM3, ENABLE);
  
///////////////////////////////////////////////////////  
    /* TIM16 clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM16, ENABLE);

  /* Enable the TIM16 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM16_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

    /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Period = 65535;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM16, &TIM_TimeBaseStructure);

  /* Prescaler configuration */
  TIM_PrescalerConfig(TIM16, PrescalerValue, TIM_PSCReloadMode_Immediate);

  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR1_Val;

  TIM_OC1Init(TIM16, &TIM_OCInitStructure);

  TIM_OC1PreloadConfig(TIM16, TIM_OCPreload_Disable);
  
  // TIM Channel 16 interrupt enable
  TIM_ITConfig(TIM16, TIM_IT_CC1, ENABLE);

  /* TIM3 enable counter */
  TIM_Cmd(TIM16, ENABLE);

  
  ///////////////////////////////////////////////////////  
    /* TIM17 clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM17, ENABLE);

  /* Enable the TIM17 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM17_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

    /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Period = 65535;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM17, &TIM_TimeBaseStructure);

  /* Prescaler configuration */
  TIM_PrescalerConfig(TIM17, PrescalerValue, TIM_PSCReloadMode_Immediate);

  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR1_Val;

  TIM_OC1Init(TIM17, &TIM_OCInitStructure);

  TIM_OC1PreloadConfig(TIM17, TIM_OCPreload_Disable);
  
  // TIM Channel 17 interrupt enable
  TIM_ITConfig(TIM17, TIM_IT_CC1, ENABLE);

  /* TIM3 enable counter */
  TIM_Cmd(TIM17, ENABLE);

}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
