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

static const char *screen_names[] = { "Main", "mode", "ready", "info", "sewing_data1", "sewing_data2", "sewing_data3", "sewing_data4", "sewing_data5", "sewing_data6", "mode1_1", "mode1_2", "mode1_3", "mode1_4", "mode2_1", "mode2_2", "mode2_3", "mode2_4", "check_program", "mode_sewing_data", "mode_sewing_data1", "mode_sewing_data2", "presser type selection", "pattern_no_selecttion", "change_direct", "register_the_pattern", "select_the_pattern", "new_register_the_pattern", "name_the_parttern", "bobbin_winding", "maintenance_and_inspection_information", "production_control_start", "production_control_stop", "working_measurement", "input_final_target_value", "input_pitch_time", "input_number_of_times_of_thread trimming" };
static const char *object_names[] = { "main", "mode", "ready", "info", "sewing_data1", "sewing_data2", "sewing_data3", "sewing_data4", "sewing_data5", "sewing_data6", "mode1_1", "mode1_2", "mode1_3", "mode1_4", "mode2_1", "mode2_2", "mode2_3", "mode2_4", "check_program", "mode_sewing_data", "mode_sewing_data1", "mode_sewing_data2", "presser_type_selection", "pattern_no_selecttion", "change_direct", "register_the_pattern", "select_the_pattern", "new_register_the_pattern", "name_the_parttern", "bobbin_winding", "maintenance_and_inspection_information", "production_control_start", "production_control_stop", "working_measurement", "input_final_target_value", "input_pitch_time", "input_number_of_times_of_thread_trimming", "obj0", "obj1", "obj2", "obj3", "obj4", "btn_ready_screen", "btn_info_screen", "btn_sewing_data", "p1_btn_mode_screen", "btn_communication_screen", "presser_type", "btn_pattern_no_selecttion", "btn_bobbin_winder", "obj5", "obj6", "obj7", "obj8", "obj9", "btn_mode2", "btn_check_program", "btn_sewing_data_in_mode", "btn_mode1", "btn_ready_screen1", "btn_info_screen1", "btn_communication_screen1", "btn_mode_screen1", "btn_register_the_pattern", "mode1", "mode2", "mode5", "mode8", "mode4", "obj10", "obj11", "obj12", "btn_ready_screen2", "obj13", "obj14", "obj15", "obj16", "obj17", "obj18", "obj19", "btn_production_control", "btn_working_measurement", "btn_maintenance_and_inspection", "btn_ready_screen1_1", "btn_info_screen1_1", "btn_communication_screen1_1", "btn_mode_screen1_1", "i1", "i2", "i3", "obj20", "obj21", "btn_s004", "btn_s002", "btn_s005", "btn_s003", "btn_s006", "btn_s001", "btn_ready_screen3", "btn_info_screen3", "btn_communication_screen3", "btn_mode_screen3", "btn_next", "btn_back", "btn_exit", "s001", "s002", "s003", "s004", "s005", "s006", "obj22", "obj23", "btn_s010", "btn_s008", "btn_s011", "btn_s009", "btn_s021", "btn_s007", "btn_ready_screen4", "btn_info_screen4", "btn_communication_screen4", "btn_mode_screen4", "btn_next1", "btn_back1", "btn_exit1", "s007", "s008", "s009", "s0010", "s0011", "s021", "obj24", "obj25", "btn_ready_screen5", "btn_info_screen5", "btn_communication_screen5", "btn_mode_screen5", "btn_next2", "btn_back2", "btn_exit2", "s022", "s023", "s031", "s034", "s035", "s036", "obj26", "obj27", "btn_s044", "btn_s038", "btn_s051", "btn_s040", "btn_s055", "btn_s037", "btn_ready_screen6", "btn_info_screen6", "btn_communication_screen6", "btn_mode_screen6", "btn_next3", "btn_back3", "btn_exit3", "s037", "s038", "s040", "s044", "s051", "s055", "obj28", "obj29", "btn_s064", "btn_s058", "btn_s067", "btn_s062", "btn_s068", "btn_s057", "btn_ready_screen7", "btn_info_screen7", "btn_communication_screen7", "btn_mode_screen7", "btn_next4", "btn_back4", "btn_exit4", "s057", "s058", "s062", "s064", "s067", "s068", "obj30", "obj31", "btn_s084", "btn_s081", "btn_ready_screen8", "btn_info_screen8", "btn_communication_screen8", "btn_mode_screen8", "btn_next5", "btn_back5", "btn_exit5", "s081", "s084", "obj32", "obj33", "btn_u004", "btn_u002", "btn_u005", "btn_u003", "btn_u006", "btn_u001", "btn_ready_screen9", "btn_info_screen9", "btn_communication_screen9", "btn_mode_screen9", "btn_next6", "btn_back6", "btn_exit6", "u001", "u002", "u003", "u004", "u005", "u006", "obj34", "obj35", "btn_u010", "btn_u008", "btn_u011", "btn_u009", "btn_u012", "btn_u007", "btn_ready_screen10", "btn_info_screen10", "btn_communication_screen10", "btn_mode_screen10", "btn_next7", "btn_back7", "btn_exit7", "u007", "u008", "u009", "u010", "u011", "u012", "obj36", "obj37", "btn_u018", "btn_u014", "btn_u019", "btn_u015", "btn_u020", "btn_u013", "btn_ready_screen11", "btn_info_screen11", "btn_communication_screen11", "btn_mode_screen11", "btn_next8", "btn_back8", "btn_exit8", "u013", "u014", "u015", "u018", "u019", "u020", "obj38", "obj39", "btn_u024", "btn_u022", "btn_u025", "btn_u023", "btn_u500", "btn_u021", "btn_ready_screen12", "btn_info_screen12", "btn_communication_screen12", "btn_mode_screen12", "obj40", "obj41", "u021", "u022", "u023", "u024", "u025", "u500", "obj42", "obj43", "btn_k005", "btn_k003", "btn_k006", "btn_k004", "btn_k007", "btn_k001", "btn_ready_screen13", "btn_info_screen13", "btn_communication_screen13", "btn_mode_screen13", "btn_next9", "btn_back9", "btn_exit9", "k001", "k003", "k004", "k005", "k006", "k007", "obj44", "obj45", "btn_k011", "btn_k009", "btn_k012", "btn_k010", "btn_k013", "btn_k008", "btn_ready_screen14", "btn_info_screen14", "btn_communication_screen14", "btn_mode_screen14", "btn_next10", "btn_back10", "btn_exit10", "k008", "k009", "k010", "k011", "k012", "k013", "obj46", "obj47", "btn_k017", "btn_k015", "btn_k018", "btn_k016", "btn_k019", "btn_k014", "btn_ready_screen15", "btn_info_screen15", "btn_communication_screen15", "btn_mode_screen15", "btn_next11", "btn_back11", "btn_exit11", "k014", "k015", "k016", "k017", "k018", "k019", "obj48", "obj49", "btn_k021", "btn_k022", "btn_k020", "btn_ready_screen16", "btn_info_screen16", "btn_communication_screen16", "btn_mode_screen16", "btn_next12", "btn_back12", "btn_exit12", "k020", "k021", "k022", "obj50", "obj51", "btn_i004", "btn_i002", "btn_i005", "btn_i003", "btn_i001", "btn_ready_screen17", "btn_info_screen17", "btn_communication_screen17", "btn_mode_screen17", "btn_exit13", "i001", "i002", "i003", "i004", "i005", "obj52", "obj53", "btn_s042", "btn_s039", "btn_s052", "btn_s041", "btn_s053", "btn_s020", "btn_ready_screen18", "btn_info_screen18", "btn_communication_screen18", "btn_mode_screen18", "btn_next14", "btn_back14", "btn_exit14", "s020", "s039", "s041", "s042", "s052", "s053", "obj54", "obj55", "btn_s060", "btn_s056", "btn_s061", "btn_s059", "btn_s063", "btn_s054", "btn_ready_screen19", "btn_info_screen19", "btn_communication_screen19", "btn_mode_screen19", "btn_next15", "btn_back15", "btn_exit15", "s054", "s056", "s059", "s060", "s061", "s063", "obj56", "obj57", "btn_s070", "btn_s066", "btn_s083", "btn_s069", "btn_s065", "btn_ready_screen20", "btn_info_screen20", "btn_communication_screen20", "btn_mode_screen20", "btn_next16", "btn_back16", "btn_exit16", "s065", "s066", "s069", "s070", "s083", "obj58", "obj59", "btn_ready_screen20_1", "btn_info_screen20_1", "btn_communication_screen20_1", "btn_mode_screen20_1", "btn_exit16_1", "presser_type_1", "presser_type_2", "presser_type_5", "presser_type_3", "obj60", "obj61", "obj62", "btn_ready_screen20_3", "btn_info_screen20_3", "btn_communication_screen20_3", "btn_mode_screen20_3", "btn_exit16_3", "obj63", "obj64", "obj65", "obj66", "obj67", "obj68", "obj69", "pattern_no", "obj70", "obj71", "obj72", "btn_ready_screen_1", "btn_info_screen_1", "p1_btn_mode_screen_1", "btn_communication_screen_1", "obj73", "obj74", "btn_ready_screen20_4", "btn_info_screen20_4", "btn_communication_screen20_4", "btn_mode_screen20_4", "btn_exit16_4", "obj75", "obj76", "obj77", "obj78", "obj79", "obj80", "obj81", "obj82", "obj83", "obj84", "obj85", "obj86", "btn_ready_screen20_5", "btn_info_screen20_5", "btn_communication_screen20_5", "btn_mode_screen20_5", "btn_exit16_5", "obj87", "obj88", "obj89", "obj90", "btn_ready_screen_2", "btn_info_screen_2", "p1_btn_mode_screen_2", "btn_communication_screen_2", "obj91", "obj92", "obj93", "btn_ready_screen_3", "btn_info_screen_3", "p1_btn_mode_screen_3", "btn_communication_screen_3", "obj94", "obj95", "obj96", "obj97", "obj98", "obj99", "obj100", "obj101", "obj102", "obj103", "obj104", "obj105", "obj106", "obj107", "obj108", "obj109", "obj110", "obj111", "obj112", "obj113", "obj114", "obj115", "obj116", "obj117", "obj118", "obj119", "obj120", "obj121", "obj122", "obj123", "obj124", "obj125", "obj126", "obj127", "obj128", "obj129", "obj130", "obj131", "obj132", "obj133", "obj134", "obj135", "obj136", "obj137", "obj138", "obj139", "obj140", "obj141", "btn_ready_screen_4", "btn_info_screen_4", "p1_btn_mode_screen_4", "btn_communication_screen_4", "obj142", "obj143", "btn_ready_screen_5", "btn_info_screen_5", "p1_btn_mode_screen_5", "btn_communication_screen_5", "obj144", "obj145", "obj146", "btn_ready_screen_6", "btn_info_screen_6", "p1_btn_mode_screen_6", "btn_communication_screen_6", "obj147", "start", "clear", "obj148", "obj149", "obj150", "obj151", "obj152", "btn_ready_screen_8", "btn_info_screen_8", "p1_btn_mode_screen_8", "btn_communication_screen_8", "obj153", "start_1", "obj154", "obj155", "btn_ready_screen_9", "btn_info_screen_9", "p1_btn_mode_screen_9", "btn_communication_screen_9", "obj156", "start_2", "clear_1", "obj157", "obj158", "btn_ready_screen_7", "btn_info_screen_7", "p1_btn_mode_screen_7", "btn_communication_screen_7", "obj159", "obj160", "obj161", "btn_ready_screen_10", "btn_info_screen_10", "p1_btn_mode_screen_10", "btn_communication_screen_10", "obj162", "obj163", "obj164", "btn_ready_screen_11", "btn_info_screen_11", "p1_btn_mode_screen_11", "btn_communication_screen_11", "obj165" };

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
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_main_btn_info_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_main_btn_sewing_data(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_main_p1_btn_mode_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 16, 0, e);
    }
}

