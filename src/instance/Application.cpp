// Generated by dia2code
#ifndef INSTANCE__APPLICATION__C
#define INSTANCE__APPLICATION__C


namespace instance {
  class Intro;
  class Worldmap;
  class Fight;
  class Inn;
};
namespace sf {
  class RenderWindow;
};
namespace instance {
  class Screen;
}

#include "Application.h"
#include <iostream>

namespace instance {



    Application::Application() :    RenderWindow(sf::VideoMode(800, 600), "Final Fantastique",sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize),
                                    intro(&font,this),
                                    fight(&font,this),
                                    worldmap(&font,this),
                                    inn(&font,this){

      std::cout << "Starting game" << std::endl;

      setVerticalSyncEnabled(false);
      setMouseCursorVisible(true);

      std::cout << "SFML window created" << std::endl;

      font.loadFromFile("../res/Square.ttf");

      intro.init();

    }

    void Application::play() {
        //What happens when the game is launched
        intro.run();
        worldmap.init();
        if (worldmap.run() == "fight")
        {

        } else if (worldmap.run() == "inn")
        {

        } else if (worldmap.run() == "intro")
        {

        }

    }


    Application::~Application()
    {
        //dtor
    }


};

#endif
