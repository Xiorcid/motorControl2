#include "main.h"
#include "six_step.h"

extern TIM_HandleTypeDef htim1;

void MC_DisablePWM(void){
	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);
}

void MC_EnablePWM(void){
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
}

void MC_InitPWM(void){
    TIM1->CCR1 = 0;
    TIM1->CCR2 = 0;
    TIM1->CCR3 = 0;
    TIM1->CCR4 = 1;

    
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
    HAL_TIM_Base_Start_IT(&htim1);
}

void MC_LoadStep(uint8_t step){
    switch (step) {
        case 4:
            // Z L H
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
            HAL_GPIO_WritePin(PH1L_GPIO_Port, PH1L_Pin, GPIO_PIN_SET);
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
            HAL_GPIO_WritePin(PH2L_GPIO_Port, PH2L_Pin, GPIO_PIN_RESET);
            HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
            HAL_GPIO_WritePin(PH3L_GPIO_Port, PH3L_Pin, GPIO_PIN_SET);
            break;
        case 5:
            // H L Z
            HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
            HAL_GPIO_WritePin(PH1L_GPIO_Port, PH1L_Pin, GPIO_PIN_SET);
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
            HAL_GPIO_WritePin(PH2L_GPIO_Port, PH2L_Pin, GPIO_PIN_RESET);
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);
            HAL_GPIO_WritePin(PH3L_GPIO_Port, PH3L_Pin, GPIO_PIN_SET);
            break;
        case 1:
            // H Z L
            HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
            HAL_GPIO_WritePin(PH1L_GPIO_Port, PH1L_Pin, GPIO_PIN_SET);
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
            HAL_GPIO_WritePin(PH2L_GPIO_Port, PH2L_Pin, GPIO_PIN_SET);
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);
            HAL_GPIO_WritePin(PH3L_GPIO_Port, PH3L_Pin, GPIO_PIN_RESET);
            break;
        case 3:
            // Z H L
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
            HAL_GPIO_WritePin(PH1L_GPIO_Port, PH1L_Pin, GPIO_PIN_SET);
            HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
            HAL_GPIO_WritePin(PH2L_GPIO_Port, PH2L_Pin, GPIO_PIN_SET);
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);
            HAL_GPIO_WritePin(PH3L_GPIO_Port, PH3L_Pin, GPIO_PIN_RESET);
            break;
        case 2:
            // L H Z
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
            HAL_GPIO_WritePin(PH1L_GPIO_Port, PH1L_Pin, GPIO_PIN_RESET);
            HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
            HAL_GPIO_WritePin(PH2L_GPIO_Port, PH2L_Pin, GPIO_PIN_SET);
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);
            HAL_GPIO_WritePin(PH3L_GPIO_Port, PH3L_Pin, GPIO_PIN_SET);
            break;
        case 6:
            // L Z H
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
            HAL_GPIO_WritePin(PH1L_GPIO_Port, PH1L_Pin, GPIO_PIN_RESET);
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
            HAL_GPIO_WritePin(PH2L_GPIO_Port, PH2L_Pin, GPIO_PIN_SET);
            HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
            HAL_GPIO_WritePin(PH3L_GPIO_Port, PH3L_Pin, GPIO_PIN_SET);
            break;
        default:
            break;
    }
}

void MC_SetDuty(uint16_t DutyCycle){
	TIM1->CCR1 = DutyCycle;
	TIM1->CCR2 = DutyCycle;
	TIM1->CCR3 = DutyCycle;
}