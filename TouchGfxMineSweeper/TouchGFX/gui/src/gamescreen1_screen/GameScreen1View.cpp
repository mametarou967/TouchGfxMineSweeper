#include <gui/gamescreen1_screen/GameScreen1View.hpp>
#include <images/BitmapDatabase.hpp>

GameScreen1View::GameScreen1View()
{
    updateBlockImage(Block1_1, BlockState::Close);
    updateBlockImage(Block1_2, BlockState::Close);
    updateBlockImage(Block1_3, BlockState::Close);
    updateBlockImage(Block2_1, BlockState::Close);
    updateBlockImage(Block2_2, BlockState::Close);
    updateBlockImage(Block2_3, BlockState::Close);
    updateBlockImage(Block3_1, BlockState::Close);
    updateBlockImage(Block3_2, BlockState::Close);
    updateBlockImage(Block3_3, BlockState::Close);
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
