/*
 * eeprom.c
 *
 *  Created on: Aug. 23, 2024
 *      Author: NicholasMascioli
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <ti/drivers/GPIO.h>
#include <ti/display/Display.h>

#include "eeprom.h"
#include "i2c.h"
#include <ti/sysbios/knl/Task.h>


bool eeprom_write_byte(uint32_t address, uint8_t byte )
{
    bool flag;
    uint8_t *tx_data = (uint8_t*)malloc(3 * sizeof(uint8_t));

    address = address & EEPROM_ADR_MASK;

    uint8_t adr = EEPROM_TYPE_ID | ((address >> 16) << 1) | EEPROM_WRITE;

    tx_data[0]  = (address >> 8)    & EEPROM_BYTE_MASK;
    tx_data[1]  = address           & EEPROM_BYTE_MASK;
    tx_data[2]  = byte;

    flag = i2c_write(adr, tx_data, 3);

    free(tx_data);

    return flag;
}

bool eeprom_write_page(uint16_t page, uint8_t address, uint8_t byte[], uint8_t size )
{
    bool flag;
    uint8_t *tx_data = (uint8_t*)malloc((size+2) * sizeof(uint8_t));

    uint32_t merge_ADR = page*256+address;

    merge_ADR = merge_ADR & EEPROM_ADR_MASK;

    uint8_t adr = EEPROM_TYPE_ID | ((merge_ADR >> 16) << 1) | EEPROM_WRITE;

    tx_data[0]  = (merge_ADR >> 8)    & EEPROM_BYTE_MASK;
    tx_data[1]  = merge_ADR           & EEPROM_BYTE_MASK;

    for(int i=0;i<size;i++){
        tx_data[i+2] = byte[i];
    }

    flag = i2c_write(adr, tx_data, size+2);

    free(tx_data);

    return flag;
}

bool eeprom_read_current(uint8_t *byte )
{
    bool flag;
    uint8_t *tx_data = (uint8_t*)malloc(1 * sizeof(uint8_t));
    uint8_t *rx_data = (uint8_t*)malloc(1 * sizeof(uint8_t));

    uint8_t adr = EEPROM_TYPE_ID |  EEPROM_READ;

    flag = i2c_read(adr, tx_data, rx_data, 0, 1);

    *byte= rx_data[0];

    free(tx_data);
    free(rx_data);

    return flag;
}

bool eeprom_read_byte(uint32_t address, uint8_t *byte )
{
    bool flag;
    uint8_t *tx_data = (uint8_t*)malloc(2 * sizeof(uint8_t));

    address = address & EEPROM_ADR_MASK;

    uint8_t adr = EEPROM_TYPE_ID | ((address >> 16) << 1) | EEPROM_WRITE;

    tx_data[0]  = (address >> 8)    & EEPROM_BYTE_MASK;
    tx_data[1]  = address           & EEPROM_BYTE_MASK;

    flag = i2c_write(adr, tx_data, 2);
    free(tx_data);

    flag=eeprom_read_current(byte);

    return flag;
}

bool eeprom_read_sequential(uint32_t address, uint8_t *byte, uint32_t size )
{
    bool flag;
    uint8_t *tx_data = (uint8_t*)malloc(2 * sizeof(uint8_t));

    address = address & EEPROM_ADR_MASK;

    uint8_t adr = EEPROM_TYPE_ID | ((address >> 16) << 1) | EEPROM_WRITE;

    tx_data[0]  = (address >> 8)    & EEPROM_BYTE_MASK;
    tx_data[1]  = address           & EEPROM_BYTE_MASK;

    flag = i2c_write(adr, tx_data, 2);
    free(tx_data);


    uint8_t *tx_data1 = (uint8_t*)malloc(1 * sizeof(uint8_t));
    uint8_t *rx_data1 = (uint8_t*)malloc(size * sizeof(uint8_t));

    uint8_t adr1 = EEPROM_TYPE_ID |  EEPROM_READ;

    flag |= i2c_read(adr1, tx_data1, rx_data1, 0, size);

    for(int i=0;i<size;i++){
        byte[i]= rx_data1[i];
    }

    free(tx_data1);
    free(rx_data1);

    return flag;
}

bool eeprom_clear_byte(uint32_t address)
{
    bool flag;

    flag = eeprom_write_byte(address,0);

    return flag;
}

bool eeprom_clear_page(uint16_t page)
{
    bool flag;

    uint8_t *tx_data = (uint8_t*)malloc(256 * sizeof(uint8_t));
    memset(tx_data, 0, 256 * sizeof(uint8_t));

    flag = eeprom_write_page(page,0,tx_data,255);

    return false;
}

bool eeprom_clear_all(void)
{
    bool flag;

    for(int i = 0;i < 1023;i++){
        flag |= eeprom_clear_page(i);
    }

    return false;
}










