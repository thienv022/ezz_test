#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_ma_a;
extern const lv_img_dsc_t img_ma_b;
extern const lv_img_dsc_t img_ma_c;
extern const lv_img_dsc_t img_ma_e;
extern const lv_img_dsc_t img_ma_f;
extern const lv_img_dsc_t img_ma_g;
extern const lv_img_dsc_t img_ma_h;
extern const lv_img_dsc_t img_ma_i;
extern const lv_img_dsc_t img_ma_j;
extern const lv_img_dsc_t img_ma_k;
extern const lv_img_dsc_t img_ma_l;
extern const lv_img_dsc_t img_ma_m;
extern const lv_img_dsc_t img_ma_n;
extern const lv_img_dsc_t img_ma_o;
extern const lv_img_dsc_t img_ma_p;
extern const lv_img_dsc_t img_ma_q;
extern const lv_img_dsc_t img_ma_r;
extern const lv_img_dsc_t img_ma_s1;
extern const lv_img_dsc_t img_ma_s2;
extern const lv_img_dsc_t img_ma_s3;
extern const lv_img_dsc_t img_ma_s4;
extern const lv_img_dsc_t img_defaul1;
extern const lv_img_dsc_t img_defaul2;
extern const lv_img_dsc_t img_defaul3;
extern const lv_img_dsc_t img_defaul4;
extern const lv_img_dsc_t img_ma_not;
extern const lv_img_dsc_t img_mode1;
extern const lv_img_dsc_t img_mode2;
extern const lv_img_dsc_t img_sewing_data;
extern const lv_img_dsc_t img_check_program;
extern const lv_img_dsc_t img_register_sewing_data_custom;
extern const lv_img_dsc_t img_register_the_pattern;
extern const lv_img_dsc_t img_change_sewing_mode;
extern const lv_img_dsc_t img_performing_format;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[34];

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/