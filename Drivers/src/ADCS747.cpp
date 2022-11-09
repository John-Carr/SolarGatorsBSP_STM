/*
 * ADCS747.cpp
 *
 *  Created on: Feb 24, 2022
 *      Author: John Carr
 */

#include <ADCS747.hpp>

namespace SolarGators {
namespace Drivers {

ADCS747::ADCS747(SPI_HandleTypeDef* hspi, GPIO_TypeDef* cs_port, uint16_t cs_pin):
    hspi_(hspi), cs_port_(cs_port), cs_pin_(cs_pin)
{

}

ADCS747::~ADCS747() {
  // TODO Auto-generated destructor stub
}

void ADCS747::Init()
{
  // Just need 16 clock cycles result of this is invalid
  GetVoltage();
}

void ADCS747::Read(uint8_t* buff)
{
  HAL_GPIO_WritePin(cs_port_, cs_pin_, GPIO_PIN_RESET);
  HAL_SPI_Receive(hspi_, buff, 2, HAL_MAX_DELAY);
  HAL_GPIO_WritePin(cs_port_, cs_pin_, GPIO_PIN_SET);
}

uint8_t ADCS747::GetVoltage()
{
  uint8_t buff[2];
  Read(buff);
  uint16_t temp = static_cast<uint16_t>(buff[0]) << 8 | buff[1];
  temp = temp >> 4;
  return static_cast<uint8_t>(temp);
}

} /* namespace Drivers */
} /* namespace SolarGators */
