/*
 * i2c.c
 *
 *  Created on: Aug. 23, 2024
 *      Author: NicholasMascioli
 */
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>

#include <ti/drivers/GPIO.h>
#include "ti_drivers_config.h"
#include <ti/drivers/I2C.h>
#include "i2c.h"

#define PLACER 0
#define WRITE_PROTECT 0


static I2C_Handle i2c = NULL;

static I2C_Handle i2cOpen(void);

bool i2c_init(void){
    I2C_init();

    I2C_Params i2cParams;

    i2cParams.bitRate = I2C_400kHz;
    i2cParams.transferMode = I2C_MODE_BLOCKING;
    i2cParams.transferCallbackFxn = NULL;
    i2cParams.custom = NULL;

    i2c = I2C_open(CONFIG_I2C_TMP, &i2cParams);

    return i2c;
}

bool i2c_write(uint8_t address, uint8_t *txBytes,  uint8_t size){
    I2C_Transaction i2cTransaction;
    bool ret;

    i2cTransaction.targetAddress = address;
    i2cTransaction.writeBuf = txBytes;
    i2cTransaction.writeCount = size;
    i2cTransaction.readBuf = NULL;
    i2cTransaction.readCount = 0;
    i2cTransaction.arg = NULL;

    GPIO_write(WRITE_PROTECT, 0); //Toggle Write Protect pin
    ret = I2C_transfer(i2c, &i2cTransaction);
    GPIO_write(WRITE_PROTECT,1);

    return ret;
}

bool i2c_read(uint8_t address, uint8_t *txBytes, uint8_t *rxBytes, uint8_t write_count, uint8_t read_count){
    I2C_Transaction i2cTransaction;
    bool ret;

    i2cTransaction.targetAddress = address;
    i2cTransaction.writeBuf = txBytes;
    i2cTransaction.writeCount = write_count;
    i2cTransaction.readBuf = rxBytes;
    i2cTransaction.readCount = read_count;
    i2cTransaction.arg = NULL;

    ret = I2C_transfer(i2c, &i2cTransaction);

    return ret;
}

