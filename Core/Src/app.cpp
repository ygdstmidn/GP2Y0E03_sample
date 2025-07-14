// main code here!!

#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"

    // MARK:setup
    void user_setup(void)
    {
        setbuf(stdout, NULL);
        printf("Hello World!!\n");
    }

    // MARK:loop
    void user_loop(void)
    {
        for (uint8_t addr = 1; addr < 128; addr++)
        {
            if (HAL_I2C_IsDeviceReady(&hi2c1, (uint16_t)(addr << 1), 1, 10) == HAL_OK)
            {
                printf("I2C device found at address 0x%02X\r\n", addr);
            }
        }
        HAL_Delay(1000);
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
