#include "config.h"
#include <TFT_eSPI.h> 
#include <SPI.h>
#include "mhttp.h"
#include "mtime.h"
#include "weather.h"
#include "fangzhengxiaobiaosongjianti28.h"
#include "bangtamvan-kvjmd80.h"
#include <Ticker.h>
#include "window.h"
#include "simsun23.h"

Ticker my_ticker;

int cnt = 0;
bool flag_last;

void setup() 
{
  Serial.begin(115200);

  my_lcd.init();
  my_lcd.setRotation(3);

  // my_ticker.attach_ms(3 * 1000, ticker_cb);

// 在 ESP8266 上，可以创建的最大 16 位彩色 Sprite 大约为 160x128 像素，这会消耗 40 KB 的 RAM
// 在 ESP32 上，16 位色深的 Sprite 限制为约 200x200 像素(~ 80KB），8 位色深的 sprite 限制为 320x240 像素（~76KB）
// 16 位色深 Sprite 所需的 RAM 为（2 x 宽 x 高）字节，8 位色深 Sprite 所需的 RAM 为（宽 x 高）字节。
  my_sprite_time.setColorDepth(8); // note: 设置小于8会panic
  my_sprite_time.setSwapBytes(true);// todo
  my_sprite_time.createSprite(188, 62);

  my_lcd.fillScreen(TFT_BLACK); 
  draw_background_header();
  draw_background_booter();

  wifiInit();
  draw_background_header_inited();
	syncSysTime();

	printf("init done!\r\n");
}

void loop() 
{
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time");
    return;
  }

  draw_time(&timeinfo); 

  if (cnt % (INTERNAL_DATE/INTERNAL_LOOP) == 0 ){
    printf("draw date...\r\n");
    init_area_top_left();
    draw_date(&timeinfo);    
  }

  if (cnt % (INTERNAL_WEATHER/INTERNAL_LOOP) == 0 ){
    printf("draw weather...\r\n");
    init_area_top_right();
    init_area_bottom();
    draw_weather();
  }

  if (cnt % (INTERNAL_TIMESYNC/INTERNAL_LOOP) == 0 ){
    printf("sync time...\r\n");
    syncSysTime();
  }
  
  Serial.printf("test done!\r\n");
  cnt++;
  delay(INTERNAL_LOOP);

  // getTraffic();
}

void draw_time(struct tm *timeinfo)
{
  my_sprite_time.fillSprite(TFT_BLACK); // note 不能用fillscreen，因为和setColorDepth相关
 
  my_sprite_time.loadFont(num_bangtamvan_kvjmd80);
  my_sprite_time.setTextColor(my_lcd.color24to16(COLOR_TIME));

  char tmp_hour[10] ={};char tmp_min[10] ={};
  sprintf(tmp_hour, "%02d", timeinfo->tm_hour);sprintf(tmp_min, "%02d", timeinfo->tm_min);
  my_sprite_time.drawString(tmp_hour,0,0);
  my_sprite_time.drawString(tmp_min,95,0);
  if (flag_last){
    my_sprite_time.drawString(":",75,0);
  }else {
    my_sprite_time.drawString(" ",75,0);
  }
  flag_last = !flag_last;

  my_sprite_time.unloadFont();
  my_sprite_time.pushSprite(75,80);
}

const char *wday_map[7] = {"星期日","星期一","星期二","星期三","星期四","星期五","星期六"};
void draw_date(struct tm *timeinfo)
{
  // printf("%d %d %d %d\r\n",timeinfo->tm_year+1900, timeinfo->tm_mon+1, timeinfo->tm_mday, timeinfo->tm_wday);
  char tmp_date[10] ={};char tmp_week[10] ={};
  sprintf(tmp_date, "%d.%02d.%02d", timeinfo->tm_year+1900, timeinfo->tm_mon+1, timeinfo->tm_mday);
  sprintf(tmp_week, "%s", wday_map[timeinfo->tm_wday]);

  // my_lcd.setTextFont(4);// 1 2 4 6 7 8
  my_lcd.setTextColor(my_lcd.color24to16(COLOR_DATE));
  my_lcd.drawCentreString(tmp_date, area_top_left_w/2+2, area_top_left_y+4,4);

  my_lcd.loadFont(chn_fangzhengxiaobiaosongjianti28);
  my_lcd.setTextColor(my_lcd.color24to16(COLOR_WEEK));
  my_lcd.drawCentreString(tmp_week, area_top_left_w/2, area_top_left_y+33,4);
  my_lcd.unloadFont();  
}

