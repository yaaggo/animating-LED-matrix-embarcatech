#include "animation.h"

#define HEART_FRAME_COUNT 8

// Funções

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

static const uint32_t heart_data[8][25] = {
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