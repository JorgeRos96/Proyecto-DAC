/**
  ******************************************************************************
  * @file    Templates/Src/DAC.c
  * @author  MCD Application Team
  * @brief   Fichero de inicialización y cofiguración del DAC. Se conecta el DAC 
	*					 1 canal 1 a la salida analogica de la tarjeta de aplicaciones. 
	*					 
	*					 - Pin canal 1 del DAC1: PA4 (se conecta al pin 18 de la MAB) 
	*						
  * @note    modified by ARM
  *          The modifications allow to use this file as User Code Template
  *          within the Device Family Pack.
  ******************************************************************************
  * 
  ******************************************************************************
  */


#include "DAC.h"

DAC_HandleTypeDef hdac;


/**
  * @brief Función de inicialización del canal 1 del DAC 1 (pin PA4)
  * @param None
  * @retval Se devuelve el estado en el que ha finalizado la inicialización
  */
int  MX_DAC_Init(void)
{
  DAC_ChannelConfTypeDef sConfig = {0};
  /** DAC Initialization
  */
  hdac.Instance = DAC;
  if (HAL_DAC_Init(&hdac) != HAL_OK)
  {
    return -1;
  }
  /** DAC channel OUT1 config
  */
  sConfig.DAC_Trigger = DAC_TRIGGER_NONE;
  sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
  if (HAL_DAC_ConfigChannel(&hdac, &sConfig, DAC_CHANNEL_1) != HAL_OK)
  {
    return -1;
  }
	return 0;
}

/**
  * @brief Función de habilitacón del canal 1 del DAC 1 (pin PA4)
  * @param None
  * @retval None
  */
void start_DAC (void){
	HAL_DAC_Start(&hdac, DAC1_CHANNEL_1);
}

/**
  * @brief Función que establece el valor que se pasa por parametro en 
	*				 la salida del DAC 1 
  * @param None
  * @retval None
  */
void set_value_DAC (float value){
	uint32_t var; 

	/*El valor a la salida del DAC (value) que se espera se encuentra entre 0 y 3.3 voltios*/
	var =  value*4096/3.3;
	HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, var);
	
}

/**
  * @brief Función que obtiene el valor del DAC (0 a 4096)
  * @param None
  * @retval Se devuelve el valor del DAC
  */
uint32_t get_DAC (void){
	
	return HAL_DAC_GetValue(&hdac, DAC_CHANNEL_1);
}