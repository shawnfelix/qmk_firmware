/*******************************************************************************
 * Size: 36 px
 * Bpp: 1
 * Opts: --bpp 1 --size 36 --no-compress --font HooskaiChamferedSquare.woff --range 32-96,123-126 --format lvgl -o hooskai_font_36.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "../../lvgl.h"
#endif

#ifndef HOOSKAI_FONT_36
#define HOOSKAI_FONT_36 1
#endif

#if HOOSKAI_FONT_36

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xdc, 0xc0, 0x0, 0xf, 0xff, 0xff, 0xf8,

    /* U+0022 "\"" */
    0xf8, 0xff, 0xc7, 0xfe, 0x3f, 0xf1, 0xff, 0x8f,
    0xfc, 0x7f, 0xe3, 0xfe, 0x1e, 0xe0, 0xe6, 0x6,
    0x0,

    /* U+0023 "#" */
    0x7, 0xc1, 0xf0, 0x3, 0xe0, 0xf8, 0x1, 0xf0,
    0x7c, 0x0, 0xf8, 0x3e, 0x0, 0x7c, 0x1f, 0x7,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc1,
    0xf0, 0x7c, 0x0, 0xf8, 0x3e, 0x0, 0x7c, 0x1f,
    0x0, 0x3e, 0xf, 0x80, 0x1f, 0x7, 0xc1, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x7c,
    0x1f, 0x0, 0x3e, 0xf, 0x80, 0x1f, 0x7, 0xc0,
    0xf, 0x83, 0xe0, 0x7, 0xc1, 0xf0, 0x0,

    /* U+0024 "$" */
    0x0, 0x3e, 0x0, 0x0, 0x1f, 0x0, 0x7, 0xff,
    0xff, 0xe7, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x7c,
    0x0, 0xf8, 0x3e, 0x0, 0x7c, 0x1f, 0x0, 0x3f,
    0xff, 0xff, 0x1f, 0xff, 0xff, 0xc7, 0xff, 0xff,
    0xf1, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xfe, 0x0,
    0x7c, 0x1f, 0x0, 0x3e, 0xf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff,
    0xff, 0xe7, 0xff, 0xff, 0xe0, 0x0, 0xf8, 0x0,
    0x0, 0x7c, 0x0, 0x0, 0x3e, 0x0, 0x0,

    /* U+0025 "%" */
    0x0, 0x0, 0x4, 0x0, 0x0, 0x7, 0x0, 0x0,
    0x7, 0xc3, 0xe0, 0x7, 0xf1, 0xf0, 0x7, 0xf0,
    0xf8, 0x7, 0xf0, 0x7c, 0x7, 0xf0, 0x3e, 0x7,
    0xf0, 0x0, 0x7, 0xf0, 0x0, 0x7, 0xf0, 0x0,
    0x7, 0xf0, 0x0, 0x7, 0xf0, 0x0, 0x7, 0xf0,
    0x0, 0x7, 0xf0, 0x0, 0x7, 0xf0, 0x0, 0x7,
    0xf0, 0x0, 0x7, 0xf0, 0x0, 0x7, 0xf0, 0x3e,
    0x7, 0xf0, 0x1f, 0x7, 0xf0, 0xf, 0x87, 0xf0,
    0x7, 0xc7, 0xf0, 0x3, 0xe1, 0xf0, 0x0, 0x0,
    0x70, 0x0, 0x0, 0x10, 0x0, 0x0, 0x0,

    /* U+0026 "&" */
    0x1f, 0xfe, 0x0, 0x1f, 0xff, 0x0, 0x1f, 0xff,
    0x80, 0x1f, 0xff, 0xc0, 0xf, 0xff, 0xe0, 0x7,
    0xc0, 0x0, 0x3, 0xe0, 0x0, 0x1, 0xf0, 0x0,
    0x0, 0xf8, 0x1, 0xf0, 0x7c, 0x0, 0xf8, 0x3f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x3, 0xe0, 0xf8, 0x1, 0xf0, 0x7c, 0x0, 0xf8,
    0x3e, 0x0, 0x7c, 0x1f, 0x0, 0x3e, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xfe,
    0x7f, 0xfd, 0xff, 0x1f, 0xfe, 0x7f, 0x80,

    /* U+0027 "'" */
    0xff, 0xff, 0xff, 0xff, 0xfe, 0xe6, 0x0,

    /* U+0028 "(" */
    0x1f, 0xcf, 0xf7, 0xff, 0xff, 0xff, 0xfe, 0xf,
    0x83, 0xe0, 0xf8, 0x3e, 0xf, 0x83, 0xe0, 0xf8,
    0x3e, 0xf, 0x83, 0xe0, 0xf8, 0x3e, 0xf, 0x83,
    0xe0, 0xff, 0xff, 0xf7, 0xfc, 0xff, 0x1f, 0xc0,

    /* U+0029 ")" */
    0xfe, 0x3f, 0xcf, 0xfb, 0xff, 0xff, 0xc1, 0xf0,
    0x7c, 0x1f, 0x7, 0xc1, 0xf0, 0x7c, 0x1f, 0x7,
    0xc1, 0xf0, 0x7c, 0x1f, 0x7, 0xc1, 0xf0, 0x7c,
    0x1f, 0xff, 0xff, 0xff, 0xfb, 0xfc, 0xfe, 0x0,

    /* U+002A "*" */
    0x3, 0xe0, 0x3, 0xe0, 0x3, 0xe0, 0x3, 0xe0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf, 0xf0, 0x1f, 0xf8, 0x3f, 0xfc,
    0x7f, 0xfe, 0x3e, 0x7c, 0x1c, 0x38, 0x8, 0x10,

    /* U+002B "+" */
    0x3, 0xe0, 0x3, 0xe0, 0x3, 0xe0, 0x3, 0xe0,
    0x3, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x3, 0xe0, 0x3, 0xe0,
    0x3, 0xe0, 0x3, 0xe0, 0x3, 0xe0, 0x3, 0xe0,

    /* U+002C "," */
    0xff, 0xff, 0xff, 0xff, 0xfe, 0xe6, 0x0,

    /* U+002D "-" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,

    /* U+002E "." */
    0xff, 0xff, 0xff, 0x80,

    /* U+002F "/" */
    0x0, 0x0, 0x4, 0x0, 0x0, 0x7, 0x0, 0x0,
    0x7, 0xc0, 0x0, 0x7, 0xf0, 0x0, 0x7, 0xf0,
    0x0, 0x7, 0xf0, 0x0, 0x7, 0xf0, 0x0, 0x7,
    0xf0, 0x0, 0x7, 0xf0, 0x0, 0x7, 0xf0, 0x0,
    0x7, 0xf0, 0x0, 0x7, 0xf0, 0x0, 0x7, 0xf0,
    0x0, 0x7, 0xf0, 0x0, 0x7, 0xf0, 0x0, 0x7,
    0xf0, 0x0, 0x7, 0xf0, 0x0, 0x7, 0xf0, 0x0,
    0x7, 0xf0, 0x0, 0x7, 0xf0, 0x0, 0x7, 0xf0,
    0x0, 0x7, 0xf0, 0x0, 0x1, 0xf0, 0x0, 0x0,
    0x70, 0x0, 0x0, 0x10, 0x0, 0x0, 0x0,

    /* U+0030 "0" */
    0x1f, 0xf0, 0x7f, 0xf1, 0xff, 0xf7, 0xff, 0xff,
    0xff, 0xff, 0x7, 0xfe, 0xf, 0xfc, 0x1f, 0xf8,
    0x3f, 0xf0, 0x7f, 0xe0, 0xff, 0xc1, 0xff, 0x83,
    0xff, 0x7, 0xfe, 0xf, 0xfc, 0x1f, 0xf8, 0x3f,
    0xf0, 0x7f, 0xe0, 0xff, 0xc1, 0xff, 0xff, 0xff,
    0xff, 0xdf, 0xff, 0x1f, 0xfc, 0x1f, 0xf0,

    /* U+0031 "1" */
    0x1f, 0xc0, 0x7f, 0x81, 0xff, 0x7, 0xfe, 0xf,
    0xfc, 0x0, 0xf8, 0x1, 0xf0, 0x3, 0xe0, 0x7,
    0xc0, 0xf, 0x80, 0x1f, 0x0, 0x3e, 0x0, 0x7c,
    0x0, 0xf8, 0x1, 0xf0, 0x3, 0xe0, 0x7, 0xc0,
    0xf, 0x80, 0x1f, 0x0, 0x3e, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,

    /* U+0032 "2" */
    0xff, 0xf1, 0xff, 0xf3, 0xff, 0xf7, 0xff, 0xff,
    0xff, 0xe0, 0x7, 0xc0, 0xf, 0x80, 0x1f, 0x0,
    0x3e, 0x0, 0x7c, 0x7f, 0xf9, 0xff, 0xf7, 0xff,
    0xdf, 0xff, 0x3f, 0xfc, 0x7c, 0x0, 0xf8, 0x1,
    0xf0, 0x3, 0xe0, 0x7, 0xc0, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,

    /* U+0033 "3" */
    0xff, 0xf1, 0xff, 0xf3, 0xff, 0xf7, 0xff, 0xff,
    0xff, 0xe0, 0x7, 0xc0, 0xf, 0x80, 0x1f, 0x0,
    0x3e, 0x0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xdf, 0xff, 0xff, 0xff, 0x80, 0x1f, 0x0, 0x3e,
    0x0, 0x7c, 0x0, 0xf8, 0x1, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x7f, 0xfc, 0xff, 0xf0,

    /* U+0034 "4" */
    0xf8, 0x3f, 0xf0, 0x7f, 0xe0, 0xff, 0xc1, 0xff,
    0x83, 0xff, 0x7, 0xfe, 0xf, 0xfc, 0x1f, 0xf8,
    0x3f, 0xf0, 0x7f, 0xff, 0xff, 0xff, 0xf7, 0xff,
    0xe7, 0xff, 0xc7, 0xff, 0x80, 0x1f, 0x0, 0x3e,
    0x0, 0x7c, 0x0, 0xf8, 0x1, 0xf0, 0x3, 0xe0,
    0x7, 0xc0, 0xf, 0x80, 0x1f, 0x0, 0x3e,

    /* U+0035 "5" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x0, 0x3e, 0x0, 0x7c, 0x0, 0xf8,
    0x1, 0xf0, 0x3, 0xff, 0xc7, 0xff, 0xc7, 0xff,
    0xc7, 0xff, 0xc7, 0xff, 0x80, 0x1f, 0x0, 0x3e,
    0x0, 0x7c, 0x0, 0xf8, 0x1, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x7f, 0xfc, 0xff, 0xf0,

    /* U+0036 "6" */
    0x1f, 0xfe, 0x7f, 0xfd, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x0, 0x3e, 0x0, 0x7c, 0x0, 0xf8,
    0x1, 0xf0, 0x3, 0xff, 0xc7, 0xff, 0xcf, 0xff,
    0xdf, 0xff, 0xff, 0xff, 0xfc, 0x1f, 0xf8, 0x3f,
    0xf0, 0x7f, 0xe0, 0xff, 0xc1, 0xff, 0xff, 0xff,
    0xff, 0xdf, 0xff, 0x1f, 0xfc, 0x1f, 0xf0,

    /* U+0037 "7" */
    0xff, 0xf1, 0xff, 0xf3, 0xff, 0xf7, 0xff, 0xff,
    0xff, 0xe0, 0x7, 0xc0, 0xf, 0x80, 0x1f, 0x0,
    0x3e, 0x0, 0x7c, 0x0, 0xf8, 0x1, 0xf0, 0x3,
    0xe0, 0x7, 0xc0, 0xf, 0x80, 0x1f, 0x0, 0x3e,
    0x0, 0x7c, 0x0, 0xf8, 0x1, 0xf0, 0x3, 0xe0,
    0x7, 0xc0, 0xf, 0x80, 0x1f, 0x0, 0x3e,

    /* U+0038 "8" */
    0x1f, 0xf0, 0x7f, 0xf1, 0xff, 0xf7, 0xff, 0xff,
    0xff, 0xff, 0x7, 0xfe, 0xf, 0xfc, 0x1f, 0xf8,
    0x3f, 0xf0, 0x7f, 0xff, 0xff, 0xff, 0xf7, 0xff,
    0xdf, 0xff, 0xff, 0xff, 0xfc, 0x1f, 0xf8, 0x3f,
    0xf0, 0x7f, 0xe0, 0xff, 0xc1, 0xff, 0xff, 0xff,
    0xff, 0xdf, 0xff, 0x1f, 0xfc, 0x1f, 0xf0,

    /* U+0039 "9" */
    0x1f, 0xf0, 0x7f, 0xf1, 0xff, 0xf7, 0xff, 0xff,
    0xff, 0xff, 0x7, 0xfe, 0xf, 0xfc, 0x1f, 0xf8,
    0x3f, 0xf0, 0x7f, 0xff, 0xff, 0xff, 0xf7, 0xff,
    0xe7, 0xff, 0xc7, 0xff, 0x80, 0x1f, 0x0, 0x3e,
    0x0, 0x7c, 0x0, 0xf8, 0x1, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x7f, 0xfc, 0xff, 0xf0,

    /* U+003A ":" */
    0xff, 0xff, 0xff, 0x80, 0x0, 0x0, 0x3f, 0xff,
    0xff, 0xe0,

    /* U+003B ";" */
    0xff, 0xff, 0xff, 0x80, 0x0, 0x0, 0x3f, 0xff,
    0xff, 0xff, 0xff, 0xb9, 0x80,

    /* U+003C "<" */
    0x0, 0x8, 0x0, 0x1c, 0x0, 0x3e, 0x0, 0x7f,
    0x0, 0xfe, 0x1, 0xfc, 0x3, 0xf8, 0x7, 0xf0,
    0xf, 0xe0, 0x1f, 0xc0, 0x3f, 0x80, 0x7f, 0x0,
    0xfe, 0x0, 0x7f, 0x0, 0x3f, 0x80, 0x1f, 0xc0,
    0xf, 0xe0, 0x7, 0xf0, 0x3, 0xf8, 0x1, 0xfc,
    0x0, 0xfe, 0x0, 0x7f, 0x0, 0x3e, 0x0, 0x1c,
    0x0, 0x8,

    /* U+003D "=" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,

    /* U+003E ">" */
    0x10, 0x0, 0x38, 0x0, 0x7c, 0x0, 0xfe, 0x0,
    0x7f, 0x0, 0x3f, 0x80, 0x1f, 0xc0, 0xf, 0xe0,
    0x7, 0xf0, 0x3, 0xf8, 0x1, 0xfc, 0x0, 0xfe,
    0x0, 0x7f, 0x0, 0xfe, 0x1, 0xfc, 0x3, 0xf8,
    0x7, 0xf0, 0xf, 0xe0, 0x1f, 0xc0, 0x3f, 0x80,
    0x7f, 0x0, 0xfe, 0x0, 0x7c, 0x0, 0x38, 0x0,
    0x10, 0x0,

    /* U+003F "?" */
    0x1f, 0xf0, 0x7f, 0xf1, 0xff, 0xf7, 0xff, 0xf7,
    0xff, 0xe7, 0x7, 0xc4, 0xf, 0x80, 0x3f, 0x0,
    0xfe, 0x3, 0xf8, 0xf, 0xe0, 0x3f, 0x80, 0x7e,
    0x0, 0xf8, 0x1, 0xf0, 0x3, 0xe0, 0x7, 0xc0,
    0xf, 0x80, 0x0, 0x0, 0x0, 0x0, 0x7c, 0x0,
    0xf8, 0x1, 0xf0, 0x3, 0xe0, 0x7, 0xc0,

    /* U+0041 "A" */
    0x0, 0x0, 0x4, 0x0, 0x0, 0x7, 0x0, 0x0,
    0x7, 0xc0, 0x0, 0x7, 0xf0, 0x0, 0x7, 0xf8,
    0x0, 0x7, 0xfc, 0x0, 0x7, 0xfe, 0x0, 0x7,
    0xff, 0x0, 0x7, 0xff, 0x80, 0x7, 0xf7, 0xc0,
    0x7, 0xf3, 0xe0, 0x7, 0xf1, 0xf0, 0x7, 0xf0,
    0xf8, 0x7, 0xf0, 0x7c, 0x7, 0xf0, 0x3e, 0x7,
    0xf0, 0x1f, 0x7, 0xf0, 0xf, 0x87, 0xf0, 0x7,
    0xc7, 0xf0, 0x3, 0xe7, 0xf0, 0x1, 0xf7, 0xff,
    0xe0, 0xff, 0xff, 0xf0, 0x7d, 0xff, 0xf8, 0x3e,
    0x7f, 0xfc, 0x1f, 0x1f, 0xfe, 0xf, 0x80,

    /* U+0042 "B" */
    0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0x3f, 0xff,
    0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0x0, 0x7f, 0xe0, 0x0, 0x3f, 0xf0, 0x0,
    0x1f, 0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff,
    0xe7, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x1f, 0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7,
    0xfe, 0x0, 0x3, 0xff, 0x0, 0x1, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd,
    0xff, 0xff, 0xfc, 0xff, 0xff, 0xfc, 0x0,

    /* U+0043 "C" */
    0x1f, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xdf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0x0, 0x3, 0xe0, 0x0, 0x1, 0xf0, 0x0,
    0x0, 0xf8, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x3e,
    0x0, 0x0, 0x1f, 0x0, 0x0, 0xf, 0x80, 0x0,
    0x7, 0xc0, 0x0, 0x3, 0xe0, 0x0, 0x1, 0xf0,
    0x0, 0x0, 0xf8, 0x0, 0x0, 0x7c, 0x0, 0x0,
    0x3e, 0x0, 0x0, 0x1f, 0x0, 0x0, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xfe,
    0x7f, 0xff, 0xff, 0x1f, 0xff, 0xff, 0x80,

    /* U+0044 "D" */
    0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0x3f, 0xff,
    0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0x0, 0x7f, 0xe0, 0x0, 0x3f, 0xf0, 0x0,
    0x1f, 0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7, 0xfe,
    0x0, 0x3, 0xff, 0x0, 0x1, 0xff, 0x80, 0x0,
    0xff, 0xc0, 0x0, 0x7f, 0xe0, 0x0, 0x3f, 0xf0,
    0x0, 0x1f, 0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7,
    0xfe, 0x0, 0x3, 0xff, 0x0, 0x1, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd,
    0xff, 0xff, 0xfc, 0xff, 0xff, 0xfc, 0x0,

    /* U+0045 "E" */
    0x1f, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xdf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0x0, 0x3, 0xe0, 0x0, 0x1, 0xf0, 0x0,
    0x0, 0xf8, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x3f,
    0xff, 0xfc, 0x1f, 0xff, 0xfe, 0xf, 0xff, 0xff,
    0x7, 0xff, 0xff, 0x83, 0xff, 0xff, 0xc1, 0xf0,
    0x0, 0x0, 0xf8, 0x0, 0x0, 0x7c, 0x0, 0x0,
    0x3e, 0x0, 0x0, 0x1f, 0x0, 0x0, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xfe,
    0x7f, 0xff, 0xff, 0x1f, 0xff, 0xff, 0x80,

    /* U+0046 "F" */
    0x1f, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xdf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0x0, 0x3, 0xe0, 0x0, 0x1, 0xf0, 0x0,
    0x0, 0xf8, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x3f,
    0xff, 0xfc, 0x1f, 0xff, 0xfe, 0xf, 0xff, 0xff,
    0x7, 0xff, 0xff, 0x83, 0xff, 0xff, 0xc1, 0xf0,
    0x0, 0x0, 0xf8, 0x0, 0x0, 0x7c, 0x0, 0x0,
    0x3e, 0x0, 0x0, 0x1f, 0x0, 0x0, 0xf, 0x80,
    0x0, 0x7, 0xc0, 0x0, 0x3, 0xe0, 0x0, 0x1,
    0xf0, 0x0, 0x0, 0xf8, 0x0, 0x0, 0x0,

    /* U+0047 "G" */
    0x1f, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xdf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0x0, 0x3, 0xe0, 0x0, 0x1, 0xf0, 0x0,
    0x0, 0xf8, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x3e,
    0xf, 0xff, 0x1f, 0x7, 0xff, 0xcf, 0x83, 0xff,
    0xf7, 0xc1, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xf0,
    0x0, 0x1f, 0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7,
    0xfe, 0x0, 0x3, 0xff, 0x0, 0x1, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xfc,
    0x7f, 0xff, 0xfc, 0x1f, 0xff, 0xfc, 0x0,

    /* U+0048 "H" */
    0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7, 0xfe, 0x0,
    0x3, 0xff, 0x0, 0x1, 0xff, 0x80, 0x0, 0xff,
    0xc0, 0x0, 0x7f, 0xe0, 0x0, 0x3f, 0xf0, 0x0,
    0x1f, 0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x1f, 0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7,
    0xfe, 0x0, 0x3, 0xff, 0x0, 0x1, 0xff, 0x80,
    0x0, 0xff, 0xc0, 0x0, 0x7f, 0xe0, 0x0, 0x3f,
    0xf0, 0x0, 0x1f, 0xf8, 0x0, 0xf, 0x80,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8,

    /* U+004A "J" */
    0x0, 0x0, 0xf, 0x80, 0x0, 0x7, 0xc0, 0x0,
    0x3, 0xe0, 0x0, 0x1, 0xf0, 0x0, 0x0, 0xf8,
    0x0, 0x0, 0x7c, 0x0, 0x0, 0x3e, 0x0, 0x0,
    0x1f, 0x0, 0x0, 0xf, 0x80, 0x0, 0x7, 0xc0,
    0x0, 0x3, 0xe0, 0x0, 0x1, 0xf0, 0x0, 0x0,
    0xf8, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x3f, 0xf0,
    0x0, 0x1f, 0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7,
    0xfe, 0x0, 0x3, 0xff, 0x0, 0x1, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xfc,
    0x7f, 0xff, 0xfc, 0x1f, 0xff, 0xfc, 0x0,

    /* U+004B "K" */
    0xf8, 0x0, 0x4, 0x7c, 0x0, 0x7, 0x3e, 0x0,
    0x7, 0xdf, 0x0, 0x7, 0xff, 0x80, 0x7, 0xf7,
    0xc0, 0x7, 0xf3, 0xe0, 0x7, 0xf1, 0xf0, 0x7,
    0xf0, 0xf8, 0x7, 0xf0, 0x7c, 0x7, 0xf0, 0x3e,
    0x7, 0xf0, 0x1f, 0x7, 0xf0, 0xf, 0x87, 0xf0,
    0x7, 0xc7, 0xfc, 0x3, 0xe7, 0xff, 0x1, 0xf7,
    0xff, 0xc0, 0xff, 0xf7, 0xf0, 0x7f, 0xf1, 0xfc,
    0x3f, 0xf0, 0x7f, 0x1f, 0xf0, 0x1f, 0xcf, 0xf0,
    0x7, 0xf7, 0xf0, 0x1, 0xfd, 0xf0, 0x0, 0x7c,
    0x70, 0x0, 0x1c, 0x10, 0x0, 0x4, 0x0,

    /* U+004C "L" */
    0xf8, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x3e, 0x0,
    0x0, 0x1f, 0x0, 0x0, 0xf, 0x80, 0x0, 0x7,
    0xc0, 0x0, 0x3, 0xe0, 0x0, 0x1, 0xf0, 0x0,
    0x0, 0xf8, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x3e,
    0x0, 0x0, 0x1f, 0x0, 0x0, 0xf, 0x80, 0x0,
    0x7, 0xc0, 0x0, 0x3, 0xe0, 0x0, 0x1, 0xf0,
    0x0, 0x0, 0xf8, 0x0, 0x0, 0x7c, 0x0, 0x0,
    0x3e, 0x0, 0x0, 0x1f, 0x0, 0x0, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xfe,
    0x7f, 0xff, 0xff, 0x1f, 0xff, 0xff, 0x80,

    /* U+004D "M" */
    0x10, 0x0, 0x4, 0x1c, 0x0, 0x7, 0x1f, 0x0,
    0x7, 0xdf, 0xc0, 0x7, 0xff, 0xf0, 0x7, 0xff,
    0xfc, 0x7, 0xff, 0xff, 0x7, 0xff, 0xff, 0xc7,
    0xff, 0xff, 0xf7, 0xff, 0xfd, 0xff, 0xf7, 0xfe,
    0x7f, 0xf3, 0xff, 0x1f, 0xf1, 0xff, 0x87, 0xf0,
    0xff, 0xc1, 0xf0, 0x7f, 0xe0, 0x70, 0x3f, 0xf0,
    0x10, 0x1f, 0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7,
    0xfe, 0x0, 0x3, 0xff, 0x0, 0x1, 0xff, 0x80,
    0x0, 0xff, 0xc0, 0x0, 0x7f, 0xe0, 0x0, 0x3f,
    0xf0, 0x0, 0x1f, 0xf8, 0x0, 0xf, 0x80,

    /* U+004E "N" */
    0x10, 0x0, 0xf, 0x9c, 0x0, 0x7, 0xdf, 0x0,
    0x3, 0xff, 0xc0, 0x1, 0xff, 0xf0, 0x0, 0xff,
    0xfc, 0x0, 0x7f, 0xff, 0x0, 0x3f, 0xff, 0xc0,
    0x1f, 0xff, 0xf0, 0xf, 0xfd, 0xfc, 0x7, 0xfe,
    0x7f, 0x3, 0xff, 0x1f, 0xc1, 0xff, 0x87, 0xf0,
    0xff, 0xc1, 0xfc, 0x7f, 0xe0, 0x7f, 0x3f, 0xf0,
    0x1f, 0xdf, 0xf8, 0x7, 0xff, 0xfc, 0x1, 0xff,
    0xfe, 0x0, 0x7f, 0xff, 0x0, 0x1f, 0xff, 0x80,
    0x7, 0xff, 0xc0, 0x1, 0xff, 0xe0, 0x0, 0x7d,
    0xf0, 0x0, 0x1c, 0xf8, 0x0, 0x4, 0x0,

    /* U+004F "O" */
    0x1f, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0x1f, 0xff,
    0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0x0, 0x7f, 0xe0, 0x0, 0x3f, 0xf0, 0x0,
    0x1f, 0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7, 0xfe,
    0x0, 0x3, 0xff, 0x0, 0x1, 0xff, 0x80, 0x0,
    0xff, 0xc0, 0x0, 0x7f, 0xe0, 0x0, 0x3f, 0xf0,
    0x0, 0x1f, 0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7,
    0xfe, 0x0, 0x3, 0xff, 0x0, 0x1, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xfc,
    0x7f, 0xff, 0xfc, 0x1f, 0xff, 0xfc, 0x0,

    /* U+0050 "P" */
    0x1f, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0x1f, 0xff,
    0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0x0, 0x7f, 0xe0, 0x0, 0x3f, 0xf0, 0x0,
    0x1f, 0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf7, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xf1, 0xf0,
    0x0, 0x0, 0xf8, 0x0, 0x0, 0x7c, 0x0, 0x0,
    0x3e, 0x0, 0x0, 0x1f, 0x0, 0x0, 0xf, 0x80,
    0x0, 0x7, 0xc0, 0x0, 0x3, 0xe0, 0x0, 0x1,
    0xf0, 0x0, 0x0, 0xf8, 0x0, 0x0, 0x0,

    /* U+0051 "Q" */
    0x1f, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0x1f, 0xff,
    0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0x0, 0x7f, 0xe0, 0x0, 0x3f, 0xf0, 0x0,
    0x1f, 0xf8, 0x0, 0xf, 0xfc, 0x4, 0x7, 0xfe,
    0x7, 0x3, 0xff, 0x7, 0xc1, 0xff, 0x87, 0xf0,
    0xff, 0xc1, 0xfc, 0x7f, 0xe0, 0x7f, 0x3f, 0xf0,
    0x1f, 0xdf, 0xf8, 0x7, 0xff, 0xfc, 0x1, 0xff,
    0xfe, 0x0, 0x7f, 0xff, 0x0, 0x1f, 0xff, 0xfc,
    0x7, 0xff, 0xff, 0x1, 0xfd, 0xff, 0xc0, 0x7c,
    0x7f, 0xf0, 0x1c, 0x1f, 0xfc, 0x4, 0x0,

    /* U+0052 "R" */
    0x1f, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0x1f, 0xff,
    0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0x0, 0x7f, 0xe0, 0x0, 0x3f, 0xf0, 0x0,
    0x1f, 0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf7, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xf1, 0xf0,
    0x1f, 0xc0, 0xf8, 0x7, 0xf0, 0x7c, 0x1, 0xfc,
    0x3e, 0x0, 0x7f, 0x1f, 0x0, 0x1f, 0xcf, 0x80,
    0x7, 0xf7, 0xc0, 0x1, 0xff, 0xe0, 0x0, 0x7d,
    0xf0, 0x0, 0x1c, 0xf8, 0x0, 0x4, 0x0,

    /* U+0053 "S" */
    0x1f, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xdf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0x0, 0x3, 0xe0, 0x0, 0x1, 0xf0, 0x0,
    0x0, 0xf8, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x3f,
    0xff, 0xff, 0x1f, 0xff, 0xff, 0xc7, 0xff, 0xff,
    0xf1, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xfe, 0x0,
    0x0, 0x1f, 0x0, 0x0, 0xf, 0x80, 0x0, 0x7,
    0xc0, 0x0, 0x3, 0xe0, 0x0, 0x1, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd,
    0xff, 0xff, 0xfc, 0xff, 0xff, 0xfc, 0x0,

    /* U+0054 "T" */
    0xff, 0xc7, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xf7,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8,
    0x1, 0xf0, 0x0, 0x0, 0xf8, 0x0, 0x0, 0x7c,
    0x0, 0x0, 0x3e, 0x0, 0x0, 0x1f, 0x0, 0x0,
    0xf, 0x80, 0x0, 0x7, 0xc0, 0x0, 0x3, 0xe0,
    0x0, 0x1, 0xf0, 0x0, 0x0, 0xf8, 0x0, 0x0,
    0x7c, 0x0, 0x0, 0x3e, 0x0, 0x0, 0x1f, 0x0,
    0x0, 0xf, 0x80, 0x0, 0x7, 0xc0, 0x0, 0x3,
    0xe0, 0x0, 0x1, 0xf0, 0x0, 0x0, 0xf8, 0x0,
    0x0, 0x7c, 0x0, 0x0, 0x3e, 0x0, 0x0,

    /* U+0055 "U" */
    0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7, 0xfe, 0x0,
    0x3, 0xff, 0x0, 0x1, 0xff, 0x80, 0x0, 0xff,
    0xc0, 0x0, 0x7f, 0xe0, 0x0, 0x3f, 0xf0, 0x0,
    0x1f, 0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7, 0xfe,
    0x0, 0x3, 0xff, 0x0, 0x1, 0xff, 0x80, 0x0,
    0xff, 0xc0, 0x0, 0x7f, 0xe0, 0x0, 0x3f, 0xf0,
    0x0, 0x1f, 0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7,
    0xfe, 0x0, 0x3, 0xff, 0x0, 0x1, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xfc,
    0x7f, 0xff, 0xfc, 0x1f, 0xff, 0xfc, 0x0,

    /* U+0056 "V" */
    0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7, 0xfe, 0x0,
    0x3, 0xff, 0x0, 0x1, 0xff, 0x80, 0x0, 0xff,
    0xc0, 0x0, 0x7f, 0xe0, 0x0, 0x3f, 0xf0, 0x0,
    0x1f, 0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7, 0xfe,
    0x0, 0x3, 0xff, 0x80, 0x3, 0xff, 0xe0, 0x3,
    0xfb, 0xf8, 0x3, 0xf8, 0xfe, 0x3, 0xf8, 0x3f,
    0x83, 0xf8, 0xf, 0xe3, 0xf8, 0x3, 0xfb, 0xf8,
    0x0, 0xff, 0xf8, 0x0, 0x3f, 0xf8, 0x0, 0xf,
    0xf8, 0x0, 0x3, 0xf8, 0x0, 0x0, 0xf8, 0x0,
    0x0, 0x38, 0x0, 0x0, 0x8, 0x0, 0x0,

    /* U+0057 "W" */
    0xf8, 0x0, 0xf, 0xfc, 0x0, 0x7, 0xfe, 0x0,
    0x3, 0xff, 0x0, 0x1, 0xff, 0x80, 0x0, 0xff,
    0xc0, 0x0, 0x7f, 0xe0, 0x0, 0x3f, 0xf0, 0x0,
    0x1f, 0xf8, 0x0, 0xf, 0xfc, 0x4, 0x7, 0xfe,
    0x7, 0x3, 0xff, 0x7, 0xc1, 0xff, 0x87, 0xf0,
    0xff, 0xc7, 0xfc, 0x7f, 0xe7, 0xff, 0x3f, 0xf7,
    0xff, 0xdf, 0xff, 0xf7, 0xff, 0xff, 0xf1, 0xff,
    0xff, 0xf0, 0x7f, 0xff, 0xf0, 0x1f, 0xff, 0xf0,
    0x7, 0xff, 0xf0, 0x1, 0xfd, 0xf0, 0x0, 0x7c,
    0x70, 0x0, 0x1c, 0x10, 0x0, 0x4, 0x0,

    /* U+0058 "X" */
    0x10, 0x0, 0x4, 0x1c, 0x0, 0x7, 0x1f, 0x0,
    0x7, 0xdf, 0xc0, 0x7, 0xf7, 0xf0, 0x7, 0xf1,
    0xfc, 0x7, 0xf0, 0x7f, 0x7, 0xf0, 0x1f, 0xc7,
    0xf0, 0x7, 0xf7, 0xf0, 0x1, 0xff, 0xf0, 0x0,
    0x7f, 0xf0, 0x0, 0x1f, 0xf0, 0x0, 0x7, 0xf0,
    0x0, 0x7, 0xfc, 0x0, 0x7, 0xff, 0x0, 0x7,
    0xff, 0xc0, 0x7, 0xf7, 0xf0, 0x7, 0xf1, 0xfc,
    0x7, 0xf0, 0x7f, 0x7, 0xf0, 0x1f, 0xc7, 0xf0,
    0x7, 0xf7, 0xf0, 0x1, 0xfd, 0xf0, 0x0, 0x7c,
    0x70, 0x0, 0x1c, 0x10, 0x0, 0x4, 0x0,

    /* U+0059 "Y" */
    0x10, 0x0, 0x4, 0x1c, 0x0, 0x7, 0x1f, 0x0,
    0x7, 0xdf, 0xc0, 0x7, 0xf7, 0xf0, 0x7, 0xf1,
    0xfc, 0x7, 0xf0, 0x7f, 0x7, 0xf0, 0x1f, 0xc7,
    0xf0, 0x7, 0xf7, 0xf0, 0x1, 0xff, 0xf0, 0x0,
    0x7f, 0xf0, 0x0, 0x1f, 0xf0, 0x0, 0x7, 0xf0,
    0x0, 0x1, 0xf0, 0x0, 0x0, 0xf8, 0x0, 0x0,
    0x7c, 0x0, 0x0, 0x3e, 0x0, 0x0, 0x1f, 0x0,
    0x0, 0xf, 0x80, 0x0, 0x7, 0xc0, 0x0, 0x3,
    0xe0, 0x0, 0x1, 0xf0, 0x0, 0x0, 0xf8, 0x0,
    0x0, 0x7c, 0x0, 0x0, 0x3e, 0x0, 0x0,

    /* U+005A "Z" */
    0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0x3f, 0xff,
    0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x7, 0xf0, 0x0, 0x7, 0xf0, 0x0, 0x7,
    0xf0, 0x0, 0x7, 0xf0, 0x0, 0x7, 0xf0, 0x0,
    0x7, 0xf0, 0x0, 0x7, 0xf0, 0x0, 0x7, 0xf0,
    0x0, 0x7, 0xf0, 0x0, 0x7, 0xf0, 0x0, 0x7,
    0xf0, 0x0, 0x7, 0xf0, 0x0, 0x7, 0xf0, 0x0,
    0x7, 0xf0, 0x0, 0x7, 0xf0, 0x0, 0x7, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xfe,
    0x7f, 0xff, 0xff, 0x1f, 0xff, 0xff, 0x80,

    /* U+005B "[" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf,
    0x83, 0xe0, 0xf8, 0x3e, 0xf, 0x83, 0xe0, 0xf8,
    0x3e, 0xf, 0x83, 0xe0, 0xf8, 0x3e, 0xf, 0x83,
    0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+005C "\\" */
    0x10, 0x0, 0x0, 0x1c, 0x0, 0x0, 0x1f, 0x0,
    0x0, 0x1f, 0xc0, 0x0, 0x7, 0xf0, 0x0, 0x1,
    0xfc, 0x0, 0x0, 0x7f, 0x0, 0x0, 0x1f, 0xc0,
    0x0, 0x7, 0xf0, 0x0, 0x1, 0xfc, 0x0, 0x0,
    0x7f, 0x0, 0x0, 0x1f, 0xc0, 0x0, 0x7, 0xf0,
    0x0, 0x1, 0xfc, 0x0, 0x0, 0x7f, 0x0, 0x0,
    0x1f, 0xc0, 0x0, 0x7, 0xf0, 0x0, 0x1, 0xfc,
    0x0, 0x0, 0x7f, 0x0, 0x0, 0x1f, 0xc0, 0x0,
    0x7, 0xf0, 0x0, 0x1, 0xfc, 0x0, 0x0, 0x7c,
    0x0, 0x0, 0x1c, 0x0, 0x0, 0x4, 0x0,

    /* U+005D "]" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xf0,
    0x7c, 0x1f, 0x7, 0xc1, 0xf0, 0x7c, 0x1f, 0x7,
    0xc1, 0xf0, 0x7c, 0x1f, 0x7, 0xc1, 0xf0, 0x7c,
    0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+005F "_" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8,

    /* U+0060 "`" */
    0xff, 0xff, 0xff, 0xff, 0xef, 0x38, 0xc0,

    /* U+007E "~" */
    0x0, 0x0, 0xf, 0x80, 0x0, 0x7, 0xc0, 0x0,
    0x3, 0xe0, 0x0, 0x1, 0xf0, 0x0, 0x0, 0xf8,
    0xff, 0xff, 0xfc, 0xff, 0xff, 0xfe, 0xff, 0xff,
    0xfe, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xfe, 0x3e,
    0x0, 0x0, 0x1f, 0x0, 0x0, 0xf, 0x80, 0x0,
    0x7, 0xc0, 0x0, 0x3, 0xe0, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 121, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 202, .box_w = 5, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 324, .box_w = 13, .box_h = 10, .ofs_x = 4, .ofs_y = 15},
    {.bitmap_index = 34, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 113, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 192, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 271, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 202, .box_w = 5, .box_h = 10, .ofs_x = 4, .ofs_y = 15},
    {.bitmap_index = 357, .adv_w = 282, .box_w = 10, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 389, .adv_w = 282, .box_w = 10, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 421, .adv_w = 377, .box_w = 16, .box_h = 16, .ofs_x = 4, .ofs_y = 9},
    {.bitmap_index = 453, .adv_w = 379, .box_w = 16, .box_h = 16, .ofs_x = 4, .ofs_y = 4},
    {.bitmap_index = 485, .adv_w = 202, .box_w = 5, .box_h = 10, .ofs_x = 4, .ofs_y = -5},
    {.bitmap_index = 492, .adv_w = 291, .box_w = 11, .box_h = 5, .ofs_x = 4, .ofs_y = 10},
    {.bitmap_index = 499, .adv_w = 202, .box_w = 5, .box_h = 5, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 503, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 582, .adv_w = 363, .box_w = 15, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 629, .adv_w = 363, .box_w = 15, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 676, .adv_w = 363, .box_w = 15, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 723, .adv_w = 363, .box_w = 15, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 770, .adv_w = 363, .box_w = 15, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 817, .adv_w = 363, .box_w = 15, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 864, .adv_w = 363, .box_w = 15, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 911, .adv_w = 363, .box_w = 15, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 958, .adv_w = 363, .box_w = 15, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1005, .adv_w = 363, .box_w = 15, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1052, .adv_w = 202, .box_w = 5, .box_h = 15, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1062, .adv_w = 202, .box_w = 5, .box_h = 20, .ofs_x = 4, .ofs_y = -5},
    {.bitmap_index = 1075, .adv_w = 379, .box_w = 16, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1125, .adv_w = 379, .box_w = 16, .box_h = 16, .ofs_x = 4, .ofs_y = 4},
    {.bitmap_index = 1157, .adv_w = 379, .box_w = 16, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1207, .adv_w = 363, .box_w = 15, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1254, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1333, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1412, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1491, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1570, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1649, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1728, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1807, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1886, .adv_w = 202, .box_w = 5, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1902, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1981, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 2060, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 2139, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 2218, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 2297, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 2376, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 2455, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 2534, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 2613, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 2692, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 2771, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 2850, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 2929, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 3008, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 3087, .adv_w = 525, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 3166, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 3245, .adv_w = 282, .box_w = 10, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 3277, .adv_w = 524, .box_w = 25, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 3356, .adv_w = 282, .box_w = 10, .box_h = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 3388, .adv_w = 524, .box_w = 25, .box_h = 5, .ofs_x = 4, .ofs_y = -7},
    {.bitmap_index = 3404, .adv_w = 202, .box_w = 5, .box_h = 10, .ofs_x = 4, .ofs_y = 15},
    {.bitmap_index = 3411, .adv_w = 524, .box_w = 25, .box_h = 15, .ofs_x = 4, .ofs_y = 5}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_2[] = {
    0x0, 0x1, 0x1f
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 32, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 65, .range_length = 29, .glyph_id_start = 33,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 95, .range_length = 32, .glyph_id_start = 62,
        .unicode_list = unicode_list_2, .glyph_id_ofs_list = NULL, .list_length = 3, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    54, 33,
    57, 33
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -77, -116
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 2,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 25,
    .cmap_num = 3,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t hooskai_font_36 = {
#else
lv_font_t hooskai_font_36 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 32,          /*The maximum line height required by the font*/
    .base_line = 7,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -4,
    .underline_thickness = 3,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .user_data = NULL,
};



#endif /*#if HOOSKAI_FONT_36*/

