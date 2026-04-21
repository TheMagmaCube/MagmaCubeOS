#ifndef FONTS_H
#define FONTS_H

typedef struct{

    int body[6][4];

} Font;

static Font font_a = {
    .body = {
        {0,1,1,0},
        {1,0,0,1},
        {1,0,0,1},
        {1,1,1,1},
        {1,0,0,1},
        {1,0,0,1}
    }
};

static Font font_b = {
    .body = {
        {1,1,1,0},
        {1,0,1,1},
        {1,1,1,0},
        {1,0,1,0},
        {1,0,0,1},
        {1,1,1,0}
    }
};

static Font font_c = {
    .body = {
        {0,1,1,1},
        {1,0,0,0},
        {1,0,0,0},
        {1,0,0,0},
        {1,0,0,0},
        {0,1,1,1}
    }
};

static Font font_d = {
    .body = {
        {1,1,1,0},
        {1,0,1,1},
        {1,0,0,1},
        {1,0,0,1},
        {1,0,1,1},
        {1,1,1,0}
    }
};

#endif
