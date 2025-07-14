// main code here!!

#ifdef __cplusplus

#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"

#include <GP2Y0E03/GP2Y0E03.h>

GP2Y0E03::GP2Y0E03 myGPsensor(&hi2c1, 0x80);

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
        printf(">distance:%f", distance);

        pre = now;
    }
}

// MARK:_write (for printf)
int _write(int file, char *ptr, int len)
{
    HAL_UART_Transmit(&huart2, (uint8_t *)ptr, len, 10);
    return len;
}

#endif
