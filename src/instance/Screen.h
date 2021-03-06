// Generated by dia2code
#ifndef INSTANCE__SCREEN__H
#define INSTANCE__SCREEN__H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>

namespace sf {
  class Texture;
  class RenderWindow;
  class Sprite;
};
namespace state {
  class Element;
  class State;
}

#include "state/Element.h"
#include "state/State.h"

namespace instance {

  /// class Screen - Wrapper for all screen logic and display
  class Screen {
    // Attributes
  protected:
    sf::Texture background;
    sf::Font* font;
    sf::RenderWindow* window;
    bool needScreenChange;
    sf::Event event;
    sf::Sprite spriteScreen;
    std::string nextScreen;
    // Operations
  public:
    Screen (sf::Font* font, sf::RenderWindow* rwindow);
    virtual ~Screen ();
    virtual void init () = 0;
    virtual void render () = 0;
    void setBackground ();
    virtual void eventHandler () = 0;
    std::string run ();
    void setNextScreen (std::string nScreen);
  };

};

#endif
