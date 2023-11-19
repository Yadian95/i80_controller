idf_component_register(SRCS "bsp_sdCard.c"
                    REQUIRES driver lvgl fatfs log freertos sdmmc esp_common
                    INCLUDE_DIRS ".")