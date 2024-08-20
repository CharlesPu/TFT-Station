/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "../lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"



int home_digital_clock_1_min_value = 9;
int home_digital_clock_1_hour_value = 9;
int home_digital_clock_1_sec_value = 58;
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
	lv_obj_set_size(ui->home_tabview_1, 320, 220);
	lv_obj_set_scrollbar_mode(ui->home_tabview_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for home_tabview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->home_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->home_tabview_1, lv_color_hex(0xeaeff3), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->home_tabview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->home_tabview_1, lv_color_hex(0x4d4d4d), LV_PART_MAIN|LV_STATE_DEFAULT);
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
	lv_style_set_bg_color(&style_home_tabview_1_extra_btnm_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_home_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_border_width(&style_home_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_radius(&style_home_tabview_1_extra_btnm_main_default, 3);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->home_tabview_1), &style_home_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_home_tabview_1_extra_btnm_items_default
	static lv_style_t style_home_tabview_1_extra_btnm_items_default;
	ui_init_style(&style_home_tabview_1_extra_btnm_items_default);
	
	lv_style_set_text_color(&style_home_tabview_1_extra_btnm_items_default, lv_color_hex(0x4d4d4d));
	lv_style_set_text_font(&style_home_tabview_1_extra_btnm_items_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_home_tabview_1_extra_btnm_items_default, 255);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->home_tabview_1), &style_home_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_home_tabview_1_extra_btnm_items_checked
	static lv_style_t style_home_tabview_1_extra_btnm_items_checked;
	ui_init_style(&style_home_tabview_1_extra_btnm_items_checked);
	
	lv_style_set_text_color(&style_home_tabview_1_extra_btnm_items_checked, lv_color_hex(0x2195f6));
	lv_style_set_text_font(&style_home_tabview_1_extra_btnm_items_checked, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_home_tabview_1_extra_btnm_items_checked, 255);
	lv_style_set_border_width(&style_home_tabview_1_extra_btnm_items_checked, 4);
	lv_style_set_border_opa(&style_home_tabview_1_extra_btnm_items_checked, 255);
	lv_style_set_border_color(&style_home_tabview_1_extra_btnm_items_checked, lv_color_hex(0x2195f6));
	lv_style_set_border_side(&style_home_tabview_1_extra_btnm_items_checked, LV_BORDER_SIDE_BOTTOM);
	lv_style_set_radius(&style_home_tabview_1_extra_btnm_items_checked, 3);
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
	ui->home_digital_clock_1 = lv_dclock_create(ui->home_tabview_1_tab_1, "9:09:58");
	if (!home_digital_clock_1_timer_enabled) {
		lv_timer_create(home_digital_clock_1_timer, 1000, NULL);
		home_digital_clock_1_timer_enabled = true;
	}
	lv_obj_set_pos(ui->home_digital_clock_1, 14, 34);
	lv_obj_set_size(ui->home_digital_clock_1, 274, 78);

	//Write style for home_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->home_digital_clock_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->home_digital_clock_1, lv_color_hex(0xf54d40), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->home_digital_clock_1, &lv_font_bangtamvan_kvjmd_72, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->home_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->home_digital_clock_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->home_digital_clock_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->home_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->home_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->home_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->home_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->home_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->home_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

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

	//Write codes traffic
	ui->home_tabview_1_tab_3 = lv_tabview_add_tab(ui->home_tabview_1,"traffic");
	lv_obj_t * home_tabview_1_tab_3_label = lv_label_create(ui->home_tabview_1_tab_3);
	lv_label_set_text(home_tabview_1_tab_3_label, "con3");

	//Write codes home_cont_1
	ui->home_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->home_cont_1, 0, 220);
	lv_obj_set_size(ui->home_cont_1, 320, 20);
	lv_obj_set_scrollbar_mode(ui->home_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for home_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->home_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->home_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->home_cont_1, 163, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->home_cont_1, lv_color_hex(0x4D982E), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->home_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->home_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->home_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->home_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->home_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->home_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_1
	ui->home_label_1 = lv_label_create(ui->home);
	lv_label_set_text(ui->home_label_1, "Tues");
	lv_label_set_long_mode(ui->home_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->home_label_1, 91, 220);
	lv_obj_set_size(ui->home_label_1, 40, 20);

	//Write style for home_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->home_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->home_label_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->home_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->home_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->home_label_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_datetext_1
	ui->home_datetext_1 = lv_label_create(ui->home);
	lv_label_set_text(ui->home_datetext_1, "2023/07/31");
	lv_obj_set_style_text_align(ui->home_datetext_1, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_add_flag(ui->home_datetext_1, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_event_cb(ui->home_datetext_1, home_datetext_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ui->home_datetext_1, 0, 220);
	lv_obj_set_size(ui->home_datetext_1, 81, 20);

	//Write style for home_datetext_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->home_datetext_1, lv_color_hex(0xf2be38), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->home_datetext_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->home_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->home_datetext_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->home_datetext_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->home_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->home_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->home_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->home_datetext_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->home_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->home_datetext_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->home_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_2
	ui->home_label_2 = lv_label_create(ui->home);
	lv_label_set_text(ui->home_label_2, "Hangzhou");
	lv_label_set_long_mode(ui->home_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->home_label_2, 230, 220);
	lv_obj_set_size(ui->home_label_2, 90, 20);

	//Write style for home_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->home_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->home_label_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->home_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->home_label_2, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->home_label_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->home_label_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of home.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->home);

}
