#ifndef __WEATHER_H
#define __WEATHER_H


#include <Arduino.h>


typedef struct{
	int code;
  // 下面都不用指针，防止之前内存释放，自己copy一份
	char date[30];
	char text[20];
	char temp[10];
  char temp_low[10];
  char temp_high[10];
  char humidity[10];

  float precip;
  char city[10];
  int wind_scale;
}weather_t;

typedef struct{
	weather_t weathers[3];
}weather_info_t;

#define CODE_MAP_MAX 10

typedef struct{
	int code[CODE_MAP_MAX];
	unsigned char code_pic_48[288];
	unsigned char code_pic_128[2048];
}weather_code_t;

typedef struct{
	int code;
	const char *chinese;
}weather_code_chinese_t;


extern weather_code_t w_codes[];
extern weather_code_chinese_t w_chn_codes[];
extern int w_codes_len; 
extern int w_chn_codes_len;






#endif


