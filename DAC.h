#include "stm32f4xx_hal.h"

int MX_DAC_Init(void);
void set_value_DAC (float value);
uint32_t get_DAC (void);
void start_DAC (void);