void draw_weather()
{
  weather_info_t w = getForecastWeather("hangzhou");

  // 城市
  my_lcd.setTextColor(my_lcd.color24to16(0xd03542));
  my_lcd.drawRightString(w.weathers[0].city, my_lcd.width(), 3, 1);

  // my_lcd.setCursor(70, 200);       //设置光标位置
  // my_lcd.println("晴天雨天暴雨");     //打印文字
  const char *chns[3] = {};
  for (int j = 0; j < w_chn_codes_len; j++)
  {
    for (int i = 0; i < 3; i++)
    {
      if(w_chn_codes[j].code == w.weathers[i].code) {
        chns[i] = w_chn_codes[j].chinese;
      }
    }
  }
  my_lcd.loadFont(chn_fangzhengxiaobiaosongjianti28);
  my_lcd.setTextColor(my_lcd.color24to16(COLOR_WEATHER));
  // 今明后三天天气
  my_lcd.drawCentreString(chns[0], area_top_right_x+50, area_top_right_y+7,1);
  my_lcd.drawCentreString(chns[1], area_bottom_x+50,    area_bottom_y+12,1);
  my_lcd.drawCentreString(chns[2], area_bottom_x+50,    area_bottom_y+50,1);
  my_lcd.unloadFont();             //释放字库,节省RAM

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // 今天
  // 风速
  my_lcd.setCursor(area_top_right_x+14, area_top_right_y+37);my_lcd.setTextFont(2);my_lcd.setTextColor(TFT_GREEN);
  if (w.weathers[0].wind_scale >5 && w.weathers[0].wind_scale <=8 )my_lcd.setTextColor(TFT_BLUE);else if(w.weathers[0].wind_scale >8)my_lcd.setTextColor(TFT_RED);
  my_lcd.println(w.weathers[0].wind_scale);
  // 降水概率
  my_lcd.setCursor(area_top_right_x+40, area_top_right_y+37);my_lcd.setTextFont(2);my_lcd.setTextColor(TFT_GREEN);
  if (w.weathers[0].wind_scale >0.4 && w.weathers[0].wind_scale <= 0.8 )my_lcd.setTextColor(TFT_BLUE);else if(w.weathers[0].wind_scale >0.8)my_lcd.setTextColor(TFT_RED);
  my_lcd.println(w.weathers[0].precip);

 ///////////////////////////////////// 温湿度
  my_lcd.loadFont(simsun23);
  // my_lcd.setTextFont(4);// 1 2 4 6 7 8
  my_lcd.setTextColor(my_lcd.color24to16(COLOR_HUMIDITY));
  char tmp[40] ={};

  // printf("prepare to use data: [%s %s %s][%s %s %s][%s %s %s]\r\n",w.weathers[0].humidity,w.weathers[0].temp_low, w.weathers[0].temp_high,
  // w.weathers[1].humidity,w.weathers[1].temp_low, w.weathers[1].temp_high,
  // w.weathers[2].humidity,w.weathers[2].temp_low, w.weathers[2].temp_high);
  //今天温湿度
  memset(tmp,0,sizeof(tmp));sprintf(tmp, "%s%%", w.weathers[0].humidity);
  my_lcd.drawCentreString(tmp, area_top_right_x+135, area_top_right_y+10,4);
  memset(tmp,0,sizeof(tmp));sprintf(tmp, "%s℃-%s℃", w.weathers[0].temp_low, w.weathers[0].temp_high);
  my_lcd.drawCentreString(tmp, area_top_right_x+130, area_top_right_y+37,4);
  //明后天温湿度
  memset(tmp,0,sizeof(tmp));sprintf(tmp, "%s%% | %s℃-%s℃", w.weathers[1].humidity, w.weathers[1].temp_low, w.weathers[1].temp_high);
  my_lcd.drawString(tmp, area_bottom_x+120, area_bottom_y+12);
  
  memset(tmp,0,sizeof(tmp));sprintf(tmp, "%s%% | %s℃-%s℃", w.weathers[2].humidity, w.weathers[2].temp_low, w.weathers[2].temp_high);
  my_lcd.drawString(tmp, area_bottom_x+120, area_bottom_y+48);
  my_lcd.unloadFont();             //释放字库,节省RAM
}

void ticker_cb(){}
