/**
  @page DMA_FLASH_RAM DMA FLASH to RAM example
  
  @verbatim
  ******************** (C) COPYRIGHT 2013 STMicroelectronics *******************
  * @file    DMA_FLASH_RAM/readme.txt 
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    11-October-2013
  * @brief   Description of the DMA FLASH to RAM example.
  ******************************************************************************
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
   @endverbatim

@par Example Description 

This example provides a description of how to use a DMA channel to transfer 
a word data buffer from FLASH memory to embedded SRAM memory.

DMA1 Channel1 is configured to transfer the contents of a 32-word data buffer
stored in Flash memory to the reception buffer declared in RAM.

The start of transfer is triggered by software. DMA1 Channel1 memory-to-memory
transfer is enabled. Source and destination addresses incrementing is also enabled.
The transfer is started by setting the Channel enable bit for DMA1 Channel1.
At the end of the transfer, a Transfer Complete interrupt is generated since it
is enabled. Once interrupt is generated, the remaining data to be transferred is
read which must be equal to 0. The Transfer Complete Interrupt pending bit is
then cleared. A comparison between the source and destination buffers is done to
check that all data have been correctly transferred.
 

@par Directory contents 

  - DMA_FLASH_RAM/stm32f0xx_conf.h    Library Configuration file
  - DMA_FLASH_RAM/stm32f0xx_it.c      Interrupt handlers
  - DMA_FLASH_RAM/stm32f0xx_it.h      Interrupt handlers header file
  - DMA_FLASH_RAM/main.c              Main program
  - DMA_FLASH_RAM/system_stm32f0xx.c  STM32F0xx system source file
  
@note The "system_stm32f0xx.c" file contains the system clock configuration for
      STM32F0xx devices, and is customized for use with STM32F0308-DISCO Kit. 
      The STM32F0xx is configured to run at 48 MHz, following the three  
      configuration below:
        + PLL_SOURCE_HSI
           - HSI (~8 MHz) used to clock the PLL, and the PLL is used as system 
             clock source.  
        + PLL_SOURCE_HSE          
           - HSE (8 MHz) used to clock the PLL, and the PLL is used as system
             clock source.
           - The HSE crystal is not provided with the Discovery Kit, some 
             hardware modification are needed in manner to connect this crystal.
             For more details, refer to section "4.7 OSC clock" in "STM32F030 Value Line
             discovery kit User manual (UM1658)"
        + PLL_SOURCE_HSE_BYPASS   
           - HSE bypassed with an external clock (fixed at 8 MHz, coming from 
             ST-Link circuit) used to clock the PLL, and the PLL is used as 
             system clock source.
           - Some  hardware modification are needed in manner to bypass the HSE 
             with clock coming from the ST-Link circuit.
             For more details, refer to section "4.7 OSC clock" in "STM32F030 Value Line
             discovery kit User manual (UM1658)"
      User can select one of the three configuration in system_stm32f0xx.c file
      (default configuration is PLL_SOURCE_HSI).
         
@par Hardware and Software environment

  - This example runs on STM32F030x Devices.
  
  - This example has been tested with STMicroelectronics STM32F0308-DISCO (MB1134) 
    RevA and can be easily tailored to any other supported device and development board.
    
@par How to use it ? 

In order to make the program work, you must do the following :

 + EWARM
    - Open the DMA_FLASH_RAM.eww workspace 
    - Rebuild all files: Project->Rebuild all
    - Load project image: Project->Debug
    - Run program: Debug->Go(F5)

 + MDK-ARM
    - Open the DMA_FLASH_RAM.uvproj project
    - Rebuild all files: Project->Rebuild all target files
    - Load project image: Debug->Start/Stop Debug Session
    - Run program: Debug->Run (F5)    

 + TrueSTUDIO for ARM
    - Open the TrueSTUDIO for ARM toolchain.
    - Click on File->Switch Workspace->Other and browse to TrueSTUDIO workspace 
      directory.
    - Click on File->Import, select General->'Existing Projects into Workspace' 
      and then click "Next". 
    - Browse to the TrueSTUDIO workspace directory and select the project "DMA_FLASH_RAM" 
    - Rebuild all project files: Select the project in the "Project explorer" 
      window then click on Project->build project menu.
    - Run program: Select the project in the "Project explorer" window then click 
      Run->Debug (F11)

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
