/**
 ********************************************************************************
 * @file    :LPS25HB.h
 * @author  :Vytautas Daunoras
 * @date    :2022-10-20
 ********************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Adresai -------------------------------------------------------------------*/
#define LPS25HB_ADDRESS 		0x5C << 1 		//Note that SA0 = 0 so address is 1011101 and not 1011100
#define LPS25HB_DEVICE_ID 		0xBD 			//Device ID, the value in the WHO_AM_I 	Register
/* Registrai -----------------------------------------------------------------*/
#define LPS25HB_WHO_AM_I 		0x0F 			//Who am I register location
#define LPS25HB_STATUS_REG 		0x27 			//Tells whether the Pressure Data is ready or is being overrun
#define LPS25HB_TEMP_OUT_L 		0x2B 			// Temperature output value (LSB)
#define LPS25HB_TEMP_OUT_H 		0x2C 			// Temperature output value (MSB)
#define LPS25HB_CTRL_REG1 		0x20 			//Contains PD, BDU and more
#define LPS25HB_CTRL_REG2 		0x21 			//Contains one-shot mode and FIFO settings
#define LPS25HB_RES_CONF 		0x10 			//Pressure and temperature Resolution
#define LPS25HB_PRESS_OUT_H 		0x2A			// Pressure output value (MSB)
#define LPS25HB_PRESS_OUT_L		0x29			// Pressure output value (mid part)
#define LPS25HB_PRESS_OUT_XL		0x28			// Pressure output value (LSB)

/* Private function prototypes -----------------------------------------------*/

uint8_t 	LPS25HB_Initialise(I2C_HandleTypeDef *i2cHandle);
uint8_t   	LPS25HB_Measure_Temperature_IT(I2C_HandleTypeDef *i2cHandle);
uint8_t		LPS25HB_Measure_Pressure_IT(I2C_HandleTypeDef *i2cHandle);
