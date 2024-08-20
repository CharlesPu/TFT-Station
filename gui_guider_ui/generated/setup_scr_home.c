/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



int home_digital_clock_1_min_value = 59;
int home_digital_clock_1_hour_value = 23;
int home_digital_clock_1_sec_value = 47;
lv_calendar_date_t home_calendar_1_today;
lv_calendar_date_t home_calendar_1_highlihted_days[1];
void setup_scr_home(lv_ui *ui)
{
	//Write codes home
	ui->home = lv_obj_create(NULL);
	lv_obj_set_size(ui->home, 320, 240);
	lv_obj_set_scrollbar_mode(ui->home, LV_SCROLLBAR_MODE_OFF);

	//Write style for home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_tabview_1
	ui->home_tabview_1 = lv_tabview_create(ui->home, LV_DIR_TOP, 30);
	lv_obj_set_pos(ui->home_tabview_1, 0, 0);
	lv_obj_set_size(ui->home_tabview_1, 320, 240);
	lv_obj_set_scrollbar_mode(ui->home_tabview_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for home_tabview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->home_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->home_tabview_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->home_tabview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->home_tabview_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->home_tabview_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->home_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->home_tabview_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->home_tabview_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->home_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->home_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->home_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_home_tabview_1_extra_btnm_main_default
	static lv_style_t style_home_tabview_1_extra_btnm_main_default;
	ui_init_style(&style_home_tabview_1_extra_btnm_main_default);
	
	lv_style_set_bg_opa(&style_home_tabview_1_extra_btnm_main_default, 255);
	lv_style_set_bg_color(&style_home_tabview_1_extra_btnm_main_default, lv_color_hex(0x241f1f));
	lv_style_set_bg_grad_dir(&style_home_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_border_width(&style_home_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_radius(&style_home_tabview_1_extra_btnm_main_default, 3);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->home_tabview_1), &style_home_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_home_tabview_1_extra_btnm_items_default
	static lv_style_t style_home_tabview_1_extra_btnm_items_default;
	ui_init_style(&style_home_tabview_1_extra_btnm_items_default);
	
	lv_style_set_text_color(&style_home_tabview_1_extra_btnm_items_default, lv_color_hex(0x949494));
	lv_style_set_text_font(&style_home_tabview_1_extra_btnm_items_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_home_tabview_1_extra_btnm_items_default, 255);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->home_tabview_1), &style_home_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_home_tabview_1_extra_btnm_items_checked
	static lv_style_t style_home_tabview_1_extra_btnm_items_checked;
	ui_init_style(&style_home_tabview_1_extra_btnm_items_checked);
	
	lv_style_set_text_color(&style_home_tabview_1_extra_btnm_items_checked, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_home_tabview_1_extra_btnm_items_checked, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_home_tabview_1_extra_btnm_items_checked, 255);
	lv_style_set_border_width(&style_home_tabview_1_extra_btnm_items_checked, 3);
	lv_style_set_border_opa(&style_home_tabview_1_extra_btnm_items_checked, 255);
	lv_style_set_border_color(&style_home_tabview_1_extra_btnm_items_checked, lv_color_hex(0x626262));
	lv_style_set_border_side(&style_home_tabview_1_extra_btnm_items_checked, LV_BORDER_SIDE_BOTTOM);
	lv_style_set_radius(&style_home_tabview_1_extra_btnm_items_checked, 0);
	lv_style_set_bg_opa(&style_home_tabview_1_extra_btnm_items_checked, 60);
	lv_style_set_bg_color(&style_home_tabview_1_extra_btnm_items_checked, lv_color_hex(0x2195f6));
	lv_style_set_bg_grad_dir(&style_home_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->home_tabview_1), &style_home_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

	//Write codes index
	ui->home_tabview_1_tab_1 = lv_tabview_add_tab(ui->home_tabview_1,"index");
	lv_obj_t * home_tabview_1_tab_1_label = lv_label_create(ui->home_tabview_1_tab_1);
	lv_label_set_text(home_tabview_1_tab_1_label, "");

	//Write codes home_digital_clock_1
	static bool home_digital_clock_1_timer_enabled = false;
	ui->home_digital_clock_1 = lv_dclock_create(ui->home_tabview_1_tab_1, "23:59:47");
	if (!home_digital_clock_1_timer_enabled) {
		lv_timer_create(home_digital_clock_1_timer, 1000, NULL);
		home_digital_clock_1_timer_enabled = true;
	}
	lv_obj_set_pos(ui->home_digital_clock_1, -12, 23);
	lv_obj_set_size(ui->home_digital_clock_1, 308, 78);

	//Write style for home_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->home_digital_clock_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->home_digital_clock_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->home_digital_clock_1, &lv_font_bangtamvan_kvjmd_72, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->home_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->home_digital_clock_1, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->home_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->home_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->home_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->home_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->home_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->home_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->home_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_cont_today
	ui->home_cont_today = lv_obj_create(ui->home_tabview_1_tab_1);
	lv_obj_set_pos(ui->home_cont_today, -14, 104);
	lv_obj_set_size(ui->home_cont_today, 232, 14);
	lv_obj_set_scrollbar_mode(ui->home_cont_today, LV_SCROLLBAR_MODE_OFF);

	//Write style for home_cont_today, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->home_cont_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->home_cont_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->home_cont_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->home_cont_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->home_cont_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->home_cont_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->home_cont_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->home_cont_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_today_weather
	ui->home_label_today_weather = lv_label_create(ui->home_cont_today);
	lv_label_set_text(ui->home_label_today_weather, "雷阵雨");
	lv_label_set_long_mode(ui->home_label_today_weather, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->home_label_today_weather, 0, 0);
	lv_obj_set_size(ui->home_label_today_weather, 63, 14);

	//Write style for home_label_today_weather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->home_label_today_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->home_label_today_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->home_label_today_weather, lv_color_hex(0xd0241c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->home_label_today_weather, &lv_font_fangzhengxiaobiaosong_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->home_label_today_weather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->home_label_today_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->home_label_today_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->home_label_today_weather, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->home_label_today_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->home_label_today_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->home_label_today_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->home_label_today_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->home_label_today_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->home_label_today_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_today_temp
	ui->home_label_today_temp = lv_label_create(ui->home_cont_today);
	lv_label_set_text(ui->home_label_today_temp, "12℃-24℃");
	lv_label_set_long_mode(ui->home_label_today_temp, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->home_label_today_temp, 56, 0);
	lv_obj_set_size(ui->home_label_today_temp, 82, 14);

	//Write style for home_label_today_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->home_label_today_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->home_label_today_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->home_label_today_temp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->home_label_today_temp, &lv_font_fangzhengxiaobiaosong_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->home_label_today_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->home_label_today_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->home_label_today_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->home_label_today_temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->home_label_today_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->home_label_today_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->home_label_today_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->home_label_today_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->home_label_today_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->home_label_today_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_today_humidity
	ui->home_label_today_humidity = lv_label_create(ui->home_cont_today);
	lv_label_set_text(ui->home_label_today_humidity, "40%");
	lv_label_set_long_mode(ui->home_label_today_humidity, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->home_label_today_humidity, 131, 0);
	lv_obj_set_size(ui->home_label_today_humidity, 42, 14);

	//Write style for home_label_today_humidity, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->home_label_today_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->home_label_today_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->home_label_today_humidity, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->home_label_today_humidity, &lv_font_fangzhengxiaobiaosong_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->home_label_today_humidity, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->home_label_today_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->home_label_today_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->home_label_today_humidity, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->home_label_today_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->home_label_today_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->home_label_today_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->home_label_today_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->home_label_today_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->home_label_today_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_today_wind
	ui->home_label_today_wind = lv_label_create(ui->home_cont_today);
	lv_label_set_text(ui->home_label_today_wind, "风力4");
	lv_label_set_long_mode(ui->home_label_today_wind, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->home_label_today_wind, 166, 0);
	lv_obj_set_size(ui->home_label_today_wind, 51, 14);

	//Write style for home_label_today_wind, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->home_label_today_wind, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->home_label_today_wind, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->home_label_today_wind, lv_color_hex(0xf2be38), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->home_label_today_wind, &lv_font_fangzhengxiaobiaosong_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->home_label_today_wind, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->home_label_today_wind, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->home_label_today_wind, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->home_label_today_wind, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->home_label_today_wind, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->home_label_today_wind, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->home_label_today_wind, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->home_label_today_wind, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->home_label_today_wind, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->home_label_today_wind, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes calendar
	ui->home_tabview_1_tab_2 = lv_tabview_add_tab(ui->home_tabview_1,"calendar");
	lv_obj_t * home_tabview_1_tab_2_label = lv_label_create(ui->home_tabview_1_tab_2);
	lv_label_set_text(home_tabview_1_tab_2_label, "");

	//Write codes home_calendar_1
	ui->home_calendar_1 = lv_calendar_create(ui->home_tabview_1_tab_2);
	home_calendar_1_today.year = 2024;
	home_calendar_1_today.month = 8;
	home_calendar_1_today.day = 20;
	lv_calendar_set_today_date(ui->home_calendar_1, home_calendar_1_today.year, home_calendar_1_today.month, home_calendar_1_today.day);
	lv_calendar_set_showed_date(ui->home_calendar_1, home_calendar_1_today.year, home_calendar_1_today.month);
	home_calendar_1_highlihted_days[0].year = 2024;
	home_calendar_1_highlihted_days[0].month = 8;
	home_calendar_1_highlihted_days[0].day = 21;
	lv_calendar_set_highlighted_dates(ui->home_calendar_1, home_calendar_1_highlihted_days, 1);
	lv_obj_t *home_calendar_1_header = lv_calendar_header_arrow_create(ui->home_calendar_1);
	lv_calendar_t *home_calendar_1 = (lv_calendar_t *)ui->home_calendar_1;
	lv_obj_add_event_cb(home_calendar_1->btnm, home_calendar_1_draw_part_begin_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);
	lv_obj_add_event_cb(ui->home_calendar_1, home_calendar_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->home_calendar_1, -20, -19);
	lv_obj_set_size(ui->home_calendar_1, 320, 190);

	//Write style state: LV_STATE_DEFAULT for &style_home_calendar_1_main_main_default
	static lv_style_t style_home_calendar_1_main_main_default;
	ui_init_style(&style_home_calendar_1_main_main_default);
	
	lv_style_set_border_width(&style_home_calendar_1_main_main_default, 1);
	lv_style_set_border_opa(&style_home_calendar_1_main_main_default, 255);
	lv_style_set_border_color(&style_home_calendar_1_main_main_default, lv_color_hex(0xc0c0c0));
	lv_style_set_border_side(&style_home_calendar_1_main_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_bg_opa(&style_home_calendar_1_main_main_default, 255);
	lv_style_set_bg_color(&style_home_calendar_1_main_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_home_calendar_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_shadow_width(&style_home_calendar_1_main_main_default, 0);
	lv_style_set_radius(&style_home_calendar_1_main_main_default, 0);
	lv_obj_add_style(ui->home_calendar_1, &style_home_calendar_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_home_calendar_1_extra_header_main_default
	static lv_style_t style_home_calendar_1_extra_header_main_default;
	ui_init_style(&style_home_calendar_1_extra_header_main_default);
	
	lv_style_set_text_color(&style_home_calendar_1_extra_header_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_home_calendar_1_extra_header_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_home_calendar_1_extra_header_main_default, 255);
	lv_style_set_bg_opa(&style_home_calendar_1_extra_header_main_default, 255);
	lv_style_set_bg_color(&style_home_calendar_1_extra_header_main_default, lv_color_hex(0x2195f6));
	lv_style_set_bg_grad_dir(&style_home_calendar_1_extra_header_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(home_calendar_1_header, &style_home_calendar_1_extra_header_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_home_calendar_1_main_items_default
	static lv_style_t style_home_calendar_1_main_items_default;
	ui_init_style(&style_home_calendar_1_main_items_default);
	
	lv_style_set_bg_opa(&style_home_calendar_1_main_items_default, 0);
	lv_style_set_border_width(&style_home_calendar_1_main_items_default, 1);
	lv_style_set_border_opa(&style_home_calendar_1_main_items_default, 255);
	lv_style_set_border_color(&style_home_calendar_1_main_items_default, lv_color_hex(0xc0c0c0));
	lv_style_set_border_side(&style_home_calendar_1_main_items_default, LV_BORDER_SIDE_FULL);
	lv_style_set_text_color(&style_home_calendar_1_main_items_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_home_calendar_1_main_items_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_home_calendar_1_main_items_default, 255);
	lv_obj_add_style(lv_calendar_get_btnmatrix(ui->home_calendar_1), &style_home_calendar_1_main_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write codes more
	ui->home_tabview_1_tab_3 = lv_tabview_add_tab(ui->home_tabview_1,"more");
	lv_obj_t * home_tabview_1_tab_3_label = lv_label_create(ui->home_tabview_1_tab_3);
	lv_label_set_text(home_tabview_1_tab_3_label, "con3");

	//Write codes home_cont_bkg
	ui->home_cont_bkg = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->home_cont_bkg, 0, 220);
	lv_obj_set_size(ui->home_cont_bkg, 320, 20);
	lv_obj_set_scrollbar_mode(ui->home_cont_bkg, LV_SCROLLBAR_MODE_OFF);

	//Write style for home_cont_bkg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->home_cont_bkg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->home_cont_bkg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->home_cont_bkg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->home_cont_bkg, lv_color_hex(0x4D982E), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->home_cont_bkg, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->home_cont_bkg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->home_cont_bkg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->home_cont_bkg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->home_cont_bkg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->home_cont_bkg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_week
	ui->home_label_week = lv_label_create(ui->home);
	lv_label_set_text(ui->home_label_week, "Tues");
	lv_label_set_long_mode(ui->home_label_week, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->home_label_week, 91, 220);
	lv_obj_set_size(ui->home_label_week, 40, 20);

	//Write style for home_label_week, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->home_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->home_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->home_label_week, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->home_label_week, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->home_label_week, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->home_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->home_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->home_label_week, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->home_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->home_label_week, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->home_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->home_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->home_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->home_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_datetext_date
	ui->home_datetext_date = lv_label_create(ui->home);
	lv_label_set_text(ui->home_datetext_date, "2024/08/20");
	lv_obj_set_style_text_align(ui->home_datetext_date, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_add_flag(ui->home_datetext_date, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_event_cb(ui->home_datetext_date, home_datetext_date_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->home_datetext_date, 0, 220);
	lv_obj_set_size(ui->home_datetext_date, 85, 20);

	//Write style for home_datetext_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->home_datetext_date, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->home_datetext_date, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->home_datetext_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->home_datetext_date, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->home_datetext_date, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->home_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->home_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->home_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->home_datetext_date, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->home_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->home_datetext_date, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->home_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_posi
	ui->home_label_posi = lv_label_create(ui->home);
	lv_label_set_text(ui->home_label_posi, "Hangz");
	lv_label_set_long_mode(ui->home_label_posi, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->home_label_posi, 230, 220);
	lv_obj_set_size(ui->home_label_posi, 90, 20);

	//Write style for home_label_posi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->home_label_posi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->home_label_posi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->home_label_posi, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->home_label_posi, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->home_label_posi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->home_label_posi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->home_label_posi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->home_label_posi, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->home_label_posi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->home_label_posi, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->home_label_posi, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->home_label_posi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->home_label_posi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->home_label_posi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of home.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->home);

}
