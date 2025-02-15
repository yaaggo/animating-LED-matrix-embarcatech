#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"

#include "include/buzzer.h"
#include "include/keypad.h"
#include "include/ledmatrix.h"

#include "animation.h"

#define ANIMATION_TIME 3000
#define DEBUG(var) printf("%s : %c\n", #var, var)

// comentar seguinte linha caso não queira utilizar o keypad

#define KEYPAD // DEFINIDO : DADOS KEYPAD / NÃO DEFINIDO (COMENTADO): DADOS UART

int main() {
    stdio_init_all();
    
    #ifdef KEYPAD
        keypad_init();
    #endif

    buzzer_init(BUZZER_A_PIN);
    matrix_init(LEDMATRIX_PIN);
    matrix_write();

    while (true) {
        int key_pressed;

        #ifdef KEYPAD
            key_pressed = keypad_return();
        #else
            key_pressed = getchar();
        #endif

        #if 1
        if(key_pressed != ' ') {

            uint16_t time = 0;

            DEBUG(key_pressed);

            switch (key_pressed) {
                // Animação 1: ventilador
                case '1':             
                    while(time < ANIMATION_TIME) {
                        display_animation(
                            fan_data, 
                            FAN_FRAME_COUNT, 
                            1000
                        );
                        time += 1000;
                    }
                    break;

                // Animação 2: coração
                case '2':
                    while(time < ANIMATION_TIME) {
                        display_animation(
                            heart_data, 
                            HEART_FRAME_COUNT, 
                            1000
                        );
                        time += 1000;
                    }
                    break;

                // Animação 3: cores
                case '3':
                    while(time < ANIMATION_TIME) {
                        display_animation(
                            color_data, 
                            COLOR_FRAME_COUNT, 
                            1000
                        );
                        time += 1000;
                    }
                    break;

                // Animação 4: vogáis
                case '4':
                    while(time < ANIMATION_TIME) {
                        display_animation(
                            vowels_data, 
                            VOWELS_FRAME_COUNT, 
                            3000
                        );
                        time += 3000;
                    }
                    break;

                // Animação 5: gatos
                case '5':
                    while(time < ANIMATION_TIME) {
                        display_animation(
                            miaw_data, 
                            MIAW_FRAME_COUNT, 
                            3000
                        );
                        time += 3000;
                    }
                    break;

                // Animação 6: espiral
                case '6':
                    while(time < ANIMATION_TIME) {
                        display_animation(
                            spiral_data, 
                            SPIRAL_FRAME_COUNT, 
                            3000
                        );
                        time += 3000;
                    }
                    break;

                // Animação 7: bomba
                case '7':
                    while(time < ANIMATION_TIME) {
                        display_animation(
                            bomb_data, 
                            BOMB_FRAME_COUNT, 
                            2000
                        );
                        time += 2000;
                    }
                    break;

                // Animação 8: tetris
                case '8':
                    while(time < ANIMATION_TIME) {
                        display_animation(
                            tetris_data, 
                            TETRIS_FRAME_COUNT, 
                            3000
                        );
                        time += 3000;
                    }
                    break;

                // Animação 9: esperando ser feita
                case '9':
                    while(time < ANIMATION_TIME) {
                        display_animation(
                            degrade_data, 
                            DEGRADE_FRAME_COUNT, 
                            1000
                        );
                        time += 1000;
                    }

                    break;

                // Animação com buzzer: bubble sort
                case '0':
                    while(time < ANIMATION_TIME) {
                        display_animation_with_sound(
                            bubble_sort_data, 
                            BUBBLESORT_FRAME_COUNT, 
                            4000,
                            melody_bubble_sort
                        );
                        time += 4000;
                    }
                    break;
                
                // Tecla A: apagar todos os leds
                case 'A':
                    matrix_clear();
                    matrix_write();
                    break;

                // Tecla B: pinta tudo de azul intensidade 100%
                case 'B':
                    matrix_fill(0, 0, 255);
                    matrix_write();
                    break;

                // Tecla B: pinta tudo de vermelho intensidade 80%
                case 'C':
                    matrix_fill(255 * 0.8, 0, 0);
                    matrix_write();
                    break;

                // Tecla D: pinta tudo de verde intensidade 50%
                case 'D':
                    matrix_fill(0, 255 * 0.5, 0);
                    matrix_write();
                    break;

                // Tecla #: pinta tudo de branco intensidade 20%
                case '#':
                    matrix_fill(255 *0.2 , 255 * 0.2, 255 * 0.2);
                    matrix_write();
                    break;

                // Tecla *: limpa tudo e entra em modo bootsel
                case '*':
                    matrix_clear();
                    matrix_write();
                    reset_usb_boot(0, 0);
                    break;
            }
        }
        #endif
        sleep_ms(100);
    }
}