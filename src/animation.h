#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include <stdint.h>
#include <include/ledmatrix.h>
#include <unistd.h>

// Definições
#define MATRIX_ROWS 5
#define MATRIX_COLS 5
#define MATRIX_DEPTH 3
#define MIAW_FRAME_COUNT 8
#define MIAW_FRAME_WIDTH 5
#define MIAW_FRAME_HEIGHT 5
#define SPIRAL_FRAME_COUNT 50
#define SPIRAL_FRAME_WIDTH 5
#define SPIRAL_FRAME_HEIGHT 5

// exemplo de como fazer o define para a qt de frames

#define NUM_PIXELS 25 // Número de LEDs na matriz
#define FAN_FRAME_COUNT 4
#define NEW_PISKEL_FRAME_COUNT 6
#define NEW_PISKEL_FRAME_WIDTH 5
#define NEW_PISKEL_FRAME_HEIGHT 5

// Funções
void convertToRGB(int argb, int rgb[3]); //apesar da sugestão, optei por deixar deste modo, por argb ser um pouco mais completo para converssão.


// sugestão para a função de conversão
void apply_frame(const uint32_t frame[NUM_PIXELS]);
void display_animation(const uint32_t *frames, uint num_frames, uint fps);
rgb_led hex_to_rgb(uint32_t hex_color);

// Variáveis globais
// exemplo de como fazer

extern const uint32_t fan_data[4][25];
extern const uint32_t color_data[6][25];
extern const uint32_t vowels_data[5][25];
extern const uint32_t miaw_data[8][25];
extern const uint32_t spiral_data[50][25];

#endif // ANIMATIONS_H