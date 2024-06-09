/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef GAMESCREEN1VIEWBASE_HPP
#define GAMESCREEN1VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/gamescreen1_screen/GameScreen1Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ButtonWithIcon.hpp>

class GameScreen1ViewBase : public touchgfx::View<GameScreen1Presenter>
{
public:
    GameScreen1ViewBase();
    virtual ~GameScreen1ViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Image BackScreen;
    touchgfx::ButtonWithIcon Block1_1;

private:

};

#endif // GAMESCREEN1VIEWBASE_HPP
