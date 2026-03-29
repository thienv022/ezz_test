#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Screens

enum ScreensEnum {
    _SCREEN_ID_FIRST = 1,
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_MODE = 2,
    _SCREEN_ID_LAST = 2
};

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *mode;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *btn_ready_screen;
    lv_obj_t *btn_info_screen;
    lv_obj_t *btn_sewing_data;
    lv_obj_t *btn_mode_screen;
    lv_obj_t *btn_communication_screen;
    lv_obj_t *obj5;
    lv_obj_t *obj6;
    lv_obj_t *btn_mode2;
    lv_obj_t *btn_check_program;
    lv_obj_t *btn_change_sewing_mode;
    lv_obj_t *btn_register_sewing_data_custom;
    lv_obj_t *btn_sewing_data_in_mode;
    lv_obj_t *btn_mode1;
    lv_obj_t *btn_ready_screen1;
    lv_obj_t *btn_info_screen1;
    lv_obj_t *btn_communication_screen1;
    lv_obj_t *btn_mode_screen1;
    lv_obj_t *btn_performing_format;
    lv_obj_t *btn_register_the_pattern;
    lv_obj_t *mode1;
    lv_obj_t *mode2;
    lv_obj_t *mode3;
    lv_obj_t *mode5;
    lv_obj_t *mode7;
    lv_obj_t *mode8;
    lv_obj_t *mode4;
    lv_obj_t *mode9;
} objects_t;

extern objects_t objects;

void create_screen_main();
void tick_screen_main();

void create_screen_mode();
void tick_screen_mode();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/