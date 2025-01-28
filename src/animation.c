#include "animation.h"
#include <stdio.h>

#define HEART_FRAME_COUNT 8

// Funções
void convertToRGB(int argb, int rgb[3]) {
    rgb[0] = argb & 0xFF;          // Blue
    rgb[2] = (argb >> 16) & 0xFF;  // Red
    rgb[1] = (argb >> 8) & 0xFF;   // Green
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

const uint32_t heart_data[8][25] = {
{
0x00000000, 0xff000000, 0x00000000, 0xff000000, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0x00000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000
},
{
0x00000000, 0xff000000, 0x00000000, 0xff000000, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff2b2bdf, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff2b2bdf, 
0x00000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000
},
{
0x00000000, 0xff000000, 0x00000000, 0xff2b2bdf, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0xff2b2bdf, 0xff2b2bdf, 
0xff000000, 0xff000000, 0xff000000, 0xff2b2bdf, 0xff2b2bdf, 
0x00000000, 0xff000000, 0xff000000, 0xff2b2bdf, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000
},
{
0x00000000, 0xff000000, 0x00000000, 0xff2b2bdf, 0x00000000, 
0xff000000, 0xff000000, 0xff2b2bdf, 0xff2b2bdf, 0xff2b2bdf, 
0xff000000, 0xff000000, 0xff2b2bdf, 0xff2b2bdf, 0xff2b2bdf, 
0x00000000, 0xff000000, 0xff2b2bdf, 0xff2b2bdf, 0x00000000, 
0x00000000, 0x00000000, 0xff2b2bdf, 0x00000000, 0x00000000
},
{
0x00000000, 0xff2323df, 0x00000000, 0xff2b2bdf, 0x00000000, 
0xff000000, 0xffffffff, 0xff2b2bdf, 0xff2b2bdf, 0xff2b2bdf, 
0xff000000, 0xff2323df, 0xff2b2bdf, 0xff2b2bdf, 0xff2b2bdf, 
0x00000000, 0xff2323df, 0xff2b2bdf, 0xff2b2bdf, 0x00000000, 
0x00000000, 0x00000000, 0xff2b2bdf, 0x00000000, 0x00000000
},
{
0x00000000, 0xff2323df, 0x00000000, 0xff2b2bdf, 0x00000000, 
0xff2323df, 0xffffffff, 0xff2b2bdf, 0xff2b2bdf, 0xff2b2bdf, 
0xff2323df, 0xff2323df, 0xff2b2bdf, 0xff2b2bdf, 0xff2b2bdf, 
0x00000000, 0xff2323df, 0xff2b2bdf, 0xff2b2bdf, 0x00000000, 
0x00000000, 0x00000000, 0xff2b2bdf, 0x00000000, 0x00000000
},
{
0x00000000, 0xff00981d, 0x00000000, 0xff00981d, 0x00000000, 
0xff00981d, 0xffffffff, 0xff00981d, 0xff00981d, 0xff00981d, 
0xff00981d, 0xff00981d, 0xff00981d, 0xff00981d, 0xff00981d, 
0x00000000, 0xff00981d, 0xff00981d, 0xff00981d, 0x00000000, 
0x00000000, 0x00000000, 0xff00981d, 0x00000000, 0x00000000
},
{
0x00000000, 0xffff0046, 0x00000000, 0xffff0046, 0x00000000, 
0xffff0046, 0xffffffff, 0xffff0046, 0xffff0046, 0xffff0046, 
0xffff0046, 0xffff0046, 0xffff0046, 0xffff0046, 0xffff0046, 
0x00000000, 0xffff0046, 0xffff0046, 0xffff0046, 0x00000000, 
0x00000000, 0x00000000, 0xffff0046, 0x00000000, 0x00000000
}
};

const uint32_t miaw_data[8][25] = {
{
0xffe5f507, 0xffe5f507, 0xffe5f507, 0xffe5f507, 0xffe5f507, 
0xffe5f507, 0xff000000, 0xffe5f507, 0xff000000, 0xffe5f507, 
0xffe5f507, 0xff66c46a, 0xffffffff, 0xff66c46a, 0xffe5f507, 
0xffe5f507, 0xff000000, 0xffcbabc6, 0xff000000, 0xffe5f507, 
0xffe5f507, 0xffe5f507, 0xffffffff, 0xff000000, 0xff000000
},
{
0xffe5f507, 0xffe5f507, 0xffe5f507, 0xffe5f507, 0xffe5f507, 
0xffe5f507, 0xff000000, 0xffe5f507, 0xff000000, 0xffe5f507, 
0xffe5f507, 0xff000000, 0xffffffff, 0xff000000, 0xffe5f507, 
0xffe5f507, 0xff000000, 0xffcbabc6, 0xff000000, 0xffe5f507, 
0xffe5f507, 0xffe5f507, 0xffffffff, 0xff000000, 0xff000000
},
{
0xffe5f507, 0xffe5f507, 0xffe5f507, 0xffe5f507, 0xffe5f507, 
0xffe5f507, 0xff000000, 0xffe5f507, 0xff000000, 0xffe5f507, 
0xffe5f507, 0xff66c46a, 0xffffffff, 0xff66c46a, 0xffe5f507, 
0xffe5f507, 0xff000000, 0xffcbabc6, 0xff000000, 0xffe5f507, 
0xffe5f507, 0xffe5f507, 0xffffffff, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xff27489b, 0xff27489b, 0xff27489b, 0xff27489b, 0xff27489b, 
0xff27489b, 0xff07a3de, 0xff27489b, 0xff07a3de, 0xff27489b, 
0xff27489b, 0xffdcf707, 0xff07a3de, 0xffdcf707, 0xff27489b, 
0xff27489b, 0xff07a3de, 0xffcbabc6, 0xff07a3de, 0xff27489b, 
0xff27489b, 0xff27489b, 0xff07a3de, 0xff07a3de, 0xff07a3de
},
{
0xff27489b, 0xff27489b, 0xff27489b, 0xff27489b, 0xff27489b, 
0xff27489b, 0xff07a3de, 0xff27489b, 0xff07a3de, 0xff27489b, 
0xff27489b, 0xff07a3de, 0xff07a3de, 0xff07a3de, 0xff27489b, 
0xff27489b, 0xff07a3de, 0xffcbabc6, 0xff07a3de, 0xff27489b, 
0xff27489b, 0xff27489b, 0xff07a3de, 0xff07a3de, 0xff07a3de
},
{
0xff27489b, 0xff27489b, 0xff27489b, 0xff27489b, 0xff27489b, 
0xff27489b, 0xff07a3de, 0xff27489b, 0xff07a3de, 0xff27489b, 
0xff27489b, 0xffdcf707, 0xff07a3de, 0xffdcf707, 0xff27489b, 
0xff27489b, 0xff07a3de, 0xffcbabc6, 0xff07a3de, 0xff27489b, 
0xff27489b, 0xff27489b, 0xff07a3de, 0xff07a3de, 0xff07a3de
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
}
};

const uint32_t spiral_data[50][25] = {
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xffffffff
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xffffffff, 0xffffffff
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0x00000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xffffffff, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xffffffff, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xff000000, 0xffffffff, 
0xffffffff, 0xffffffff, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xff000000, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xff000000, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xff000000, 0xffffffff, 
0xffffffff, 0xffffffff, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xffffffff, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xffffffff, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xffffffff, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xffffffff, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xffffffff, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xffffffff, 0xffffffff, 0xffffffff
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xffffffff, 0xffffffff
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xffffffff
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
}
};

const uint32_t vowels_data[5][25] = {
{
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000
},
{
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000
},
{
0x00000000, 0x00000000, 0xffffffff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffffff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffffff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffffff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffffff, 0x00000000, 0x00000000
},
{
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000
},
{
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000
}
};