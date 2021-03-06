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
#include "../state.hpp"
#include <iostream>
#include <state/ElementList.h>

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

        state::ElementList *elementlist = new state::ElementList();
        state::Character *Claude = new state::Character(0);
        state::Character *Youenn = new state::Character(1);
        elementlist->element.push_back(Claude);
        elementlist->element.push_back(Youenn);
        state::Node *temp_node = new state::Node(0,0,0);
        state::State *Etat = new state::State(elementlist, temp_node, 0);

        intro.run();
        worldmap.init(Etat);
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
