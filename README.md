# Air Quality Sensor Project

## Overview
This repository contains the implementation of an air quality sensor system using a TI Arm Cortex-M4 MCU. The project includes drivers for an analog dust sensor and a 1-Mb EEPROM, with data communication managed via I2C and UART protocols. 

## Features
- **Analog Dust Sensor**: Measures air quality by detecting dust concentration in the environment.
- **EEPROM Storage**: Stores air quality data with timestamps, allowing for historical data retrieval.
- **I2C Communication**: Interfaces between the MCU and peripherals (dust sensor and EEPROM).
- **UART Communication**: Enables data access via a terminal emulator, with commands to display data for the last hour, day, or the entire lifespan.
- **LED Indicator**: Alerts when dust concentration exceeds 200 PPM, signaling poor air quality.

## Components
- **MCU**: TI Arm Cortex-M4
- **Sensors**: Analog dust sensor
- **Memory**: 1-Mb EEPROM
- **Communication Protocols**: I2C, UART
- **LED**: Indicator for high dust concentration
