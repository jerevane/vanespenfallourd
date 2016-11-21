// Generated by dia2code
#ifndef INSTANCE__INN__H
#define INSTANCE__INN__H

#include "render/InnRenderer.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

namespace render {
  class InnRenderer;
};
namespace sf {
  class RenderWindow;
};
namespace state {
  class State;
};
namespace engine {
  class Engine;
};
namespace instance {
  class Screen;
}

#include "Screen.h"
#include "render/InnRenderer.h"

namespace instance {

  /// class Inn - Handles Inn logic and rendering
  class Inn : public instance::Screen {
    // Associations
    // Attributes
  public:
    render::InnRenderer* renderer;
    // Operations
  public:
    Inn (sf::RenderWindow* window, render::InnRenderer* renderer, state::State* state, engine::Engine* engine);
    virtual ~Inn ();
    void init ();
    void eventHandler ();
  };

};

#endif
