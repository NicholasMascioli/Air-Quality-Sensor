/*
 * i2c.c
 *
 *  Created on: Aug. 23, 2024
 *      Author: NicholasMascioli
 */
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <ti/drivers/I2C.h>
#include "i2c.h"

#define placer 0

static I2C_Handle i2c = NULL;

static I2C_Handle i2cOpen(void);

bool i2c_write(uint8_t address, uint8_t *txBytes,  uint8_t count){

}

bool i2c_read(uint8_t address, uint8_t *txBytes,  uint8_t count){

}

bool i2c_init(void){
    I2C_init();
    I2C_Params i2cParams;
    i2cParams.bitRate = I2C_400kHz;


    i2cParams.transferMode = I2C_MODE_BLOCKING;
    i2cParams.transferCallbackFxn = NULL;
    i2cParams.custom = NULL;
    i2c = I2C_open(PLACER, &i2cParams);

    return i2c;
}
