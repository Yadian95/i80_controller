// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.3
// LVGL version: 8.3.6
// Project name: ESP32S3_UI

#ifndef _ESP32S3_UI_UI_H
#define _ESP32S3_UI_UI_H

#ifdef __cplusplus
extern "C" {
#endif

    #include "lvgl.h"

#include "ui_helpers.h"
#include "ui_events.h"
// SCREEN: ui_Home
void ui_Home_screen_init(void);
extern lv_obj_t *ui_Home;
extern lv_obj_t *ui_header;
extern lv_obj_t *ui_WIFILabel;
extern lv_obj_t *ui_WIFISymbel;
extern lv_obj_t *ui_HeaderTimeHome;
extern lv_obj_t *ui_SliderHeaderBat;
extern lv_obj_t *ui_PanelBathead;
extern lv_obj_t *ui_LabelHeaderBatValue;
extern lv_obj_t *ui_Body;
extern lv_obj_t *ui_home1;
void ui_event_ToolIcon( lv_event_t * e);
extern lv_obj_t *ui_ToolIcon;
extern lv_obj_t *ui_home2;
extern lv_obj_t *ui_Label1;
// SCREEN: ui_settings
void ui_settings_screen_init(void);
extern lv_obj_t *ui_settings;
void ui_event_settingHeader( lv_event_t * e);
extern lv_obj_t *ui_settingHeader;
void ui_event_HomeImg( lv_event_t * e);
extern lv_obj_t *ui_HomeImg;
extern lv_obj_t *ui_Label11;
void ui_event_StepPannel( lv_event_t * e);
extern lv_obj_t *ui_StepPannel;
void ui_event_Bat( lv_event_t * e);
extern lv_obj_t *ui_Bat;
extern lv_obj_t *ui_dianchi;
extern lv_obj_t *ui_dayu;
void ui_event_Time( lv_event_t * e);
extern lv_obj_t *ui_Time;
extern lv_obj_t *ui_dianchi1;
extern lv_obj_t *ui_dayu1;
// SCREEN: ui_Batinfo
void ui_Batinfo_screen_init(void);
void ui_event_Batinfo( lv_event_t * e);
extern lv_obj_t *ui_Batinfo;
void ui_event_Panel8( lv_event_t * e);
extern lv_obj_t *ui_Panel8;
extern lv_obj_t *ui_Label14;
extern lv_obj_t *ui_Label15;
extern lv_obj_t *ui_Panel9;
extern lv_obj_t *ui_Label16;
extern lv_obj_t *ui_BarBAT;
extern lv_obj_t *ui_Label19;
extern lv_obj_t *ui_Label22;
extern lv_obj_t *ui_LabelValue;
extern lv_obj_t *ui_LabelVoltage;
extern lv_obj_t *ui_labelSampleVoltage;
extern lv_obj_t *ui_Label21;
extern lv_obj_t *ui_labelSampleVolume;
extern lv_obj_t *ui_valueVoltage;
extern lv_obj_t *ui_valueVolume;
extern lv_obj_t *ui____initial_actions0;

LV_IMG_DECLARE( ui_img_519783640);   // assets\child320-480.png
LV_IMG_DECLARE( ui_img_358101685);   // assets\Set60-60.png
LV_IMG_DECLARE( ui_img_316889752);   // assets\home40-40.png
LV_IMG_DECLARE( ui_img_636766446);   // assets\Desktop320-480.png
LV_IMG_DECLARE( ui_img_1978383688);   // assets\PhotoAlberm60-60.png

LV_FONT_DECLARE( ui_font_AlimamaAgileVF);
LV_FONT_DECLARE( ui_font_AlimamaAgileVFFangyuan40);
LV_FONT_DECLARE( ui_font_LenovoHTC);
LV_FONT_DECLARE( ui_font_MiSansB40);
LV_FONT_DECLARE( ui_font_MiSansM);
LV_FONT_DECLARE( ui_font_MiSansN);
LV_FONT_DECLARE( ui_font_MiSansN14);
LV_FONT_DECLARE( ui_font_symbols16);
LV_FONT_DECLARE( ui_font_symbolsalibaba);
LV_FONT_DECLARE( ui_font_symbolsalibaba16);

void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
