/**
 * @file lv_demo_stress.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "../lv_demo.h"

void lv_demo_amt()
{
    LV_IMG_DECLARE(img_amt_bg);
    lv_obj_t * img1 = lv_img_create(lv_scr_act());
    lv_img_set_src(img1, &img_amt_bg);
    lv_obj_align(img1, LV_ALIGN_CENTER, 0, -20);
    lv_obj_set_size(img1, 1024, 600);
}