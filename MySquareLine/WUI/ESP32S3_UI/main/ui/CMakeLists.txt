SET(SOURCES screens/ui_Home.c
    screens/ui_settings.c
    screens/ui_Batinfo.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    images/ui_img_519783640.c
    images/ui_img_358101685.c
    images/ui_img_316889752.c
    images/ui_img_636766446.c
    images/ui_img_1978383688.c
    fonts/ui_font_AlimamaAgileVF.c
    fonts/ui_font_AlimamaAgileVFFangyuan40.c
    fonts/ui_font_LenovoHTC.c
    fonts/ui_font_MiSansB40.c
    fonts/ui_font_MiSansM.c
    fonts/ui_font_MiSansN.c
    fonts/ui_font_MiSansN14.c
    fonts/ui_font_symbols16.c
    fonts/ui_font_symbolsalibaba.c
    fonts/ui_font_symbolsalibaba16.c)

add_library(ui ${SOURCES})
