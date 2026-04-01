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
    SCREEN_ID_READY = 3,
    SCREEN_ID_INFO = 4,
    SCREEN_ID_SEWING_DATA1 = 5,
    SCREEN_ID_SEWING_DATA2 = 6,
    SCREEN_ID_SEWING_DATA3 = 7,
    SCREEN_ID_SEWING_DATA4 = 8,
    SCREEN_ID_SEWING_DATA5 = 9,
    SCREEN_ID_SEWING_DATA6 = 10,
    SCREEN_ID_MODE1_1 = 11,
    SCREEN_ID_MODE1_2 = 12,
    SCREEN_ID_MODE1_3 = 13,
    SCREEN_ID_MODE1_4 = 14,
    SCREEN_ID_MODE2_1 = 15,
    SCREEN_ID_MODE2_2 = 16,
    SCREEN_ID_MODE2_3 = 17,
    SCREEN_ID_MODE2_4 = 18,
    SCREEN_ID_CHECK_PROGRAM = 19,
    SCREEN_ID_MODE_SEWING_DATA = 20,
    SCREEN_ID_MODE_SEWING_DATA1 = 21,
    SCREEN_ID_MODE_SEWING_DATA2 = 22,
    SCREEN_ID_PRESSER_TYPE_SELECTION = 23,
    SCREEN_ID_PATTERN_NO_SELECTTION = 24,
    SCREEN_ID_CHANGE_DIRECT = 25,
    SCREEN_ID_REGISTER_THE_PATTERN = 26,
    SCREEN_ID_SELECT_THE_PATTERN = 27,
    SCREEN_ID_NEW_REGISTER_THE_PATTERN = 28,
    SCREEN_ID_NAME_THE_PARTTERN = 29,
    SCREEN_ID_BOBBIN_WINDING = 30,
    SCREEN_ID_MAINTENANCE_AND_INSPECTION_INFORMATION = 31,
    SCREEN_ID_PRODUCTION_CONTROL_START = 32,
    SCREEN_ID_PRODUCTION_CONTROL_STOP = 33,
    SCREEN_ID_WORKING_MEASUREMENT = 34,
    SCREEN_ID_INPUT_FINAL_TARGET_VALUE = 35,
    SCREEN_ID_INPUT_PITCH_TIME = 36,
    SCREEN_ID_INPUT_NUMBER_OF_TIMES_OF_THREAD_TRIMMING = 37,
    _SCREEN_ID_LAST = 37
};

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *mode;
    lv_obj_t *ready;
    lv_obj_t *info;
    lv_obj_t *sewing_data1;
    lv_obj_t *sewing_data2;
    lv_obj_t *sewing_data3;
    lv_obj_t *sewing_data4;
    lv_obj_t *sewing_data5;
    lv_obj_t *sewing_data6;
    lv_obj_t *mode1_1;
    lv_obj_t *mode1_2;
    lv_obj_t *mode1_3;
    lv_obj_t *mode1_4;
    lv_obj_t *mode2_1;
    lv_obj_t *mode2_2;
    lv_obj_t *mode2_3;
    lv_obj_t *mode2_4;
    lv_obj_t *check_program;
    lv_obj_t *mode_sewing_data;
    lv_obj_t *mode_sewing_data1;
    lv_obj_t *mode_sewing_data2;
    lv_obj_t *presser_type_selection;
    lv_obj_t *pattern_no_selecttion;
    lv_obj_t *change_direct;
    lv_obj_t *register_the_pattern;
    lv_obj_t *select_the_pattern;
    lv_obj_t *new_register_the_pattern;
    lv_obj_t *name_the_parttern;
    lv_obj_t *bobbin_winding;
    lv_obj_t *maintenance_and_inspection_information;
    lv_obj_t *production_control_start;
    lv_obj_t *production_control_stop;
    lv_obj_t *working_measurement;
    lv_obj_t *input_final_target_value;
    lv_obj_t *input_pitch_time;
    lv_obj_t *input_number_of_times_of_thread_trimming;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *btn_ready_screen;
    lv_obj_t *btn_info_screen;
    lv_obj_t *btn_sewing_data;
    lv_obj_t *p1_btn_mode_screen;
    lv_obj_t *btn_communication_screen;
    lv_obj_t *presser_type;
    lv_obj_t *btn_pattern_no_selecttion;
    lv_obj_t *btn_bobbin_winder;
    lv_obj_t *obj5;
    lv_obj_t *obj6;
    lv_obj_t *obj7;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
    lv_obj_t *btn_mode2;
    lv_obj_t *btn_check_program;
    lv_obj_t *btn_sewing_data_in_mode;
    lv_obj_t *btn_mode1;
    lv_obj_t *btn_ready_screen1;
    lv_obj_t *btn_info_screen1;
    lv_obj_t *btn_communication_screen1;
    lv_obj_t *btn_mode_screen1;
    lv_obj_t *btn_register_the_pattern;
    lv_obj_t *mode1;
    lv_obj_t *mode2;
    lv_obj_t *mode5;
    lv_obj_t *mode8;
    lv_obj_t *mode4;
    lv_obj_t *obj10;
    lv_obj_t *obj11;
    lv_obj_t *obj12;
    lv_obj_t *btn_ready_screen2;
    lv_obj_t *obj13;
    lv_obj_t *obj14;
    lv_obj_t *obj15;
    lv_obj_t *obj16;
    lv_obj_t *obj17;
    lv_obj_t *obj18;
    lv_obj_t *obj19;
    lv_obj_t *btn_production_control;
    lv_obj_t *btn_working_measurement;
    lv_obj_t *btn_maintenance_and_inspection;
    lv_obj_t *btn_ready_screen1_1;
    lv_obj_t *btn_info_screen1_1;
    lv_obj_t *btn_communication_screen1_1;
    lv_obj_t *btn_mode_screen1_1;
    lv_obj_t *i1;
    lv_obj_t *i2;
    lv_obj_t *i3;
    lv_obj_t *obj20;
    lv_obj_t *obj21;
    lv_obj_t *btn_s004;
    lv_obj_t *btn_s002;
    lv_obj_t *btn_s005;
    lv_obj_t *btn_s003;
    lv_obj_t *btn_s006;
    lv_obj_t *btn_s001;
    lv_obj_t *btn_ready_screen3;
    lv_obj_t *btn_info_screen3;
    lv_obj_t *btn_communication_screen3;
    lv_obj_t *btn_mode_screen3;
    lv_obj_t *btn_next;
    lv_obj_t *btn_back;
    lv_obj_t *btn_exit;
    lv_obj_t *s001;
    lv_obj_t *s002;
    lv_obj_t *s003;
    lv_obj_t *s004;
    lv_obj_t *s005;
    lv_obj_t *s006;
    lv_obj_t *obj22;
    lv_obj_t *obj23;
    lv_obj_t *btn_s010;
    lv_obj_t *btn_s008;
    lv_obj_t *btn_s011;
    lv_obj_t *btn_s009;
    lv_obj_t *btn_s021;
    lv_obj_t *btn_s007;
    lv_obj_t *btn_ready_screen4;
    lv_obj_t *btn_info_screen4;
    lv_obj_t *btn_communication_screen4;
    lv_obj_t *btn_mode_screen4;
    lv_obj_t *btn_next1;
    lv_obj_t *btn_back1;
    lv_obj_t *btn_exit1;
    lv_obj_t *s007;
    lv_obj_t *s008;
    lv_obj_t *s009;
    lv_obj_t *s0010;
    lv_obj_t *s0011;
    lv_obj_t *s021;
    lv_obj_t *obj24;
    lv_obj_t *obj25;
    lv_obj_t *btn_ready_screen5;
    lv_obj_t *btn_info_screen5;
    lv_obj_t *btn_communication_screen5;
    lv_obj_t *btn_mode_screen5;
    lv_obj_t *btn_next2;
    lv_obj_t *btn_back2;
    lv_obj_t *btn_exit2;
    lv_obj_t *s022;
    lv_obj_t *s023;
    lv_obj_t *s031;
    lv_obj_t *s034;
    lv_obj_t *s035;
    lv_obj_t *s036;
    lv_obj_t *obj26;
    lv_obj_t *obj27;
    lv_obj_t *btn_s044;
    lv_obj_t *btn_s038;
    lv_obj_t *btn_s051;
    lv_obj_t *btn_s040;
    lv_obj_t *btn_s055;
    lv_obj_t *btn_s037;
    lv_obj_t *btn_ready_screen6;
    lv_obj_t *btn_info_screen6;
    lv_obj_t *btn_communication_screen6;
    lv_obj_t *btn_mode_screen6;
    lv_obj_t *btn_next3;
    lv_obj_t *btn_back3;
    lv_obj_t *btn_exit3;
    lv_obj_t *s037;
    lv_obj_t *s038;
    lv_obj_t *s040;
    lv_obj_t *s044;
    lv_obj_t *s051;
    lv_obj_t *s055;
    lv_obj_t *obj28;
    lv_obj_t *obj29;
    lv_obj_t *btn_s064;
    lv_obj_t *btn_s058;
    lv_obj_t *btn_s067;
    lv_obj_t *btn_s062;
    lv_obj_t *btn_s068;
    lv_obj_t *btn_s057;
    lv_obj_t *btn_ready_screen7;
    lv_obj_t *btn_info_screen7;
    lv_obj_t *btn_communication_screen7;
    lv_obj_t *btn_mode_screen7;
    lv_obj_t *btn_next4;
    lv_obj_t *btn_back4;
    lv_obj_t *btn_exit4;
    lv_obj_t *s057;
    lv_obj_t *s058;
    lv_obj_t *s062;
    lv_obj_t *s064;
    lv_obj_t *s067;
    lv_obj_t *s068;
    lv_obj_t *obj30;
    lv_obj_t *obj31;
    lv_obj_t *btn_s084;
    lv_obj_t *btn_s081;
    lv_obj_t *btn_ready_screen8;
    lv_obj_t *btn_info_screen8;
    lv_obj_t *btn_communication_screen8;
    lv_obj_t *btn_mode_screen8;
    lv_obj_t *btn_next5;
    lv_obj_t *btn_back5;
    lv_obj_t *btn_exit5;
    lv_obj_t *s081;
    lv_obj_t *s084;
    lv_obj_t *obj32;
    lv_obj_t *obj33;
    lv_obj_t *btn_u004;
    lv_obj_t *btn_u002;
    lv_obj_t *btn_u005;
    lv_obj_t *btn_u003;
    lv_obj_t *btn_u006;
    lv_obj_t *btn_u001;
    lv_obj_t *btn_ready_screen9;
    lv_obj_t *btn_info_screen9;
    lv_obj_t *btn_communication_screen9;
    lv_obj_t *btn_mode_screen9;
    lv_obj_t *btn_next6;
    lv_obj_t *btn_back6;
    lv_obj_t *btn_exit6;
    lv_obj_t *u001;
    lv_obj_t *u002;
    lv_obj_t *u003;
    lv_obj_t *u004;
    lv_obj_t *u005;
    lv_obj_t *u006;
    lv_obj_t *obj34;
    lv_obj_t *obj35;
    lv_obj_t *btn_u010;
    lv_obj_t *btn_u008;
    lv_obj_t *btn_u011;
    lv_obj_t *btn_u009;
    lv_obj_t *btn_u012;
    lv_obj_t *btn_u007;
    lv_obj_t *btn_ready_screen10;
    lv_obj_t *btn_info_screen10;
    lv_obj_t *btn_communication_screen10;
    lv_obj_t *btn_mode_screen10;
    lv_obj_t *btn_next7;
    lv_obj_t *btn_back7;
    lv_obj_t *btn_exit7;
    lv_obj_t *u007;
    lv_obj_t *u008;
    lv_obj_t *u009;
    lv_obj_t *u010;
    lv_obj_t *u011;
    lv_obj_t *u012;
    lv_obj_t *obj36;
    lv_obj_t *obj37;
    lv_obj_t *btn_u018;
    lv_obj_t *btn_u014;
    lv_obj_t *btn_u019;
    lv_obj_t *btn_u015;
    lv_obj_t *btn_u020;
    lv_obj_t *btn_u013;
    lv_obj_t *btn_ready_screen11;
    lv_obj_t *btn_info_screen11;
    lv_obj_t *btn_communication_screen11;
    lv_obj_t *btn_mode_screen11;
    lv_obj_t *btn_next8;
    lv_obj_t *btn_back8;
    lv_obj_t *btn_exit8;
    lv_obj_t *u013;
    lv_obj_t *u014;
    lv_obj_t *u015;
    lv_obj_t *u018;
    lv_obj_t *u019;
    lv_obj_t *u020;
    lv_obj_t *obj38;
    lv_obj_t *obj39;
    lv_obj_t *btn_u024;
    lv_obj_t *btn_u022;
    lv_obj_t *btn_u025;
    lv_obj_t *btn_u023;
    lv_obj_t *btn_u500;
    lv_obj_t *btn_u021;
    lv_obj_t *btn_ready_screen12;
    lv_obj_t *btn_info_screen12;
    lv_obj_t *btn_communication_screen12;
    lv_obj_t *btn_mode_screen12;
    lv_obj_t *obj40;
    lv_obj_t *obj41;
    lv_obj_t *u021;
    lv_obj_t *u022;
    lv_obj_t *u023;
    lv_obj_t *u024;
    lv_obj_t *u025;
    lv_obj_t *u500;
    lv_obj_t *obj42;
    lv_obj_t *obj43;
    lv_obj_t *btn_k005;
    lv_obj_t *btn_k003;
    lv_obj_t *btn_k006;
    lv_obj_t *btn_k004;
    lv_obj_t *btn_k007;
    lv_obj_t *btn_k001;
    lv_obj_t *btn_ready_screen13;
    lv_obj_t *btn_info_screen13;
    lv_obj_t *btn_communication_screen13;
    lv_obj_t *btn_mode_screen13;
    lv_obj_t *btn_next9;
    lv_obj_t *btn_back9;
    lv_obj_t *btn_exit9;
    lv_obj_t *k001;
    lv_obj_t *k003;
    lv_obj_t *k004;
    lv_obj_t *k005;
    lv_obj_t *k006;
    lv_obj_t *k007;
    lv_obj_t *obj44;
    lv_obj_t *obj45;
    lv_obj_t *btn_k011;
    lv_obj_t *btn_k009;
    lv_obj_t *btn_k012;
    lv_obj_t *btn_k010;
    lv_obj_t *btn_k013;
    lv_obj_t *btn_k008;
    lv_obj_t *btn_ready_screen14;
    lv_obj_t *btn_info_screen14;
    lv_obj_t *btn_communication_screen14;
    lv_obj_t *btn_mode_screen14;
    lv_obj_t *btn_next10;
    lv_obj_t *btn_back10;
    lv_obj_t *btn_exit10;
    lv_obj_t *k008;
    lv_obj_t *k009;
    lv_obj_t *k010;
    lv_obj_t *k011;
    lv_obj_t *k012;
    lv_obj_t *k013;
    lv_obj_t *obj46;
    lv_obj_t *obj47;
    lv_obj_t *btn_k017;
    lv_obj_t *btn_k015;
    lv_obj_t *btn_k018;
    lv_obj_t *btn_k016;
    lv_obj_t *btn_k019;
    lv_obj_t *btn_k014;
    lv_obj_t *btn_ready_screen15;
    lv_obj_t *btn_info_screen15;
    lv_obj_t *btn_communication_screen15;
    lv_obj_t *btn_mode_screen15;
    lv_obj_t *btn_next11;
    lv_obj_t *btn_back11;
    lv_obj_t *btn_exit11;
    lv_obj_t *k014;
    lv_obj_t *k015;
    lv_obj_t *k016;
    lv_obj_t *k017;
    lv_obj_t *k018;
    lv_obj_t *k019;
    lv_obj_t *obj48;
    lv_obj_t *obj49;
    lv_obj_t *btn_k021;
    lv_obj_t *btn_k022;
    lv_obj_t *btn_k020;
    lv_obj_t *btn_ready_screen16;
    lv_obj_t *btn_info_screen16;
    lv_obj_t *btn_communication_screen16;
    lv_obj_t *btn_mode_screen16;
    lv_obj_t *btn_next12;
    lv_obj_t *btn_back12;
    lv_obj_t *btn_exit12;
    lv_obj_t *k020;
    lv_obj_t *k021;
    lv_obj_t *k022;
    lv_obj_t *obj50;
    lv_obj_t *obj51;
    lv_obj_t *btn_i004;
    lv_obj_t *btn_i002;
    lv_obj_t *btn_i005;
    lv_obj_t *btn_i003;
    lv_obj_t *btn_i001;
    lv_obj_t *btn_ready_screen17;
    lv_obj_t *btn_info_screen17;
    lv_obj_t *btn_communication_screen17;
    lv_obj_t *btn_mode_screen17;
    lv_obj_t *btn_exit13;
    lv_obj_t *i001;
    lv_obj_t *i002;
    lv_obj_t *i003;
    lv_obj_t *i004;
    lv_obj_t *i005;
    lv_obj_t *obj52;
    lv_obj_t *obj53;
    lv_obj_t *btn_s042;
    lv_obj_t *btn_s039;
    lv_obj_t *btn_s052;
    lv_obj_t *btn_s041;
    lv_obj_t *btn_s053;
    lv_obj_t *btn_s020;
    lv_obj_t *btn_ready_screen18;
    lv_obj_t *btn_info_screen18;
    lv_obj_t *btn_communication_screen18;
    lv_obj_t *btn_mode_screen18;
    lv_obj_t *btn_next14;
    lv_obj_t *btn_back14;
    lv_obj_t *btn_exit14;
    lv_obj_t *s020;
    lv_obj_t *s039;
    lv_obj_t *s041;
    lv_obj_t *s042;
    lv_obj_t *s052;
    lv_obj_t *s053;
    lv_obj_t *obj54;
    lv_obj_t *obj55;
    lv_obj_t *btn_s060;
    lv_obj_t *btn_s056;
    lv_obj_t *btn_s061;
    lv_obj_t *btn_s059;
    lv_obj_t *btn_s063;
    lv_obj_t *btn_s054;
    lv_obj_t *btn_ready_screen19;
    lv_obj_t *btn_info_screen19;
    lv_obj_t *btn_communication_screen19;
    lv_obj_t *btn_mode_screen19;
    lv_obj_t *btn_next15;
    lv_obj_t *btn_back15;
    lv_obj_t *btn_exit15;
    lv_obj_t *s054;
    lv_obj_t *s056;
    lv_obj_t *s059;
    lv_obj_t *s060;
    lv_obj_t *s061;
    lv_obj_t *s063;
    lv_obj_t *obj56;
    lv_obj_t *obj57;
    lv_obj_t *btn_s070;
    lv_obj_t *btn_s066;
    lv_obj_t *btn_s083;
    lv_obj_t *btn_s069;
    lv_obj_t *btn_s065;
    lv_obj_t *btn_ready_screen20;
    lv_obj_t *btn_info_screen20;
    lv_obj_t *btn_communication_screen20;
    lv_obj_t *btn_mode_screen20;
    lv_obj_t *btn_next16;
    lv_obj_t *btn_back16;
    lv_obj_t *btn_exit16;
    lv_obj_t *s065;
    lv_obj_t *s066;
    lv_obj_t *s069;
    lv_obj_t *s070;
    lv_obj_t *s083;
    lv_obj_t *obj58;
    lv_obj_t *obj59;
    lv_obj_t *btn_ready_screen20_1;
    lv_obj_t *btn_info_screen20_1;
    lv_obj_t *btn_communication_screen20_1;
    lv_obj_t *btn_mode_screen20_1;
    lv_obj_t *btn_exit16_1;
    lv_obj_t *presser_type_1;
    lv_obj_t *presser_type_2;
    lv_obj_t *presser_type_5;
    lv_obj_t *presser_type_3;
    lv_obj_t *obj60;
    lv_obj_t *obj61;
    lv_obj_t *obj62;
    lv_obj_t *btn_ready_screen20_3;
    lv_obj_t *btn_info_screen20_3;
    lv_obj_t *btn_communication_screen20_3;
    lv_obj_t *btn_mode_screen20_3;
    lv_obj_t *btn_exit16_3;
    lv_obj_t *obj63;
    lv_obj_t *obj64;
    lv_obj_t *obj65;
    lv_obj_t *obj66;
    lv_obj_t *obj67;
    lv_obj_t *obj68;
    lv_obj_t *obj69;
    lv_obj_t *pattern_no;
    lv_obj_t *obj70;
    lv_obj_t *obj71;
    lv_obj_t *obj72;
    lv_obj_t *btn_ready_screen_1;
    lv_obj_t *btn_info_screen_1;
    lv_obj_t *p1_btn_mode_screen_1;
    lv_obj_t *btn_communication_screen_1;
    lv_obj_t *obj73;
    lv_obj_t *obj74;
    lv_obj_t *btn_ready_screen20_4;
    lv_obj_t *btn_info_screen20_4;
    lv_obj_t *btn_communication_screen20_4;
    lv_obj_t *btn_mode_screen20_4;
    lv_obj_t *btn_exit16_4;
    lv_obj_t *obj75;
    lv_obj_t *obj76;
    lv_obj_t *obj77;
    lv_obj_t *obj78;
    lv_obj_t *obj79;
    lv_obj_t *obj80;
    lv_obj_t *obj81;
    lv_obj_t *obj82;
    lv_obj_t *obj83;
    lv_obj_t *obj84;
    lv_obj_t *obj85;
    lv_obj_t *obj86;
    lv_obj_t *btn_ready_screen20_5;
    lv_obj_t *btn_info_screen20_5;
    lv_obj_t *btn_communication_screen20_5;
    lv_obj_t *btn_mode_screen20_5;
    lv_obj_t *btn_exit16_5;
    lv_obj_t *obj87;
    lv_obj_t *obj88;
    lv_obj_t *obj89;
    lv_obj_t *obj90;
    lv_obj_t *btn_ready_screen_2;
    lv_obj_t *btn_info_screen_2;
    lv_obj_t *p1_btn_mode_screen_2;
    lv_obj_t *btn_communication_screen_2;
    lv_obj_t *obj91;
    lv_obj_t *obj92;
    lv_obj_t *obj93;
    lv_obj_t *btn_ready_screen_3;
    lv_obj_t *btn_info_screen_3;
    lv_obj_t *p1_btn_mode_screen_3;
    lv_obj_t *btn_communication_screen_3;
    lv_obj_t *obj94;
    lv_obj_t *obj95;
    lv_obj_t *obj96;
    lv_obj_t *obj97;
    lv_obj_t *obj98;
    lv_obj_t *obj99;
    lv_obj_t *obj100;
    lv_obj_t *obj101;
    lv_obj_t *obj102;
    lv_obj_t *obj103;
    lv_obj_t *obj104;
    lv_obj_t *obj105;
    lv_obj_t *obj106;
    lv_obj_t *obj107;
    lv_obj_t *obj108;
    lv_obj_t *obj109;
    lv_obj_t *obj110;
    lv_obj_t *obj111;
    lv_obj_t *obj112;
    lv_obj_t *obj113;
    lv_obj_t *obj114;
    lv_obj_t *obj115;
    lv_obj_t *obj116;
    lv_obj_t *obj117;
    lv_obj_t *obj118;
    lv_obj_t *obj119;
    lv_obj_t *obj120;
    lv_obj_t *obj121;
    lv_obj_t *obj122;
    lv_obj_t *obj123;
    lv_obj_t *obj124;
    lv_obj_t *obj125;
    lv_obj_t *obj126;
    lv_obj_t *obj127;
    lv_obj_t *obj128;
    lv_obj_t *obj129;
    lv_obj_t *obj130;
    lv_obj_t *obj131;
    lv_obj_t *obj132;
    lv_obj_t *obj133;
    lv_obj_t *obj134;
    lv_obj_t *obj135;
    lv_obj_t *obj136;
    lv_obj_t *obj137;
    lv_obj_t *obj138;
    lv_obj_t *obj139;
    lv_obj_t *obj140;
    lv_obj_t *obj141;
    lv_obj_t *btn_ready_screen_4;
    lv_obj_t *btn_info_screen_4;
    lv_obj_t *p1_btn_mode_screen_4;
    lv_obj_t *btn_communication_screen_4;
    lv_obj_t *obj142;
    lv_obj_t *obj143;
    lv_obj_t *btn_ready_screen_5;
    lv_obj_t *btn_info_screen_5;
    lv_obj_t *p1_btn_mode_screen_5;
    lv_obj_t *btn_communication_screen_5;
    lv_obj_t *obj144;
    lv_obj_t *obj145;
    lv_obj_t *obj146;
    lv_obj_t *btn_ready_screen_6;
    lv_obj_t *btn_info_screen_6;
    lv_obj_t *p1_btn_mode_screen_6;
    lv_obj_t *btn_communication_screen_6;
    lv_obj_t *obj147;
    lv_obj_t *start;
    lv_obj_t *clear;
    lv_obj_t *obj148;
    lv_obj_t *obj149;
    lv_obj_t *obj150;
    lv_obj_t *obj151;
    lv_obj_t *obj152;
    lv_obj_t *btn_ready_screen_8;
    lv_obj_t *btn_info_screen_8;
    lv_obj_t *p1_btn_mode_screen_8;
    lv_obj_t *btn_communication_screen_8;
    lv_obj_t *obj153;
    lv_obj_t *start_1;
    lv_obj_t *obj154;
    lv_obj_t *obj155;
    lv_obj_t *btn_ready_screen_9;
    lv_obj_t *btn_info_screen_9;
    lv_obj_t *p1_btn_mode_screen_9;
    lv_obj_t *btn_communication_screen_9;
    lv_obj_t *obj156;
    lv_obj_t *start_2;
    lv_obj_t *clear_1;
    lv_obj_t *obj157;
    lv_obj_t *obj158;
    lv_obj_t *btn_ready_screen_7;
    lv_obj_t *btn_info_screen_7;
    lv_obj_t *p1_btn_mode_screen_7;
    lv_obj_t *btn_communication_screen_7;
    lv_obj_t *obj159;
    lv_obj_t *obj160;
    lv_obj_t *obj161;
    lv_obj_t *btn_ready_screen_10;
    lv_obj_t *btn_info_screen_10;
    lv_obj_t *p1_btn_mode_screen_10;
    lv_obj_t *btn_communication_screen_10;
    lv_obj_t *obj162;
    lv_obj_t *obj163;
    lv_obj_t *obj164;
    lv_obj_t *btn_ready_screen_11;
    lv_obj_t *btn_info_screen_11;
    lv_obj_t *p1_btn_mode_screen_11;
    lv_obj_t *btn_communication_screen_11;
    lv_obj_t *obj165;
} objects_t;

