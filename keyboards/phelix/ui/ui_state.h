// enum of the WUI widget UI states
typedef enum { MAX, MIN, HIDDEN } wui_ui_state_t;
/*
enum of all WUI widget program states
state transitions: NOT_INIT -> INIT -> IDLE <-> RUNNING
*/
typedef enum { NOT_INIT, INIT, IDLE, RUNNING } wui_init_state_t;

typedef struct {
    bool init;
    uint32_t pomo_timer;
    uint8_t pomodoro_state;
    lv_obj_t *pomo_label;
    deferred_token token;
} pomo_wui_state_t;

// wrapper common type for the state of a WUI widget,
typedef struct {
    wui_init_state_t wui_init_state;
    wui_ui_state_t wui_ui_state;
    union {
        // add other widgets here
        pomo_wui_state_t pomo_wui_state;
    };
} wui_gbl_state_t;

// enum of all WUI widgets that are developed for phelix keyboards
typedef enum {
    WUI_POMODORO,
    NumberOfWuiTypes
} wui_t;