#ifndef __CONFIG_H
#define __CONFIG_H

#include <Arduino.h>
#include <TFT_eSPI.h> 

#include "config.private.h"

#define MY_ESP_8266

// note 要加括号！
#define INTERNAL_LOOP (1 * 1000) // MS 
#define INTERNAL_WEATHER (10 * 1000)
#define INTERNAL_TIMESYNC (1* 60 * 1000)
#define INTERNAL_DATE (10 * 1000)


// #define URL_WEATHER "https://e.weather.com.cn/mweather/101210101.shtml"
#define WEATHER_URL_TODAY 		"https://api.seniverse.com/v3/weather/now.json"
#define WEATHER_URL_FORECAST 	"https://api.seniverse.com/v3/weather/daily.json"
#define WEATHER_URL_LANGUAGE_EN "en"
#define WEATHER_URL_LANGUAGE_CN "zh-Hans"

#define TRAFFIC_URL_DRIVING 		"https://restapi.amap.com/v5/direction/driving"


// NTP配置参数, 使用阿里云的NTP服务器
static const char *ntpServerUrl1 = "ntp1.aliyun.com";
static const char *ntpServerUrl2 = "ntp2.aliyun.com";
static const char *ntpServerUrl3 = "ntp3.aliyun.com";

////////////////////////// colors ///////////////////////////////
#define COLOR_HEADER_INITED 0x4D982E

#define COLOR_AREA_BORDER 0xe9a621

#define COLOR_WEATHER 0x008c8c
#define COLOR_HUMIDITY 0xe85827
#define COLOR_TEMP COLOR_HUMIDITY

#define COLOR_DATE 0xFF5F2E
#define COLOR_TIME 0xd0241c
#define COLOR_WEEK 0x1E50A1
/////////////////////////////////////////////////////////
#define CENTER 160

extern TFT_eSPI my_lcd; 
extern TFT_eSprite my_sprite_time;


#endif
