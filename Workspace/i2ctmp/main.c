
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>

#include <ti/drivers/GPIO.h>
#include <ti/display/Display.h>

#include "ti_drivers_config.h"

#define TASKSTACKSIZE 1024

static Display_Handle display;


/*
 *  ======== mainThread ========
 */
void *mainThread(void *arg0)
{

    Display_init();
    GPIO_init();

    display = Display_open(Display_Type_UART, NULL);
    if (display == NULL)
    {
        while (1) {}
    }

    Display_printf(display, 0, 0, "I2C closed!");

    return (NULL);
}

