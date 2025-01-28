#include <stdio.h>
#include "pico/stdlib.h"

#include "include/buzzer.h"
#include "include/keypad.h"
#include "include/ledmatrix.h"

#include "animation.h"

#define DEBUG(var) printf("%s : %c\n", #var, var)

int main() {
    stdio_init_all();

    keypad_init();
    buzzer_init(BUZZER_A_PIN);
    matrix_init(LEDMATRIX_PIN);
    matrix_write();

    while (true) {
        char key_pressed = keypad_return();
        if(key_pressed != ' ') {
            DEBUG(key_pressed);

            switch (key_pressed) {
                case '1':
                #if 1
                    display_animation(
                        fan_data, 
                        FAN_FRAME_COUNT, 
                        3000
                    );
                #endif
                    break;
                case '2':
                
                    break;
                case '3':
                
                    break;
                case '4':
                
                    break;
                case '5':
                
                    break;
                case '6':
                
                    break;
                case '7':
                
                    break;
                case '8':
                
                    break;
                case '9':
                
                    break;
                case '0':
                
                    break;
                case 'A':
                
                    break;
                case 'B':
                
                    break;
                case 'C':
                
                    break;
                case 'D':
                
                    break;
                case '*':
                
                    break;
                case '#':

                    break;
            }
        }

        sleep_ms(50);
    }
}