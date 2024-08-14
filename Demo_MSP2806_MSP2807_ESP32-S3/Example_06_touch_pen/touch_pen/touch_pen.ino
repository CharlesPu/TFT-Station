// IMPORTANT: LCDWIKI_SPI LIBRARY AND LCDWIKI_TOUCH LIBRARY MUST BE SPECIFICALLY
// CONFIGURED FOR EITHER THE TFT SHIELD OR THE BREAKOUT BOARD.

//This program is a demo of drawing

//when using the BREAKOUT BOARD only and using these hardware spi lines to the LCD,
//the SDA pin and SCK pin is defined by the system and can't be modified.
//if you don't need to control the LED pin,you can set it to 3.3V and set the pin definition to -1.
//other pins can be defined by youself,for example
//pin usage as follow:
//            CS  DC/RS  RESET  SDI/MOSI  SCK  SDO/MISO  LED   T_CLK   T_CS   T_DIN   T_DO   T_IRQ   VCC   GND    
//ESP32-S3:   10    2      15      11      12      13     21     6      4       5      7       -1     5V   GND 

//Remember to set the pins to suit your display module!

/*********************************************************************************
* @attention
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
* TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
* DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
* FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE 
* CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**********************************************************************************/
#include <TFT_eSPI.h> 
#include <SPI.h>
#include <TFT_Touch.h>

#define RTP_CS    4
#define RTP_DIN   5
#define RTP_DOUT  7
#define RTP_CLK   6

TFT_eSPI my_lcd = TFT_eSPI();
TFT_Touch my_touch = TFT_Touch(RTP_CS, RTP_CLK, RTP_DIN, RTP_DOUT);

#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

uint16_t px = 0;
uint16_t py = 0;

void LCD_Draw_Line(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t Size,uint16_t colour)
{
  uint16_t t; 
  int xerr=0,yerr=0,delta_x,delta_y,distance; 
  int incx,incy,uRow,uCol; 
  if(x1<Size||x2<Size||y1<Size||y2<Size)
  {
    return;  
  }
  delta_x=x2-x1; //计算坐标增量 
  delta_y=y2-y1; 
  uRow=x1; 
  uCol=y1; 
  if(delta_x>0)incx=1; //设置单步方向 
  else if(delta_x==0)incx=0;//垂直线 
  else {incx=-1;delta_x=-delta_x;} 
  if(delta_y>0)incy=1; 
  else if(delta_y==0)incy=0;//水平线 
  else{incy=-1;delta_y=-delta_y;} 
  if( delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴 
  else distance=delta_y; 
  for(t=0;t<=distance+1;t++ )//画线输出 
  {  
     my_lcd.fillCircle(uRow, uCol, Size,colour);
    //gui_circle(uRow, uCol,color, size, 1);
    //LCD_DrawPoint(uRow,uCol);//画点 
    xerr+=delta_x ; 
    yerr+=delta_y ; 
    if(xerr>distance) 
    { 
      xerr-=distance; 
      uRow+=incx; 
    } 
    if(yerr>distance) 
    { 
      yerr-=distance; 
      uCol+=incy; 
    } 
  }  
}

void setup(void) 
{
  Serial.begin(115200);
  my_lcd.init();
  my_touch.setCal(3583, 678, 3328, 616, 320, 240, 1);
  my_lcd.setRotation(0);  
  my_touch.setRotation(0);
  my_lcd.fillScreen(WHITE);
  my_lcd.setTextColor(BLUE);
  my_lcd.drawString("RST",my_lcd.width()-36,0,2);
}

void loop()
{
      if(my_touch.Pressed()) 
      {
        if( my_touch.X()<my_lcd.width()&&my_touch.Y()<my_lcd.height()) 
        {
          if(px == 0xFFFF)
          {
            px = my_touch.X();
            py = my_touch.Y();
          }
           if(my_touch.X()>(my_lcd.width()-36)&&my_touch.Y()<16)
           {
              my_lcd.fillScreen(WHITE);
              my_lcd.setTextColor(BLUE);
              my_lcd.drawString("RST",my_lcd.width()-36,0,2);
            } 
            else
            {
                LCD_Draw_Line(px,py,my_touch.X(),my_touch.Y(),2,RED);
            } 
            px = my_touch.X();
            py = my_touch.Y();         
          }
       }
       else
       {
            px = 0xFFFF;
       }
}
