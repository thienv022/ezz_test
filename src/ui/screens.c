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

static const char *screen_names[] = { "Main", "mode", "ready", "info", "sewing_data1", "sewing_data2", "sewing_data3", "sewing_data4", "sewing_data5", "sewing_data6", "mode1_1", "mode1_2", "mode1_3", "mode1_4", "mode2_1", "mode2_2", "mode2_3", "mode2_4", "check_program", "mode_sewing_data", "mode_sewing_data1", "mode_sewing_data2" };
static const char *object_names[] = { "main", "mode", "ready", "info", "sewing_data1", "sewing_data2", "sewing_data3", "sewing_data4", "sewing_data5", "sewing_data6", "mode1_1", "mode1_2", "mode1_3", "mode1_4", "mode2_1", "mode2_2", "mode2_3", "mode2_4", "check_program", "mode_sewing_data", "mode_sewing_data1", "mode_sewing_data2", "obj0", "obj1", "obj2", "obj3", "obj4", "btn_ready_screen", "btn_info_screen", "btn_sewing_data", "p1_btn_mode_screen", "btn_communication_screen", "obj5", "obj6", "btn_mode2", "btn_check_program", "btn_change_sewing_mode", "btn_register_sewing_data_custom", "btn_sewing_data_in_mode", "btn_mode1", "btn_ready_screen1", "btn_info_screen1", "btn_communication_screen1", "btn_mode_screen1", "btn_performing_format", "btn_register_the_pattern", "mode1", "mode2", "mode3", "mode5", "mode7", "mode8", "mode4", "mode9", "obj7", "obj8", "obj9", "btn_ready_screen2", "btn_info_screen2", "btn_communication_screen2", "btn_mode_screen2", "obj10", "obj11", "btn_production_control", "btn_working_measurement", "btn_maintenance_and_inspection", "btn_ready_screen1_1", "btn_info_screen1_1", "btn_communication_screen1_1", "btn_mode_screen1_1", "i1", "i2", "i3", "obj12", "obj13", "btn_s004", "btn_s002", "btn_s005", "btn_s003", "btn_s006", "btn_s001", "btn_ready_screen3", "btn_info_screen3", "btn_communication_screen3", "btn_mode_screen3", "btn_next", "btn_back", "btn_exit", "s001", "s002", "s003", "s004", "s005", "s006", "obj14", "obj15", "btn_s010", "btn_s008", "btn_s011", "btn_s009", "btn_s021", "btn_s007", "btn_ready_screen4", "btn_info_screen4", "btn_communication_screen4", "btn_mode_screen4", "btn_next1", "btn_back1", "btn_exit1", "s007", "s008", "s009", "s0010", "s0011", "s021", "obj16", "obj17", "btn_ready_screen5", "btn_info_screen5", "btn_communication_screen5", "btn_mode_screen5", "btn_next2", "btn_back2", "btn_exit2", "s022", "s023", "s031", "s034", "s035", "s036", "obj18", "obj19", "btn_s044", "btn_s038", "btn_s051", "btn_s040", "btn_s055", "btn_s037", "btn_ready_screen6", "btn_info_screen6", "btn_communication_screen6", "btn_mode_screen6", "btn_next3", "btn_back3", "btn_exit3", "s037", "s038", "s040", "s044", "s051", "s055", "obj20", "obj21", "btn_s064", "btn_s058", "btn_s067", "btn_s062", "btn_s068", "btn_s057", "btn_ready_screen7", "btn_info_screen7", "btn_communication_screen7", "btn_mode_screen7", "btn_next4", "btn_back4", "btn_exit4", "s057", "s058", "s062", "s064", "s067", "s068", "obj22", "obj23", "btn_s084", "btn_s081", "btn_ready_screen8", "btn_info_screen8", "btn_communication_screen8", "btn_mode_screen8", "btn_next5", "btn_back5", "btn_exit5", "s081", "s084", "obj24", "obj25", "btn_u004", "btn_u002", "btn_u005", "btn_u003", "btn_u006", "btn_u001", "btn_ready_screen9", "btn_info_screen9", "btn_communication_screen9", "btn_mode_screen9", "btn_next6", "btn_back6", "btn_exit6", "u001", "u002", "u003", "u004", "u005", "u006", "obj26", "obj27", "btn_u010", "btn_u008", "btn_u011", "btn_u009", "btn_u012", "btn_u007", "btn_ready_screen10", "btn_info_screen10", "btn_communication_screen10", "btn_mode_screen10", "btn_next7", "btn_back7", "btn_exit7", "u007", "u008", "u009", "u010", "u011", "u012", "obj28", "obj29", "btn_u018", "btn_u014", "btn_u019", "btn_u015", "btn_u020", "btn_u013", "btn_ready_screen11", "btn_info_screen11", "btn_communication_screen11", "btn_mode_screen11", "btn_next8", "btn_back8", "btn_exit8", "u013", "u014", "u015", "u018", "u019", "u020", "obj30", "obj31", "btn_u024", "btn_u022", "btn_u025", "btn_u023", "btn_u500", "btn_u021", "btn_ready_screen12", "btn_info_screen12", "btn_communication_screen12", "btn_mode_screen12", "u021", "u022", "u023", "u024", "u025", "u500", "obj32", "obj33", "btn_k005", "btn_k003", "btn_k006", "btn_k004", "btn_k007", "btn_k001", "btn_ready_screen13", "btn_info_screen13", "btn_communication_screen13", "btn_mode_screen13", "btn_next9", "btn_back9", "btn_exit9", "k001", "k003", "k004", "k005", "k006", "k007", "obj34", "obj35", "btn_k011", "btn_k009", "btn_k012", "btn_k010", "btn_k013", "btn_k008", "btn_ready_screen14", "btn_info_screen14", "btn_communication_screen14", "btn_mode_screen14", "btn_next10", "btn_back10", "btn_exit10", "k008", "k009", "k010", "k011", "k012", "k013", "obj36", "obj37", "btn_k017", "btn_k015", "btn_k018", "btn_k016", "btn_k019", "btn_k014", "btn_ready_screen15", "btn_info_screen15", "btn_communication_screen15", "btn_mode_screen15", "btn_next11", "btn_back11", "btn_exit11", "k014", "k015", "k016", "k017", "k018", "k019", "obj38", "obj39", "btn_k021", "btn_k022", "btn_k020", "btn_ready_screen16", "btn_info_screen16", "btn_communication_screen16", "btn_mode_screen16", "btn_next12", "btn_back12", "btn_exit12", "k020", "k021", "k022", "obj40", "obj41", "btn_i004", "btn_i002", "btn_i005", "btn_i003", "btn_i001", "btn_ready_screen17", "btn_info_screen17", "btn_communication_screen17", "btn_mode_screen17", "btn_next13", "btn_back13", "btn_exit13", "i001", "i002", "i003", "i004", "i005", "obj42", "obj43", "btn_s042", "btn_s039", "btn_s052", "btn_s041", "btn_s053", "btn_s020", "btn_ready_screen18", "btn_info_screen18", "btn_communication_screen18", "btn_mode_screen18", "btn_next14", "btn_back14", "btn_exit14", "s020", "s039", "s041", "s042", "s052", "s053", "obj44", "obj45", "btn_s060", "btn_s056", "btn_s061", "btn_s059", "btn_s063", "btn_s054", "btn_ready_screen19", "btn_info_screen19", "btn_communication_screen19", "btn_mode_screen19", "btn_next15", "btn_back15", "btn_exit15", "s054", "s056", "s059", "s060", "s061", "s063", "obj46", "obj47", "btn_s070", "btn_s066", "btn_s083", "btn_s069", "btn_s065", "btn_ready_screen20", "btn_info_screen20", "btn_communication_screen20", "btn_mode_screen20", "btn_next16", "btn_back16", "btn_exit16", "s065", "s066", "s069", "s070", "s083" };

