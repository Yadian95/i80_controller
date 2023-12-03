#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "soc/soc_caps.h"
#include "esp_log.h"
#include "esp_adc/adc_oneshot.h"
#include "esp_adc/adc_cali.h"
#include "esp_adc/adc_cali_scheme.h"
#include "lvgl.h"

#define EXAMPLE_POWER_IO 12
#define EXAMPLE_STATE_IO 46
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

static void stateTasks(void)
{
    bool IO_STATE = false;
    bool Dir = false;
    uint32_t Duty = 0;
    while (1)
    {
#if 0
        vTaskDelay(pdMS_TO_TICKS(50));
        // gpio_set_level(EXAMPLE_STATE_IO, IO_STATE);
        // ESP_LOGI(TAG, "Fade on\n");
        ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, Duty);
        ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
        ESP_LOGI(TAG, "Duty = %ld\n", Duty);
        if (!Dir)
        {
            Duty += 300;
        }
        else
        {
            Duty -= 300;
        }

        if (Duty > 7000)
        {
            // Duty = 0;
            Dir = !Dir;
        }
        else if (Duty == 0)
        {
            Dir = !Dir;
        }
#else
        vTaskDelay(pdMS_TO_TICKS(600));
        gpio_set_level(EXAMPLE_STATE_IO, IO_STATE);
        IO_STATE = !IO_STATE;
#endif
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

    gpio_config_t StateIOConfig = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << EXAMPLE_STATE_IO};
    ESP_ERROR_CHECK(gpio_config(&StateIOConfig));
    gpio_set_level(EXAMPLE_STATE_IO, 1);

    gpio_config_t KeyPowerIO = {
        .mode = GPIO_MODE_INPUT,
        .intr_type = GPIO_INTR_POSEDGE,
        .pin_bit_mask = 1ULL << EXAMPLE_KEY_POWER_IO};
    ESP_ERROR_CHECK(gpio_config(&KeyPowerIO));

    gpio_install_isr_service(0);
    powerIOGpioEventQueue = xQueueCreate(10, sizeof(uint32_t));

    xTaskCreate(gpioTaskPowerIO, "KEY_POWERIO_Task", 2048, NULL, 10, NULL);
#if 0
    // 初始化呼吸灯PWM
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = LEDC_TIMER_13_BIT,
        .freq_hz = 5000,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_num = LEDC_TIMER_1,
        .clk_cfg = LEDC_AUTO_CLK,
    };
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t channel_config = {
        .channel = LEDC_CHANNEL_0,
        .duty = 0,
        .gpio_num = 46,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .hpoint = 0,
        .timer_sel = LEDC_TIMER_1,
        .flags.output_invert = 0,
    };
    ledc_channel_config(&channel_config);

    ledc_fade_func_install(0);
#endif
    xTaskCreate(stateTasks, "State_Task", 4096, NULL, 10, NULL);

    gpio_isr_handler_add(EXAMPLE_KEY_POWER_IO, intrHandler, (void *)EXAMPLE_KEY_POWER_IO);

    ESP_LOGI(TAG, "Power Manage Service Install finished!\n");
}