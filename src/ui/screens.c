#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;

//
// Event handlers
//

lv_obj_t *tick_value_change_obj;

//
// Screens
//

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 459, 0);
            lv_obj_set_size(obj, 221, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff599bdc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, -3, 0);
            lv_obj_set_size(obj, 459, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0000ff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 12, 402);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_a);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 12, 323);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_b);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 12, 242);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_c);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 12, 85);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_e);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 12, 8);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_f);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 12, 163);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_not);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 82, 382);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_g);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 72, 15);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_m);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 128, 15);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_n);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 153, 143);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_p);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 185, 331);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_h);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 215, 18);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_o);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 313, 331);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_i);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 390, 110);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_q);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 390, 252);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_j);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 469, 192);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_k);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 469, 60);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_r);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 535, 358);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_s1);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 535, 245);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_s2);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 535, 130);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_s3);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 535, 18);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_s4);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 243, 295);
            lv_obj_set_size(obj, 2, LV_SIZE_CONTENT);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 0, 35 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 249, 138);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 0, 35 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen = obj;
            lv_obj_set_pos(obj, 690, 362);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen = obj;
            lv_obj_set_pos(obj, 690, 246);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_sewing_data
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_sewing_data = obj;
            lv_obj_set_pos(obj, 469, 338);
            lv_obj_set_size(obj, 59, 120);
            lv_obj_set_style_bg_img_src(obj, &img_ma_l, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen = obj;
            lv_obj_set_pos(obj, 690, 15);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen = obj;
            lv_obj_set_pos(obj, 690, 130);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}

void create_screen_mode() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.mode = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff7ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj6 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode2 = obj;
            lv_obj_set_pos(obj, 51, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_mode2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_check_program
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_check_program = obj;
            lv_obj_set_pos(obj, 210, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_check_program, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_change_sewing_mode
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_change_sewing_mode = obj;
            lv_obj_set_pos(obj, 210, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_change_sewing_mode, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_register_sewing_data_custom
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_register_sewing_data_custom = obj;
            lv_obj_set_pos(obj, 367, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_register_sewing_data_custom, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_sewing_data_in_mode
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_sewing_data_in_mode = obj;
            lv_obj_set_pos(obj, 367, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_sewing_data, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode1 = obj;
            lv_obj_set_pos(obj, 51, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_mode1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen1 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen1 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen1 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen1 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_performing_format
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_performing_format = obj;
            lv_obj_set_pos(obj, 524, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_performing_format, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_register_the_pattern
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_register_the_pattern = obj;
            lv_obj_set_pos(obj, 524, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_register_the_pattern, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // mode1
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.mode1 = obj;
            lv_obj_set_pos(obj, 51, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // mode2
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.mode2 = obj;
            lv_obj_set_pos(obj, 210, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // mode3
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.mode3 = obj;
            lv_obj_set_pos(obj, 367, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // mode5
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.mode5 = obj;
            lv_obj_set_pos(obj, 51, 3);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // mode7
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.mode7 = obj;
            lv_obj_set_pos(obj, 210, 3);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // mode8
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.mode8 = obj;
            lv_obj_set_pos(obj, 367, 3);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // mode4
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.mode4 = obj;
            lv_obj_set_pos(obj, 524, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // mode9
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.mode9 = obj;
            lv_obj_set_pos(obj, 524, 3);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_mode();
}

void tick_screen_mode() {
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_mode,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

//
// Fonts
//

ext_font_desc_t fonts[] = {
    { "roboto_vn_16", &ui_font_roboto_vn_16 },
#if LV_FONT_MONTSERRAT_8
    { "MONTSERRAT_8", &lv_font_montserrat_8 },
#endif
#if LV_FONT_MONTSERRAT_10
    { "MONTSERRAT_10", &lv_font_montserrat_10 },
#endif
#if LV_FONT_MONTSERRAT_12
    { "MONTSERRAT_12", &lv_font_montserrat_12 },
#endif
#if LV_FONT_MONTSERRAT_14
    { "MONTSERRAT_14", &lv_font_montserrat_14 },
#endif
#if LV_FONT_MONTSERRAT_16
    { "MONTSERRAT_16", &lv_font_montserrat_16 },
#endif
#if LV_FONT_MONTSERRAT_18
    { "MONTSERRAT_18", &lv_font_montserrat_18 },
#endif
#if LV_FONT_MONTSERRAT_20
    { "MONTSERRAT_20", &lv_font_montserrat_20 },
#endif
#if LV_FONT_MONTSERRAT_22
    { "MONTSERRAT_22", &lv_font_montserrat_22 },
#endif
#if LV_FONT_MONTSERRAT_24
    { "MONTSERRAT_24", &lv_font_montserrat_24 },
#endif
#if LV_FONT_MONTSERRAT_26
    { "MONTSERRAT_26", &lv_font_montserrat_26 },
#endif
#if LV_FONT_MONTSERRAT_28
    { "MONTSERRAT_28", &lv_font_montserrat_28 },
#endif
#if LV_FONT_MONTSERRAT_30
    { "MONTSERRAT_30", &lv_font_montserrat_30 },
#endif
#if LV_FONT_MONTSERRAT_32
    { "MONTSERRAT_32", &lv_font_montserrat_32 },
#endif
#if LV_FONT_MONTSERRAT_34
    { "MONTSERRAT_34", &lv_font_montserrat_34 },
#endif
#if LV_FONT_MONTSERRAT_36
    { "MONTSERRAT_36", &lv_font_montserrat_36 },
#endif
#if LV_FONT_MONTSERRAT_38
    { "MONTSERRAT_38", &lv_font_montserrat_38 },
#endif
#if LV_FONT_MONTSERRAT_40
    { "MONTSERRAT_40", &lv_font_montserrat_40 },
#endif
#if LV_FONT_MONTSERRAT_42
    { "MONTSERRAT_42", &lv_font_montserrat_42 },
#endif
#if LV_FONT_MONTSERRAT_44
    { "MONTSERRAT_44", &lv_font_montserrat_44 },
#endif
#if LV_FONT_MONTSERRAT_46
    { "MONTSERRAT_46", &lv_font_montserrat_46 },
#endif
#if LV_FONT_MONTSERRAT_48
    { "MONTSERRAT_48", &lv_font_montserrat_48 },
#endif
};

//
// Color themes
//

uint32_t active_theme_index = 0;

//
//
//

void create_screens() {

// Set default LVGL theme
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    // Initialize screens
    // Create screens
    create_screen_main();
    create_screen_mode();
}