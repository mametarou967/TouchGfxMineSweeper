/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/gamescreen1_screen/GameScreen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>

GameScreen1ViewBase::GameScreen1ViewBase()
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    BackScreen.setXY(0, 0);
    BackScreen.setBitmap(touchgfx::Bitmap(BITMAP_BACKSCREEN_ID));
    add(BackScreen);

    buttonWithIcon1.setXY(20, 19);
    buttonWithIcon1.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_FILL_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_FILL_NORMAL_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_CONTENT_OUTLINED_FLAG_50_50_E8F6FB_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_CONTENT_OUTLINED_FLAG_50_50_E8F6FB_SVG_ID));
    buttonWithIcon1.setIconXY(5, 5);
    add(buttonWithIcon1);
}

GameScreen1ViewBase::~GameScreen1ViewBase()
{

}

void GameScreen1ViewBase::setupScreen()
{

}