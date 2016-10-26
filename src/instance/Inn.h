// Generated by dia2code
#ifndef INSTANCE__INN__H
#define INSTANCE__INN__H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

namespace sf {
  class RenderWindow;
};
namespace render {
  class Renderer;
};
namespace instance {
  class Screen;
}

#include "Screen.h"

namespace instance {

  /// class Inn - Handles Inn logic and rendering
  class Inn : public instance::Screen {
    // Operations
  public:
    Inn (sf::RenderWindow* window, render::Renderer* renderer);
    virtual ~Inn ();
    void init ();
    void eventHandler ();
  };

};

#endif