static void event_handler_cb_main_presser_type(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 18, 0, e);
    }
}

static void event_handler_cb_main_btn_pattern_no_selecttion(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 19, 0, e);
    }
}

static void event_handler_cb_main_btn_bobbin_winder(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 21, 0, e);
    }
}

static void event_handler_cb_main_obj5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 22, 0, e);
    }
}

static void event_handler_cb_main_obj6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 25, 0, e);
    }
}

static void event_handler_cb_main_obj7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 31, 0, e);
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
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_mode_btn_mode1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_mode_btn_ready_screen1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_mode_btn_info_screen1(lv_event_t *e) {
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
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_mode_btn_register_the_pattern(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
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

static void event_handler_cb_ready_obj13(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 19, 0, e);
    }
}

static void event_handler_cb_ready_obj14(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 21, 0, e);
    }
}

static void event_handler_cb_ready_obj15(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 22, 0, e);
    }
}

static void event_handler_cb_ready_obj16(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 23, 0, e);
    }
}

static void event_handler_cb_ready_obj17(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 24, 0, e);
    }
}

static void event_handler_cb_info_btn_production_control(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_info_btn_working_measurement(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_info_btn_maintenance_and_inspection(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_info_btn_mode_screen1_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_sewing_data1_btn_ready_screen3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_sewing_data1_btn_info_screen3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_sewing_data1_btn_mode_screen3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
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

static void event_handler_cb_sewing_data2_btn_ready_screen4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_sewing_data2_btn_info_screen4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_sewing_data2_btn_mode_screen4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
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

static void event_handler_cb_sewing_data3_btn_ready_screen5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_sewing_data3_btn_info_screen5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_sewing_data3_btn_mode_screen5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_sewing_data3_btn_next2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_sewing_data3_btn_back2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_sewing_data3_btn_exit2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_sewing_data4_btn_ready_screen6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_sewing_data4_btn_info_screen6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_sewing_data4_btn_mode_screen6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_sewing_data4_btn_next3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_sewing_data4_btn_back3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_sewing_data4_btn_exit3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_sewing_data5_btn_ready_screen7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_sewing_data5_btn_info_screen7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_sewing_data5_btn_mode_screen7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_sewing_data5_btn_next4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_sewing_data5_btn_back4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_sewing_data5_btn_exit4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_sewing_data6_btn_ready_screen8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_sewing_data6_btn_info_screen8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_sewing_data6_btn_mode_screen8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_sewing_data6_btn_back5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_sewing_data6_btn_exit5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_mode1_1_btn_ready_screen9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_mode1_1_btn_info_screen9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_mode1_1_btn_mode_screen9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_mode1_1_btn_next6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
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

static void event_handler_cb_mode1_2_btn_ready_screen10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_mode1_2_btn_info_screen10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_mode1_2_btn_mode_screen10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_mode1_2_btn_next7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_mode1_2_btn_back7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_mode1_2_btn_exit7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_mode1_3_btn_ready_screen11(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_mode1_3_btn_info_screen11(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_mode1_3_btn_mode_screen11(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_mode1_3_btn_next8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_mode1_3_btn_back8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_mode1_3_btn_exit8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_mode1_4_btn_ready_screen12(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_mode1_4_btn_info_screen12(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_mode1_4_btn_mode_screen12(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_mode1_4_obj40(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_mode1_4_obj41(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_mode2_1_btn_ready_screen13(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_mode2_1_btn_info_screen13(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_mode2_1_btn_mode_screen13(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_mode2_1_btn_next9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
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

static void event_handler_cb_mode2_2_btn_ready_screen14(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_mode2_2_btn_info_screen14(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_mode2_2_btn_mode_screen14(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_mode2_2_btn_next10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_mode2_2_btn_back10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_mode2_2_btn_exit10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_mode2_3_btn_ready_screen15(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_mode2_3_btn_info_screen15(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_mode2_3_btn_mode_screen15(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_mode2_3_btn_next11(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_mode2_3_btn_back11(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_mode2_3_btn_exit11(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_mode2_4_btn_ready_screen16(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_mode2_4_btn_info_screen16(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_mode2_4_btn_mode_screen16(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_mode2_4_btn_back12(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_mode2_4_btn_exit12(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_check_program_btn_ready_screen17(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_check_program_btn_info_screen17(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_check_program_btn_mode_screen17(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_check_program_btn_exit13(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_mode_sewing_data_btn_ready_screen18(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_mode_sewing_data_btn_info_screen18(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_mode_sewing_data_btn_mode_screen18(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_mode_sewing_data_btn_next14(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
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

static void event_handler_cb_mode_sewing_data1_btn_ready_screen19(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_mode_sewing_data1_btn_info_screen19(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_mode_sewing_data1_btn_mode_screen19(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_mode_sewing_data1_btn_next15(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_mode_sewing_data1_btn_back15(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_mode_sewing_data1_btn_exit15(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_mode_sewing_data2_btn_ready_screen20(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_mode_sewing_data2_btn_info_screen20(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_mode_sewing_data2_btn_mode_screen20(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_mode_sewing_data2_btn_back16(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_mode_sewing_data2_btn_exit16(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_presser_type_selection_btn_mode_screen20_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_presser_type_selection_btn_exit16_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_presser_type_selection_presser_type_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_presser_type_selection_presser_type_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_presser_type_selection_presser_type_5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_presser_type_selection_presser_type_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_presser_type_selection_obj60(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_pattern_no_selecttion_btn_ready_screen20_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_pattern_no_selecttion_btn_info_screen20_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_pattern_no_selecttion_btn_mode_screen20_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_pattern_no_selecttion_btn_exit16_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_pattern_no_selecttion_obj63(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_pattern_no_selecttion_obj64(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_pattern_no_selecttion_obj65(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_pattern_no_selecttion_obj66(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_pattern_no_selecttion_obj67(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_pattern_no_selecttion_obj68(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_pattern_no_selecttion_obj69(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 16, 0, e);
    }
}

static void event_handler_cb_change_direct_btn_ready_screen_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_change_direct_btn_info_screen_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_change_direct_p1_btn_mode_screen_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_register_the_pattern_btn_ready_screen20_4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_register_the_pattern_btn_info_screen20_4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_register_the_pattern_btn_mode_screen20_4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_register_the_pattern_btn_exit16_4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_register_the_pattern_obj75(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_register_the_pattern_obj76(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_register_the_pattern_obj77(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_register_the_pattern_obj78(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_register_the_pattern_obj79(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_register_the_pattern_obj80(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_register_the_pattern_obj81(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_register_the_pattern_obj82(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_register_the_pattern_obj83(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 16, 0, e);
    }
}

static void event_handler_cb_register_the_pattern_obj84(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 17, 0, e);
    }
}

static void event_handler_cb_select_the_pattern_btn_ready_screen20_5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_select_the_pattern_btn_info_screen20_5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_select_the_pattern_btn_mode_screen20_5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_select_the_pattern_btn_exit16_5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_select_the_pattern_obj87(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 18, 0, e);
    }
}

static void event_handler_cb_new_register_the_pattern_btn_ready_screen_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_new_register_the_pattern_btn_info_screen_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_new_register_the_pattern_p1_btn_mode_screen_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_name_the_parttern_btn_ready_screen_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_name_the_parttern_btn_info_screen_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_name_the_parttern_p1_btn_mode_screen_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_bobbin_winding_btn_ready_screen_4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_bobbin_winding_btn_info_screen_4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_bobbin_winding_p1_btn_mode_screen_4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_maintenance_and_inspection_information_btn_ready_screen_5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_maintenance_and_inspection_information_btn_info_screen_5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_maintenance_and_inspection_information_p1_btn_mode_screen_5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_maintenance_and_inspection_information_obj144(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_production_control_start_btn_ready_screen_6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_production_control_start_btn_info_screen_6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_production_control_start_p1_btn_mode_screen_6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_production_control_start_obj147(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_production_control_start_start(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_production_control_start_obj148(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_production_control_start_obj149(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_production_control_start_obj150(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_production_control_stop_btn_ready_screen_8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_production_control_stop_btn_info_screen_8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_production_control_stop_p1_btn_mode_screen_8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_production_control_stop_obj153(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_production_control_stop_start_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_working_measurement_btn_ready_screen_9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_working_measurement_btn_info_screen_9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_working_measurement_p1_btn_mode_screen_9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_working_measurement_obj156(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_working_measurement_start_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_input_final_target_value_btn_ready_screen_7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_input_final_target_value_btn_info_screen_7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_input_final_target_value_p1_btn_mode_screen_7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_input_final_target_value_obj159(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 17, 0, e);
    }
}

static void event_handler_cb_input_pitch_time_btn_ready_screen_10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_input_pitch_time_btn_info_screen_10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_input_pitch_time_p1_btn_mode_screen_10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_input_pitch_time_obj162(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 17, 0, e);
    }
}

static void event_handler_cb_input_number_of_times_of_thread_trimming_btn_ready_screen_11(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_input_number_of_times_of_thread_trimming_btn_info_screen_11(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_input_number_of_times_of_thread_trimming_p1_btn_mode_screen_11(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_input_number_of_times_of_thread_trimming_obj165(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 17, 0, e);
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
    lv_obj_set_style_bg_img_src(obj, &img_ma_b, LV_PART_MAIN | LV_STATE_DEFAULT);
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
            lv_obj_set_pos(obj, 12, 163);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_not);
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
        {
            // presser_type
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.presser_type = obj;
            lv_obj_set_pos(obj, 469, 54);
            lv_obj_set_size(obj, 60, 120);
            lv_obj_add_event_cb(obj, event_handler_cb_main_presser_type, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_ma_r, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_pattern_no_selecttion
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_pattern_no_selecttion = obj;
            lv_obj_set_pos(obj, 82, 382);
            lv_obj_set_size(obj, 80, 90);
            lv_obj_add_event_cb(obj, event_handler_cb_main_btn_pattern_no_selecttion, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_ma_g, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 12, 86);
            lv_obj_set_size(obj, 50, 70);
            lv_obj_set_style_bg_img_src(obj, &img_ma_e, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_bobbin_winder
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_bobbin_winder = obj;
            lv_obj_set_pos(obj, 12, 8);
            lv_obj_set_size(obj, 50, 70);
            lv_obj_add_event_cb(obj, event_handler_cb_main_btn_bobbin_winder, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_ma_f, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 12, 243);
            lv_obj_set_size(obj, 50, 70);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj5, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_ma_c, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 72, 15);
            lv_obj_set_size(obj, 50, 70);
            lv_obj_set_style_bg_img_src(obj, &img_ma_m, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 12, 323);
            lv_obj_set_size(obj, 50, 70);
            lv_obj_set_style_bg_img_src(obj, &img_ma_b, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj6 = obj;
            lv_obj_set_pos(obj, 12, 403);
            lv_obj_set_size(obj, 50, 70);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj6, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_ma_a, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 128, 16);
            lv_obj_set_size(obj, 50, 70);
            lv_obj_set_style_bg_img_src(obj, &img_ma_n, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 535, 358);
            lv_obj_set_size(obj, 130, 100);
            lv_obj_set_style_bg_img_src(obj, &img_ma_s1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 535, 246);
            lv_obj_set_size(obj, 130, 100);
            lv_obj_set_style_bg_img_src(obj, &img_ma_s2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 535, 133);
            lv_obj_set_size(obj, 130, 100);
            lv_obj_set_style_bg_img_src(obj, &img_ma_s3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 535, 18);
            lv_obj_set_size(obj, 130, 100);
            lv_obj_set_style_bg_img_src(obj, &img_ma_s4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 469, 193);
            lv_obj_set_size(obj, 60, 120);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj7, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_ma_k, LV_PART_MAIN | LV_STATE_DEFAULT);
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
            objects.obj8 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff7ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj9 = obj;
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
            // btn_sewing_data_in_mode
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_sewing_data_in_mode = obj;
            lv_obj_set_pos(obj, 210, 103);
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode_btn_ready_screen1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen1 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_mode_btn_info_screen1, LV_EVENT_ALL, flowState);
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
            // btn_register_the_pattern
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_register_the_pattern = obj;
            lv_obj_set_pos(obj, 372, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_add_event_cb(obj, event_handler_cb_mode_btn_register_the_pattern, LV_EVENT_ALL, flowState);
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
            // mode5
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.mode5 = obj;
            lv_obj_set_pos(obj, 51, 3);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // mode8
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.mode8 = obj;
            lv_obj_set_pos(obj, 210, 3);
            lv_obj_set_size(obj, 130, 92);
        }
        {
            // mode4
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.mode4 = obj;
            lv_obj_set_pos(obj, 372, 240);
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
            objects.obj10 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj11 = obj;
            lv_obj_set_pos(obj, 459, 0);
            lv_obj_set_size(obj, 221, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff599bdc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj12 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 459, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ffa4), LV_PART_MAIN | LV_STATE_DEFAULT);
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
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 181, 81);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_se_ikmnpq);
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
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj13 = obj;
            lv_obj_set_pos(obj, 690, 20);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_ready_obj13, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 690, 130);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj14 = obj;
            lv_obj_set_pos(obj, 690, 245);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_ready_obj14, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj15 = obj;
            lv_obj_set_pos(obj, 691, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_ready_obj15, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj16 = obj;
            lv_obj_set_pos(obj, 469, 192);
            lv_obj_set_size(obj, 60, 120);
            lv_obj_add_event_cb(obj, event_handler_cb_ready_obj16, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_ma_k, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj17 = obj;
            lv_obj_set_pos(obj, 12, 8);
            lv_obj_set_size(obj, 50, 70);
            lv_obj_add_event_cb(obj, event_handler_cb_ready_obj17, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_ma_f, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 12, 85);
            lv_obj_set_size(obj, 50, 70);
            lv_obj_set_style_bg_img_src(obj, &img_ma_e, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 12, 160);
            lv_obj_set_size(obj, 50, 70);
            lv_obj_set_style_bg_img_src(obj, &img_se_d, LV_PART_MAIN | LV_STATE_DEFAULT);
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
            objects.obj18 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd7fffb), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj19 = obj;
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
            lv_obj_add_event_cb(obj, event_handler_cb_info_btn_production_control, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_production_control, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_working_measurement
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_working_measurement = obj;
            lv_obj_set_pos(obj, 445, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_add_event_cb(obj, event_handler_cb_info_btn_working_measurement, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_working_measurement, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_maintenance_and_inspection
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_maintenance_and_inspection = obj;
            lv_obj_set_pos(obj, 100, 341);
            lv_obj_set_size(obj, 130, 110);
            lv_obj_add_event_cb(obj, event_handler_cb_info_btn_maintenance_and_inspection, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_info_btn_mode_screen1_1, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data1_btn_ready_screen3, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen3 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data1_btn_info_screen3, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data1_btn_mode_screen3, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data2_btn_ready_screen4, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen4 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data2_btn_info_screen4, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data2_btn_mode_screen4, LV_EVENT_ALL, flowState);
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
            objects.obj24 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj25 = obj;
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
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data3_btn_ready_screen5, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen5 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data3_btn_info_screen5, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data3_btn_mode_screen5, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next2 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data3_btn_next2, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back2 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data3_btn_back2, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit2 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data3_btn_exit2, LV_EVENT_ALL, flowState);
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
            objects.obj26 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj27 = obj;
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
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data4_btn_ready_screen6, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen6 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data4_btn_info_screen6, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data4_btn_mode_screen6, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next3 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data4_btn_next3, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back3 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data4_btn_back3, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit3 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data4_btn_exit3, LV_EVENT_ALL, flowState);
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
            objects.obj28 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj29 = obj;
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
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data5_btn_ready_screen7, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen7 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data5_btn_info_screen7, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data5_btn_mode_screen7, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next4 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data5_btn_next4, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back4 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data5_btn_back4, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit4 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data5_btn_exit4, LV_EVENT_ALL, flowState);
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
            objects.obj30 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj31 = obj;
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
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data6_btn_ready_screen8, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen8 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data6_btn_info_screen8, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data6_btn_mode_screen8, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data6_btn_back5, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit5 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_sewing_data6_btn_exit5, LV_EVENT_ALL, flowState);
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
            objects.obj32 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffafec9a), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj33 = obj;
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_1_btn_ready_screen9, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen9 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_1_btn_info_screen9, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_1_btn_mode_screen9, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next6 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_1_btn_next6, LV_EVENT_ALL, flowState);
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
            objects.obj34 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffafec9a), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj35 = obj;
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_2_btn_ready_screen10, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen10
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen10 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_2_btn_info_screen10, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_2_btn_mode_screen10, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next7 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_2_btn_next7, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back7 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_2_btn_back7, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit7 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_2_btn_exit7, LV_EVENT_ALL, flowState);
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
            objects.obj36 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffafec9a), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj37 = obj;
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_3_btn_ready_screen11, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen11
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen11 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_3_btn_info_screen11, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_3_btn_mode_screen11, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next8 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_3_btn_next8, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back8 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_3_btn_back8, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit8 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_3_btn_exit8, LV_EVENT_ALL, flowState);
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
            objects.obj38 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffafec9a), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj39 = obj;
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_4_btn_ready_screen12, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen12
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen12 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_4_btn_info_screen12, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_4_btn_mode_screen12, LV_EVENT_ALL, flowState);
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
            objects.obj40 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_4_obj40, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj41 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode1_4_obj41, LV_EVENT_ALL, flowState);
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
            objects.obj42 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffadefc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj43 = obj;
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_1_btn_ready_screen13, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen13
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen13 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_1_btn_info_screen13, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_1_btn_mode_screen13, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next9 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_1_btn_next9, LV_EVENT_ALL, flowState);
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
            objects.obj44 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffadefc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj45 = obj;
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_2_btn_ready_screen14, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen14
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen14 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_2_btn_info_screen14, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_2_btn_mode_screen14, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next10
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next10 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_2_btn_next10, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back10
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back10 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_2_btn_back10, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit10
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit10 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_2_btn_exit10, LV_EVENT_ALL, flowState);
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
            objects.obj46 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffadefc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj47 = obj;
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_3_btn_ready_screen15, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen15
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen15 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_3_btn_info_screen15, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_3_btn_mode_screen15, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next11
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next11 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_3_btn_next11, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back11
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back11 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_3_btn_back11, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit11
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit11 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_3_btn_exit11, LV_EVENT_ALL, flowState);
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
            objects.obj48 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffadefc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj49 = obj;
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_4_btn_ready_screen16, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen16
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen16 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_4_btn_info_screen16, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_4_btn_mode_screen16, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_4_btn_back12, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit12
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit12 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode2_4_btn_exit12, LV_EVENT_ALL, flowState);
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
            objects.obj50 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffdde7f8), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj51 = obj;
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
            lv_obj_add_event_cb(obj, event_handler_cb_check_program_btn_ready_screen17, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen17
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen17 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_check_program_btn_info_screen17, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_check_program_btn_mode_screen17, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
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
            objects.obj52 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj53 = obj;
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode_sewing_data_btn_ready_screen18, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen18
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen18 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_mode_sewing_data_btn_info_screen18, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode_sewing_data_btn_mode_screen18, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next14
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next14 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode_sewing_data_btn_next14, LV_EVENT_ALL, flowState);
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
            objects.obj54 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj55 = obj;
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode_sewing_data1_btn_ready_screen19, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen19
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen19 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_mode_sewing_data1_btn_info_screen19, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode_sewing_data1_btn_mode_screen19, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next15
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_next15 = obj;
            lv_obj_set_pos(obj, 613, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode_sewing_data1_btn_next15, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_back15
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_back15 = obj;
            lv_obj_set_pos(obj, 613, 411);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode_sewing_data1_btn_back15, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit15
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit15 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode_sewing_data1_btn_exit15, LV_EVENT_ALL, flowState);
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
            objects.obj56 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj57 = obj;
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode_sewing_data2_btn_ready_screen20, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen20
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen20 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_mode_sewing_data2_btn_info_screen20, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode_sewing_data2_btn_mode_screen20, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_mode_sewing_data2_btn_back16, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit16
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit16 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_mode_sewing_data2_btn_exit16, LV_EVENT_ALL, flowState);
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

void create_screen_presser_type_selection() {
    void *flowState = getFlowState(0, 22);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.presser_type_selection = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj58 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj59 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen20_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen20_1 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen20_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen20_1 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen20_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen20_1 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen20_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen20_1 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_presser_type_selection_btn_mode_screen20_1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit16_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit16_1 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_presser_type_selection_btn_exit16_1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // presser_type_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.presser_type_1 = obj;
            lv_obj_set_pos(obj, 60, 291);
            lv_obj_set_size(obj, 100, 150);
            lv_obj_add_event_cb(obj, event_handler_cb_presser_type_selection_presser_type_1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_type1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // presser_type_2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.presser_type_2 = obj;
            lv_obj_set_pos(obj, 208, 291);
            lv_obj_set_size(obj, 100, 150);
            lv_obj_add_event_cb(obj, event_handler_cb_presser_type_selection_presser_type_2, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_type2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // presser_type_5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.presser_type_5 = obj;
            lv_obj_set_pos(obj, 495, 291);
            lv_obj_set_size(obj, 100, 150);
            lv_obj_add_event_cb(obj, event_handler_cb_presser_type_selection_presser_type_5, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_type5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // presser_type_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.presser_type_3 = obj;
            lv_obj_set_pos(obj, 350, 291);
            lv_obj_set_size(obj, 100, 150);
            lv_obj_add_event_cb(obj, event_handler_cb_presser_type_selection_presser_type_3, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_type3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj60 = obj;
            lv_obj_set_pos(obj, 595, 18);
            lv_obj_set_size(obj, 70, 90);
            lv_obj_add_event_cb(obj, event_handler_cb_presser_type_selection_obj60, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_enter, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_presser_type_selection();
}

void tick_screen_presser_type_selection() {
    void *flowState = getFlowState(0, 22);
    (void)flowState;
}

void create_screen_pattern_no_selecttion() {
    void *flowState = getFlowState(0, 23);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.pattern_no_selecttion = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj61 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj62 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen20_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen20_3 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_pattern_no_selecttion_btn_ready_screen20_3, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen20_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen20_3 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_pattern_no_selecttion_btn_info_screen20_3, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen20_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen20_3 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen20_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen20_3 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_pattern_no_selecttion_btn_mode_screen20_3, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit16_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit16_3 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_pattern_no_selecttion_btn_exit16_3, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj63 = obj;
            lv_obj_set_pos(obj, 345, 321);
            lv_obj_set_size(obj, 125, 140);
            lv_obj_add_event_cb(obj, event_handler_cb_pattern_no_selecttion_obj63, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_pattern_no_1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 615, 401);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 615, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_next, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj64 = obj;
            lv_obj_set_pos(obj, 257, 18);
            lv_obj_set_size(obj, 70, 90);
            lv_obj_add_event_cb(obj, event_handler_cb_pattern_no_selecttion_obj64, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_enter, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj65 = obj;
            lv_obj_set_pos(obj, 345, 169);
            lv_obj_set_size(obj, 125, 140);
            lv_obj_add_event_cb(obj, event_handler_cb_pattern_no_selecttion_obj65, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_pattern_no_2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj66 = obj;
            lv_obj_set_pos(obj, 345, 18);
            lv_obj_set_size(obj, 125, 140);
            lv_obj_add_event_cb(obj, event_handler_cb_pattern_no_selecttion_obj66, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_pattern_no_3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj67 = obj;
            lv_obj_set_pos(obj, 479, 321);
            lv_obj_set_size(obj, 125, 140);
            lv_obj_add_event_cb(obj, event_handler_cb_pattern_no_selecttion_obj67, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_pattern_no_4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj68 = obj;
            lv_obj_set_pos(obj, 479, 169);
            lv_obj_set_size(obj, 125, 140);
            lv_obj_add_event_cb(obj, event_handler_cb_pattern_no_selecttion_obj68, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_pattern_no_5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj69 = obj;
            lv_obj_set_pos(obj, 479, 18);
            lv_obj_set_size(obj, 125, 140);
            lv_obj_add_event_cb(obj, event_handler_cb_pattern_no_selecttion_obj69, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_pattern_no_6, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // pattern_no
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.pattern_no = obj;
            lv_obj_set_pos(obj, 7, 111);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_pattern_no_1_1);
        }
    }
    
    tick_screen_pattern_no_selecttion();
}

void tick_screen_pattern_no_selecttion() {
    void *flowState = getFlowState(0, 23);
    (void)flowState;
}

void create_screen_change_direct() {
    void *flowState = getFlowState(0, 24);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.change_direct = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj70 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj71 = obj;
            lv_obj_set_pos(obj, 459, 0);
            lv_obj_set_size(obj, 221, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff599bdc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj72 = obj;
            lv_obj_set_pos(obj, -3, 0);
            lv_obj_set_size(obj, 459, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0000ff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen_1 = obj;
            lv_obj_set_pos(obj, 690, 362);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_change_direct_btn_ready_screen_1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen_1 = obj;
            lv_obj_set_pos(obj, 690, 246);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_change_direct_btn_info_screen_1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // P1_btn_mode_screen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.p1_btn_mode_screen_1 = obj;
            lv_obj_set_pos(obj, 690, 15);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_change_direct_p1_btn_mode_screen_1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen_1 = obj;
            lv_obj_set_pos(obj, 690, 130);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 80, 71);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_pattern_no_1_1);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 10, 391);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_a_not_background);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 10, 321);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_b_not_background);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 10, 251);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_c_not_background);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 10, 95);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_e_not_background);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 10, 15);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_f_not_background);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 472, 10);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 472, 100);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 472, 189);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 473, 281);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 473, 372);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 582, 372);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_6, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 583, 281);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_7, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 583, 190);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 582, 101);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_9, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 582, 11);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_change_direct();
}

void tick_screen_change_direct() {
    void *flowState = getFlowState(0, 24);
    (void)flowState;
}

void create_screen_register_the_pattern() {
    void *flowState = getFlowState(0, 25);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.register_the_pattern = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj73 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj74 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen20_4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen20_4 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_register_the_pattern_btn_ready_screen20_4, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen20_4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen20_4 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_register_the_pattern_btn_info_screen20_4, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen20_4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen20_4 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen20_4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen20_4 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_register_the_pattern_btn_mode_screen20_4, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit16_4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit16_4 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_register_the_pattern_btn_exit16_4, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj75 = obj;
            lv_obj_set_pos(obj, 209, 20);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_add_event_cb(obj, event_handler_cb_register_the_pattern_obj75, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_direct_5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj76 = obj;
            lv_obj_set_pos(obj, 209, 110);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_add_event_cb(obj, event_handler_cb_register_the_pattern_obj76, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_direct_4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj77 = obj;
            lv_obj_set_pos(obj, 209, 199);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_add_event_cb(obj, event_handler_cb_register_the_pattern_obj77, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_direct_3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj78 = obj;
            lv_obj_set_pos(obj, 210, 291);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_add_event_cb(obj, event_handler_cb_register_the_pattern_obj78, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_direct_2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj79 = obj;
            lv_obj_set_pos(obj, 210, 382);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_add_event_cb(obj, event_handler_cb_register_the_pattern_obj79, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_direct_1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj80 = obj;
            lv_obj_set_pos(obj, 319, 382);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_add_event_cb(obj, event_handler_cb_register_the_pattern_obj80, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_direct_6, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj81 = obj;
            lv_obj_set_pos(obj, 319, 296);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_add_event_cb(obj, event_handler_cb_register_the_pattern_obj81, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_direct_7, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj82 = obj;
            lv_obj_set_pos(obj, 320, 200);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_add_event_cb(obj, event_handler_cb_register_the_pattern_obj82, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_direct_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj83 = obj;
            lv_obj_set_pos(obj, 319, 111);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_add_event_cb(obj, event_handler_cb_register_the_pattern_obj83, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_direct_9, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj84 = obj;
            lv_obj_set_pos(obj, 319, 21);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_add_event_cb(obj, event_handler_cb_register_the_pattern_obj84, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_direct_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_register_the_pattern();
}

void tick_screen_register_the_pattern() {
    void *flowState = getFlowState(0, 25);
    (void)flowState;
}

void create_screen_select_the_pattern() {
    void *flowState = getFlowState(0, 26);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.select_the_pattern = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_set_style_bg_img_src(obj, &img_pattern_no_1, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj85 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffababf2), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj86 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen20_5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen20_5 = obj;
            lv_obj_set_pos(obj, 690, 361);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_select_the_pattern_btn_ready_screen20_5, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen20_5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen20_5 = obj;
            lv_obj_set_pos(obj, 690, 241);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_select_the_pattern_btn_info_screen20_5, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen20_5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen20_5 = obj;
            lv_obj_set_pos(obj, 690, 128);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_mode_screen20_5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_mode_screen20_5 = obj;
            lv_obj_set_pos(obj, 690, 18);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_select_the_pattern_btn_mode_screen20_5, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_exit16_5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_exit16_5 = obj;
            lv_obj_set_pos(obj, 18, 18);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_select_the_pattern_btn_exit16_5, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 118, 324);
            lv_obj_set_size(obj, 125, 140);
            lv_obj_set_style_bg_img_src(obj, &img_pattern_no_1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 118, 171);
            lv_obj_set_size(obj, 125, 140);
            lv_obj_set_style_bg_img_src(obj, &img_pattern_no_2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 118, 18);
            lv_obj_set_size(obj, 125, 140);
            lv_obj_set_style_bg_img_src(obj, &img_pattern_no_3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 393, 172);
            lv_obj_set_size(obj, 125, 140);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 256, 324);
            lv_obj_set_size(obj, 125, 140);
            lv_obj_set_style_bg_img_src(obj, &img_pattern_no_4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 392, 324);
            lv_obj_set_size(obj, 125, 140);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 538, 324);
            lv_obj_set_size(obj, 125, 140);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 256, 171);
            lv_obj_set_size(obj, 125, 140);
            lv_obj_set_style_bg_img_src(obj, &img_pattern_no_5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 256, 18);
            lv_obj_set_size(obj, 125, 140);
            lv_obj_set_style_bg_img_src(obj, &img_pattern_no_6, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 393, 19);
            lv_obj_set_size(obj, 125, 140);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj87 = obj;
            lv_obj_set_pos(obj, 593, 18);
            lv_obj_set_size(obj, 70, 90);
            lv_obj_add_event_cb(obj, event_handler_cb_select_the_pattern_obj87, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_enter, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_select_the_pattern();
}

void tick_screen_select_the_pattern() {
    void *flowState = getFlowState(0, 26);
    (void)flowState;
}

void create_screen_new_register_the_pattern() {
    void *flowState = getFlowState(0, 27);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.new_register_the_pattern = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj88 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj89 = obj;
            lv_obj_set_pos(obj, 275, 0);
            lv_obj_set_size(obj, 405, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff599bdc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj90 = obj;
            lv_obj_set_pos(obj, -3, 0);
            lv_obj_set_size(obj, 278, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0000ff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen_2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen_2 = obj;
            lv_obj_set_pos(obj, 690, 362);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_new_register_the_pattern_btn_ready_screen_2, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen_2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen_2 = obj;
            lv_obj_set_pos(obj, 690, 246);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_new_register_the_pattern_btn_info_screen_2, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // P1_btn_mode_screen_2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.p1_btn_mode_screen_2 = obj;
            lv_obj_set_pos(obj, 690, 15);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_new_register_the_pattern_p1_btn_mode_screen_2, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen_2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen_2 = obj;
            lv_obj_set_pos(obj, 690, 130);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 388, 199);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 388, 301);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 287, 99);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 287, 199);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 287, 301);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 388, 99);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_6, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 488, 301);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_7, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 488, 199);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 488, 99);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_9, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 588, 301);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 15, 15);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 588, 199);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 588, 99);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 193, 15);
            lv_obj_set_size(obj, 70, 90);
            lv_obj_set_style_bg_img_src(obj, &img_enter, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_new_register_the_pattern();
}

void tick_screen_new_register_the_pattern() {
    void *flowState = getFlowState(0, 27);
    (void)flowState;
}

void create_screen_name_the_parttern() {
    void *flowState = getFlowState(0, 28);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.name_the_parttern = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj91 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj92 = obj;
            lv_obj_set_pos(obj, 168, 0);
            lv_obj_set_size(obj, 512, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff599bdc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj93 = obj;
            lv_obj_set_pos(obj, -3, 0);
            lv_obj_set_size(obj, 171, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0000ff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen_3 = obj;
            lv_obj_set_pos(obj, 690, 362);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_name_the_parttern_btn_ready_screen_3, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen_3 = obj;
            lv_obj_set_pos(obj, 690, 246);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_name_the_parttern_btn_info_screen_3, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // P1_btn_mode_screen_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.p1_btn_mode_screen_3 = obj;
            lv_obj_set_pos(obj, 690, 15);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_name_the_parttern_p1_btn_mode_screen_3, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen_3 = obj;
            lv_obj_set_pos(obj, 690, 130);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 15, 15);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 83, 15);
            lv_obj_set_size(obj, 70, 90);
            lv_obj_set_style_bg_img_src(obj, &img_enter, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj94 = obj;
            lv_obj_set_pos(obj, 181, 415);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj95 = obj;
            lv_obj_set_pos(obj, 181, 281);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj96 = obj;
            lv_obj_set_pos(obj, 181, 213);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj97 = obj;
            lv_obj_set_pos(obj, 181, 146);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj98 = obj;
            lv_obj_set_pos(obj, 181, 78);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj99 = obj;
            lv_obj_set_pos(obj, 181, 11);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj100 = obj;
            lv_obj_set_pos(obj, 181, 348);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj101 = obj;
            lv_obj_set_pos(obj, 252, 415);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj102 = obj;
            lv_obj_set_pos(obj, 252, 281);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj103 = obj;
            lv_obj_set_pos(obj, 252, 213);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj104 = obj;
            lv_obj_set_pos(obj, 252, 146);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj105 = obj;
            lv_obj_set_pos(obj, 252, 78);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj106 = obj;
            lv_obj_set_pos(obj, 252, 11);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj107 = obj;
            lv_obj_set_pos(obj, 252, 348);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj108 = obj;
            lv_obj_set_pos(obj, 324, 413);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj109 = obj;
            lv_obj_set_pos(obj, 324, 279);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj110 = obj;
            lv_obj_set_pos(obj, 324, 211);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj111 = obj;
            lv_obj_set_pos(obj, 324, 144);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj112 = obj;
            lv_obj_set_pos(obj, 324, 76);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj113 = obj;
            lv_obj_set_pos(obj, 324, 9);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj114 = obj;
            lv_obj_set_pos(obj, 324, 346);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj115 = obj;
            lv_obj_set_pos(obj, 395, 412);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj116 = obj;
            lv_obj_set_pos(obj, 395, 278);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj117 = obj;
            lv_obj_set_pos(obj, 395, 210);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj118 = obj;
            lv_obj_set_pos(obj, 395, 143);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj119 = obj;
            lv_obj_set_pos(obj, 395, 75);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj120 = obj;
            lv_obj_set_pos(obj, 395, 8);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj121 = obj;
            lv_obj_set_pos(obj, 395, 345);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj122 = obj;
            lv_obj_set_pos(obj, 469, 413);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj123 = obj;
            lv_obj_set_pos(obj, 469, 279);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj124 = obj;
            lv_obj_set_pos(obj, 469, 211);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj125 = obj;
            lv_obj_set_pos(obj, 469, 144);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj126 = obj;
            lv_obj_set_pos(obj, 469, 76);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj127 = obj;
            lv_obj_set_pos(obj, 469, 9);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj128 = obj;
            lv_obj_set_pos(obj, 469, 346);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj129 = obj;
            lv_obj_set_pos(obj, 540, 414);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj130 = obj;
            lv_obj_set_pos(obj, 540, 280);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj131 = obj;
            lv_obj_set_pos(obj, 540, 212);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj132 = obj;
            lv_obj_set_pos(obj, 540, 145);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj133 = obj;
            lv_obj_set_pos(obj, 540, 77);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj134 = obj;
            lv_obj_set_pos(obj, 540, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj135 = obj;
            lv_obj_set_pos(obj, 540, 347);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj136 = obj;
            lv_obj_set_pos(obj, 612, 23);
            lv_obj_set_size(obj, 60, 90);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj137 = obj;
            lv_obj_set_pos(obj, 612, 131);
            lv_obj_set_size(obj, 60, 90);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj138 = obj;
            lv_obj_set_pos(obj, 612, 246);
            lv_obj_set_size(obj, 60, 90);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_name_the_parttern();
}

void tick_screen_name_the_parttern() {
    void *flowState = getFlowState(0, 28);
    (void)flowState;
}

void create_screen_bobbin_winding() {
    void *flowState = getFlowState(0, 29);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.bobbin_winding = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj139 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj140 = obj;
            lv_obj_set_pos(obj, 408, 0);
            lv_obj_set_size(obj, 272, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj141 = obj;
            lv_obj_set_pos(obj, -3, 0);
            lv_obj_set_size(obj, 411, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0000ff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen_4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen_4 = obj;
            lv_obj_set_pos(obj, 690, 362);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_bobbin_winding_btn_ready_screen_4, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen_4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen_4 = obj;
            lv_obj_set_pos(obj, 690, 246);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_bobbin_winding_btn_info_screen_4, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // P1_btn_mode_screen_4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.p1_btn_mode_screen_4 = obj;
            lv_obj_set_pos(obj, 690, 15);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_bobbin_winding_p1_btn_mode_screen_4, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen_4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen_4 = obj;
            lv_obj_set_pos(obj, 690, 130);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 80, 71);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_pattern_no_1_1);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 10, 391);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_a_not_background);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 10, 321);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_b_not_background);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 10, 251);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_c_not_background);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 10, 95);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_e_not_background);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 10, 15);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ma_f_not_background);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 422, 21);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_set_style_bg_img_src(obj, &img_stop, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 482, 114);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_cuon_chi);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 424, 386);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_dong_ho_cat);
        }
    }
    
    tick_screen_bobbin_winding();
}

void tick_screen_bobbin_winding() {
    void *flowState = getFlowState(0, 29);
    (void)flowState;
}

void create_screen_maintenance_and_inspection_information() {
    void *flowState = getFlowState(0, 30);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.maintenance_and_inspection_information = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj142 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj143 = obj;
            lv_obj_set_pos(obj, -3, 0);
            lv_obj_set_size(obj, 683, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd7fffb), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen_5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen_5 = obj;
            lv_obj_set_pos(obj, 690, 362);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_maintenance_and_inspection_information_btn_ready_screen_5, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen_5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen_5 = obj;
            lv_obj_set_pos(obj, 690, 246);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_maintenance_and_inspection_information_btn_info_screen_5, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // P1_btn_mode_screen_5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.p1_btn_mode_screen_5 = obj;
            lv_obj_set_pos(obj, 690, 15);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_maintenance_and_inspection_information_p1_btn_mode_screen_5, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen_5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen_5 = obj;
            lv_obj_set_pos(obj, 690, 130);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 441, 312);
            lv_obj_set_size(obj, 120, 150);
            lv_obj_set_style_bg_img_src(obj, &img_oil_replacement_time, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj144 = obj;
            lv_obj_set_pos(obj, 31, 15);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_maintenance_and_inspection_information_obj144, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 605, 15);
            lv_obj_set_size(obj, 70, 90);
            lv_obj_set_style_bg_img_src(obj, &img_threading, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 268, 312);
            lv_obj_set_size(obj, 120, 150);
            lv_obj_set_style_bg_img_src(obj, &img_cleaning_time, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 91, 312);
            lv_obj_set_size(obj, 120, 150);
            lv_obj_set_style_bg_img_src(obj, &img_needle_replacement, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_maintenance_and_inspection_information();
}

void tick_screen_maintenance_and_inspection_information() {
    void *flowState = getFlowState(0, 30);
    (void)flowState;
}

void create_screen_production_control_start() {
    void *flowState = getFlowState(0, 31);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.production_control_start = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj145 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj146 = obj;
            lv_obj_set_pos(obj, 0, 1);
            lv_obj_set_size(obj, 683, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd7fffb), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen_6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen_6 = obj;
            lv_obj_set_pos(obj, 690, 362);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_production_control_start_btn_ready_screen_6, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen_6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen_6 = obj;
            lv_obj_set_pos(obj, 690, 246);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_production_control_start_btn_info_screen_6, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // P1_btn_mode_screen_6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.p1_btn_mode_screen_6 = obj;
            lv_obj_set_pos(obj, 690, 15);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_production_control_start_p1_btn_mode_screen_6, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen_6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen_6 = obj;
            lv_obj_set_pos(obj, 690, 130);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 39, 331);
            lv_obj_set_size(obj, 110, 130);
            lv_obj_set_style_bg_img_src(obj, &img_existing_target_value, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj147 = obj;
            lv_obj_set_pos(obj, 18, 15);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_production_control_start_obj147, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // start
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.start = obj;
            lv_obj_set_pos(obj, 605, 15);
            lv_obj_set_size(obj, 70, 90);
            lv_obj_add_event_cb(obj, event_handler_cb_production_control_start_start, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_start, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // clear
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.clear = obj;
            lv_obj_set_pos(obj, 514, 15);
            lv_obj_set_size(obj, 70, 90);
            lv_obj_set_style_bg_img_src(obj, &img_clear, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 163, 331);
            lv_obj_set_size(obj, 110, 130);
            lv_obj_set_style_bg_img_src(obj, &img_actual_results_value, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj148 = obj;
            lv_obj_set_pos(obj, 290, 331);
            lv_obj_set_size(obj, 110, 130);
            lv_obj_add_event_cb(obj, event_handler_cb_production_control_start_obj148, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_final_target_value, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj149 = obj;
            lv_obj_set_pos(obj, 540, 331);
            lv_obj_set_size(obj, 110, 130);
            lv_obj_add_event_cb(obj, event_handler_cb_production_control_start_obj149, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_number_of_times_of_thread_trimming, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj150 = obj;
            lv_obj_set_pos(obj, 418, 331);
            lv_obj_set_size(obj, 110, 130);
            lv_obj_add_event_cb(obj, event_handler_cb_production_control_start_obj150, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_pitch_time, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_production_control_start();
}

void tick_screen_production_control_start() {
    void *flowState = getFlowState(0, 31);
    (void)flowState;
}

void create_screen_production_control_stop() {
    void *flowState = getFlowState(0, 32);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.production_control_stop = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj151 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj152 = obj;
            lv_obj_set_pos(obj, 0, 1);
            lv_obj_set_size(obj, 683, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd7fffb), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen_8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen_8 = obj;
            lv_obj_set_pos(obj, 690, 362);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_production_control_stop_btn_ready_screen_8, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen_8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen_8 = obj;
            lv_obj_set_pos(obj, 690, 246);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_production_control_stop_btn_info_screen_8, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // P1_btn_mode_screen_8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.p1_btn_mode_screen_8 = obj;
            lv_obj_set_pos(obj, 690, 15);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_production_control_stop_p1_btn_mode_screen_8, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen_8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen_8 = obj;
            lv_obj_set_pos(obj, 690, 130);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 39, 331);
            lv_obj_set_size(obj, 110, 130);
            lv_obj_set_style_bg_img_src(obj, &img_existing_target_value, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj153 = obj;
            lv_obj_set_pos(obj, 18, 15);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_production_control_stop_obj153, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // start_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.start_1 = obj;
            lv_obj_set_pos(obj, 605, 15);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_production_control_stop_start_1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_stop, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 163, 331);
            lv_obj_set_size(obj, 110, 130);
            lv_obj_set_style_bg_img_src(obj, &img_actual_results_value, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 290, 331);
            lv_obj_set_size(obj, 110, 130);
            lv_obj_set_style_bg_img_src(obj, &img_final_target_value, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 540, 331);
            lv_obj_set_size(obj, 110, 130);
            lv_obj_set_style_bg_img_src(obj, &img_pitch_time, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 418, 331);
            lv_obj_set_size(obj, 110, 130);
            lv_obj_set_style_bg_img_src(obj, &img_number_of_times_of_thread_trimming, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_production_control_stop();
}

void tick_screen_production_control_stop() {
    void *flowState = getFlowState(0, 32);
    (void)flowState;
}

void create_screen_working_measurement() {
    void *flowState = getFlowState(0, 33);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.working_measurement = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj154 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj155 = obj;
            lv_obj_set_pos(obj, 0, 1);
            lv_obj_set_size(obj, 683, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd7fffb), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen_9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen_9 = obj;
            lv_obj_set_pos(obj, 690, 362);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_working_measurement_btn_ready_screen_9, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen_9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen_9 = obj;
            lv_obj_set_pos(obj, 690, 246);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_working_measurement_btn_info_screen_9, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // P1_btn_mode_screen_9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.p1_btn_mode_screen_9 = obj;
            lv_obj_set_pos(obj, 690, 15);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_working_measurement_p1_btn_mode_screen_9, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen_9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen_9 = obj;
            lv_obj_set_pos(obj, 690, 130);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 39, 331);
            lv_obj_set_size(obj, 110, 130);
            lv_obj_set_style_bg_img_src(obj, &img_working_ratio, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj156 = obj;
            lv_obj_set_pos(obj, 18, 15);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_working_measurement_obj156, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // start_2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.start_2 = obj;
            lv_obj_set_pos(obj, 605, 15);
            lv_obj_set_size(obj, 70, 90);
            lv_obj_add_event_cb(obj, event_handler_cb_working_measurement_start_2, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_start, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // clear_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.clear_1 = obj;
            lv_obj_set_pos(obj, 514, 15);
            lv_obj_set_size(obj, 70, 90);
            lv_obj_set_style_bg_img_src(obj, &img_clear, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 163, 331);
            lv_obj_set_size(obj, 110, 130);
            lv_obj_set_style_bg_img_src(obj, &img_machine_speed, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 290, 331);
            lv_obj_set_size(obj, 110, 130);
            lv_obj_set_style_bg_img_src(obj, &img_pitch_time, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 540, 331);
            lv_obj_set_size(obj, 110, 130);
            lv_obj_set_style_bg_img_src(obj, &img_number_of_times_of_thread_trimming, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 418, 331);
            lv_obj_set_size(obj, 110, 130);
            lv_obj_set_style_bg_img_src(obj, &img_machine_time, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_working_measurement();
}

void tick_screen_working_measurement() {
    void *flowState = getFlowState(0, 33);
    (void)flowState;
}

void create_screen_input_final_target_value() {
    void *flowState = getFlowState(0, 34);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.input_final_target_value = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj157 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj158 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff599bdc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen_7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen_7 = obj;
            lv_obj_set_pos(obj, 690, 362);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_input_final_target_value_btn_ready_screen_7, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen_7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen_7 = obj;
            lv_obj_set_pos(obj, 690, 246);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_input_final_target_value_btn_info_screen_7, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // P1_btn_mode_screen_7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.p1_btn_mode_screen_7 = obj;
            lv_obj_set_pos(obj, 690, 15);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_input_final_target_value_p1_btn_mode_screen_7, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen_7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen_7 = obj;
            lv_obj_set_pos(obj, 690, 130);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 388, 199);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 388, 301);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 287, 99);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 287, 199);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 287, 301);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 388, 99);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_6, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 488, 301);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_7, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 488, 199);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 488, 99);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_9, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 588, 301);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj159 = obj;
            lv_obj_set_pos(obj, 15, 15);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_input_final_target_value_obj159, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 588, 199);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 588, 99);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 193, 15);
            lv_obj_set_size(obj, 70, 90);
            lv_obj_set_style_bg_img_src(obj, &img_enter, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 15, 331);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_final_target_value);
        }
    }
    
    tick_screen_input_final_target_value();
}

void tick_screen_input_final_target_value() {
    void *flowState = getFlowState(0, 34);
    (void)flowState;
}

void create_screen_input_pitch_time() {
    void *flowState = getFlowState(0, 35);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.input_pitch_time = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj160 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj161 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff599bdc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen_10
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen_10 = obj;
            lv_obj_set_pos(obj, 690, 362);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_input_pitch_time_btn_ready_screen_10, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen_10
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen_10 = obj;
            lv_obj_set_pos(obj, 690, 246);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_input_pitch_time_btn_info_screen_10, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // P1_btn_mode_screen_10
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.p1_btn_mode_screen_10 = obj;
            lv_obj_set_pos(obj, 690, 15);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_input_pitch_time_p1_btn_mode_screen_10, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen_10
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen_10 = obj;
            lv_obj_set_pos(obj, 690, 130);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 388, 199);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 388, 301);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 287, 99);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 287, 199);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 287, 301);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 388, 99);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_6, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 488, 301);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_7, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 488, 199);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 488, 99);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_9, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 588, 301);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj162 = obj;
            lv_obj_set_pos(obj, 15, 15);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_input_pitch_time_obj162, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 588, 199);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 588, 99);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 193, 15);
            lv_obj_set_size(obj, 70, 90);
            lv_obj_set_style_bg_img_src(obj, &img_enter, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 15, 331);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_pitch_time);
        }
    }
    
    tick_screen_input_pitch_time();
}

