#include "mhttp.h"
#include "config.h"
#include <ArduinoJson.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;

// #include <ArduinoHttpClient.h>
// #include <HTTPClient.h>
#include <string.h>

// WiFiClient mwifiMulti;

// 采用此定义是为了消除 The plain HTTP request was sent to HTTPS port 的报错
std::unique_ptr<BearSSL::WiFiClientSecure> client(new BearSSL::WiFiClientSecure);

void wifiInit(void){
	
	WiFi.mode(WIFI_STA);
	WiFiMulti.addAP(WIFI_AP_NAME, WIFI_AP_PWD); 
	
	// wait for WiFi connection
	Serial.print("Waiting for WiFi to connect...");
	while ((WiFiMulti.run() != WL_CONNECTED)) {
	  Serial.print(".");
		delay(300);
	}
	Serial.println(" connected");
	client->setInsecure();
}

weather_info_t getTodayWeather(String city){
	String url_xinzhi = WEATHER_URL_TODAY;
	url_xinzhi = url_xinzhi + "?key=" + WEATHER_URL_KEY;
	url_xinzhi = url_xinzhi + "&location=" + city;
	url_xinzhi = url_xinzhi + "&language=" + WEATHER_URL_LANGUAGE_CN;
	url_xinzhi = url_xinzhi + "&unit=c";

	JsonDocument doc; //分配内存,动态

	HTTPClient http;
	weather_info_t r;

	http.begin(*client, url_xinzhi);
	int httpGet = http.GET();
	if (httpGet > 0)
	{
		if (httpGet == HTTP_CODE_OK)
		{
			String json = http.getString();
			// Serial.println(json);  //打印接受到的消息

			deserializeJson(doc, json);
			serializeJsonPretty(doc, Serial);

			JsonObject root = doc.as<JsonObject>();
			JsonArray results = root["results"];

      strcpy(r.weathers[0].date,      results[0]["now"][0]["last_update"].as<const char*>());
      strcpy(r.weathers[0].text,      results[0]["now"][0]["text"].as<const char*>());
      r.weathers[0].code = results[0]["now"][0]["code"];

      strcpy(r.weathers[0].temp,      results[0]["now"][0]["temperature"].as<const char*>());
		}else 
		{
			String json = http.getString();
			printf("request fail: %d %s\r\n",httpGet,json);
		}
	}
	http.end();

	return r;
}

weather_info_t getForecastWeather(String city){
	String url_xinzhi = WEATHER_URL_FORECAST;
	url_xinzhi = url_xinzhi + "?key=" + WEATHER_URL_KEY;
	url_xinzhi = url_xinzhi + "&location=" + city;
	url_xinzhi = url_xinzhi + "&language=" + WEATHER_URL_LANGUAGE_EN;
	url_xinzhi = url_xinzhi + "&unit=c&start=0&days=3"; // 非vip最多三天

	JsonDocument doc; 

	HTTPClient http;
	weather_info_t r;

	http.begin(*client, url_xinzhi);

	int httpGet = http.GET();
	if (httpGet > 0)
	{
		if (httpGet == HTTP_CODE_OK)
		{
			String json = http.getString();
			// Serial.println(json);  //打印接受到的消息

			deserializeJson(doc, json);
			serializeJsonPretty(doc, Serial);

			JsonObject root = doc.as<JsonObject>();
			JsonArray results = root["results"];

			for (int i = 0; i < 3; ++i)
			{
        r.weathers[i].code = results[0]["daily"][i]["code_day"];
        r.weathers[i].precip = results[0]["daily"][i]["precip"].as<float>();
        r.weathers[i].wind_scale = results[0]["daily"][i]["wind_scale"].as<int>();

        strcpy(r.weathers[i].date,      results[0]["daily"][i]["date"].as<const char*>());
        strcpy(r.weathers[i].text,      results[0]["daily"][i]["text_day"].as<const char*>());
        strcpy(r.weathers[i].temp,      results[0]["daily"][i]["high"].as<const char*>());
        strcpy(r.weathers[i].temp_low,  results[0]["daily"][i]["low"].as<const char*>());
        strcpy(r.weathers[i].temp_high, results[0]["daily"][i]["high"].as<const char*>());
        strcpy(r.weathers[i].humidity,  results[0]["daily"][i]["humidity"].as<const char*>());
        strcpy(r.weathers[i].city,  results[0]["location"]["name"].as<const char*>());

        // printf("raw deserial data %s, %s %s -------\r\n", r.weathers[i].temp_high, r.weathers[i].temp_low, r.weathers[i].humidity);
				// r.weathers[i].temp = results[0]["daily"][i]["high"];
        // r.weathers[i].temp_low = results[0]["daily"][i]["low"];
        // r.weathers[i].temp_high = results[0]["daily"][i]["high"];
        // r.weathers[i].humidity = results[0]["daily"][i]["humidity"];
			}
		}else 
		{
			String json = http.getString();
			printf("request fail: %d, %s\r\n",httpGet,json);
		}
	}else
  {
    Serial.printf("[HTTP] GET %s... failed, error: %s\n",url_xinzhi.c_str(), http.errorToString(httpGet).c_str());
  }
	http.end();

	return r;
}

