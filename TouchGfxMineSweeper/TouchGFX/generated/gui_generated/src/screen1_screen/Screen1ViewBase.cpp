/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>

Screen1ViewBase::Screen1ViewBase()
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    BackScreen.setXY(0, 0);
    BackScreen.setBitmap(touchgfx::Bitmap(BITMAP_BACKSCREEN_ID));
    add(BackScreen);

    Sample1.setXY(17, 17);
    Sample1.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_OUTLINE_DISABLED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_OUTLINE_DISABLED_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_CONTENT_OUTLINED_FLAG_50_50_E8F6FB_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_CONTENT_OUTLINED_FLAG_50_50_E8F6FB_SVG_ID));
    Sample1.setIconXY(5, 5);
    add(Sample1);
}

Screen1ViewBase::~Screen1ViewBase()
{

}

void Screen1ViewBase::setupScreen()
{

}