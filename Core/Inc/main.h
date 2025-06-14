/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define GASE_Pin GPIO_PIN_0
#define GASE_GPIO_Port GPIOA
#define Start_Stop_BTT_Pin GPIO_PIN_10
#define Start_Stop_BTT_GPIO_Port GPIOB
#define Start_Stop_LED_Pin GPIO_PIN_11
#define Start_Stop_LED_GPIO_Port GPIOB
#define H1_Pin GPIO_PIN_13
#define H1_GPIO_Port GPIOB
#define H2_Pin GPIO_PIN_14
#define H2_GPIO_Port GPIOB
#define H3_Pin GPIO_PIN_15
#define H3_GPIO_Port GPIOB
#define PH1L_Pin GPIO_PIN_7
#define PH1L_GPIO_Port GPIOC
#define PH2L_Pin GPIO_PIN_8
#define PH2L_GPIO_Port GPIOC
#define PH3L_Pin GPIO_PIN_9
#define PH3L_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
