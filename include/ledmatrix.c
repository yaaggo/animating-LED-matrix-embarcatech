#include <stdio.h>
#include "ledmatrix.h"
#include <hardware/pio.h>
#include "hardware/clocks.h"

// Biblioteca gerada pelo arquivo .pio durante compilação.
#include "ws2818b.pio.h"

PIO pio;
uint sm;
rgb_led leds[NUM_PIXELS];

// função que inicializa a matriz de LEDs
uint matrix_init(uint pin_out) {
    
    uint offset = pio_add_program(pio0, &ws2818b_program);
    pio = pio0;

    sm = pio_claim_unused_sm(pio, false);
    if (sm < 0) {
        pio = pio1;
        sm = pio_claim_unused_sm(pio, true);
    }

    ws2818b_program_init(pio, sm, offset, pin_out); // tive que mudar a .pio

    for (uint i = 0; i < NUM_PIXELS; ++i) {
        //leds[i].activate = 0;
        leds[i].R = 0;
        leds[i].G = 0;
        leds[i].B = 0;
    }

    return sm;
}

// função que ativa um único LED com código rgb
void matrix_led_set(const uint index, const uint8_t r, const uint8_t g, const uint8_t b) {
    leds[index].R = r;
    leds[index].G = g;
    leds[index].B = b;
}

// função que acende todos os LEDs da matriz com uma única cor
void matrix_fill(const uint8_t r, const uint8_t g, const uint8_t b) {
    for(uint i = 0; i < NUM_PIXELS; i++) {
        matrix_led_set(i, r, g, b);
    }
}

// função que limpa a matriz (desliga todos os LEDs)
void matrix_clear() {
    for(uint i = 0; i < NUM_PIXELS; i++) {
        matrix_led_set(i, 0, 0, 0);
    }
}

// função que escreve os dados do buffer nos LEDs
void matrix_write() {
    // Escreve cada dado de 8-bits dos pixels em sequência no buffer da máquina PIO.
    for (uint8_t i = 0; i < NUM_PIXELS; ++i) {
        uint32_t color = COLOR_HEX(leds[i].R, leds[i].G, leds[i].B);
        pio_sm_put_blocking(pio, sm, color);
    }
    sleep_us(100);
}

// função que procura um LED específico na matriz de LEDs, de acordo com suas coordenadas x e y
int matrix_get_index(int x, int y) {
    // Se a linha for par (0, 2, 4), percorremos da esquerda para a direita.
    // Se a linha for ímpar (1, 3), percorremos da direita para a esquerda.
    if (y % 2 == 0) {
        return y * 5 + (4 - x); // Linha par (direita para esquerda).
    } else {
        return y * 5 + x; // Linha ímpar (esquerda para direita).
    }
}