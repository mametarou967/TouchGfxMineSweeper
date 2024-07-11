#ifndef GAMESCREEN1VIEW_HPP
#define GAMESCREEN1VIEW_HPP

#include <gui_generated/gamescreen1_screen/GameScreen1ViewBase.hpp>
#include <gui/gamescreen1_screen/GameScreen1Presenter.hpp>

class GameScreen1View : public GameScreen1ViewBase
{
public:
    GameScreen1View();
    virtual ~GameScreen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void Block1_1_Clicked();
    virtual void Block1_2_Clicked();
    virtual void Block1_3_Clicked();
    virtual void Block1_4_Clicked();
    virtual void Block1_5_Clicked();
    virtual void Block1_6_Clicked();
    virtual void Block1_7_Clicked();
    virtual void Block1_8_Clicked();
    virtual void Block1_9_Clicked();
    virtual void Block2_1_Clicked();
    virtual void Block2_2_Clicked();
    virtual void Block2_3_Clicked();
    virtual void Block2_4_Clicked();
    virtual void Block2_5_Clicked();
    virtual void Block2_6_Clicked();
    virtual void Block2_7_Clicked();
    virtual void Block2_8_Clicked();
    virtual void Block2_9_Clicked();
    virtual void Block3_1_Clicked();
    virtual void Block3_2_Clicked();
    virtual void Block3_3_Clicked();
    virtual void Block3_4_Clicked();
    virtual void Block3_5_Clicked();
    virtual void Block3_6_Clicked();
    virtual void Block3_7_Clicked();
    virtual void Block3_8_Clicked();
    virtual void Block3_9_Clicked();
    virtual void Block4_1_Clicked();
    virtual void Block4_2_Clicked();
    virtual void Block4_3_Clicked();
    virtual void Block4_4_Clicked();
    virtual void Block4_5_Clicked();
    virtual void Block4_6_Clicked();
    virtual void Block4_7_Clicked();
    virtual void Block4_8_Clicked();
    virtual void Block4_9_Clicked();
    virtual void Block5_1_Clicked();
    virtual void Block5_2_Clicked();
    virtual void Block5_3_Clicked();
    virtual void Block5_4_Clicked();
    virtual void Block5_5_Clicked();
    virtual void Block5_6_Clicked();
    virtual void Block5_7_Clicked();
    virtual void Block5_8_Clicked();
    virtual void Block5_9_Clicked();
    virtual void Block6_1_Clicked();
    virtual void Block6_2_Clicked();
    virtual void Block6_3_Clicked();
    virtual void Block6_4_Clicked();
    virtual void Block6_5_Clicked();
    virtual void Block6_6_Clicked();
    virtual void Block6_7_Clicked();
    virtual void Block6_8_Clicked();
    virtual void Block6_9_Clicked();
    virtual void Block7_1_Clicked();
    virtual void Block7_2_Clicked();
    virtual void Block7_3_Clicked();
    virtual void Block7_4_Clicked();
    virtual void Block7_5_Clicked();
    virtual void Block7_6_Clicked();
    virtual void Block7_7_Clicked();
    virtual void Block7_8_Clicked();
    virtual void Block7_9_Clicked();
    virtual void Mode_Clicked();
    virtual void Reset_Clicked();

    void updateBlockImage(int row,int column,GameScreen1Presenter::BlockState);
protected:
    int block1_1_Cliecked_number;
    touchgfx::ButtonWithIcon& getBlockWithIcon(int row , int column);
    void blockClicked(int row,int column);
};

#endif // GAMESCREEN1VIEW_HPP
