#ifndef GAMESCREEN1PRESENTER_HPP
#define GAMESCREEN1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>
#include <gui/model/Model.hpp>

using namespace touchgfx;

class GameScreen1View;

class GameScreen1Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    GameScreen1Presenter(GameScreen1View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~GameScreen1Presenter() {}

    void blockClicked(int row, int column);
    void resetClicked(void);
    void modeToggleClicked(void);
    bool checkFlagMode(void);

    enum class BlockState
	{
    	Close = 0,
		CloseWithFlag,
		OpenNumber0,
		OpenNumber1,
		OpenNumber2,
		OpenNumber3,
		OpenNumber4,
		OpenNumber5,
		OpenNumber6,
		OpenNumber7,
		OpenNumber8,
		OpenNumber9,
		OpenBomb,
		BlockStateMax
	};

private:
    void CurrentViewSave(void);
    void ViewUpdate(void);
    GameScreen1Presenter();
    BlockState GetBlockState(Model::Block);

    GameScreen1View& view;
    Model model;
};

#endif // GAMESCREEN1PRESENTER_HPP
