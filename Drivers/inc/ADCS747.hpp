/*
 * ADCS747.hpp
 *
 *  Created on: Feb 24, 2022
 *      Author: John Carr
 */

#ifndef SOLARGATORSBSP_STM_DRIVERS_INC_ADCS747_HPP_
#define SOLARGATORSBSP_STM_DRIVERS_INC_ADCS747_HPP_

#include "stm32f0xx_hal.h"

namespace SolarGators {
namespace Drivers {

class ADCS747 {
  const uint16_t DataWidth = 256;
  SPI_HandleTypeDef* hspi_;
  GPIO_TypeDef* cs_port_;
  uint16_t cs_pin_;
  void Read(uint8_t *);
public:
  ADCS747(SPI_HandleTypeDef* hspi, GPIO_TypeDef* port, uint16_t pin);
  virtual ~ADCS747();
  void Init();
  uint8_t GetVoltage();
};

} /* namespace Drivers */
} /* namespace SolarGators */

#endif /* SOLARGATORSBSP_STM_DRIVERS_INC_ADCS747_HPP_ */