//
// Event handlers
//

lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_btn_ready_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 27, 0, e);
    }
}

static void event_handler_cb_main_btn_info_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 28, 0, e);
    }
}

static void event_handler_cb_main_btn_sewing_data(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 29, 0, e);
    }
}

static void event_handler_cb_main_p1_btn_mode_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 30, 0, e);
    }
}

static void event_handler_cb_mode_btn_mode2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_mode_btn_check_program(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_mode_btn_sewing_data_in_mode(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_mode_btn_mode1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_mode_btn_mode_screen1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_ready_btn_ready_screen2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_go_to_sewing_screen(e);
    }
}

static void event_handler_cb_ready_btn_mode_screen2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_sewing_data1_btn_next(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_sewing_data1_btn_exit(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_sewing_data2_btn_next1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_sewing_data2_btn_back1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_sewing_data2_btn_exit1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_mode1_1_btn_exit6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_mode2_1_btn_exit9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_check_program_btn_exit13(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_mode_sewing_data_btn_exit14(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

//
// Screens
//

void create_screen_main() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
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
            lv_obj_add_event_cb(obj, event_handler_cb_main_btn_ready_screen, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_main_btn_info_screen, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_sewing_data
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_sewing_data = obj;
            lv_obj_set_pos(obj, 469, 338);
            lv_obj_set_size(obj, 60, 120);
            lv_obj_add_event_cb(obj, event_handler_cb_main_btn_sewing_data, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_ma_l, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // P1_btn_mode_screen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.p1_btn_mode_screen = obj;
            lv_obj_set_pos(obj, 690, 15);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_main_p1_btn_mode_screen, LV_EVENT_ALL, flowState);
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
    void *flowState = getFlowState(0, 0);
    (void)flowState;
}

void create_screen_mode() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode_btn_mode2, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_mode2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_check_program
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_check_program = obj;
            lv_obj_set_pos(obj, 210, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_add_event_cb(obj, event_handler_cb_mode_btn_check_program, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode_btn_sewing_data_in_mode, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_sewing_data, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode1 = obj;
            lv_obj_set_pos(obj, 51, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_add_event_cb(obj, event_handler_cb_mode_btn_mode1, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode_btn_mode_screen1, LV_EVENT_ALL, flowState);
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
    void *flowState = getFlowState(0, 1);
    (void)flowState;
}

void create_screen_ready() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.ready = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj8 = obj;
            lv_obj_set_pos(obj, 459, 0);
            lv_obj_set_size(obj, 221, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff599bdc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj9 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 459, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ffa4), LV_PART_MAIN | LV_STATE_DEFAULT);
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
            lv_obj_set_pos(obj, 469, 192);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_k);
        }
        {
            // btn_ready_screen2
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.btn_ready_screen2 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_defaul1);
            lv_obj_add_event_cb(obj, event_handler_cb_ready_btn_ready_screen2, LV_EVENT_ALL, flowState);
        }
        {
            // btn_info_screen2
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.btn_info_screen2 = obj;
            lv_obj_set_pos(obj, 690, 245);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_defaul2);
        }
        {
            // btn_communication_screen2
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.btn_communication_screen2 = obj;
            lv_obj_set_pos(obj, 690, 130);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_defaul3);
        }
        {
            // btn_mode_screen2
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.btn_mode_screen2 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_defaul4);
            lv_obj_add_event_cb(obj, event_handler_cb_ready_btn_mode_screen2, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 540, 19);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_se_s);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 85, 98);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_se_ac);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 75, 385);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_se_g);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 155, 395);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_se_h);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 212, 383);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_se_j);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 301, 393);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_se_l1);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 370, 374);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_se_l2);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 105, 8);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_se_o1);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 360, 8);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_se_o2);
        }
        {
            lv_obj_t *obj = lv_slider_create(parent_obj);
            lv_obj_set_pos(obj, 155, 28);
            lv_obj_set_size(obj, 205, 10);
            lv_slider_set_value(obj, 25, LV_ANIM_OFF);
            lv_obj_set_style_transform_angle(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 181, 81);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_se_ikmnpq);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 12, 160);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_se_d);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 12, 326);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_se_not);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 12, 240);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_se_not);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 12, 403);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_se_not);
        }
    }
    
    tick_screen_ready();
}

