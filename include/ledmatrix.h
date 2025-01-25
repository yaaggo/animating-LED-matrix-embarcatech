#ifndef LEDMATRIX_H
#define LEDMATRIX_H

#include <stdint.h>

// Defines
#define LEDMATRIX_PIN 7
#define NUM_PIXELS 25

// struct para indicar um led rgb
// deixei isso padronizado para aproveitar em outros espaços
typedef struct {
    uint8_t R, G, B;
    uint8_t state;
} rgb_led;

rgb_led leds[NUM_PIXELS];

// Funções
uint matrix_init(uint pin_out);
void led_set(const uint index, const uint8_t r, const uint8_t g, const uint8_t b);
void matrix_fill(const uint8_t r, const uint8_t g, const uint8_t b);
void matrix_clear();
void matrix_write();
int matrix_get_index(int x, int y);

#endif