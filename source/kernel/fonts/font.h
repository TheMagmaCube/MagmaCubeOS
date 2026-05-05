#ifndef FONT_H
#define FONT_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct{

    uint8_t indicator[2];
    uint8_t body[32];

} Font;

static Font font_SPACE = {

    .indicator = {0x00, 0x00},
    .body = {0xAA,0xAA,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x4A,0x51,0xEA,0x50,0x5A,0x51,0xC9,0x9E,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x55,0x55}
};

static Font font_A = {

    .indicator = {0x00,0x41},
    .body = {0x00,0x00,0x00,0x00,0x18,0x24,0x24,0x42,0x42,0x7E,0x42,0x42,0x42,0x42,0x00,0x00}

};

static Font font_B = {

    .indicator = {},
    .body = {}
};

static Font font_C = {

    .indicator = {},
    .body = {}
};

static Font font_D = {

    .indicator = {},
    .body = {}
};

static Font font_E = {

    .indicator = {},
    .body = {}
};

static Font font_F = {

    .indicator = {},
    .body = {}
};

static Font font_G = {

    .indicator = {},
    .body = {}
};

static Font font_H = {

    .indicator = {},
    .body = {}
};

static Font font_I = {

    .indicator = {},
    .body = {}
};

static Font font_J = {

    .indicator = {},
    .body = {}
};

static Font font_K = {

    .indicator = {},
    .body = {}
};

static Font font_L = {

    .indicator = {},
    .body = {}
};

static Font font_M = {

    .indicator = {},
    .body = {}
};

static Font font_N = {

    .indicator = {},
    .body = {}
};

static Font font_O = {

    .indicator = {},
    .body = {}
};

static Font font_P = {

    .indicator = {},
    .body = {}
};

static Font font_Q = {

    .indicator = {},
    .body = {}
};

static Font font_R = {

    .indicator = {},
    .body = {}
};

static Font font_S = {

    .indicator = {},
    .body = {}
};

static Font font_T = {

    .indicator = {},
    .body = {}
};

static Font font_U = {

    .indicator = {},
    .body = {}
};

static Font font_V = {

    .indicator = {},
    .body = {}
};

static Font font_W = {

    .indicator = {},
    .body = {}
};

static Font font_X = {

    .indicator = {},
    .body = {}
};

static Font font_Y = {

    .indicator = {},
    .body = {}
};

static Font font_Z = {

    .indicator = {},
    .body = {}
};

#endif
