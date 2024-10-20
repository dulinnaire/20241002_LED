//
// Created by 81301 on 2024/10/2.
//
#include "stm32f4xx.h"
#include "tim.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) {
    if (htim == &htim1) {
        HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin);
        if (HAL_GPIO_ReadPin(LED_G_GPIO_Port, LED_G_Pin) == GPIO_PIN_SET) {
            HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin);
        }
    }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == BUTTON_Pin) {
        HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin);
    }
}
