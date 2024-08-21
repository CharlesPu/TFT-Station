/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <stdbool.h>
#include "lvgl.h"
#include "custom.h"
// #include "guider_customer_fonts.h"

/*********************
 *      DEFINES
 *********************/
uint32_t MY_EVENT_POWER_ON;

/**********************
 *      TYPEDEFS
 **********************/
#define INTERVAL_POWERON_BAR_ANIM 10 // ms
#define INTERVAL_WEATHER 3000 // ms

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static init_phase_t phases[4] = {
  {
    PHASE_POWER_ON_STARTING,
    1,
    "station awake!",
    NULL,
  },
  {
    PHASE_POWER_ON_WIFI_CONNECTING,
    20,
    "wifi connecting...",
    NULL,
  },
  {
    PHASE_POWER_ON_TIME_SYNCING,
    50,
    "time syncing...",
    NULL,
  },
  {
    PHASE_POWER_ON_DONE,
    90,
    "init done!",
    NULL,
  },
};

int PHASE_NUM = sizeof(phases) / sizeof(init_phase_t);
void weather_loop() 
{
  // weather_info_t w = getForecastWeather("hangzhou");

  // 城市
  lv_label_set_text(guider_ui.home_label_posi,"haha");

  const char *chns[3] = {};
  // for (int j = 0; j < w_chn_codes_len; j++)
  // {
  //   for (int i = 0; i < 3; i++)
  //   {
  //     if(w_chn_codes[j].code == w.weathers[i].code) {
  //       chns[i] = w_chn_codes[j].chinese;
  //     }
  //   }
  // }
  // chns[0] = "晴天";
  // printf("aaaa %s\r\n",chns[0]);
  // lv_obj_set_style_text_font(guider_ui.home_label_today_weather, &lv_customer_font_fangzhengxiaobiaosong_14, LV_PART_MAIN|LV_STATE_DEFAULT);
  lv_label_set_text(guider_ui.home_label_today_weather, "晴天");
}
void bar_show_adjust()
{
   static lv_style_t style_bg;            //创建bar背景样式
   static lv_style_t style_indic;         //创建bar指示器样式

   lv_style_init(&style_bg);              //初始化样式
   lv_style_set_border_color(&style_bg,lv_palette_main(LV_PALETTE_BLUE));//设置边款颜色
   lv_style_set_border_width(&style_bg,2);//设置边框宽度
   lv_style_set_pad_all(&style_bg,6);     //设置内边距
   lv_style_set_radius(&style_bg,6);      //设置圆角
   lv_style_set_anim_time(&style_bg,INTERVAL_POWERON_BAR_ANIM);//设置动画时间

   lv_style_init(&style_indic);           //初始化样式
   lv_style_set_bg_opa(&style_indic,LV_OPA_COVER);//设置样式背景透明度
   lv_style_set_bg_color(&style_indic,lv_palette_main(LV_PALETTE_BLUE));//设置背景颜色
   lv_style_set_radius(&style_indic,3);   //设置圆角

   lv_obj_t * bar = guider_ui.power_on_bar_1;
   lv_obj_remove_style_all(bar);          //移除样式
   lv_obj_add_style(bar,&style_bg,0);     //创添样式
   lv_obj_add_style(bar,&style_indic,LV_PART_INDICATOR);//添加样式

   lv_obj_set_size(bar,260,20);           //设置样式尺寸
   lv_obj_center(bar);                    //居中显示
   lv_bar_set_value(bar,0,LV_ANIM_OFF);  //设置初始值
}

int32_t x = 0;
int32_t x_max;
void station_init(lv_timer_t * tm)
{
  x++;

  if (x >= x_max) {
    printf("MY_EVENT_POWER_ON progress_val done\r\n");
  lv_timer_set_repeat_count(lv_timer_create(weather_loop, INTERVAL_WEATHER, NULL), -1);
    // 这里不能多次进入，否则会死机
    ui_load_scr_animation(&guider_ui, &guider_ui.home, guider_ui.home_del, &guider_ui.power_on_del, setup_scr_home, LV_SCR_LOAD_ANIM_OUT_RIGHT, 200, 200, true, true);
    return;
  }
  for (int i = 0; i < PHASE_NUM; i++)
  {
    phase_power_on_e p = i;
    int proc_val = phases[i].progress_val;

    if (x == proc_val) {
      printf("%d catch progress_val %d\r\n",p, x);
      void (*f)(void)=NULL;
      if (i > 0) { f = phases[i-1].exec;}
      if (f!=NULL) {f();}
      const char *msg = phases[i].msg;
      lv_label_set_text(guider_ui.power_on_label_1, msg);
    }
  }
  printf("set progress_val %d\r\n", x);
  lv_bar_set_value(guider_ui.power_on_bar_1, x, LV_ANIM_OFF);
  lv_textprogress_set_value(guider_ui.power_on_textprogress_1, x);
}


void custom_init(lv_ui *ui)
{
    /* Add your codes here */
  MY_EVENT_POWER_ON = lv_event_register_id();  

  // lv_obj_add_event_cb(ui->power_on_bar_1, m_power_on_bar_1_event_handler, LV_EVENT_ALL, ui);

  bar_show_adjust();
  x_max = lv_bar_get_max_value(guider_ui.power_on_bar_1);

  // start trigger!
    lv_timer_set_repeat_count(lv_timer_create(station_init, INTERVAL_POWERON_BAR_ANIM, NULL), x_max);

  printf("custom init done!\r\n");
}

