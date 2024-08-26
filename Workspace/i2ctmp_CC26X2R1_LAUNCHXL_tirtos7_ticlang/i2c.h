/*
 * i2c.h
 *
 *  Created on: Aug. 23, 2024
 *      Author: NicholasMascioli
 */

#ifndef i2c_H_INCLUDED
#define i2c_H_INCLUDED

#include <ti/drivers/I2C.h>


bool i2c_write(uint8_t address, uint8_t *txBytes,  uint8_t count);
bool i2c_read(uint8_t address, uint8_t *rxBytes, uint8_t count);
bool i2c_init(void);

#endif
