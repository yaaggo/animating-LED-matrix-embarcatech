#include <stdio.h>
#include "pico/stdlib.h"
#include <hardware/pio.h>
#include "include/buzzer.h"
#include "include/keypad.h"
#include "include/ledmatrix.h"

int main() {

    PIO pio = pio0;
    uint sm;

    stdio_init_all();

    matrix_init(NUM_PIXELS);
    matrix_clear();
    matrix_write(pio, sm);

    while(true) {
        for(int i = 0; i < 25; i++) {   
            led_set(i, 0, 0, 10); //define qual pixel será ligado e sua cor 
            matrix_write(pio, sm); //envia o comando para a matrix
            sleep_ms(100);
            matrix_clear();  //apago o pixel
        } 
    }
}
