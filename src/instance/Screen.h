// Generated by dia2code
#ifndef INSTANCE__SCREEN__H
#define INSTANCE__SCREEN__H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

namespace sf {
  class RenderWindow;
  class Sprite;
  class Texture;
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
  public:
    sf::RenderWindow* window;
    sf::Sprite spriteScreen;
  protected:
    sf::Texture background;
    sf::Font* font;
    bool needScreenChange;
    sf::Event event;
    // Operations
  public:
    Screen (sf::Font* font, sf::RenderWindow* rwindow);
    virtual ~Screen ();
    virtual void init () = 0;
    virtual void render () = 0;
    void setBackground ();
    virtual void eventHandler () = 0;
    void run ();
  };

};

#endif
