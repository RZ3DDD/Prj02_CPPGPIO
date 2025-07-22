#ifndef CPPGPIO_
#define CPPGPIO_

#include "driver/gpio.h"

namespace CPPGPIO
{

class GpioBase
{
protected:
    const gpio_num_t _pin;
    const bool _inverted_logic = false;
    const gpio_config_t _cfg;

public:
    constexpr GpioBase(const gpio_num_t pin,
            const gpio_config_t& config,
            const bool invert_logic = false) :
        _pin{pin},
        _cfg{config},
        _inverted_logic{invert_logic}
    {

    }
    
    
    virtual bool state(void) = 0; // Чистая вирт.функция. Должна быть переопр. в произв.классах.
    virtual esp_err_t set(const bool state) = 0;

    [[nodiscard]] esp_err_t init(void);

};

class GpioOutput : public GpioBase
{
    bool _state = false;

public:
    constexpr GpioOutput(const gpio_num_t pin, const bool invert = false) :
        GpioBase{pin,
            gpio_config_t{
                .pin_bit_mask = static_cast<uint64_t>(1) << pin,
                .mode         = GPIO_MODE_OUTPUT,
                .pull_up_en   = GPIO_PULLUP_DISABLE,
                .pull_down_en = GPIO_PULLDOWN_ENABLE,
                .intr_type    = GPIO_INTR_DISABLE
            },
            invert}
    {

    }

    [[nodiscard]] esp_err_t init(void);

};




} // namespace CPPGPIO




#endif //CPPGPIO_
