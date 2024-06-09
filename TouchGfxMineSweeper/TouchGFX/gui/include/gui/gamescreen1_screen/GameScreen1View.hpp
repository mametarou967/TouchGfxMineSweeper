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
protected:
    int block1_1_Cliecked_number;
    enum class BlockState
	{
    	Close = 0,
		CloseWithFlag,
		OpenNumber0,
		OpenNumber1,
		OpenNumber2,
		BlockStateMax
	};
    void updateBlockImage(touchgfx::ButtonWithIcon&,BlockState);
};

#endif // GAMESCREEN1VIEW_HPP
