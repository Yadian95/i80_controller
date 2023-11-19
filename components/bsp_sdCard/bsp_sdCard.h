#ifndef __BSP_SDCARD_H__
#define __BSP_SDCARD_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "esp_err.h"
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_vfs_fat.h"
#include "sdmmc_cmd.h"
#include "driver/sdmmc_host.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"

#define MOUNT_POINT "/sdcard"
#define TAG1 "FatFs"
#define CONFIG_EXAMPLE_SDMMC_BUS_WIDTH_4 1

    esp_err_t bsp_sdCard_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
