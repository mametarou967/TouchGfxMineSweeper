#ifndef GAMESCREEN1PRESENTER_HPP
#define GAMESCREEN1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

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

private:
    GameScreen1Presenter();

    GameScreen1View& view;
};

#endif // GAMESCREEN1PRESENTER_HPP
