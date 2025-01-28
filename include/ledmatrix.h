#ifndef LEDMATRIX_H
#define LEDMATRIX_H

#include <stdint.h>
#include "pico/stdlib.h"

// Defines
#define LEDMATRIX_PIN 7
#define NUM_PIXELS 25

#define COLOR_HEX(r, g, b) (g << 24) | (r << 16) | (b << 8)


// struct para indicar um led rgb
typedef struct {
    uint8_t R, G, B;
    uint8_t state;
} rgb_led;

extern rgb_led leds[NUM_PIXELS];

// Funções
uint matrix_init(uint pin_out);
void matrix_led_set(const uint index, const uint8_t r, const uint8_t g, const uint8_t b);
void matrix_fill(const uint8_t r, const uint8_t g, const uint8_t b);
void matrix_clear();
void matrix_write();
int matrix_get_index(int x, int y);

#endif