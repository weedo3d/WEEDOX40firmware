/**
* WEEDO 71A Motherboad pin configuration
* Copyright (C) 2020 Wiibooxtech Perron
*
*
*/


#ifndef BOARD_NAME
#define BOARD_NAME "WEEDO 73A"
#endif

// X Endstop
#define X_MIN_PIN           PB5
#define X_MAX_PIN           PD7

// Y Endstop
#define Y_MIN_PIN			PB4
#define Y_MAX_PIN			-1

// Z Endstop
#define Z_MIN_PIN			PC13
#define Z_MAX_PIN			PB3

// X Motor
#define X_STEP_PIN          PC2
#define X_DIR_PIN           PC1
#define X_ENABLE_PIN        PC3

// Y Motor
#define Y_STEP_PIN          PE12
#define Y_DIR_PIN           PE11
#define Y_ENABLE_PIN        PE13

// Z Motor
#define Z_STEP_PIN          PE1
#define Z_DIR_PIN           PE0
#define Z_ENABLE_PIN        PE2

// E0 Motor
#define E0_STEP_PIN         PE4
#define E0_DIR_PIN          PE3
#define E0_ENABLE_PIN       PE5

// E1 Motor
#define E1_STEP_PIN         PA6
#define E1_DIR_PIN          PA5
#define E1_ENABLE_PIN       PA7

// E2 / X2 Motor
#define X2_STEP_PIN         PA1
#define X2_DIR_PIN          PA0
#define X2_ENABLE_PIN       PA4

// Extruder0
#define AUTO_FAN0_PIN     PE6
#define HEATER_0_PIN        PC15
#define TEMP_0_PIN          PB0  
#define FAN_PIN            PC14

// Extruder1
#define AUTO_FAN1_PIN     PE7
#define HEATER_1_PIN        PE10
#define TEMP_1_PIN          PC4
#define FAN1_PIN            PE9

// Heater Bed
#define HEATER_BED_PIN		PB12
#define TEMP_BED_PIN        PC5 

// #define TEMP_CHAMBER_PIN    TEMP_BED_PIN
#define CASE_FAN_PIN    PB13

#define POWEROFF_PIN        PB14

//#define POWEROFFPIN 28

#define LED_PIN             PA8

#define FIL_RUNOUT_PIN      PD4
#define FIL_RUNOUT1_PIN     PD4
#define FIL_RUNOUT2_PIN     PD3

#define SD_DETECT_PIN       PA12

//
// Onboard SD support
//
#define SDIO_D0_PIN        PC8
#define SDIO_D1_PIN        PC9
#define SDIO_D2_PIN        PC10
#define SDIO_D3_PIN        PC11
#define SDIO_CK_PIN        PC12
#define SDIO_CMD_PIN       PD2

#define SDIO_SUPPORT 

#define SPI_SPEED           SPI_HALF_SPEED

#define SD_DETECT_STATE     LOW

// Motor current PWM pins
#define MOTOR_CURRENT_PWM_X_PIN     PB8     // T4/CH3
#define MOTOR_CURRENT_PWM_Y_PIN     PB9     // T4
#define MOTOR_CURRENT_PWM_Z_PIN     PB7
#define MOTOR_CURRENT_PWM_E_PIN     PB6
#define MOTOR_CURRENT_PWM_RANGE    1500 // (255 * (1000mA / 65535)) * 257 = 1000 is equal 1.6v Vref in turn equal 1Amp
//#define DEFAULT_PWM_MOTOR_CURRENT  { 600, 700, 200, 400 } // 1.05Amp per driver, here is X, Y, Z and E. This values determined empirically.

 #define DEFAULT_PWM_MOTOR_CURRENT  { 700, 700, 700, 500 } // 1.05Amp per driver, here is X, Y, Z and E. This values determined empirically.

#define FLASH_EEPROM_EMULATION
#define EEPROM_PAGE_SIZE     uint16(0x800) // 2KB
#define EEPROM_START_ADDRESS uint32(0x8000000 + 512 * 1024 - 2 * EEPROM_PAGE_SIZE)
#undef E2END
#define E2END                (EEPROM_PAGE_SIZE - 1) // 2KB

// #define RX_BUFFER_SIZE 512

// fake define for notice, you should modify the define in usart.h
#define USART_RX_BUF_SIZE 512
#define USART_TX_BUF_SIZE 512