#ifndef __MHTTP_H
#define __MHTTP_H

#include <Arduino.h>
#include "traffic.h"
#include "weather.h"


#ifdef __cplusplus
extern "C" {
#endif


void wifiInit(void);
weather_info_t getTodayWeather(const char* city);
weather_info_t getForecastWeather(const char*  city);
void httpTest(void);

traffic_t getTraffic(void);

const char* getOnePoetry();

#ifdef __cplusplus
}
#endif


#endif
