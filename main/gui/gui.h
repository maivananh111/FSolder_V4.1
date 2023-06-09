/*
 * gui.h
 *
 *  Created on: May 14, 2023
 *      Author: anh
 */

#ifndef GUI_GUI_H_
#define GUI_GUI_H_

#ifdef __cplusplus
extern "C"{
#endif


#include <stdio.h>
#include "tftspi_st7735/tftspi_st7735.h"
#include "tftspi_st7735/fonts.h"
#include "ex_rtc/ex_rtc.h"

extern const char *Menu_Scr_Item[];
extern const char *System_Scr_Item[];
extern const char *Sleep_Scr_Item[];
extern const char *Calib_Scr_Item[];
extern const char *Param_Scr_Item[];
extern const char *PID_Scr_Item[];
extern const char *RTC_Scr_Item[];

#define TIME false
#define DATE true

#define LCD_WIDTH    160
#define LCD_HEIGHT   128

extern bool theme;
#define DARK_BG_COLOR        BLACK
#define DARK_TEXT_COLOR      WHITE
#define DARK_CONTAIN_COLOR   CYAN
#define DARK_HEADER_COLOR    YELLOW
#define DARK_HEADER_BG_COLOR NAVY //BLUE

#define LIGHT_BG_COLOR        WHITE
#define LIGHT_TEXT_COLOR      0x101010 //BLACK
#define LIGHT_CONTAIN_COLOR   0x0085FF //BLUE
#define LIGHT_HEADER_COLOR    WHITE
#define LIGHT_HEADER_BG_COLOR DARKGREEN

#define BG_COLOR        ((theme)? DARK_BG_COLOR:LIGHT_BG_COLOR)
#define TEXT_COLOR      ((theme)? DARK_TEXT_COLOR:LIGHT_TEXT_COLOR)
#define CONTAIN_COLOR   ((theme)? DARK_CONTAIN_COLOR:LIGHT_CONTAIN_COLOR)
#define HEADER_COLOR    ((theme)? DARK_HEADER_COLOR :LIGHT_HEADER_COLOR )
#define HEADER_BG_COLOR ((theme)? DARK_HEADER_BG_COLOR:LIGHT_HEADER_BG_COLOR)

#define SET_TEMP_COLOR      YELLOW //ORANGE
#define SLEEP_TEMP_COLOR    GREEN //ORANGE
#define HEAT_TEMP_COLOR     RED

typedef struct{
	uint16_t tempset;
	uint16_t sleep_tempset;
	uint16_t temp;
	float voltage;
	float power;
	uint16_t intemp;
	rtc_time_t time;
	bool unit = false;
} parameter_t;

typedef enum{
	HEATING,
	SLEEPING,
	SETTING,
	MENU,
	SD_ERROR,
} main_activite_t;
extern main_activite_t gui_main_activite;

typedef enum{
	MENU_LAYER_1,
	MENU_LAYER_2,
	MENU_LAYER_3,
} menu_layer_t;
extern menu_layer_t gui_menu_layer;
extern uint8_t gui_menu_layer2_num;
extern uint8_t gui_menu_layer3_num;

void gui_limit_counter(int16_t bottom, int16_t top);
int16_t gui_get_bottom(void);
int16_t gui_get_top(void);

void gui_clear(void);


void Menu_Restart(void);
void Menu_Save_State1(void);
void Menu_Return_State1(void);
void Menu_Save_State2(void);
void Menu_Return_State2(void);

void Error_Scr(char *mes);
void Heating_Scr(parameter_t *param);
void Sleeping_Scr(parameter_t *param);
void Temp_Set_Scr(parameter_t *param);

void Menu_Setting_Scr(int8_t *Selecting);
void Menu_System_Scr(int8_t *Selecting);
void Menu_Sleep_Scr(int8_t *Selecting);
void Menu_Calib_Scr(int8_t *Selecting);
void Menu_Param_Scr(int8_t *Selecting);
void Menu_PID_Scr(int8_t *Selecting);
void Menu_RTC_Scr(int8_t *Selecting);
void Menu_SYSInfor_Scr(void);

void Draw_State_Item_1(bool State, char *Item, char *Option1, char *Option2);
void Draw_State_Item_2(bool State, char *Item1, char *Item2, char *Option1, char *Option2);

void Draw_Number_Item_1(int16_t Number, char *Item, char * Unit);
void Draw_Number_Item_2(int16_t Number, char *Item1, char *Item2, char * Unit);



#ifdef __cplusplus
}
#endif

#endif /* GUI_GUI_H_ */
