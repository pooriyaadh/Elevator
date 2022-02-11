/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f0xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define STOP_DOWN_Pin GPIO_PIN_13
#define STOP_DOWN_GPIO_Port GPIOC
#define DOOR_DOWN_Pin GPIO_PIN_14
#define DOOR_DOWN_GPIO_Port GPIOC
#define US_DOWN_Pin GPIO_PIN_15
#define US_DOWN_GPIO_Port GPIOC
#define Relay_UP_Door_Pin GPIO_PIN_0
#define Relay_UP_Door_GPIO_Port GPIOF
#define IN_NO5_Pin GPIO_PIN_1
#define IN_NO5_GPIO_Port GPIOF
#define IN_NO6_Pin GPIO_PIN_0
#define IN_NO6_GPIO_Port GPIOA
#define STOP_2_Pin GPIO_PIN_1
#define STOP_2_GPIO_Port GPIOA
#define STOP_UP_Pin GPIO_PIN_2
#define STOP_UP_GPIO_Port GPIOA
#define STOP_1_Pin GPIO_PIN_3
#define STOP_1_GPIO_Port GPIOA
#define START_DOWN_1_Pin GPIO_PIN_4
#define START_DOWN_1_GPIO_Port GPIOA
#define Relay_Down_Door_Pin GPIO_PIN_5
#define Relay_Down_Door_GPIO_Port GPIOA
#define Relay_Other_Pin GPIO_PIN_6
#define Relay_Other_GPIO_Port GPIOA
#define START_UP_1_Pin GPIO_PIN_7
#define START_UP_1_GPIO_Port GPIOA
#define START_UP_2_Pin GPIO_PIN_0
#define START_UP_2_GPIO_Port GPIOB
#define US_UP_Pin GPIO_PIN_1
#define US_UP_GPIO_Port GPIOB
#define IN_NO7_Pin GPIO_PIN_2
#define IN_NO7_GPIO_Port GPIOB
#define START_DOWN_2_Pin GPIO_PIN_10
#define START_DOWN_2_GPIO_Port GPIOB
#define IN_NO8_Pin GPIO_PIN_11
#define IN_NO8_GPIO_Port GPIOB
#define DOOR_UP_Pin GPIO_PIN_12
#define DOOR_UP_GPIO_Port GPIOB
#define Relay_UP_Pin GPIO_PIN_13
#define Relay_UP_GPIO_Port GPIOB
#define Relay_DOWN_Pin GPIO_PIN_14
#define Relay_DOWN_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
