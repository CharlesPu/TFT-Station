#include <TFT_eSPI.h> 
#include <SPI.h>
#include "mhttp.h"
#include "mtime.h"
#include "weather.h"
#include "xingkai20.h"
#include "bangtamvan-kvjmd80.h"
#include <Ticker.h>

Ticker my_ticker;

#define CENTER 160

TFT_eSPI my_lcd = TFT_eSPI(); 

void draw_background()
{
    my_lcd.fillRect(0, 0, my_lcd.width(), 15, TFT_YELLOW);
    my_lcd.setTextColor(TFT_BLUE);
    my_lcd.drawCentreString("* Universal Color TFT Display Library *",CENTER,3,1);
    my_lcd.fillRect(0, my_lcd.height()-15, my_lcd.width(), 15,0x8410);
    my_lcd.setTextColor(0xFFFF);
    my_lcd.drawCentreString("<http://www.lcdwiki.com>",CENTER,my_lcd.height()-11,1);
    
    my_lcd.drawRect(0, 14, my_lcd.width(), my_lcd.height()-30,TFT_RED); 
}

void draw_time()
{
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time");
    return;
  }
  my_lcd.loadFont(num_bangtamvan_kvjmd80);
  char tmp[40] ={};
  sprintf(tmp, "%02d:%02d:%02d", timeinfo.tm_hour,  timeinfo.tm_min, timeinfo.tm_sec);
  my_lcd.drawCentreString(tmp,CENTER,my_lcd.height()/2, 1);// 1 2 4 6 7 8
  my_lcd.unloadFont();
}

void draw_weather()
{
  weather_info_t w = getForecastWeather("hangzhou");

  my_lcd.loadFont(xingkai28);
  my_lcd.setTextColor(my_lcd.color24to16(0x008c8c));

  // my_lcd.setCursor(70, 200);       //设置光标位置
  // my_lcd.println("晴天雨天暴雨");     //打印文字
  for (int j = 0; j < w_chn_codes_len; j++)
  {
    if(w_chn_codes[j].code == w.weathers[0].code) {
        my_lcd.drawCentreString(w_chn_codes[j].chinese,CENTER,40, 1);
    }
    if(w_chn_codes[j].code == w.weathers[1].code) {
        my_lcd.setCursor(70, 100);       //设置光标位置
        my_lcd.println(w_chn_codes[j].chinese);     //打印文字
    }
    if(w_chn_codes[j].code == w.weathers[2].code) {
        my_lcd.setCursor(70, 160);       //设置光标位置
        my_lcd.println(w_chn_codes[j].chinese);     //打印文字
    }
  }
  my_lcd.unloadFont();             //释放字库,节省RAM
}

void ticker_cb(){

}

void setup() 
{
  Serial.begin(115200);
  my_lcd.init();
  my_lcd.setRotation(3);

  wifiInit();
	syncSysTime();

  my_ticker.attach_ms(3 * 1000, ticker_cb);
	printf("init done!\r\n");
}

void loop() 
{
    my_lcd.fillScreen(TFT_BLACK); 
    draw_background();
    draw_time();    
    draw_weather();
    
    Serial.printf("test done!\r\n");
    delay(5000);
}