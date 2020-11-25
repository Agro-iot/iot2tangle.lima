/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "MLX90614_API.h"
#include "MLX90614_SMBus_Driver.h"

#define MLX90614_DEFAULT_ADDRESS 0x5A // default chip address(slave address) of MLX90614

#define MLX90614_SDA_GPIO 13 // sda for MLX90614
#define MLX90614_SCL_GPIO 12 // scl for MLX90614
#define MLX90614_VCC_GPIO 14 // vcc for MLX90614

char buffer[400];
char* s;
float to = 0;

bool check_mlx90614()
{
    return true;
}

void print_mlx90614()
{
    if (check_mlx90614())
        printf("mlx90614 : OK");
    else
        printf("mlx90614 : Not detected ");
}

char *get_mlx90614()
{
    gpio_pad_select_gpio(MLX90614_VCC_GPIO);
    gpio_set_direction(MLX90614_VCC_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_level(MLX90614_VCC_GPIO, 1);
    vTaskDelay(1000/portTICK_RATE_MS);
    MLX90614_SMBusInit(MLX90614_SDA_GPIO, MLX90614_SCL_GPIO, 50000); // sda scl and 50kHz
    MLX90614_GetTo(MLX90614_DEFAULT_ADDRESS, &to);
    s = " ";
    sprintf(buffer, "%.2f", to);
    s=buffer;
    return s; 
}

