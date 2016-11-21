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
#include <render/IntroRenderer.h>
#include <render/WorldmapRenderer.h>
#include <render/FightRenderer.h>
#include <render/InnRenderer.h>

namespace instance {



    Application::Application(state::State* state, engine::Engine* engine) :    RenderWindow(sf::VideoMode(800, 600), "Final Fantastique",sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize),
                                    intro(this, new render::IntroRenderer(this), state, engine),
                                    worldmap(this, new render::WorldmapRenderer(this), state, engine),
                                    inn(this, new render::InnRenderer(this), state, engine){

      std::cout << "Starting game" << std::endl;

      setVerticalSyncEnabled(false);
      setMouseCursorVisible(true);

      std::cout << "SFML window created" << std::endl;

      font.loadFromFile("../res/Square.ttf");
      intro.renderer->initRender();
      intro.init();

    }

    void Application::play(state::State* state, engine::Engine* engine) {
        //What happens when the game is launched
        intro.run(intro.renderer, state);
        worldmap.init();
        while(1)
        {
            std::string tempstr = worldmap.run(worldmap.renderer, state);

            if (tempstr == "fight")
            {
                render::FightRenderer* fightR = new render::FightRenderer(this);
                fightR->state = state;
                Fight* f1 = new Fight(this, fightR, state, engine);
                f1->init();
                f1->run(fightR, state);
                tempstr = "temp";
            }

        }

    }


    Application::~Application()
    {
        //dtor
    }


};

#endif