traffic_t getTraffic(){
	String url = TRAFFIC_URL_DRIVING;
	url = url + "?origin=" + TRAFFIC_URL_ORIGIN;
	url = url + "&destination=" + TRAFFIC_URL_DESTINATION;
	url = url + "&key=" + TRAFFIC_URL_KEY;
	url = url + "&output=json&show_fields=cost"; 

	DynamicJsonDocument  doc(20000); 

	HTTPClient http;
	traffic_t r;

	http.begin(*client, url);

	int httpGet = http.GET();
	if (httpGet > 0)
	{
		if (httpGet == HTTP_CODE_OK)
		{
			String json = http.getString();
			Serial.println(json.c_str());  //打印接受到的消息

			// deserializeJson(doc, json);
			// serializeJsonPretty(doc, Serial);

			// JsonObject root = doc.as<JsonObject>();
			// JsonArray results = root["results"];
      
		}else 
		{
			String json = http.getString();
			printf("request fail: %d, %s\r\n",httpGet,json);
		}
	}else
  {
    Serial.printf("[HTTP] GET %s... failed, error: %s\n",url.c_str(), http.errorToString(httpGet).c_str());
  }
	http.end();

	return r;
}

void httpTest(void) {
  HTTPClient http;

  Serial.print("[HTTP] begin...\n");
   // configure traged server and url
	http.begin(*client, "https://restapi.amap.com/v5/direction/driving?origin=120.140430,30.346661&destination=120.264363,30.184050&key=7096bd9f91152cf97240707401009b86&output=json&show_fields=cost");


   Serial.print("[HTTP] GET...\n");
   // start connection and send HTTP header
   int httpCode = http.GET();

   // httpCode will be negative on error
   if(httpCode > 0) {
       // HTTP header has been send and Server response header has been handled
       Serial.printf("[HTTP] GET... code: %d\n", httpCode);

       // file found at server
       if(httpCode == HTTP_CODE_OK) {
          //  String payload = http.getString();
          //  Serial.println(payload);
          Serial.println(http.getSize());
          char buff[20480] = {0};
 
          int len = http.getSize(); // 读取响应正文数据字节数，如果返回-1是因为响应头中没有Content-Length属性
    
          WiFiClient *stream = http.getStreamPtr(); // 获取响应正文数据流指针
    
          while (http.connected() && (len > 0 || len == -1)) // 当前已连接并且有数据可读
          {
            size_t size = stream->available(); // 获取数据流中可用字节数
            if (size)
            {
              int c = stream->readBytes(buff, ((size > sizeof(buff)) ? sizeof(buff) : size)); // 读取数据到buff
              Serial.write(buff, c);
              if (len > 0)
              {
                len -= c;
              }
            }
            delay(1);
          }

          Serial.println(buff);
       }
   } else {
       Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
   }

   http.end();
}

