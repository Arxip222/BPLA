#ifndef __SX1278_HW_HEADER
#define __SX1278_HW_HEADER

#include "serv.h"
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/**
 * \brief Initialize hardware layer
 *
 * Clears NSS and resets LoRa module.
 *
 * \param[in]   hw 		Pointer to hardware structure
 */
void SX1278_hw_init(void);

/**
 * \brief Control NSS
 *
 * Clears and sets NSS according to passed value.
 *
 * \param[in]   hw 		Pointer to hardware structure.
 * \param[in]   value   1 sets NSS high, other value sets NSS low.
 */
void SX1278_hw_SetNSS(int value);

/**
 * \brief Resets LoRa module
 *
 * Resets LoRa module.
 *
 * \param[in]   hw 		Pointer to hardware structure
 */
void SX1278_hw_Reset(void);

/**
 * \brief Send command via SPI.
 *
 * Send single byte via SPI interface.
 *
 * \param[in]   hw 		Pointer to hardware structure
 * \param[in]   cmd		Command
 */
void SX1278_hw_SPICommand(uint8_t cmd);

/**
 * \brief Reads data via SPI
 *
 * Reads data via SPI interface.
 *
 * \param[in]   hw 		Pointer to hardware structure
 *
 * \return				Read value
 */
uint8_t SX1278_hw_SPIReadByte(void);

/**
 * \brief Reads DIO0 state
 *
 * Reads LoRa DIO0 state using GPIO.
 *
 * \param[in]   hw 		Pointer to hardware structure
 *
 * \return				0 if DIO0 low, 1 if DIO high
 */
int SX1278_hw_GetDIO0(void);

#endif
