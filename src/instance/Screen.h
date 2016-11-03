// Generated by dia2code
#ifndef INSTANCE__SCREEN__H
#define INSTANCE__SCREEN__H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>
#include "render/Renderer.h"

namespace sf {
  class RenderWindow;
};
namespace render {
  class Renderer;
};
namespace state {
  class Element;
  class State;
}

#include "state/Element.h"
#include "state/State.h"
#include "render/Renderer.h"

namespace instance {

  /// class Screen - Wrapper for all screen logic and display
  class Screen {
    // Associations
    // Attributes
  protected:
    sf::RenderWindow* window;
    bool needScreenChange;
    sf::Event event;
    std::string nextScreen;
    // Operations
  public:
    Screen (sf::RenderWindow* rwindow);
    virtual ~Screen ();
    virtual void init () = 0;
    virtual void eventHandler () = 0;
    std::string run (render::Renderer* rd);
    void setNextScreen (std::string nScreen);
  };

};

#endif