extern objects_t objects;

void create_screen_main();
void tick_screen_main();

void create_screen_mode();
void tick_screen_mode();

void create_screen_ready();
void tick_screen_ready();

void create_screen_info();
void tick_screen_info();

void create_screen_sewing_data1();
void tick_screen_sewing_data1();

void create_screen_sewing_data2();
void tick_screen_sewing_data2();

void create_screen_sewing_data3();
void tick_screen_sewing_data3();

void create_screen_sewing_data4();
void tick_screen_sewing_data4();

void create_screen_sewing_data5();
void tick_screen_sewing_data5();

void create_screen_sewing_data6();
void tick_screen_sewing_data6();

void create_screen_mode1_1();
void tick_screen_mode1_1();

void create_screen_mode1_2();
void tick_screen_mode1_2();

void create_screen_mode1_3();
void tick_screen_mode1_3();

void create_screen_mode1_4();
void tick_screen_mode1_4();

void create_screen_mode2_1();
void tick_screen_mode2_1();

void create_screen_mode2_2();
void tick_screen_mode2_2();

void create_screen_mode2_3();
void tick_screen_mode2_3();

void create_screen_mode2_4();
void tick_screen_mode2_4();

void create_screen_check_program();
void tick_screen_check_program();

void create_screen_mode_sewing_data();
void tick_screen_mode_sewing_data();

