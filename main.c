#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include"driver/uart.h"
#include"esp_adc/adc_oneshot.h"

#define UART_NUM UART_NUM_2
#define TX_PIN 17
#define RX_PIN 16
#define JOY_CHANNEL ADC_CHANNEL_0

adc_oneshot_unit_handle_t adc1_handle;

void init_uart()
{
    uart_config_t cfg ={
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity =UART_PARITY_DISABLE,
        .stop_bits =UART_STOP_BITS_1,
        .flow_ctrl=UART_HW_FLOWCTRL_DISABLE
    };
    uart_param_config(UART_NUM, &cfg);
    uart_set_pin(UART_NUM, TX_PIN, RX_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(UART_NUM,1024,0,0,NULL,0);
}
void adc_init(){
    adc_oneshot_unit_init_cfg_t init_cfg={
        .unit_id =ADC_UNIT_1
    };
    adc_oneshot_new_unit(&init_cfg, &adc1_handle);
    adc_oneshot_chan_cfg_t chan_cfg={
        .atten = ADC_ATTEN_DB_12,
        .bitwidth=ADC_BITWIDTH_DEFAULT,
    };
    adc_oneshot_config_channel(adc1_handle, JOY_CHANNEL, &chan_cfg);
}

void app_main(void)
{
init_uart();
adc_init();
char msg[16];

while(1){
    int raw;
    adc_oneshot_read(adc1_handle, JOY_CHANNEL, &raw);
    int angle = (raw*180/4096);
    int len=sprintf(msg,"%d\n",angle);
    uart_write_bytes(UART_NUM,msg,len);
   vTaskDelay(pdMS_TO_TICKS(50)); 
}
}
