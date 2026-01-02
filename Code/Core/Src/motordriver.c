/* motordriver.c */
#include "motordriver.h"

static uint16_t clamp_u16(uint16_t v, uint16_t lo, uint16_t hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

HAL_StatusTypeDef MotorDriver_Init(TIM_HandleTypeDef *htim, uint32_t channel)
{
    if (htim == NULL) return HAL_ERROR;

    // PWM başlat
    if (HAL_TIM_PWM_Start(htim, channel) != HAL_OK)
        return HAL_ERROR;

    // Servo sinyalsiz kalmasın diye ilk açıyı ver
    MotorDriver_SetAngle(htim, channel, 90);
    return HAL_OK;
}

void MotorDriver_SetPulse(TIM_HandleTypeDef *htim, uint32_t channel, uint16_t pulse)
{
    if (htim == NULL) return;

    // Güvenli aralık
    pulse = clamp_u16(pulse, SERVO_MIN_PULSE, SERVO_MAX_PULSE);

    __HAL_TIM_SET_COMPARE(htim, channel, pulse);
}

void MotorDriver_SetAngle(TIM_HandleTypeDef *htim, uint32_t channel, uint16_t angle)
{
    if (htim == NULL) return;

    if (angle > 180U) angle = 180U;

    // 0..180 -> MIN..MAX lineer map
    uint32_t pulse = SERVO_MIN_PULSE +
        ((uint32_t)angle * (SERVO_MAX_PULSE - SERVO_MIN_PULSE)) / 180U;

    __HAL_TIM_SET_COMPARE(htim, channel, (uint16_t)pulse);
}

uint16_t ADC_ToAngle_0_180(uint16_t adc)
{
    // 12-bit ADC: 0..4095 (4096 değer)
    if (adc > 4095U) adc = 4095U;

    // 0..4095  ->  0..180 (yuvarlamalı)
    // angle = round(adc * 180 / 4095)
    return (uint16_t)(((uint32_t)adc * 180U + 2047U) / 4095U);
}
