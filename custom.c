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
#include "src/lvgl/lvgl.h"
#include "custom.h"
#include "mhttp.h"
#include "mtime.h"

/*********************
 *      DEFINES
 *********************/
uint32_t MY_EVENT_POWER_ON;

/**********************
 *      TYPEDEFS
 **********************/
#define ANIM_INTERVAL 10 // ms

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
    wifiInit,
  },
  {
    PHASE_POWER_ON_TIME_SYNCING,
    50,
    "time syncing...",
    syncSysTime,
  },
  {
    PHASE_POWER_ON_DONE,
    90,
    "init done!",
    NULL,
  },
};

int PHASE_NUM = sizeof(phases) / sizeof(init_phase_t);

/**
 * Create a demo application
 */

// void trigger_power_on_progress(phase_power_on_e p)
// {
//   printf("trigger to phase: %d\r\n", p);
//   event_params_power_on_t ep;
//   ep.phase = p;
//   ep.msg = c_phase_msg[p];
//   ep.progress_val = c_phase_progress_val[p];
//   lv_event_send(guider_ui.power_on_bar_1, MY_EVENT_POWER_ON, &ep);
// }

static void m_power_on_bar_1_event_handler (lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);
  printf("m_power_on_bar_1_event_handler get event code: %d %d\r\n",code, lv_bar_get_value(guider_ui.power_on_bar_1));

  // if (code == MY_EVENT_POWER_ON) {
  //   int32_t set_val = ((event_params_power_on_t*)lv_event_get_param(e))->progress_val;
  //   char *msg = ((event_params_power_on_t*)lv_event_get_param(e))->msg;
  //   phase_power_on_e phase = ((event_params_power_on_t*)lv_event_get_param(e))->phase;

  //   printf("MY_EVENT_POWER_ON enter, %d, %s, %d\r\n", set_val, msg, phase);
  //   if (phase = PHASE_POWER_ON_FINISHED) {
  //     printf("MY_EVENT_POWER_ON progress_val done\r\n");
  //     // 这里不能多次进入，否则会死机
  //     ui_load_scr_animation(&guider_ui, &guider_ui.home, guider_ui.home_del, &guider_ui.power_on_del, setup_scr_home, LV_SCR_LOAD_ANIM_OVER_RIGHT, 500, 200, true, true);
  //     return;
  //   }
  //   lv_label_set_text(guider_ui.power_on_label_1, msg);

  //   lv_bar_set_value(guider_ui.power_on_bar_1, set_val, LV_ANIM_OFF);
    
    // lv_refr_now(NULL); // 强制刷新
    // if (set_val >= lv_bar_get_max_value(guider_ui.power_on_bar_1)){
    //     printf("MY_EVENT_POWER_ON progress_val done\r\n");
    //     // 这里不能多次进入，否则会死机
    //     ui_load_scr_animation(&guider_ui, &guider_ui.home, guider_ui.home_del, &guider_ui.power_on_del, setup_scr_home, LV_SCR_LOAD_ANIM_OVER_RIGHT, 500, 200, true, true);
    //   }
  // }
  // else if (code == LV_EVENT_PRESSED) {
  //   int32_t val = lv_bar_get_value(guider_ui.power_on_bar_1);
  //   uint32_t anim_st = ((lv_bar_t *)(guider_ui.power_on_bar_1))->cur_value_anim.anim_state;
  //   if (anim_st == -1){
  //     printf("xxxx %d %d\r\n", val ,anim_st);
  //     if (val >= lv_bar_get_max_value(guider_ui.power_on_bar_1)){
  //       printf("MY_EVENT_POWER_ON progress_val done\r\n");
  //       // 这里不能多次进入，否则会死机
  //       ui_load_scr_animation(&guider_ui, &guider_ui.home, guider_ui.home_del, &guider_ui.power_on_del, setup_scr_home, LV_SCR_LOAD_ANIM_OVER_RIGHT, 500, 200, true, true);
  //     }
  //   }
  // }
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
   lv_style_set_anim_time(&style_bg,ANIM_INTERVAL);//设置动画时间

   lv_style_init(&style_indic);           //初始化样式
   lv_style_set_bg_opa(&style_indic,LV_OPA_COVER);//设置样式背景透明度
   lv_style_set_bg_color(&style_indic,lv_palette_main(LV_PALETTE_BLUE));//设置背景颜色
   lv_style_set_radius(&style_indic,3);   //设置圆角

   lv_obj_t * bar = guider_ui.power_on_bar_1;
   lv_obj_remove_style_all(bar);          //移除样式
   lv_obj_add_style(bar,&style_bg,0);     //创添样式
   lv_obj_add_style(bar,&style_indic,LV_PART_INDICATOR);//添加样式

   lv_obj_set_size(bar,250,20);           //设置样式尺寸
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
    // 这里不能多次进入，否则会死机
    ui_load_scr_animation(&guider_ui, &guider_ui.home, guider_ui.home_del, &guider_ui.power_on_del, setup_scr_home, LV_SCR_LOAD_ANIM_OVER_RIGHT, 500, 200, true, true);
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
  lv_timer_set_repeat_count(lv_timer_create(station_init, ANIM_INTERVAL, NULL), x_max);

  printf("custom init done!\r\n");
}

