/*
 * my_cs43l22.c
 *
 *  Created on: Nov 8, 2023
 *      Author: sebsa
 */


#include "my_cs43L22.h"
#include "stm32f4xx_hal.h"

static uint8_t dataBuffer[2];
static I2C_HandleTypeDef i2cx;
static I2S_HandleTypeDef hi2s3;

static void write_Register(uint8_t registerAddress, uint8_t *data) {
	dataBuffer[0] = registerAddress;
	dataBuffer[1] = dataToSend[0];

	HAL_I2C_Master_Transmit(&i2cx, CS43L22_I2C_ADDRESS, dataBuffer, 2, 100);

}

static void read_Register(uint8_t registerAddress, uint8_t *data) {
	dataBuffer[0] = registerAddress;
	HAL_I2C_Master_Transmit(&i2cx, CS43L22_I2C_ADDRESS, dataBuffer, 1, 100);
	HAL_I2C_Master_Receive(&i2cx, CS43L22_I2C_ADDRESS, data, 1, 100);
}

uint32_t my_cs43L22_Init() {


}

