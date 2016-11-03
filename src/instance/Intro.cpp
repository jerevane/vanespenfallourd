// Generated by dia2code
#ifndef INSTANCE__INTRO__C
#define INSTANCE__INTRO__C


namespace sf {
  class RenderWindow;
};
namespace instance {
  class Screen;
}

#include <iostream>
#include <render/IntroRenderer.h>
#include "Intro.h"
#include "../state/Element.h"

namespace instance {

    Intro::Intro(sf::RenderWindow* w, render::IntroRenderer* rd) : Screen(w), renderer(rd)  {
    }

    void Intro::init() {

    }


    Intro::~Intro() {}

    void Intro::eventHandler() {

        if(event.type == sf::Event::KeyPressed)
        {

            needScreenChange = true;


        }

    }

};

#endif
