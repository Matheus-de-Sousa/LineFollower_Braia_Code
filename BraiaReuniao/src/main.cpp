#include "io.h"

#include "driver/gpio.h"

#include "ESP32Encoder.h"
#include "QTRSensors.h"
#include "ESP32MotorControl.h"


extern "C" void app_main(void)
{
    // Configuração da biblioteca de controle do Motor
    ESP32MotorControl motoresBraia;
    motoresBraia.setSTBY(DRIVER_STBY);
    motoresBraia.attachMotors(DRIVER_AIN1, DRIVER_AIN2, DRIVER_PWMA, DRIVER_BIN1, DRIVER_BIN2, DRIVER_PWMB);

    // Configuração biblitoeca do Array
    QTRSensors array;
    array.setTypeMCP3008();
    array.setSensorPins((const uint8_t[]){0, 1, 2, 3, 4, 5, 6, 7}, 8, GPIO_NUM_19, GPIO_NUM_23, GPIO_NUM_18, GPIO_NUM_22, 1350000,
                      VSPI_HOST);

}