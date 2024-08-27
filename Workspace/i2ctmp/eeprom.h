/*
 * eeprom.h
 *
 *  Created on: Aug. 23, 2024
 *      Author: NicholasMascioli
 */

#ifndef EEPROM_H_
#define EEPROM_H_

#include "ti_drivers_config.h"


#define EEPROM_TYPE_ID          0xA0
#define EEPROM_ADR_MASK         0x3FFFF
#define EEPROM_BYTE_MASK        0xFF

#define EEPROM_WRITE            0x00
#define EEPROM_READ             0x01

bool eeprom_write_byte          (uint32_t address, uint8_t byte);
bool eeprom_write_page          (uint16_t page, uint8_t address, uint8_t byte[], uint8_t size);

bool eeprom_read_current        (uint8_t *byte );
bool eeprom_read_byte           (uint32_t address, uint8_t *byte);
bool eeprom_read_sequential     (uint32_t address, uint8_t *byte, uint32_t size);

bool eeprom_clear_byte          (uint32_t address);
bool eeprom_clear_page          (uint16_t page, uint8_t address, uint8_t size);
bool eeprom_clear_all           (void);


#endif /* EEPROM_H_ */
