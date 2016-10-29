// Generated by dia2code
#ifndef INSTANCE__FIGHT__H
#define INSTANCE__FIGHT__H

#include <map>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "render/Renderer.h"

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

  /// class Fight - Handles fights rendering and logic
  class Fight : public instance::Screen {
    // Attributes
  protected:
    std::map<int, int> turnOrderMap;
    // Operations
  public:
    Fight (sf::RenderWindow* window, render::Renderer* renderer);
    virtual ~Fight ();
    void init ();
    void eventHandler ();
  };

};

#endif
