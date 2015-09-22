/**
  ******************************************************************************
  * @file    TIM_Time_Base/stm32f0xx_it.c 
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    11-October-2013
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
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
#include "stm32f0xx_it.h"

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

extern __IO uint16_t CCR1_Val;
extern __IO uint16_t CCR2_Val;
extern __IO uint16_t CCR3_Val;

uint16_t capture = 0;

uint16_t data[][29]={
                  1,
                  0,0,0,0,0,0,
                  0,0,0,1,1,1,1,1,
                  1,1,1,1,
                  0,0,0,0,
                  0,0,0,0,
                  2,2,
                  1,
                  0,0,0,0,0,1,
                  0,0,0,0,1,1,1,1,
                  0,0,0,0,
                  1,1,1,1,                 
                  0,0,0,0,
                  2,2,
                  1,
                  0,0,0,0,1,0,
                  0,0,0,0,1,1,1,1,                 
                  0,0,0,0,                  
                  0,0,0,0,                  
                  1,1,1,1,                  
                  2,2
              };

uint16_t global_data[]={
                  1,
                  1,1,1,1,1,1,
                  1,1,1,1,1,1,1,1,
                  0,0,0,0,
                  0,0,0,0,
                  1,1,1,1,
                  2,2};

uint16_t ManIndex=0;
uint16_t ManCode[3]={0,0,0};
uint16_t DataIndex = 0;
uint16_t LedNo=0;
uint16_t flag=0;
                  
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M0 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  TimingDelay_Decrement();
}

/******************************************************************************/
/*                 STM32F0xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f0x8.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles TIM3 global interrupt request.
  * @param  None
  * @retval None
  */
enum STATE{NONE = 0, INTERVAL, START1, START2, DATA1, DATA2};
enum STATE next_state = NONE;
uint32_t Led_data = 0x0 << 20 | 0xf << 12 | 0x0 << 8 | 0x0 << 4 | 0xf;
uint32_t index = 0;

enum STATE next_state2 = NONE;
uint32_t Led_data2 = 0x0 << 20 | 0xf << 12 | 0x0 << 8 | 0x0 << 4 | 0xf;
uint32_t index2 = 0;

enum STATE next_state3 = NONE;
uint32_t Led_data3 = 0x0 << 20 | 0xf << 12 | 0x0 << 8 | 0x0 << 4 | 0xf;
uint32_t index3 = 0;
uint32_t reg = 0;

void TIM16_IRQHandler(void)
{
  /*
  if (TIM_GetITStatus(TIM16, TIM_IT_CC1) != RESET){
    TIM_ClearITPendingBit(TIM16, TIM_IT_CC1);
    capture = TIM_GetCapture1(TIM16);
    TIM_SetCompare1(TIM16, capture + CCR1_Val);
    STM_EVAL_LEDToggle(LED4);
  }
  */
  
  
    if (TIM_GetITStatus(TIM16, TIM_IT_CC1) != RESET){
      TIM_ClearITPendingBit(TIM16, TIM_IT_CC1);
      capture = TIM_GetCapture1(TIM16);             
      
      switch(next_state2)
      {
      case INTERVAL:
        TIM_SetCompare1(TIM16, capture + CCR1_Val * 5);
        STM_EVAL_LEDOff(LED4);
        next_state2 = START1;
        break;
      case START1:
        TIM_SetCompare1(TIM16, capture + CCR1_Val * 2);
        STM_EVAL_LEDOff(LED4);       
        next_state2 = START2;
        break;
      case START2:
        TIM_SetCompare1(TIM16, capture + CCR1_Val);
        STM_EVAL_LEDOn(LED4);               
        next_state2 = DATA1;
        index2 = 0x1 << 25;
        break;
      case DATA1:
        if(Led_data2 & index2){        
          TIM_SetCompare1(TIM16, capture + CCR1_Val * 2);
          STM_EVAL_LEDOff(LED4);
        }
        else
        {
          TIM_SetCompare1(TIM16, capture + CCR1_Val);
          STM_EVAL_LEDOff(LED4);          
        }                   
        next_state2 = DATA2;
        break;
      case DATA2:
        if(Led_data2 & index2){        
          TIM_SetCompare1(TIM16, capture + CCR1_Val);
          STM_EVAL_LEDOn(LED4);
        }
        else
        {
          TIM_SetCompare1(TIM16, capture + CCR1_Val*2);
          STM_EVAL_LEDOn(LED4);          
        }                           
        index2 = index2 >> 1;
        if(index2 == 0){
          next_state2 = NONE;
//          TIM_Cmd(TIM16, DISABLE);
        }
        else
          next_state2 = DATA1;
        break;        
      case NONE:
          STM_EVAL_LEDOff(LED4);
          TIM_Cmd(TIM16, DISABLE);
        break;         
      }        

  }

}