void tick_screen_ready() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
}

void create_screen_info() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.info = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj10 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd7fffb), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj11 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_production_control
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_production_control = obj;
            lv_obj_set_pos(obj, 270, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_production_control, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_working_measurement
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_working_measurement = obj;
            lv_obj_set_pos(obj, 445, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_working_measurement, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_maintenance_and_inspection
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_maintenance_and_inspection = obj;
            lv_obj_set_pos(obj, 100, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_maintenance_and_inspection, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen1_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen1_1 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen1_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen1_1 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen1_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen1_1 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen1_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen1_1 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // i1
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.i1 = obj;
            lv_obj_set_pos(obj, 100, 241);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // i2
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.i2 = obj;
            lv_obj_set_pos(obj, 270, 241);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // i3
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.i3 = obj;
            lv_obj_set_pos(obj, 445, 241);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_info();
}

void tick_screen_info() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
}

void create_screen_sewing_data1() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.sewing_data1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj12 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj13 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s004
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s004 = obj;
            lv_obj_set_pos(obj, 104, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s004, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s002
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s002 = obj;
            lv_obj_set_pos(obj, 288, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s002, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s005
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s005 = obj;
            lv_obj_set_pos(obj, 288, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s005, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s003
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s003 = obj;
            lv_obj_set_pos(obj, 471, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s003, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s006
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s006 = obj;
            lv_obj_set_pos(obj, 471, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s006, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s001
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s001 = obj;
            lv_obj_set_pos(obj, 104, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s001, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen3 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen3 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen3 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen3 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data1_btn_next, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data1_btn_exit, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s001
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s001 = obj;
            lv_obj_set_pos(obj, 104, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s002
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s002 = obj;
            lv_obj_set_pos(obj, 288, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s003
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s003 = obj;
            lv_obj_set_pos(obj, 471, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s004
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s004 = obj;
            lv_obj_set_pos(obj, 104, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s005
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s005 = obj;
            lv_obj_set_pos(obj, 288, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s006
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s006 = obj;
            lv_obj_set_pos(obj, 471, 3);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_sewing_data1();
}

void tick_screen_sewing_data1() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
}

void create_screen_sewing_data2() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.sewing_data2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj14 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj15 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s010
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s010 = obj;
            lv_obj_set_pos(obj, 104, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s010, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s008
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s008 = obj;
            lv_obj_set_pos(obj, 288, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s008, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s011
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s011 = obj;
            lv_obj_set_pos(obj, 288, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s011, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s009
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s009 = obj;
            lv_obj_set_pos(obj, 471, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s009, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s021
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s021 = obj;
            lv_obj_set_pos(obj, 471, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s021, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s007
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s007 = obj;
            lv_obj_set_pos(obj, 104, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s007, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen4 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen4 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen4 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen4 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next1 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data2_btn_next1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back1 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data2_btn_back1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit1 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data2_btn_exit1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s007
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s007 = obj;
            lv_obj_set_pos(obj, 104, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s008
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s008 = obj;
            lv_obj_set_pos(obj, 288, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s009
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s009 = obj;
            lv_obj_set_pos(obj, 471, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s0010
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s0010 = obj;
            lv_obj_set_pos(obj, 104, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s0011
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s0011 = obj;
            lv_obj_set_pos(obj, 288, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s021
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s021 = obj;
            lv_obj_set_pos(obj, 471, 3);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_sewing_data2();
}

void tick_screen_sewing_data2() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
}

void create_screen_sewing_data3() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.sewing_data3 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj16 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj17 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 104, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s034, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 288, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s023, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 288, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s035, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 471, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s031, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 471, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s036, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 104, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s022, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen5 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen5 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen5 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen5 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next2 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back2 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit2 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s022
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s022 = obj;
            lv_obj_set_pos(obj, 104, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s023
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s023 = obj;
            lv_obj_set_pos(obj, 288, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s031
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s031 = obj;
            lv_obj_set_pos(obj, 471, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s034
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s034 = obj;
            lv_obj_set_pos(obj, 104, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s035
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s035 = obj;
            lv_obj_set_pos(obj, 288, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s036
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s036 = obj;
            lv_obj_set_pos(obj, 471, 3);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_sewing_data3();
}

void tick_screen_sewing_data3() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
}

void create_screen_sewing_data4() {
    void *flowState = getFlowState(0, 7);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.sewing_data4 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj18 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj19 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s044
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s044 = obj;
            lv_obj_set_pos(obj, 104, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s044, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s038
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s038 = obj;
            lv_obj_set_pos(obj, 288, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s038, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s051
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s051 = obj;
            lv_obj_set_pos(obj, 288, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s051, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s040
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s040 = obj;
            lv_obj_set_pos(obj, 471, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s040, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s055
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s055 = obj;
            lv_obj_set_pos(obj, 471, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s055, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s037
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s037 = obj;
            lv_obj_set_pos(obj, 104, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s037, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen6 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen6 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen6 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen6 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next3 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back3 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit3 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s037
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s037 = obj;
            lv_obj_set_pos(obj, 104, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s038
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s038 = obj;
            lv_obj_set_pos(obj, 288, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s040
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s040 = obj;
            lv_obj_set_pos(obj, 471, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s044
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s044 = obj;
            lv_obj_set_pos(obj, 104, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s051
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s051 = obj;
            lv_obj_set_pos(obj, 288, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s055
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s055 = obj;
            lv_obj_set_pos(obj, 471, 3);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_sewing_data4();
}

void tick_screen_sewing_data4() {
    void *flowState = getFlowState(0, 7);
    (void)flowState;
}

void create_screen_sewing_data5() {
    void *flowState = getFlowState(0, 8);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.sewing_data5 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj20 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj21 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s064
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s064 = obj;
            lv_obj_set_pos(obj, 104, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s064, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s058
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s058 = obj;
            lv_obj_set_pos(obj, 288, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s058, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s067
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s067 = obj;
            lv_obj_set_pos(obj, 288, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s067, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s062
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s062 = obj;
            lv_obj_set_pos(obj, 471, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s062, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s068
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s068 = obj;
            lv_obj_set_pos(obj, 471, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s068, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s057
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s057 = obj;
            lv_obj_set_pos(obj, 104, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s057, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen7 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen7 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen7 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen7 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next4 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back4 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit4 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s057
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s057 = obj;
            lv_obj_set_pos(obj, 104, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s058
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s058 = obj;
            lv_obj_set_pos(obj, 288, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s062
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s062 = obj;
            lv_obj_set_pos(obj, 471, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s064
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s064 = obj;
            lv_obj_set_pos(obj, 104, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s067
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s067 = obj;
            lv_obj_set_pos(obj, 288, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s068
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s068 = obj;
            lv_obj_set_pos(obj, 471, 3);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_sewing_data5();
}

void tick_screen_sewing_data5() {
    void *flowState = getFlowState(0, 8);
    (void)flowState;
}

void create_screen_sewing_data6() {
    void *flowState = getFlowState(0, 9);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.sewing_data6 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj22 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj23 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s084
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s084 = obj;
            lv_obj_set_pos(obj, 288, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s084, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s081
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s081 = obj;
            lv_obj_set_pos(obj, 104, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s081, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen8 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen8 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen8 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen8 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next5 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back5 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit5 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s081
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s081 = obj;
            lv_obj_set_pos(obj, 104, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s084
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s084 = obj;
            lv_obj_set_pos(obj, 288, 246);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_sewing_data6();
}

void tick_screen_sewing_data6() {
    void *flowState = getFlowState(0, 9);
    (void)flowState;
}

void create_screen_mode1_1() {
    void *flowState = getFlowState(0, 10);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.mode1_1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj24 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffafec9a), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj25 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u004
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u004 = obj;
            lv_obj_set_pos(obj, 104, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u004, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u002
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u002 = obj;
            lv_obj_set_pos(obj, 288, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u002, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u005
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u005 = obj;
            lv_obj_set_pos(obj, 288, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u005, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u003
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u003 = obj;
            lv_obj_set_pos(obj, 471, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u003, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u006
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u006 = obj;
            lv_obj_set_pos(obj, 471, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u006, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u001
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u001 = obj;
            lv_obj_set_pos(obj, 104, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u001, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen9 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen9 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen9 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen9 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next6 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back6 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit6 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_1_btn_exit6, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // u001
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u001 = obj;
            lv_obj_set_pos(obj, 104, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u002
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u002 = obj;
            lv_obj_set_pos(obj, 288, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u003
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u003 = obj;
            lv_obj_set_pos(obj, 471, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u004
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u004 = obj;
            lv_obj_set_pos(obj, 104, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u005
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u005 = obj;
            lv_obj_set_pos(obj, 288, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u006
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u006 = obj;
            lv_obj_set_pos(obj, 471, 3);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_mode1_1();
}

void tick_screen_mode1_1() {
    void *flowState = getFlowState(0, 10);
    (void)flowState;
}

void create_screen_mode1_2() {
    void *flowState = getFlowState(0, 11);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.mode1_2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj26 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffafec9a), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj27 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u010
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u010 = obj;
            lv_obj_set_pos(obj, 104, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u010, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u008
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u008 = obj;
            lv_obj_set_pos(obj, 288, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u008, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u011
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u011 = obj;
            lv_obj_set_pos(obj, 288, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u011, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u009
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u009 = obj;
            lv_obj_set_pos(obj, 471, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u009, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u012
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u012 = obj;
            lv_obj_set_pos(obj, 471, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u012, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u007
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u007 = obj;
            lv_obj_set_pos(obj, 104, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u007, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen10
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen10 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen10
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen10 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen10
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen10 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen10
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen10 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next7 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back7 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit7 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // u007
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u007 = obj;
            lv_obj_set_pos(obj, 104, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u008
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u008 = obj;
            lv_obj_set_pos(obj, 288, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u009
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u009 = obj;
            lv_obj_set_pos(obj, 471, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u010
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u010 = obj;
            lv_obj_set_pos(obj, 104, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u011
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u011 = obj;
            lv_obj_set_pos(obj, 288, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u012
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u012 = obj;
            lv_obj_set_pos(obj, 471, 3);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_mode1_2();
}

void tick_screen_mode1_2() {
    void *flowState = getFlowState(0, 11);
    (void)flowState;
}

void create_screen_mode1_3() {
    void *flowState = getFlowState(0, 12);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.mode1_3 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj28 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffafec9a), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj29 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u018
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u018 = obj;
            lv_obj_set_pos(obj, 104, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u018, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u014
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u014 = obj;
            lv_obj_set_pos(obj, 288, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u014, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u019
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u019 = obj;
            lv_obj_set_pos(obj, 288, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u019, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u015
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u015 = obj;
            lv_obj_set_pos(obj, 471, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u017, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u020
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u020 = obj;
            lv_obj_set_pos(obj, 471, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u020, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u013
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u013 = obj;
            lv_obj_set_pos(obj, 104, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u013, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen11
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen11 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen11
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen11 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen11
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen11 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen11
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen11 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next8 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back8 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit8 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // u013
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u013 = obj;
            lv_obj_set_pos(obj, 104, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u014
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u014 = obj;
            lv_obj_set_pos(obj, 288, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u015
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u015 = obj;
            lv_obj_set_pos(obj, 471, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u018
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u018 = obj;
            lv_obj_set_pos(obj, 104, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u019
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u019 = obj;
            lv_obj_set_pos(obj, 288, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u020
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u020 = obj;
            lv_obj_set_pos(obj, 471, 3);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_mode1_3();
}

void tick_screen_mode1_3() {
    void *flowState = getFlowState(0, 12);
    (void)flowState;
}

void create_screen_mode1_4() {
    void *flowState = getFlowState(0, 13);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.mode1_4 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj30 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffafec9a), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj31 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u024
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u024 = obj;
            lv_obj_set_pos(obj, 104, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u024, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u022
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u022 = obj;
            lv_obj_set_pos(obj, 288, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u022, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u025
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u025 = obj;
            lv_obj_set_pos(obj, 288, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u025, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u023
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u023 = obj;
            lv_obj_set_pos(obj, 471, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u023, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u500
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u500 = obj;
            lv_obj_set_pos(obj, 471, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u500, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_u021
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_u021 = obj;
            lv_obj_set_pos(obj, 104, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_u021, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen12
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen12 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen12
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen12 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen12
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen12 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen12
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen12 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // u021
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u021 = obj;
            lv_obj_set_pos(obj, 104, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u022
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u022 = obj;
            lv_obj_set_pos(obj, 288, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u023
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u023 = obj;
            lv_obj_set_pos(obj, 471, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u024
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u024 = obj;
            lv_obj_set_pos(obj, 104, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u025
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u025 = obj;
            lv_obj_set_pos(obj, 288, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // u500
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.u500 = obj;
            lv_obj_set_pos(obj, 471, 3);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_mode1_4();
}

void tick_screen_mode1_4() {
    void *flowState = getFlowState(0, 13);
    (void)flowState;
}

void create_screen_mode2_1() {
    void *flowState = getFlowState(0, 14);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.mode2_1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj32 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffadefc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj33 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k005
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k005 = obj;
            lv_obj_set_pos(obj, 104, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k005, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k003
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k003 = obj;
            lv_obj_set_pos(obj, 288, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k003, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k006
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k006 = obj;
            lv_obj_set_pos(obj, 288, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k006, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k004
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k004 = obj;
            lv_obj_set_pos(obj, 471, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k004, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k007
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k007 = obj;
            lv_obj_set_pos(obj, 471, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k007, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k001
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k001 = obj;
            lv_obj_set_pos(obj, 104, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k001, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen13
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen13 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen13
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen13 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen13
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen13 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen13
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen13 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next9 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back9 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit9 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_1_btn_exit9, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // k001
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k001 = obj;
            lv_obj_set_pos(obj, 104, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // k003
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k003 = obj;
            lv_obj_set_pos(obj, 288, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // k004
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k004 = obj;
            lv_obj_set_pos(obj, 471, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // k005
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k005 = obj;
            lv_obj_set_pos(obj, 104, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // k006
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k006 = obj;
            lv_obj_set_pos(obj, 288, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // k007
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k007 = obj;
            lv_obj_set_pos(obj, 471, 3);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_mode2_1();
}

void tick_screen_mode2_1() {
    void *flowState = getFlowState(0, 14);
    (void)flowState;
}

void create_screen_mode2_2() {
    void *flowState = getFlowState(0, 15);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.mode2_2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj34 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffadefc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj35 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k011
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k011 = obj;
            lv_obj_set_pos(obj, 104, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k011, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k009
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k009 = obj;
            lv_obj_set_pos(obj, 288, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k009, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k012
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k012 = obj;
            lv_obj_set_pos(obj, 288, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k012, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k010
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k010 = obj;
            lv_obj_set_pos(obj, 471, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k010, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k013
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k013 = obj;
            lv_obj_set_pos(obj, 471, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k013, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k008
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k008 = obj;
            lv_obj_set_pos(obj, 104, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k008, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen14
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen14 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen14
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen14 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen14
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen14 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen14
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen14 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next10
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next10 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back10
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back10 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit10
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit10 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // k008
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k008 = obj;
            lv_obj_set_pos(obj, 104, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // k009
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k009 = obj;
            lv_obj_set_pos(obj, 288, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // k010
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k010 = obj;
            lv_obj_set_pos(obj, 471, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // k011
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k011 = obj;
            lv_obj_set_pos(obj, 104, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // k012
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k012 = obj;
            lv_obj_set_pos(obj, 288, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // k013
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k013 = obj;
            lv_obj_set_pos(obj, 471, 3);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_mode2_2();
}

void tick_screen_mode2_2() {
    void *flowState = getFlowState(0, 15);
    (void)flowState;
}

void create_screen_mode2_3() {
    void *flowState = getFlowState(0, 16);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.mode2_3 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj36 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffadefc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj37 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k017
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k017 = obj;
            lv_obj_set_pos(obj, 104, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k017, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k015
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k015 = obj;
            lv_obj_set_pos(obj, 288, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k015, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k018
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k018 = obj;
            lv_obj_set_pos(obj, 288, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k018, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k016
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k016 = obj;
            lv_obj_set_pos(obj, 471, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k016, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k019
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k019 = obj;
            lv_obj_set_pos(obj, 471, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k019, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k014
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k014 = obj;
            lv_obj_set_pos(obj, 104, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k014, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen15
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen15 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen15
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen15 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen15
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen15 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen15
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen15 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next11
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next11 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back11
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back11 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit11
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit11 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // k014
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k014 = obj;
            lv_obj_set_pos(obj, 104, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // k015
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k015 = obj;
            lv_obj_set_pos(obj, 288, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // k016
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k016 = obj;
            lv_obj_set_pos(obj, 471, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // k017
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k017 = obj;
            lv_obj_set_pos(obj, 104, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // k018
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k018 = obj;
            lv_obj_set_pos(obj, 288, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // k019
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k019 = obj;
            lv_obj_set_pos(obj, 471, 3);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_mode2_3();
}

void tick_screen_mode2_3() {
    void *flowState = getFlowState(0, 16);
    (void)flowState;
}

void create_screen_mode2_4() {
    void *flowState = getFlowState(0, 17);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.mode2_4 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj38 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffadefc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj39 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k021
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k021 = obj;
            lv_obj_set_pos(obj, 288, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k021, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k022
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k022 = obj;
            lv_obj_set_pos(obj, 471, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k022, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_k020
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_k020 = obj;
            lv_obj_set_pos(obj, 104, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_k020, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen16
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen16 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen16
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen16 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen16
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen16 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen16
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen16 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next12
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next12 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back12
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back12 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit12
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit12 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // k020
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k020 = obj;
            lv_obj_set_pos(obj, 104, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // k021
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k021 = obj;
            lv_obj_set_pos(obj, 288, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // k022
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.k022 = obj;
            lv_obj_set_pos(obj, 471, 246);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_mode2_4();
}

void tick_screen_mode2_4() {
    void *flowState = getFlowState(0, 17);
    (void)flowState;
}

void create_screen_check_program() {
    void *flowState = getFlowState(0, 18);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.check_program = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj40 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffdde7f8), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj41 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_i004
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_i004 = obj;
            lv_obj_set_pos(obj, 104, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_i004, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_i002
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_i002 = obj;
            lv_obj_set_pos(obj, 288, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_i002, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_i005
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_i005 = obj;
            lv_obj_set_pos(obj, 288, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_i005, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_i003
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_i003 = obj;
            lv_obj_set_pos(obj, 471, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_i003, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_i001
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_i001 = obj;
            lv_obj_set_pos(obj, 104, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_i001, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen17
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen17 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen17
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen17 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen17
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen17 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen17
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen17 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next13
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next13 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back13
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back13 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit13
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit13 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_check_program_btn_exit13, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // i001
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.i001 = obj;
            lv_obj_set_pos(obj, 104, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // i002
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.i002 = obj;
            lv_obj_set_pos(obj, 307, 243);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // i003
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.i003 = obj;
            lv_obj_set_pos(obj, 471, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // i004
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.i004 = obj;
            lv_obj_set_pos(obj, 104, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // i005
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.i005 = obj;
            lv_obj_set_pos(obj, 288, 11);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_check_program();
}

void tick_screen_check_program() {
    void *flowState = getFlowState(0, 18);
    (void)flowState;
}

void create_screen_mode_sewing_data() {
    void *flowState = getFlowState(0, 19);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.mode_sewing_data = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj42 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj43 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s042
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s042 = obj;
            lv_obj_set_pos(obj, 104, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s042, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s039
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s039 = obj;
            lv_obj_set_pos(obj, 288, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s039, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s052
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s052 = obj;
            lv_obj_set_pos(obj, 288, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s052, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s041
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s041 = obj;
            lv_obj_set_pos(obj, 471, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s041, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s053
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s053 = obj;
            lv_obj_set_pos(obj, 471, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s053, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s020
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s020 = obj;
            lv_obj_set_pos(obj, 104, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s020, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen18
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen18 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen18
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen18 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen18
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen18 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen18
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen18 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next14
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next14 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back14
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back14 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit14
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit14 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode_sewing_data_btn_exit14, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s020
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s020 = obj;
            lv_obj_set_pos(obj, 104, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s039
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s039 = obj;
            lv_obj_set_pos(obj, 288, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s041
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s041 = obj;
            lv_obj_set_pos(obj, 471, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s042
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s042 = obj;
            lv_obj_set_pos(obj, 104, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s052
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s052 = obj;
            lv_obj_set_pos(obj, 288, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s053
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s053 = obj;
            lv_obj_set_pos(obj, 471, 3);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_mode_sewing_data();
}

void tick_screen_mode_sewing_data() {
    void *flowState = getFlowState(0, 19);
    (void)flowState;
}

void create_screen_mode_sewing_data1() {
    void *flowState = getFlowState(0, 20);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.mode_sewing_data1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj44 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj45 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s060
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s060 = obj;
            lv_obj_set_pos(obj, 104, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s060, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s056
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s056 = obj;
            lv_obj_set_pos(obj, 288, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s056, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s061
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s061 = obj;
            lv_obj_set_pos(obj, 288, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s061, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s059
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s059 = obj;
            lv_obj_set_pos(obj, 471, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s059, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s063
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s063 = obj;
            lv_obj_set_pos(obj, 471, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s063, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s054
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s054 = obj;
            lv_obj_set_pos(obj, 104, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s054, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen19
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen19 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen19
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen19 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen19
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen19 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen19
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen19 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next15
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next15 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back15
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back15 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit15
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit15 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s054
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s054 = obj;
            lv_obj_set_pos(obj, 104, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s056
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s056 = obj;
            lv_obj_set_pos(obj, 288, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s059
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s059 = obj;
            lv_obj_set_pos(obj, 471, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s060
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s060 = obj;
            lv_obj_set_pos(obj, 104, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s061
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s061 = obj;
            lv_obj_set_pos(obj, 288, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s063
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s063 = obj;
            lv_obj_set_pos(obj, 471, 3);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_mode_sewing_data1();
}

void tick_screen_mode_sewing_data1() {
    void *flowState = getFlowState(0, 20);
    (void)flowState;
}

void create_screen_mode_sewing_data2() {
    void *flowState = getFlowState(0, 21);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.mode_sewing_data2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj46 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj47 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s070
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s070 = obj;
            lv_obj_set_pos(obj, 104, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s070, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s066
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s066 = obj;
            lv_obj_set_pos(obj, 288, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s066, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s083
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s083 = obj;
            lv_obj_set_pos(obj, 288, 103);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s083, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s069
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s069 = obj;
            lv_obj_set_pos(obj, 471, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s069, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_s065
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_s065 = obj;
            lv_obj_set_pos(obj, 104, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_set_style_bg_img_src(obj, &img_s065, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen20
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen20 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen20
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen20 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen20
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen20 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen20
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen20 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next16
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next16 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back16
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back16 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit16
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit16 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // s065
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s065 = obj;
            lv_obj_set_pos(obj, 104, 240);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s066
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s066 = obj;
            lv_obj_set_pos(obj, 288, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s069
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s069 = obj;
            lv_obj_set_pos(obj, 471, 246);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s070
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s070 = obj;
            lv_obj_set_pos(obj, 104, 11);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // s083
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.s083 = obj;
            lv_obj_set_pos(obj, 288, 11);
            lv_obj_set_size(obj, 130, 92);
        }
    }
    
    tick_screen_mode_sewing_data2();
}

void tick_screen_mode_sewing_data2() {
    void *flowState = getFlowState(0, 21);
    (void)flowState;
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_mode,
    tick_screen_ready,
    tick_screen_info,
    tick_screen_sewing_data1,
    tick_screen_sewing_data2,
    tick_screen_sewing_data3,
    tick_screen_sewing_data4,
    tick_screen_sewing_data5,
    tick_screen_sewing_data6,
    tick_screen_mode1_1,
    tick_screen_mode1_2,
    tick_screen_mode1_3,
    tick_screen_mode1_4,
    tick_screen_mode2_1,
    tick_screen_mode2_2,
    tick_screen_mode2_3,
    tick_screen_mode2_4,
    tick_screen_check_program,
    tick_screen_mode_sewing_data,
    tick_screen_mode_sewing_data1,
    tick_screen_mode_sewing_data2,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

//
// Styles
//

static const char *style_names[] = { "vn_text" };

extern void add_style(lv_obj_t *obj, int32_t styleIndex);
extern void remove_style(lv_obj_t *obj, int32_t styleIndex);

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
//
//

void create_screens() {
    // Initialize styles
    eez_flow_init_styles(add_style, remove_style);
    eez_flow_init_style_names(style_names, sizeof(style_names) / sizeof(const char *));

eez_flow_init_fonts(fonts, sizeof(fonts) / sizeof(ext_font_desc_t));

// Set default LVGL theme
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    // Initialize screens
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    
    // Create screens
    create_screen_main();
    create_screen_mode();
    create_screen_ready();
    create_screen_info();
    create_screen_sewing_data1();
    create_screen_sewing_data2();
    create_screen_sewing_data3();
    create_screen_sewing_data4();
    create_screen_sewing_data5();
    create_screen_sewing_data6();
    create_screen_mode1_1();
    create_screen_mode1_2();
    create_screen_mode1_3();
    create_screen_mode1_4();
    create_screen_mode2_1();
    create_screen_mode2_2();
    create_screen_mode2_3();
    create_screen_mode2_4();
    create_screen_check_program();
    create_screen_mode_sewing_data();
    create_screen_mode_sewing_data1();
    create_screen_mode_sewing_data2();
}