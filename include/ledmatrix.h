#ifndef LEDMATRIX_H
#define LEDMATRIX_H

#include <stdint.h>

// struct para indicar um led rgb
// deixei isso padronizado para aproveitar em outros espaços
typedef struct {
    uint8_t r, g, b;
    uint8_t state;
} rgb_led;

// Defines
#define LEDMATRIX_PIN 7

// Funções

#endif