void TIM17_IRQHandler(void)
{
  /*
  if (TIM_GetITStatus(TIM17, TIM_IT_CC1) != RESET){
    TIM_ClearITPendingBit(TIM17, TIM_IT_CC1);
    capture = TIM_GetCapture1(TIM17);
    TIM_SetCompare1(TIM17, capture + CCR1_Val);
    STM_EVAL_LEDToggle(LED5);
  }
  */
  
    if (TIM_GetITStatus(TIM17, TIM_IT_CC1) != RESET){
      TIM_ClearITPendingBit(TIM17, TIM_IT_CC1);
      capture = TIM_GetCapture1(TIM17);         
      
      //STM_EVAL_LEDToggle(LED5);
      //TIM_SetCompare2(TIM17, capture + CCR1_Val);
      
      switch(next_state3)
      {
      case INTERVAL:
        TIM_SetCompare1(TIM17, capture + CCR1_Val * 5);
        STM_EVAL_LEDOff(LED5);
        next_state3 = START1;
        break;
      case START1:
        TIM_SetCompare1(TIM17, capture + CCR1_Val * 2);
        STM_EVAL_LEDOff(LED5);       
        next_state3 = START2;
        break;
      case START2:
        TIM_SetCompare1(TIM17, capture + CCR1_Val);
        STM_EVAL_LEDOn(LED5);               
        next_state3 = DATA1;
        index3 = 0x1 << 25;
        break;
      case DATA1:
        if(Led_data3 & index3){        
          TIM_SetCompare1(TIM17, capture + CCR1_Val * 2);
          STM_EVAL_LEDOff(LED5);
        }
        else
        {
          TIM_SetCompare1(TIM17, capture + CCR1_Val);
          STM_EVAL_LEDOff(LED5);          
        }                   
        next_state3 = DATA2;
        break;
      case DATA2:
        if(Led_data3 & index3){        
          TIM_SetCompare1(TIM17, capture + CCR1_Val);
          STM_EVAL_LEDOn(LED5);
        }
        else
        {
          TIM_SetCompare1(TIM17, capture + CCR1_Val*2);
          STM_EVAL_LEDOn(LED5);          
        }                           
        index3 = index3 >> 1;
        if(index3 == 0){
          next_state3 = NONE;
//          TIM_Cmd(TIM17, DISABLE);
        }
        else
          next_state3 = DATA1;
        break;        
      case NONE:
          STM_EVAL_LEDOff(LED5);
          TIM_Cmd(TIM17, DISABLE);
        break;         
      }        

  }

}

void TIM3_IRQHandler(void)
{ 

  if (TIM_GetITStatus(TIM3, TIM_IT_CC3) != RESET){
      TIM_ClearITPendingBit(TIM3, TIM_IT_CC3);
      capture = TIM_GetCapture3(TIM3);
      
      switch(next_state)
      {
      case INTERVAL:
        TIM_SetCompare3(TIM3, capture + CCR3_Val * 5);
        STM_EVAL_LEDOff(LED3);
        next_state = START1;
        break;
      case START1:
        TIM_SetCompare3(TIM3, capture + CCR3_Val * 2);
        STM_EVAL_LEDOff(LED3);       
        next_state = START2;
        break;
      case START2:
        TIM_SetCompare3(TIM3, capture + CCR3_Val);
        STM_EVAL_LEDOn(LED3);               
        next_state = DATA1;
        index = 0x1 << 25;
        break;
      case DATA1:
        if(Led_data & index){        
          TIM_SetCompare3(TIM3, capture + CCR3_Val * 2);
          STM_EVAL_LEDOff(LED3);
        }
        else
        {
          TIM_SetCompare3(TIM3, capture + CCR3_Val);
          STM_EVAL_LEDOff(LED3);          
        }                   
        next_state = DATA2;
        break;
      case DATA2:
        if(Led_data & index){        
          TIM_SetCompare3(TIM3, capture + CCR3_Val);
          STM_EVAL_LEDOn(LED3);
        }
        else
        {
          TIM_SetCompare3(TIM3, capture + CCR3_Val*2);
          STM_EVAL_LEDOn(LED3);          
        }                           
        index = index >> 1;
        if(index == 0){
          next_state = NONE;
//          TIM_Cmd(TIM3, DISABLE);
        }
        else
          next_state = DATA1;
        break;        
      case NONE:
          STM_EVAL_LEDOff(LED3);
          TIM_Cmd(TIM3, DISABLE);
        break;         
      }        
  }
    
  /*
  if (TIM_GetITStatus(TIM3, TIM_IT_CC3) != RESET)
  {
      TIM_ClearITPendingBit(TIM3, TIM_IT_CC3);

      // LED3 toggling with frequency = 219.7 Hz
      //STM_EVAL_LEDToggle(LED3);
      capture = TIM_GetCapture3(TIM3);
      if(flag ==1){
        TIM_SetCompare3(TIM3, capture + CCR3_Val);
        flag = 0;
      }
      else
      {
          TIM_SetCompare3(TIM3, capture + CCR3_Val * 2);
          flag = 1;          
      }
      
      STM_EVAL_LEDToggle(LED3);
     
      
      if(LedNo >= 3){
        ManIndex = 0;
        DataIndex = 0;
        return;
      }
   
      
      if(ManIndex >=3){
          ManIndex = 0;
          DataIndex = DataIndex + 1;        
      } 
      
      if(DataIndex == 29){
        DataIndex = 0;
        LedNo = LedNo + 1;
      }      
       
      if(LedNo < 3){
        if(data[LedNo][DataIndex] ==0){
            ManCode[0] = 0;
            ManCode[1] = 1;
            ManCode[2] = 1;
        }else if(data[LedNo][DataIndex] ==1) {
            ManCode[0] = 0;
            ManCode[1] = 0;
            ManCode[2] = 1;
        }else{
            ManCode[0] = 0;
            ManCode[1] = 0;
            ManCode[2] = 0;      
        }
       }
       else
       {
        if (LedNo > 255) LedNo = 3;
        if(global_data[DataIndex] ==0){
            ManCode[0] = 0;
            ManCode[1] = 1;
            ManCode[2] = 1;
        }else if(global_data[DataIndex] ==1) {
            ManCode[0] = 0;
            ManCode[1] = 0;
            ManCode[2] = 1;
        }else{
            ManCode[0] = 0;
            ManCode[1] = 0;
            ManCode[2] = 0;      
        }
          
       }
      
      if(ManCode[ManIndex] == 1)
            STM_EVAL_LEDOn(LED3);
      else
            STM_EVAL_LEDOff(LED3);
      
      ManIndex = ManIndex + 1;          
  }
  */
}

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
