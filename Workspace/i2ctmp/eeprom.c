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
#include <ti/drivers/GPIO.h>
#include <ti/display/Display.h>

#include "eeprom.h"
#include "i2c.h"
#include <ti/sysbios/knl/Task.h>


bool eeprom_write_byte          (uint32_t address, uint8_t byte ){
    return false;
}

bool eeprom_write_page          (uint16_t page, uint8_t address, uint8_t byte[], uint8_t size ){
    return false;
}

bool eeprom_read_current        (uint8_t *byte ){
    return false;
}

bool eeprom_read_byte           (uint32_t address, uint8_t *byte ){
    return false;
}

bool eeprom_read_sequential     (uint32_t address, uint8_t *byte, uint32_t size ){
    return false;
}

bool eeprom_clear_byte          (uint32_t address){
    return false;
}

bool eeprom_clear_page          (uint16_t page, uint8_t address, uint8_t size ){
    return false;
}

bool eeprom_clear_all           (void){
    return false;
}


