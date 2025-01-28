#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include <stdint.h>
#include "pico/stdlib.h"

#include "include/ledmatrix.h"
#include "include/buzzer.h"

// Definições

// exemplo de como fazer o define para a qt de frames

#define NUM_PIXELS 25 // Número de LEDs na matriz
#define FAN_FRAME_COUNT 5
#define HEART_FRAME_COUNT 8
#define VOWELS_FRAME_COUNT 6
#define COLOR_FRAME_COUNT 6
#define MIAW_FRAME_COUNT 8
#define SPIRAL_FRAME_COUNT 50
#define BOMB_FRAME_COUNT 5
#define BUBBLESORT_FRAME_COUNT 20

// Funções
void convertToRGB(int argb, int rgb[3]); //apesar da sugestão, optei por deixar deste modo, por argb ser um pouco mais completo para converssão.
void apply_frame(const uint32_t frame[NUM_PIXELS]);
void display_animation(const uint32_t frames[][NUM_PIXELS], uint num_frames, uint time);

void display_animation_with_sound(const uint32_t frames[][NUM_PIXELS],
                                  const uint8_t num_frames,
                                  const uint16_t time,
                                  const uint16_t *melody);


// Variáveis globais

// sons para animação
extern const uint16_t melody_bubble_sort[BUBBLESORT_FRAME_COUNT];
// exemplo de como fazer

extern const uint32_t fan_data[5][25];      // implemendado
extern const uint32_t heart_data[8][25];    // implemendado
extern const uint32_t color_data[6][25];    // implemendado
extern const uint32_t vowels_data[5][25];   // implemendado
extern const uint32_t miaw_data[8][25];     // implemendado
extern const uint32_t spiral_data[50][25];  // implemendado
extern const uint32_t bomb_data[5][25];
extern const uint32_t bubble_sort_data[20][25];

#endif // ANIMATIONS_H