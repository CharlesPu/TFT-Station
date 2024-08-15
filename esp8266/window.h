#ifndef __WINDOW_H
#define __WINDOW_H

#include <Arduino.h>

#define area_top_left_x   2
#define area_top_left_y   17
#define area_top_left_w   132
#define area_top_left_h   60
#define area_top_right_x  135
#define area_top_right_y  17
#define area_top_right_w  185
#define area_top_right_h  60

#define area_bottom_x 2
#define area_bottom_y 144
#define area_bottom_w 316
#define area_bottom_h 80


void draw_background();
void draw_background_header();
void draw_background_header_inited();
void draw_background_booter();

void init_areas();
void init_area_top();
void init_area_top_left();
void init_area_top_right();
void init_area_bottom();


#endif


