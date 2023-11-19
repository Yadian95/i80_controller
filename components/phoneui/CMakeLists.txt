set(SOURCES ui.c
    ui_events.c
    ui_font_misans16.c
    ui_font_symbols16.c 
    ui_helpers.c
    ui_img_bg_png.c
    ui_img_bluetoothcontrl_png.c
    ui_img_browser_png.c
    ui_img_calculator_png.c
    ui_img_camera_png.c
    ui_img_car_png.c
    ui_img_clock_png.c
    ui_img_contacts_png.c
    ui_img_email_png.c
    ui_img_filemanager_png.c
    ui_img_gallery_png.c
    ui_img_jionet_png.c
    ui_img_messaging_png.c
    ui_img_mi_remote_png.c
    ui_img_music_png.c
    ui_img_notes_png.c
    ui_img_phone_png.c
    ui_img_qrbarcode_png.c
    ui_img_settings_png.c
    ui_img_videos_png.c
    ui_img_weather_png.c)

idf_component_register(SRCS ${SOURCES}
                    PRIV_REQUIRES driver lvgl
                    INCLUDE_DIRS "." )
