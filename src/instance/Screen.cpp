// Generated by dia2code
#ifndef INSTANCE__SCREEN__C
#define INSTANCE__SCREEN__C


namespace sf {
  class RenderWindow;
  class Texture;
}

#include <iostream>
#include "Screen.h"
#include "../state/Element.h"

namespace instance {

    Screen::~Screen()
    {
        //dtor
    }

    Screen::Screen(sf::Font* f,sf::RenderWindow* r){

        font = f;
        window = r;

    }

    void Screen::setBackground()
    {
        spriteScreen.setTexture(background);
        spriteScreen.setScale({0.60,0.65});
        spriteScreen.setOrigin((int)background.getSize().x/2, (int)background.getSize().y/2);
        spriteScreen.move(400, 300);
    }

    std::string Screen::run()
    {
        if(window->isOpen())
        {
            while(!needScreenChange)
            {
                while (window->pollEvent(event))
                {
                    if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    {
                        needScreenChange = true;
                        window->close();
                        std::cout << "System closed" << std::endl;
                        break;
                    }

                    eventHandler();
                }

                window->clear(sf::Color(0,0,0,255));
                render();
                window->display();
            }
            return nextScreen;
        }

    }
};

#endif
