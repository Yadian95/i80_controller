#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "soc/soc_caps.h"
#include "esp_log.h"
#include "esp_adc/adc_oneshot.h"
#include "esp_adc/adc_cali.h"
#include "esp_adc/adc_cali_scheme.h"
#include "lvgl.h"

#define EXAMPLE_POWER_IO 12
#define EXAMPLE_KEY_POWER_IO 11
#define EXAMPLE_ADC1_CHAN2 ADC_CHANNEL_2

static const char *TAG = "POWER_IO";

static QueueHandle_t powerIOGpioEventQueue = NULL;
static void intrHandler(void *arg)
{
    uint32_t gpio_num = (uint32_t)arg;
    xQueueSendFromISR(powerIOGpioEventQueue, &gpio_num, NULL);
}

extern lv_obj_t *Batvalue;
adc_oneshot_unit_handle_t adc1_handle;
void Bat_Adc_Init(void)
{
    //-------------ADC1 Init---------------//
    adc_oneshot_unit_init_cfg_t init_config1 = {
        .unit_id = ADC_UNIT_1,
    };
    ESP_ERROR_CHECK(adc_oneshot_new_unit(&init_config1, &adc1_handle));

    //-------------ADC1 Config---------------//
    adc_oneshot_chan_cfg_t config = {
        .bitwidth = ADC_BITWIDTH_DEFAULT,
        .atten = ADC_ATTEN_DB_11,
    };
    ESP_ERROR_CHECK(adc_oneshot_config_channel(adc1_handle, EXAMPLE_ADC1_CHAN2, &config));
}
static void gpioTaskPowerIO(void *arg)
{
    uint32_t ioNum = (uint32_t)arg;
    uint32_t preessCount = 0;
    while (1)
    {
        if (xQueueReceive(powerIOGpioEventQueue, &ioNum, portMAX_DELAY))
        {
            preessCount++;

            printf("GPIO[%ld] interrupted level:%d\n", ioNum, gpio_get_level(ioNum));
            for (uint32_t i = 0; i < 0xFFFFF; i++)
            {
                /* code */
            }

            if (gpio_get_level(ioNum))
            {
                gpio_set_level(EXAMPLE_POWER_IO, 0);
                printf("Power OFF\n");
            }
        }
    }
}

void bsp_power_init()
{
    Bat_Adc_Init();
    gpio_config_t PowerIOConfig = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << EXAMPLE_POWER_IO};
    ESP_ERROR_CHECK(gpio_config(&PowerIOConfig));
    gpio_set_level(EXAMPLE_POWER_IO, 1);

    gpio_config_t KeyPowerIO = {
        .mode = GPIO_MODE_INPUT,
        .intr_type = GPIO_INTR_POSEDGE,
        .pin_bit_mask = 1ULL << EXAMPLE_KEY_POWER_IO};
    ESP_ERROR_CHECK(gpio_config(&KeyPowerIO));

    gpio_install_isr_service(0);
    powerIOGpioEventQueue = xQueueCreate(10, sizeof(uint32_t));
    xTaskCreate(gpioTaskPowerIO, "KEY_POWERIO_Task", 2048, NULL, 10, NULL);
    gpio_isr_handler_add(EXAMPLE_KEY_POWER_IO, intrHandler, (void *)EXAMPLE_KEY_POWER_IO);
    ESP_LOGI(TAG, "Power Manage Service Install finished!\n");
}