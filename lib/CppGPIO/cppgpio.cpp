#include "cppgpio.h"

namespace CPPGPIO

{

[[nodiscard]] esp_err_t GpioBase::init(void)
{
    esp_err_t status{ESP_OK};
    status |= gpio_config(&_cfg);
    return status;
}

[[nodiscard]] esp_err_t GpioOutput::init(void)
{
    esp_err_t status{GpioBase::init()};
    if (ESP_OK == status)
    {
        status |= set(_inverted_logic);
    }
    return status;
}

} // namespace CPPGPIO