void create_screen_mode_sewing_data1();
void tick_screen_mode_sewing_data1();

void create_screen_mode_sewing_data2();
void tick_screen_mode_sewing_data2();

void create_screen_presser_type_selection();
void tick_screen_presser_type_selection();

void create_screen_pattern_no_selecttion();
void tick_screen_pattern_no_selecttion();

void create_screen_change_direct();
void tick_screen_change_direct();

void create_screen_register_the_pattern();
void tick_screen_register_the_pattern();

void create_screen_select_the_pattern();
void tick_screen_select_the_pattern();

void create_screen_new_register_the_pattern();
void tick_screen_new_register_the_pattern();

void create_screen_name_the_parttern();
void tick_screen_name_the_parttern();

void create_screen_bobbin_winding();
void tick_screen_bobbin_winding();

void create_screen_maintenance_and_inspection_information();
void tick_screen_maintenance_and_inspection_information();

void create_screen_production_control_start();
void tick_screen_production_control_start();

void create_screen_production_control_stop();
void tick_screen_production_control_stop();

void create_screen_working_measurement();
void tick_screen_working_measurement();

void create_screen_input_final_target_value();
void tick_screen_input_final_target_value();

void create_screen_input_pitch_time();
void tick_screen_input_pitch_time();

void create_screen_input_number_of_times_of_thread_trimming();
void tick_screen_input_number_of_times_of_thread_trimming();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/