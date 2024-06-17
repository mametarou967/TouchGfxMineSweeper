#include <gui/gamescreen1_screen/GameScreen1View.hpp>
#include <images/BitmapDatabase.hpp>

GameScreen1View::GameScreen1View()
{
	int row = 0;
	int column = 0;

	for(row=1;row<=7;row++)
	{
		for(column=1;column<=9;column++)
		{
			touchgfx::ButtonWithIcon& block = getBlockWithIcon(row, column);
		    updateBlockImage(block, BlockState::Close);
		}
	}
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
    if (GameScreen1View::block1_1_Cliecked_number == 0) updateBlockImage(Block1_1, BlockState::Close);
    else if (GameScreen1View::block1_1_Cliecked_number == 1) updateBlockImage(Block1_1, BlockState::CloseWithFlag);
    else if (GameScreen1View::block1_1_Cliecked_number == 2) updateBlockImage(Block1_1, BlockState::OpenNumber0);
    else if (GameScreen1View::block1_1_Cliecked_number == 3) updateBlockImage(Block1_1, BlockState::OpenNumber1);
    else if (GameScreen1View::block1_1_Cliecked_number == 4) updateBlockImage(Block1_1, BlockState::OpenNumber2);
    GameScreen1View::block1_1_Cliecked_number++;
    if (GameScreen1View::block1_1_Cliecked_number == 5) GameScreen1View::block1_1_Cliecked_number = 0;
}

void GameScreen1View::updateBlockImage(touchgfx::ButtonWithIcon& blockImage, GameScreen1View::BlockState blockState)
{
    switch (blockState)
    {
    case BlockState::Close:
        blockImage.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_FILL_NORMAL_ID),
                              touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_FILL_NORMAL_ID),
                              touchgfx::Bitmap(BITMAP_INVALID),
                              touchgfx::Bitmap(BITMAP_INVALID));
        break;
    case BlockState::CloseWithFlag:
        blockImage.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_FILL_NORMAL_ID),
                              touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_FILL_NORMAL_ID),
                              touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_CONTENT_OUTLINED_FLAG_50_50_E8F6FB_SVG_ID),
                              touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_CONTENT_OUTLINED_FLAG_50_50_E8F6FB_SVG_ID));
        break;
    case BlockState::OpenNumber0:
        blockImage.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_OUTLINE_DISABLED_ID),
                              touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_OUTLINE_DISABLED_ID),
                              touchgfx::Bitmap(BITMAP_INVALID),
                              touchgfx::Bitmap(BITMAP_INVALID));
        break;
    case BlockState::OpenNumber1:
        blockImage.setBitmaps(touchgfx::Bitmap(BITMAP_TINY_OUTLINE_DISABLED_NUMBER1_ID),
                              touchgfx::Bitmap(BITMAP_TINY_OUTLINE_DISABLED_NUMBER1_ID),
                              touchgfx::Bitmap(BITMAP_INVALID),
                              touchgfx::Bitmap(BITMAP_INVALID));
        break;
    case BlockState::OpenNumber2:
        blockImage.setBitmaps(touchgfx::Bitmap(BITMAP_TINY_OUTLINE_DISABLED_NUMBER2_ID),
                              touchgfx::Bitmap(BITMAP_TINY_OUTLINE_DISABLED_NUMBER2_ID),
                              touchgfx::Bitmap(BITMAP_INVALID),
                              touchgfx::Bitmap(BITMAP_INVALID));
        break;
    default:
        blockImage.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_FILL_NORMAL_ID),
                              touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_TINY_FILL_NORMAL_ID),
                              touchgfx::Bitmap(BITMAP_INVALID),
                              touchgfx::Bitmap(BITMAP_INVALID));
        break;
    }
    blockImage.invalidate();
}


touchgfx::ButtonWithIcon& GameScreen1View::getBlockWithIcon(int row , int column)
{
	if(row == 1)
	{
		if(column == 1) return Block1_1;
		else if(column == 2) return Block1_2;
		else if(column == 3) return Block1_3;
		else if(column == 4) return Block1_4;
		else if(column == 5) return Block1_5;
		else if(column == 6) return Block1_6;
		else if(column == 7) return Block1_7;
		else if(column == 8) return Block1_8;
		else if(column == 9) return Block1_9;
	}
	else if(row == 2)
	{
		if(column == 1) return Block2_1;
		else if(column == 2) return Block2_2;
		else if(column == 3) return Block2_3;
		else if(column == 4) return Block2_4;
		else if(column == 5) return Block2_5;
		else if(column == 6) return Block2_6;
		else if(column == 7) return Block2_7;
		else if(column == 8) return Block2_8;
		else if(column == 9) return Block2_9;
	}
	else if(row == 3)
	{
		if(column == 1) return Block3_1;
		else if(column == 2) return Block3_2;
		else if(column == 3) return Block3_3;
		else if(column == 4) return Block3_4;
		else if(column == 5) return Block3_5;
		else if(column == 6) return Block3_6;
		else if(column == 7) return Block3_7;
		else if(column == 8) return Block3_8;
		else if(column == 9) return Block3_9;
	}
	else if(row == 4)
	{
		if(column == 1) return Block4_1;
		else if(column == 2) return Block4_2;
		else if(column == 3) return Block4_3;
		else if(column == 4) return Block4_4;
		else if(column == 5) return Block4_5;
		else if(column == 6) return Block4_6;
		else if(column == 7) return Block4_7;
		else if(column == 8) return Block4_8;
		else if(column == 9) return Block4_9;
	}
	else if(row == 5)
	{
		if(column == 1) return Block5_1;
		else if(column == 2) return Block5_2;
		else if(column == 3) return Block5_3;
		else if(column == 4) return Block5_4;
		else if(column == 5) return Block5_5;
		else if(column == 6) return Block5_6;
		else if(column == 7) return Block5_7;
		else if(column == 8) return Block5_8;
		else if(column == 9) return Block5_9;
	}
	else if(row == 6)
	{
		if(column == 1) return Block6_1;
		else if(column == 2) return Block6_2;
		else if(column == 3) return Block6_3;
		else if(column == 4) return Block6_4;
		else if(column == 5) return Block6_5;
		else if(column == 6) return Block6_6;
		else if(column == 7) return Block6_7;
		else if(column == 8) return Block6_8;
		else if(column == 9) return Block6_9;
	}
	else if(row == 7)
	{
		if(column == 1) return Block7_1;
		else if(column == 2) return Block7_2;
		else if(column == 3) return Block7_3;
		else if(column == 4) return Block7_4;
		else if(column == 5) return Block7_5;
		else if(column == 6) return Block7_6;
		else if(column == 7) return Block7_7;
		else if(column == 8) return Block7_8;
		else if(column == 9) return Block7_9;
	}

	return Block1_1;
}