void tick_screen_input_pitch_time() {
    void *flowState = getFlowState(0, 35);
    (void)flowState;
}

void create_screen_input_number_of_times_of_thread_trimming() {
    void *flowState = getFlowState(0, 36);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.input_number_of_times_of_thread_trimming = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj163 = obj;
            lv_obj_set_pos(obj, 680, 0);
            lv_obj_set_size(obj, 120, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff002966), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj164 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 680, 480);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff599bdc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_ready_screen_11
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_ready_screen_11 = obj;
            lv_obj_set_pos(obj, 690, 362);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_input_number_of_times_of_thread_trimming_btn_ready_screen_11, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_info_screen_11
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_info_screen_11 = obj;
            lv_obj_set_pos(obj, 690, 246);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_input_number_of_times_of_thread_trimming_btn_info_screen_11, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // P1_btn_mode_screen_11
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.p1_btn_mode_screen_11 = obj;
            lv_obj_set_pos(obj, 690, 15);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_input_number_of_times_of_thread_trimming_p1_btn_mode_screen_11, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_communication_screen_11
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_communication_screen_11 = obj;
            lv_obj_set_pos(obj, 690, 130);
            lv_obj_set_size(obj, 100, 99);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_defaul3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 388, 199);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 388, 301);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 287, 99);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 287, 199);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 287, 301);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 388, 99);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_6, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 488, 301);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_7, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 488, 199);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 488, 99);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_9, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 588, 301);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj165 = obj;
            lv_obj_set_pos(obj, 15, 15);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_input_number_of_times_of_thread_trimming_obj165, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_exit, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 588, 199);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 588, 99);
            lv_obj_set_size(obj, 80, 80);
            lv_obj_set_style_bg_img_src(obj, &img_direct_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 193, 15);
            lv_obj_set_size(obj, 70, 90);
            lv_obj_set_style_bg_img_src(obj, &img_enter, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 15, 331);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_number_of_times_of_thread_trimming);
        }
    }
    
    tick_screen_input_number_of_times_of_thread_trimming();
}

