file(GLOB_RECURSE IMAGE_SOURCES images/*.c)

idf_component_register(SRCS "bsp_power.c" "i80_controller_example_main.c" "lvgl_demo_ui.c" ${IMAGE_SOURCES}
REQUIRES phoneui esp_adc customUi bsp_sdCard MPU6050
                       INCLUDE_DIRS ".")
