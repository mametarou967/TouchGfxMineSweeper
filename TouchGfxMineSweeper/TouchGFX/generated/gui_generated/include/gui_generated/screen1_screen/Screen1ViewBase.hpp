/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN1VIEWBASE_HPP
#define SCREEN1VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ButtonWithIcon.hpp>

class Screen1ViewBase : public touchgfx::View<Screen1Presenter>
{
public:
    Screen1ViewBase();
    virtual ~Screen1ViewBase();
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
    touchgfx::ButtonWithIcon Sample1;
    touchgfx::Image image1;
    touchgfx::Image image1_1;
    touchgfx::Image image_number3;
    touchgfx::Image image_number4;
    touchgfx::Image image_number5;
    touchgfx::Image image_number6;
    touchgfx::Image image_number7;
    touchgfx::Image image_number8;
    touchgfx::Image image_number9;
    touchgfx::Image image_bomb;

private:

};

#endif // SCREEN1VIEWBASE_HPP
