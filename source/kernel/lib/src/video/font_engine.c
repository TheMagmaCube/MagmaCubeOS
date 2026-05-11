// Main font_render lib

// including libs
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../../fonts/font.h"
#include "../../include/video/screen_manager.h"

// font_engine struct
typedef struct {
    uint8_t body[8];
    uint8_t hex_body;

} font_engine;

// init_to_bin func need for changing uint8_t variable to binary format variable
uint8_t int_to_bin(uint8_t i){

    uint8_t bin;

    switch(i){
        case 0:
            bin = 0b0000;
            break;
        case 1:
            bin = 0b0001;
            break;
        case 2:
            bin = 0b0010;
            break;
        case 3:
            bin = 0b0011;
            break;
        case 4:
            bin = 0b0100;
            break;
        case 5:
            bin = 0b0101;
            break;
        case 6:
            bin = 0b0110;
            break;
        case 7:
            bin = 0b0111;
            break;
        case 8:
            bin = 0b1000;
            break;
        case 9:
            bin = 0b1001;
            break;
        case 10:
            bin = 0b1010;
            break;
        case 11:
            bin = 0b1011;
            break;
        case 12:
            bin = 0b1100;
            break;
        case 13:
            bin = 0b1101;
            break;
        case 14:
            bin = 0b1110;
            break;
        case 15:
            bin = 0b1111;
            break;
    }
    return bin;
}

//hex_to_bin func need for change HEX number into binary format variable, uses int_to_bin func
void hex_to_bin(font_engine* font_engine){

    uint8_t first_bits_in_decimal = (font_engine->hex_body >> 4) & 0xF;
    uint8_t second_bits_in_decimal = font_engine->hex_body & 0xF;

    uint8_t first_bits_in_binary = int_to_bin(first_bits_in_decimal);
    uint8_t second_bits_in_binary = int_to_bin(second_bits_in_decimal);

    uint8_t b0_first = (first_bits_in_binary >> 3) & 1;
    uint8_t b1_first = (first_bits_in_binary >> 2) & 1;
    uint8_t b2_first = (first_bits_in_binary >> 1) & 1;
    uint8_t b3_first = first_bits_in_binary & 1;

    uint8_t b0_second = (second_bits_in_binary >> 3) & 1;
    uint8_t b1_second = (second_bits_in_binary >> 2) & 1;
    uint8_t b2_second = (second_bits_in_binary >> 1) & 1;
    uint8_t b3_second = second_bits_in_binary & 1;

    font_engine->body[0] = b0_first;
    font_engine->body[1] = b1_first;
    font_engine->body[2] = b2_first;
    font_engine->body[3] = b3_first;

    font_engine->body[4] = b0_second;
    font_engine->body[5] = b1_second;
    font_engine->body[6] = b2_second;
    font_engine->body[7] = b3_second;
}

