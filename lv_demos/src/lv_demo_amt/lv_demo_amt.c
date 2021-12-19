/**
 * @file lv_demo_stress.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "../lv_demo.h"
void lvgl_title_view_test(void)
{
    static lv_point_t valid_pos[] = { {0,0}, {0, 1}, {1,1} };
    lv_obj_t* tileview;
    tileview = lv_tileview_create(lv_scr_act());
    lv_tileview_add_tile(tileview, 0, 0, 0);
}
lv_obj_t* btn1,* btn2;
lv_obj_t* current_app_obj_user=NULL;
#define LV_DESKTOP  lv_disp_get_scr_act(NULL)
 
/**********************
*      MACROS
**********************/
static uint32_t menu = 0;
static uint32_t data[5] = {1,2,3,4,5};
static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* parent_menu;
    static lv_style_t style_menu;
    if(code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Clicked");
        uint32_t *value = e->user_data;
        if (*value != 5)
        {
            menu +=1;
            LV_LOG_USER("nemausa");
             if (current_app_obj_user == NULL) {
                current_app_obj_user = lv_obj_create(LV_DESKTOP);
                lv_obj_set_size(current_app_obj_user, 1024, 600);
                parent_menu = current_app_obj_user;
 
                lv_obj_t* lable = lv_label_create(parent_menu);
                char title[80];
                lv_snprintf(title, 80, "this is menu=%d", menu);
                lv_label_set_text(lable, title);
                lv_obj_align_to(lable, NULL, LV_ALIGN_CENTER, 0, -10);
                for (int i=0; i<5; i++)
                {
                    lv_obj_t *btn = lv_btn_create(parent_menu);
                    // static uint32_t data1 = 6+i;
                    uint32_t *data1 = lv_mem_alloc(sizeof(uint32_t));

                    lv_obj_t* label_btn = lv_label_create(btn);
                    char str[80];
                    lv_snprintf(str,80, "Button=%d", i+1);
                    lv_label_set_text(label_btn, str);
                    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_ALL, data[i]);
                    lv_obj_align_to(btn, lable, LV_ALIGN_OUT_BOTTOM_MID, 0, 20+30*i);
                }
            }
        }
        else
        {
            LV_LOG_USER("10");
            menu -= 1;
            lv_obj_del(current_app_obj_user);
            current_app_obj_user = NULL;
        }

    }
    else if(code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("Toggled");
    }
}

enum {

};

void lv_demo_amt()
{
    // lv_obj_t * label;

    // lv_obj_t * btn1 = lv_btn_create(lv_scr_act());
    // lv_obj_add_event_cb(btn1, event_handler, LV_EVENT_ALL, NULL);
    // lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -40);

    // label = lv_label_create(btn1);
    // lv_label_set_text(label, "Button");
    // lv_obj_center(label);


    lv_obj_t* desktop = lv_obj_create(lv_scr_act());
    lv_obj_set_size(desktop, 1024, 600);
    lv_obj_t* lable = lv_label_create(desktop);
    lv_label_set_text(lable, "hello world!");
    lv_obj_align_to(lable, NULL, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t * btn1 = lv_btn_create(desktop);
    static uint32_t data1 = 1;
    lv_obj_add_event_cb(btn1, event_handler, LV_EVENT_ALL, &data1);
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, 40);

    lv_obj_t * label;
    label = lv_label_create(btn1);
    lv_label_set_text(label, "Button");
    lv_obj_center(label);
    lv_event_send(btn1, LV_EVENT_CLICKED, NULL);
    // lvgl_title_view_test();
    // LV_IMG_DECLARE(img_amt_bg);
    // lv_obj_t * img1 = lv_img_create(lv_scr_act());
    // lv_img_set_src(img1, &img_amt_bg);
    // lv_obj_align(img1, LV_ALIGN_CENTER, 0, -20);
    // lv_obj_set_size(img1, 1024, 600);
}