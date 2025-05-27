/*
 * DMAadc.h
 *
 *  Created on: May 28, 2025
 *      Author: Paolo
 */

#ifndef INC_DMAADC_H_
#define INC_DMAADC_H_
#include "main.h"
#include "stm32f0xx_hal.h"

void initDMAadc();

void DMAadcUpdate();

uint16_t DMAadcGetch(uint8_t ch);

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);

#endif /* INC_DMAADC_H_ */
