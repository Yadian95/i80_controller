// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.3
// LVGL version: 8.3.6
// Project name: ESP32S3_UI

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_Home
void ui_Home_screen_init(void);
lv_obj_t *ui_Home;
lv_obj_t *ui_header;
lv_obj_t *ui_WIFILabel;
lv_obj_t *ui_WIFISymbel;
lv_obj_t *ui_HeaderTimeHome;
lv_obj_t *ui_SliderHeaderBat;
lv_obj_t *ui_PanelBathead;
lv_obj_t *ui_LabelHeaderBatValue;
lv_obj_t *ui_Body;
lv_obj_t *ui_home1;
void ui_event_ToolIcon( lv_event_t * e);
lv_obj_t *ui_ToolIcon;
lv_obj_t *ui_home2;
lv_obj_t *ui_Label1;


// SCREEN: ui_settings
void ui_settings_screen_init(void);
lv_obj_t *ui_settings;
lv_obj_t *ui_settingHeader;
void ui_event_HomeImg( lv_event_t * e);
lv_obj_t *ui_HomeImg;
lv_obj_t *ui_Label11;
lv_obj_t *ui_StepPannel;
void ui_event_Bat( lv_event_t * e);
lv_obj_t *ui_Bat;
lv_obj_t *ui_dianchi;
lv_obj_t *ui_dayu;
void ui_event_Time( lv_event_t * e);
lv_obj_t *ui_Time;
lv_obj_t *ui_dianchi1;
lv_obj_t *ui_dayu1;


// SCREEN: ui_Batinfo
void ui_Batinfo_screen_init(void);
lv_obj_t *ui_Batinfo;
void ui_event_Panel8( lv_event_t * e);
lv_obj_t *ui_Panel8;
lv_obj_t *ui_Label14;
lv_obj_t *ui_Label15;
lv_obj_t *ui_Panel9;
lv_obj_t *ui_Label16;
lv_obj_t *ui_BarBAT;
lv_obj_t *ui_Label19;
lv_obj_t *ui_Label22;
lv_obj_t *ui_LabelValue;
lv_obj_t *ui_LabelVoltage;
lv_obj_t *ui_labelSampleVoltage;
lv_obj_t *ui_Label21;
lv_obj_t *ui_labelSampleVolume;
lv_obj_t *ui_valueVoltage;
lv_obj_t *ui_valueVolume;
lv_obj_t *ui____initial_actions0;
const lv_img_dsc_t *ui_imgset_1944395116[1] = {&ui_img_636766446};
const lv_img_dsc_t *ui_imgset_1601800952[1] = {&ui_img_316889752};
const lv_img_dsc_t *ui_imgset_2042809558[1] = {&ui_img_1978383688};
const lv_img_dsc_t *ui_imgset_1798733245[1] = {&ui_img_358101685};
const lv_img_dsc_t *ui_imgset_2089696111[1] = {&ui_img_1486146667};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_ToolIcon( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_settings, LV_SCR_LOAD_ANIM_OVER_LEFT, 500, 0, &ui_settings_screen_init);
}
}
void ui_event_HomeImg( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Home, LV_SCR_LOAD_ANIM_OVER_RIGHT, 500, 0, &ui_Home_screen_init);
}
}
void ui_event_Bat( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Batinfo, LV_SCR_LOAD_ANIM_OVER_LEFT, 500, 0, &ui_Batinfo_screen_init);
}
}
void ui_event_Time( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Batinfo, LV_SCR_LOAD_ANIM_OVER_LEFT, 500, 0, &ui_Batinfo_screen_init);
}
}
void ui_event_Panel8( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_settings, LV_SCR_LOAD_ANIM_OVER_RIGHT, 500, 0, &ui_settings_screen_init);
}
}

///////////////////// SCREENS ////////////////////

void ui_init( void )
{
lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_Home_screen_init();
ui_settings_screen_init();
ui_Batinfo_screen_init();
ui____initial_actions0 = lv_obj_create(NULL);
lv_disp_load_scr( ui_Home);
}
