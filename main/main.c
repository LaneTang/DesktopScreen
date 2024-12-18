/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include "main.h"

#define CHIP_NAME "ESP32"

#define vDelay_ms(ms)   vTaskDelay( ms * ( ( 1000 / (portTICK_PERIOD_MS) ) / 1000 ) )

static const char *TAG = "MAIN APP";


void vTask_test_print(void *arg)
{
    uint8_t sec_num = 0;
    while (1) {
        printf("this is a test task, printing test info\r\n");
        printf("this message should be seen for every 0.5 seconds\r\n");
        printf("current second number: %d\r\n", sec_num);
        sec_num++;
        vDelay_ms(1000);
    }
}

void vTask_chip_info_print(void *arg)
{
    while (1) {
        printf("chip info print\r\nthis info should be seen for every 5 seconds\r\n");
        chip_info_print();
            vDelay_ms(5000);
    }
}

void app_main(void)
{
    /* Print chip information */
    chip_info_print();

    ESP_LOGI(TAG, "log info\n");
    ESP_LOGW(TAG, "log warning info\n");
    ESP_LOGE(TAG, "log error info\n");

    vDelay_ms(100);

    xTaskCreate(vTask_test_print, "vTask_test_print", 2048, NULL, 5, NULL);
    xTaskCreate(vTask_chip_info_print, "vTask_chip_info_print", 2048, NULL, 5, NULL);

    while(1){
        vDelay_ms(100);  // periodic delay
    }
}

void chip_info_print()
{
    /* Print chip information */
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    printf("This is %s chip with %d CPU core(s), WiFi%s%s, ",
            CHIP_NAME,
            chip_info.cores,
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    printf("silicon revision %d, ", chip_info.revision);

    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    printf("Minimum free heap size: %d bytes\n", esp_get_minimum_free_heap_size());

}