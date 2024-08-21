/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *power_on;
	bool power_on_del;
	lv_obj_t *power_on_bar_1;
	lv_obj_t *power_on_label_1;
	lv_obj_t *power_on_textprogress_1;
	lv_obj_t *home;
	bool home_del;
	lv_obj_t *home_tabview_1;
	lv_obj_t *home_tabview_1_tab_1;
	lv_obj_t *home_tabview_1_tab_2;
	lv_obj_t *home_tabview_1_tab_3;
	lv_obj_t *home_cont_today;
	lv_obj_t *home_label_today_weather;
	lv_obj_t *home_label_today_temp;
	lv_obj_t *home_label_today_humidity;
	lv_obj_t *home_label_today_wind;
	lv_obj_t *home_cont_1;
	lv_obj_t *home_label_4;
	lv_obj_t *home_label_3;
	lv_obj_t *home_label_2;
	lv_obj_t *home_label_1;
	lv_obj_t *home_cont_2;
	lv_obj_t *home_label_8;
	lv_obj_t *home_label_7;
	lv_obj_t *home_label_6;
	lv_obj_t *home_label_5;
	lv_obj_t *home_digital_clock_1;
	lv_obj_t *home_label_tips;
	lv_obj_t *home_label_traffic;
	lv_obj_t *home_calendar_1;
	lv_obj_t *home_cont_bkg;
	lv_obj_t *home_label_week;
	lv_obj_t *home_datetext_date;
	lv_obj_t *home_label_posi;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_power_on(lv_ui *ui);
void setup_scr_home(lv_ui *ui);

LV_IMG_DECLARE(_haimianbaobao_320x240);

LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_fangzhengxiaobiaosong_12)
LV_FONT_DECLARE(lv_font_bangtamvan_kvjmd_72)
LV_FONT_DECLARE(lv_font_fangzhengxiaobiaosong_14)


#ifdef __cplusplus
}
#endif
#endif
