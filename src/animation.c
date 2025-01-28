#include "animation.h"

// Funções

// Função para aplicar um único frame nos LEDs
void apply_frame(const uint32_t frame[NUM_PIXELS]) {
    for (uint i = 0; i < NUM_PIXELS; ++i) {
        // Extrai os valores RGB do hexadecimal
        uint8_t r = (frame[i] >> 16) & 0xFF;
        uint8_t g = (frame[i] >> 8) & 0xFF;
        uint8_t b = frame[i] & 0xFF;

        // Define a cor do LED correspondente
        matrix_led_set(i, r, g, b);
    }

    // Escreve os dados no hardware dos LEDs
    matrix_write();
}

// Função para exibir uma animação a partir de uma matriz de frames
void display_animation(const uint32_t *frames, uint num_frames, uint fps) {
    if (fps == 0) return; // Evita divisão por zero

    uint frame_delay_us = 1000000 / fps; // Tempo de atraso entre frames em microsegundos

    while (1) { // Loop infinito para repetir a animação
        for (uint frame = 0; frame < num_frames; ++frame) {
            // Aplica o frame atual
            apply_frame(&frames[frame * NUM_PIXELS]);

            // Aguarda o tempo definido pelo FPS
            usleep(frame_delay_us);
        }
    }
}

// Variaveis com as animações, exemplo

const uint32_t fan_data[4][25] = {
{
0x00000000, 0x00000000, 0xffc7cb0d, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffc7cb0d, 0x00000000, 0x00000000, 
0xffc7cb0d, 0xffc7cb0d, 0xffc7cb0d, 0xffc7cb0d, 0xffc7cb0d, 
0x00000000, 0x00000000, 0xffc7cb0d, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffc7cb0d, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0x00000000, 0xffc7cb0d, 0x00000000, 
0xffc7cb0d, 0xffc7cb0d, 0x00000000, 0xffc7cb0d, 0x00000000, 
0x00000000, 0x00000000, 0xffc7cb0d, 0x00000000, 0x00000000, 
0x00000000, 0xffc7cb0d, 0x00000000, 0xffc7cb0d, 0xffc7cb0d, 
0x00000000, 0xffc7cb0d, 0x00000000, 0x00000000, 0x00000000
},
{
0xffc7cb0d, 0x00000000, 0x00000000, 0x00000000, 0xffc7cb0d, 
0x00000000, 0xffc7cb0d, 0x00000000, 0xffc7cb0d, 0x00000000, 
0x00000000, 0x00000000, 0xffc7cb0d, 0x00000000, 0x00000000, 
0x00000000, 0xffc7cb0d, 0x00000000, 0xffc7cb0d, 0x00000000, 
0xffc7cb0d, 0x00000000, 0x00000000, 0x00000000, 0xffc7cb0d
},
{
0x00000000, 0xffc7cb0d, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffc7cb0d, 0x00000000, 0xffc7cb0d, 0xffc7cb0d, 
0x00000000, 0x00000000, 0xffc7cb0d, 0x00000000, 0x00000000, 
0xffc7cb0d, 0xffc7cb0d, 0x00000000, 0xffc7cb0d, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xffc7cb0d, 0x00000000
}
};