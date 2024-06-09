#include <gui/gamescreen1_screen/GameScreen1View.hpp>
#include <images/BitmapDatabase.hpp>

GameScreen1View::GameScreen1View()
{
	Block1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_FILL_NORMAL_ID),
					touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_FILL_NORMAL_ID),
					touchgfx::Bitmap(BITMAP_INVALID),
					touchgfx::Bitmap(BITMAP_INVALID));
	GameScreen1View::block1_1_Cliecked_number = 0;
}

void GameScreen1View::setupScreen()
{
    GameScreen1ViewBase::setupScreen();
}

void GameScreen1View::tearDownScreen()
{
    GameScreen1ViewBase::tearDownScreen();
}


void GameScreen1View::Block1_1_Clicked()
{
	if(GameScreen1View::block1_1_Cliecked_number == 0)
	{
		Block1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_OUTLINE_DISABLED_ID),
						touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_OUTLINE_DISABLED_ID),
						touchgfx::Bitmap(BITMAP_INVALID),
						touchgfx::Bitmap(BITMAP_INVALID));
		GameScreen1View::block1_1_Cliecked_number++;
	}
	else if(GameScreen1View::block1_1_Cliecked_number == 1)
	{
		Block1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_FILL_NORMAL_ID),
						touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_FILL_NORMAL_ID),
						touchgfx::Bitmap(BITMAP_INVALID),
						touchgfx::Bitmap(BITMAP_INVALID));
		GameScreen1View::block1_1_Cliecked_number++;
	}
	else if(GameScreen1View::block1_1_Cliecked_number == 2)
	{
		Block1_1.setBitmaps(touchgfx::Bitmap(BITMAP_TINY_OUTLINE_DISABLED_NUMBER1_ID),
						touchgfx::Bitmap(BITMAP_TINY_OUTLINE_DISABLED_NUMBER1_ID),
						touchgfx::Bitmap(BITMAP_INVALID),
						touchgfx::Bitmap(BITMAP_INVALID));
		GameScreen1View::block1_1_Cliecked_number++;
	}
	else if(GameScreen1View::block1_1_Cliecked_number == 3)
	{
		Block1_1.setBitmaps(touchgfx::Bitmap(BITMAP_TINY_OUTLINE_DISABLED_NUMBER2_ID),
						touchgfx::Bitmap(BITMAP_TINY_OUTLINE_DISABLED_NUMBER2_ID),
						touchgfx::Bitmap(BITMAP_INVALID),
						touchgfx::Bitmap(BITMAP_INVALID));
		GameScreen1View::block1_1_Cliecked_number=0;
	}

	Block1_1.invalidate();
}
