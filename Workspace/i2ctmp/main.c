
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>

#include <ti/drivers/GPIO.h>
#include <ti/display/Display.h>

#include "ti_drivers_config.h"
#include "i2c.h"
#include "eeprom.h"


#define TASKSTACKSIZE 1024

static Display_Handle display;


/*
 *  ======== mainThread ========
 */
void *mainThread(void *arg0)
{
    sleep(1);
    Display_init();
    GPIO_init();
    i2c_init();

    display = Display_open(Display_Type_UART, NULL);
    if (display == NULL)
    {
        while (1) {}
    }

    uint8_t byte;
    uint32_t address = 1;

    eeprom_write_byte(address, 0x20);
    eeprom_read_byte(address, &byte);

    Display_printf(display, 0, 0, "%x",byte);

    //    while(1){
//        GPIO_write(CONFIG_GPIO_WP,1);
//        sleep(3);
////        GPIO_write(CONFIG_GPIO_WP,0);
//    }

    return (NULL);
}

