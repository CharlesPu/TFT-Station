#ifndef __MHTTP_H
#define __MHTTP_H

#include <Arduino.h>
#include "traffic.h"
#include "weather.h"


// #include <WiFi.h>
// #include <WiFiMulti.h>



void wifiInit(void);
weather_info_t getTodayWeather(String city);
weather_info_t getForecastWeather(String city);
void httpTest(void);

traffic_t getTraffic(void);




#endif
