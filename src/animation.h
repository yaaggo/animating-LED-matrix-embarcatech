#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include <stdint.h>
#include <include/ledmatrix.h>
#include <unistd.h>

// Definições
// exemplo de como fazer o define para a qt de frames

#define NUM_PIXELS 25 // Número de LEDs na matriz
#define FAN_FRAME_COUNT 4

// Funções
// sugestão para a função de conversão
void apply_frame(const uint32_t frame[NUM_PIXELS]);
void display_animation(const uint32_t *frames, uint num_frames, uint fps);
rgb_led hex_to_rgb(uint32_t hex_color);

// Variáveis globais
// exemplo de como fazer

extern const uint32_t fan_data[4][25];

#endif // ANIMATIONS_H