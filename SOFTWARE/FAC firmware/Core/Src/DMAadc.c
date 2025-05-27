/*
 * DMAadc.c
 *
 *  Created on: May 28, 2025
 *      Author: Paolo
 *
 */

#include "DMAadc.h"
extern ADC_HandleTypeDef hadc;
uint16_t adcChannels[3];
uint16_t battValue = 0;
uint16_t pot1Value = 0;
uint16_t pot2Value = 0;

void initDMAadc(){
	HAL_ADCEx_Calibration_Start(&hadc);
	HAL_Delay(50);
	HAL_ADC_Start_DMA(&hadc, (uint32_t*) adcChannels, 3);
}

void DMAadcUpdate(){
	HAL_ADC_Start_DMA(&hadc, (uint32_t*) adcChannels, 3);
}

uint16_t DMAadcGetch(uint8_t ch){
	return adcChannels[ch];
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
	//uint8_t string[30];
	//sprintf(string, "x =  %d\n", adcChannels[1] );
	//serialPrintString(string);
	battValue = adcChannels[0];
	pot1Value = adcChannels[1];
	pot2Value = adcChannels[2];
}
