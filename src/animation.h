#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include <stdint.h>
#include <include/ledmatrix.h>

// Definições
// exemplo de como fazer o define para a qt de frames

#define FAN_FRAME_COUNT 4
#define NEW_PISKEL_FRAME_COUNT 6
#define NEW_PISKEL_FRAME_WIDTH 5
#define NEW_PISKEL_FRAME_HEIGHT 5

// Funções
// sugestão para a função de conversão
rgb_led hex_to_rgb(uint32_t hex_color);

// Variáveis globais
// exemplo de como fazer

extern const uint32_t fan_data[4][25];
extern const uint32_t color_data[6][25];

#endif // ANIMATIONS_H