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

    .indicator = {0x00,0x20},
    .body = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
};

static Font font_A = {

    .indicator = {0x00,0x41},
    .body = {0x00,0x00,0x00,0x00,0x18,0x24,0x24,0x42,0x42,0x7E,0x42,0x42,0x42,0x42,0x00,0x00}

};

static Font font_B = {

    .indicator = {0x00,0x42},
    .body = {0x00,0x00,0x00,0x00,0x7C,0x42,0x42,0x42,0x7C,0x42,0x42,0x42,0x42,0x7C,0x00,0x00}
};

static Font font_C = {

    .indicator = {0x00,0x43},
    .body = {0x00,0x00,0x00,0x00,0x3C,0x42,0x42,0x40,0x40,0x40,0x40,0x42,0x42,0x3C,0x00,0x00}
};

static Font font_D = {

    .indicator = {0x00,0x44},
    .body = {0x00,0x00,0x00,0x00,0x78,0x44,0x42,0x42,0x42,0x42,0x42,0x42,0x44,0x78,0x00,0x00}
};

static Font font_E = {

    .indicator = {0x00,0x45},
    .body = {0x00,0x00,0x00,0x00,0x7E,0x40,0x40,0x40,0x7C,0x40,0x40,0x40,0x40,0x7E,0x00,0x00}
};

static Font font_F = {

    .indicator = {0x00,0x46},
    .body = {0x00,0x00,0x00,0x00,0x7E,0x40,0x40,0x40,0x7C,0x40,0x40,0x40,0x40,0x40,0x00,0x00}
};

static Font font_G = {

    .indicator = {0047:000000003C424240404E4242463A0000},
    .body = {0047:000000003C424240404E4242463A0000}
};

static Font font_H = {

    .indicator = {0048:00000000424242427E42424242420000},
    .body = {0048:00000000424242427E42424242420000}
};

static Font font_I = {

    .indicator = {0049:000000003E08080808080808083E0000},
    .body = {0049:000000003E08080808080808083E0000}
};

static Font font_J = {

    .indicator = {004A:000000001F0404040404044444380000},
    .body = {004A:000000001F0404040404044444380000}
};

static Font font_K = {

    .indicator = {004B:00000000424448506060504844420000},
    .body = {004B:00000000424448506060504844420000}
};

static Font font_L = {

    .indicator = {004C:000000004040404040404040407E0000},
    .body = {004C:000000004040404040404040407E0000}
};

static Font font_M = {

    .indicator = {004D:00000000424266665A5A424242420000},
    .body = {004D:00000000424266665A5A424242420000}
};

static Font font_N = {

    .indicator = {004E:0000000042626252524A4A4646420000},
    .body = {004E:0000000042626252524A4A4646420000}
};

static Font font_O = {

    .indicator = {004F:000000003C42424242424242423C0000},
    .body = {004F:000000003C42424242424242423C0000}
};

static Font font_P = {

    .indicator = {0050:000000007C4242427C40404040400000},
    .body = {0050:000000007C4242427C40404040400000}
};

static Font font_Q = {

    .indicator = {0051:000000003C4242424242425A663C0300},
    .body = {0051:000000003C4242424242425A663C0300}
};

static Font font_R = {

    .indicator = {0052:000000007C4242427C48444442420000},
    .body = {0052:000000007C4242427C48444442420000}
};

static Font font_S = {

    .indicator = {0053:000000003C424240300C0242423C0000},
    .body = {0053:000000003C424240300C0242423C0000}
};

static Font font_T = {

    .indicator = {0054:000000007F0808080808080808080000},
    .body = {0054:000000007F0808080808080808080000}
};

static Font font_U = {

    .indicator = {0055:000000004242424242424242423C0000},
    .body = {0055:000000004242424242424242423C0000}
};

static Font font_V = {

    .indicator = {0056:00000000414141222222141408080000},
    .body = {0056:00000000414141222222141408080000}
};

static Font font_W = {

    .indicator = {0057:00000000424242425A5A666642420000},
    .body = {0057:00000000424242425A5A666642420000}
};

static Font font_X = {

    .indicator = {0058:00000000424224241818242442420000},
    .body = {0058:00000000424224241818242442420000}
};

static Font font_Y = {

    .indicator = {0059:00000000414122221408080808080000},
    .body = {0059:00000000414122221408080808080000}
};

static Font font_Z = {

    .indicator = {005A:000000007E02020408102040407E0000},
    .body = {005A:000000007E02020408102040407E0000}
};

#endif
