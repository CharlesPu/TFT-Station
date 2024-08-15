#include "window.h"
#include "config.h"


void draw_background()
{
  draw_background_header();
  draw_background_booter();

  init_areas();
}

void draw_background_header()
{
  my_lcd.fillRect(0, 0, my_lcd.width(), 15, my_lcd.color24to16(0xf9dc24));
  my_lcd.setTextColor(my_lcd.color24to16(0x002fa7));
  char tmp[40] ={};sprintf(tmp, "Wifi * %s * connecting...", WIFI_AP_NAME);
  my_lcd.drawCentreString(tmp,CENTER,3,1);
}
void draw_background_header_inited()
{
  my_lcd.fillRect(0, 0, my_lcd.width(), 15, my_lcd.color24to16(COLOR_HEADER_INITED));
  my_lcd.setTextColor(my_lcd.color24to16(0x002fa7));  my_lcd.setTextFont(1);
  char tmp[40] ={};sprintf(tmp, "* %s *", WIFI_AP_NAME);
  my_lcd.drawString(tmp,2,3);
}

void draw_background_booter()
{
  my_lcd.fillRect(0, my_lcd.height()-15, my_lcd.width(), 15,0x8410);
  my_lcd.setTextColor(0xFFFF);
  my_lcd.drawCentreString("<https://github.com/CharlesPu>",CENTER,my_lcd.height()-11,1);
}

void init_areas() 
{
  init_area_top();
  init_area_bottom();
}

void init_area_top() 
{
  init_area_top_left();
  init_area_top_right();
}
void init_area_top_left()
{
  my_lcd.fillRect(area_top_left_x, area_top_left_y, area_top_left_w, area_top_left_h,TFT_BLACK);
  my_lcd.drawRoundRect(area_top_left_x, area_top_left_y, area_top_left_w, area_top_left_h,3,my_lcd.color24to16(COLOR_AREA_BORDER)); 
}
void init_area_top_right()
{
  my_lcd.fillRect(area_top_right_x, area_top_right_y, area_top_right_w, area_top_right_h,TFT_BLACK);
  my_lcd.drawRoundRect(area_top_right_x, area_top_right_y, area_top_right_w, area_top_right_h,3,my_lcd.color24to16(COLOR_AREA_BORDER)); 
}

void init_area_bottom() 
{
  my_lcd.fillRect(area_bottom_x, area_bottom_y, area_bottom_w, area_bottom_h,TFT_BLACK);
  my_lcd.drawRoundRect(area_bottom_x, area_bottom_y, area_bottom_w, area_bottom_h,3,my_lcd.color24to16(COLOR_AREA_BORDER)); 
}