// font_selector func need for chosing character and copy data to font_engine variable
void font_selector(font_engine* font_engine, char character, int i){

        switch(character){
            case 'A':
                font_engine->hex_body = font_A.body[i];
                break;
            case 'B':
                font_engine->hex_body = font_B.body[i];
                break;
            case 'C':
                font_engine->hex_body = font_C.body[i];
                break;
            case 'D':
                font_engine->hex_body = font_D.body[i];
                break;
            case 'E':
                font_engine->hex_body = font_E.body[i];
                break;
            case 'F':
                font_engine->hex_body = font_F.body[i];
                break;
            case 'G':
                font_engine->hex_body = font_G.body[i];
                break;
            case 'H':
                font_engine->hex_body = font_H.body[i];
                break;
            case 'I':
                font_engine->hex_body = font_I.body[i];
                break;
            case 'J':
                font_engine->hex_body = font_J.body[i];
                break;
            case 'K':
                font_engine->hex_body = font_K.body[i];
                break;
            case 'L':
                font_engine->hex_body = font_L.body[i];
                break;
            case 'M':
                font_engine->hex_body = font_M.body[i];
                break;
            case 'N':
                font_engine->hex_body = font_N.body[i];
                break;
            case 'O':
                font_engine->hex_body = font_O.body[i];
                break;
            case 'P':
                font_engine->hex_body = font_P.body[i];
                break;
            case 'Q':
                font_engine->hex_body = font_Q.body[i];
                break;
            case 'R':
                font_engine->hex_body = font_R.body[i];
                break;
            case 'S':
                font_engine->hex_body = font_S.body[i];
                break;
            case 'T':
                font_engine->hex_body = font_T.body[i];
                break;
            case 'U':
                font_engine->hex_body = font_U.body[i];
                break;
            case 'W':
                font_engine->hex_body = font_W.body[i];
                break;
            case 'X':
                font_engine->hex_body = font_X.body[i];
                break;
            case 'Y':
                font_engine->hex_body = font_B.body[i];
                break;
            case 'Z':
                font_engine->hex_body = font_Z.body[i];
                break;
            case ' ':
                font_engine->hex_body = font_SPACE.body[i];
                break;
            case 'a':
                font_engine->hex_body = font_a.body[i];
                break;
            case 'b':
                font_engine->hex_body = font_b.body[i];
                break;
            case 'c':
                font_engine->hex_body = font_c.body[i];
                break;
            case 'd':
                font_engine->hex_body = font_d.body[i];
                break;
            case 'e':
                font_engine->hex_body = font_e.body[i];
                break;
            case 'f':
                font_engine->hex_body = font_f.body[i];
                break;
            case 'g':
                font_engine->hex_body = font_g.body[i];
                break;
            case 'h':
                font_engine->hex_body = font_h.body[i];
                break;
            case 'i':
                font_engine->hex_body = font_i.body[i];
                break;
            case 'j':
                font_engine->hex_body = font_j.body[i];
                break;
            case 'k':
                font_engine->hex_body = font_k.body[i];
                break;
            case 'l':
                font_engine->hex_body = font_l.body[i];
                break;
            case 'm':
                font_engine->hex_body = font_m.body[i];
                break;
            case 'n':
                font_engine->hex_body = font_n.body[i];
                break;
            case 'o':
                font_engine->hex_body = font_o.body[i];
                break;
            case 'p':
                font_engine->hex_body = font_p.body[i];
                break;
            case 'q':
                font_engine->hex_body = font_q.body[i];
                break;
            case 'r':
                font_engine->hex_body = font_r.body[i];
                break;
            case 's':
                font_engine->hex_body = font_s.body[i];
                break;
            case 't':
                font_engine->hex_body = font_t.body[i];
                break;
            case 'u':
                font_engine->hex_body = font_u.body[i];
                break;
            case 'v':
                font_engine->hex_body = font_v.body[i];
                break;
            case 'w':
                font_engine->hex_body = font_w.body[i];
                break;
            case 'x':
                font_engine->hex_body = font_x.body[i];
                break;
            case 'y':
                font_engine->hex_body = font_y.body[i];
                break;
            case 'z':
                font_engine->hex_body = font_z.body[i];
                break;
            case '0':
                font_engine->hex_body = font_0.body[i];
                break;
            case '1':
                font_engine->hex_body = font_1.body[i];
                break;
            case '2':
                font_engine->hex_body = font_2.body[i];
                break;
            case '3':
                font_engine->hex_body = font_3.body[i];
                break;
            case '4':
                font_engine->hex_body = font_4.body[i];
                break;
            case '5':
                font_engine->hex_body = font_5.body[i];
                break;
            case '6':
                font_engine->hex_body = font_6.body[i];
                break;
            case '7':
                font_engine->hex_body = font_7.body[i];
                break;
            case '8':
                font_engine->hex_body = font_8.body[i];
                break;
            case '9':
                font_engine->hex_body = font_9.body[i];
                break;
            case '!':
                font_engine->hex_body = font_exclamation_mark.body[i];
                break;
            case '"':
                font_engine->hex_body = font_quotation_mark.body[i];
                break;
            case '#':
                font_engine->hex_body = font_hash.body[i];
                break;
            case '$':
                font_engine->hex_body = font_dollar_sign.body[i];
                break;
            case '%':
                font_engine->hex_body = font_percent_sign.body[i];
                break;
            case '&':
                font_engine->hex_body = font_ampersand.body[i];
                break;
            case '\'':
                font_engine->hex_body = font_apostrophe.body[i];
                break;
            case '(':
                font_engine->hex_body = font_left_paranthesis.body[i];
                break;
            case ')':
                font_engine->hex_body = font_right_paranthesis.body[i];
                break;
            case '*':
                font_engine->hex_body = font_asterisk.body[i];
                break;
            case '+':
                font_engine->hex_body = font_plus_sign.body[i];
                break;
            case ',':
                font_engine->hex_body = font_comma.body[i];
                break;
            case '-':
                font_engine->hex_body = font_minus.body[i];
                break;
            case '.':
                font_engine->hex_body = font_dot.body[i];
                break;
            case '/':
                font_engine->hex_body = font_slash.body[i];
                break;
            case ':':
                font_engine->hex_body = font_colon.body[i];
                break;
            case ';':
                font_engine->hex_body = font_semicolon.body[i];
                break;
            case '<':
                font_engine->hex_body = font_less_then_sign.body[i];
                break;
            case '=':
                font_engine->hex_body = font_equal_sign.body[i];
                break;
            case '>':
                font_engine->hex_body = font_greater_then_sign.body[i];
                break;
            case '?':
                font_engine->hex_body = font_question_mark.body[i];
                break;
            case '@':
                font_engine->hex_body = font_at_sign.body[i];
                break;
            case '[':
                font_engine->hex_body = font_left_square_bracket.body[i];
                break;
            case '\\':
                font_engine->hex_body = font_backslash.body[i];
                break;
            case ']':
                font_engine->hex_body = font_right_square_bracket.body[i];
                break;
            case '^':
                font_engine->hex_body = font_circumflex_accent.body[i];
                break;
            case '_':
                font_engine->hex_body = font_low_line.body[i];
                break;
            case '`':
                font_engine->hex_body = font_grave_accent.body[i];
                break;

        }

        hex_to_bin(font_engine);

}

// font_render func need for render font on screen
void font_render(uint32_t mode, uint64_t address, font_engine* font_engine, char character, uint32_t row, uint64_t column, uint32_t width,
                 uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha){

    for(uint32_t i = 0; i < 16; i++){
        font_selector(font_engine, character, i);
        for(uint32_t k = 0; k < 8; k++){
            uint32_t real_x = k + row * 8;
            uint32_t real_y = i + column * 16;
            if (font_engine->body[k] == 1){
                put_pixel(mode, address, width, real_x, real_y, red, green, blue, alpha);
            }
        }
    }
}