void tick_screen_input_number_of_times_of_thread_trimming() {
    void *flowState = getFlowState(0, 36);
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
    tick_screen_presser_type_selection,
    tick_screen_pattern_no_selecttion,
    tick_screen_change_direct,
    tick_screen_register_the_pattern,
    tick_screen_select_the_pattern,
    tick_screen_new_register_the_pattern,
    tick_screen_name_the_parttern,
    tick_screen_bobbin_winding,
    tick_screen_maintenance_and_inspection_information,
    tick_screen_production_control_start,
    tick_screen_production_control_stop,
    tick_screen_working_measurement,
    tick_screen_input_final_target_value,
    tick_screen_input_pitch_time,
    tick_screen_input_number_of_times_of_thread_trimming,
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
    create_screen_presser_type_selection();
    create_screen_pattern_no_selecttion();
    create_screen_change_direct();
    create_screen_register_the_pattern();
    create_screen_select_the_pattern();
    create_screen_new_register_the_pattern();
    create_screen_name_the_parttern();
    create_screen_bobbin_winding();
    create_screen_maintenance_and_inspection_information();
    create_screen_production_control_start();
    create_screen_production_control_stop();
    create_screen_working_measurement();
    create_screen_input_final_target_value();
    create_screen_input_pitch_time();
    create_screen_input_number_of_times_of_thread_trimming();
}