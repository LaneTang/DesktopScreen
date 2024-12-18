#ifndef __MAIN
#define __MAIN

#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_log.h"

#include "./components/inc/module1.h"
#include "./components/inc/module2.h"

void chip_info_print();

#endif