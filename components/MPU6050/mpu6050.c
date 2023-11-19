
#include "mpu6050.h"

#define I2C_MASTER_NUM 0

#define I2C_MASTER_TIMEOUT_MS 1000

#define MPU9250_PWR_MGMT_1_REG_ADDR 0x6B /*!< Register addresses of the power managment register */
/**
 * @brief Read a sequence of bytes from a MPU9250 sensor registers
 */
esp_err_t mpu9250_register_read(uint8_t reg_addr, uint8_t *data, size_t len)
{
    return i2c_master_write_read_device(I2C_MASTER_NUM, MPU6050_DEFAULT_ADDRESS, &reg_addr, 1, data, len, I2C_MASTER_TIMEOUT_MS / portTICK_PERIOD_MS);
}

/**
 * @brief Write a byte to a MPU9250 sensor register
 */
esp_err_t mpu9250_register_write_byte(uint8_t reg_addr, uint8_t data)
{
    int ret;
    uint8_t write_buf[2] = {reg_addr, data};

    ret = i2c_master_write_to_device(I2C_MASTER_NUM, MPU6050_DEFAULT_ADDRESS, write_buf, sizeof(write_buf), I2C_MASTER_TIMEOUT_MS / portTICK_PERIOD_MS);

    return ret;
}

esp_err_t mpu9250_Init()
{
    int ret;
    ret = mpu9250_register_write_byte(0x6B, 0x80);
    vTaskDelay(pdMS_TO_TICKS(100));
    ret = mpu9250_register_write_byte(0x6B, 0x01);
    ret = mpu9250_register_write_byte(0x6C, 0x00);
    ret = mpu9250_register_write_byte(0x38, 0x00);
    ret = mpu9250_register_write_byte(0x19, 0x00);
    ret = mpu9250_register_write_byte(0x1A, 0x04);
    ret = mpu9250_register_write_byte(0x1B, 0x18);
    ret = mpu9250_register_write_byte(0x1C, 0x08);
    ret = mpu9250_register_write_byte(0x37, 0x02);
    return ret;
}