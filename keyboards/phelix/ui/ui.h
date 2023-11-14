
enum key_label {
    UP, DOWN, LEFT, RIGHT, OK, BACK
};
struct key_input {
    enum qk_keycode_defines qmk_code;
    enum key_label key_label;
};
/*
static struct key_input map[6] = {
    {PB_1, UP},
    {PB_2, DOWN},
    {PB_3, LEFT},
    {PB_4, RIGHT},
    {PB_5, OK},
    {PB_6, BACK}
};
*/
