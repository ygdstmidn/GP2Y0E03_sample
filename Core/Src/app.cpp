// main code here!!

#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"

#include <GP2Y0E03/GP2Y0E03.h>

    GP2Y0E03::GP2Y0E03 myGPsensor(&hi2c1, 0x40); // 0x40,0x60

    // MARK:setup
    void user_setup(void)
    {
        setbuf(stdout, NULL);
        printf("Hello World!!\n");
    }

    // MARK:loop
    void user_loop(void)
    {
        const uint32_t now = HAL_GetTick();
        static uint32_t pre = now;

        if (now - pre >= 10)
        {
            const double distance = myGPsensor.read();
            printf(">distance:%f\n", distance);

            pre = now;
        }

        // // I2Cスキャナ
        // printf("Scanning I2C bus...\n");
        // for (uint8_t addr = 1; addr < 128; addr++)
        // {
        //     if (HAL_I2C_IsDeviceReady(&hi2c1, addr << 1, 1, 10) == HAL_OK)
        //     {
        //         printf("Found device at 0x%02X\n", addr);
        //     }
        // }
        // HAL_Delay(1000);
    }

    // MARK:_write (for printf)
    int _write(int file, char *ptr, int len)
    {
        HAL_UART_Transmit(&huart2, (uint8_t *)ptr, len, 10);
        return len;
    }

#ifdef __cplusplus
}
#endif
