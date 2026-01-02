/* motordriver.h */
#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include "stm32f4xx_hal.h"
#include <stdint.h>

/*
  Bu değerler SENİN timer kurulumuna göre:
  TIM tick = 84MHz / 200 = 420 kHz
  20ms period => 8400 count -> ARR = 8399
  1.0ms pulse => 420
  2.0ms pulse => 840
*/
#define SERVO_ARR_50HZ      (8399U)
#define SERVO_MIN_PULSE     (250U)   // 1.0ms
#define SERVO_MAX_PULSE     (1000U)   // 2.0ms

HAL_StatusTypeDef MotorDriver_Init(TIM_HandleTypeDef *htim, uint32_t channel);
void MotorDriver_SetAngle(TIM_HandleTypeDef *htim, uint32_t channel, uint16_t angle);
void MotorDriver_SetPulse(TIM_HandleTypeDef *htim, uint32_t channel, uint16_t pulse);
uint16_t ADC_ToAngle_0_180(uint16_t adc);
#endif /* MOTORDRIVER_H */
