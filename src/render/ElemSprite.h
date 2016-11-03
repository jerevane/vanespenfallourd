// Generated by dia2code
#ifndef RENDER__ELEMSPRITE__H
#define RENDER__ELEMSPRITE__H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>

namespace sf {
  class Texture;
  class Sprite;
};
namespace state {
  class State;
}

#include "state/State.h"

namespace render {

  /// class ElemSprite - 
  class ElemSprite : public sf::Sprite {
    // Attributes
  public:
    sf::Texture* texture;
    state::Element* element;
    state::Node* node;
  protected:
    float py;
    float px;
    std::string name;
    int id;
    // Operations
  public:
    ElemSprite (state::Element* element, sf::Texture* texture, float px, float py, std::string name, int id);
    ElemSprite (state::Node* node, sf::Texture* texture, float px, float py, std::string name, int id);
    ~ElemSprite ();
    float getPositionX ();
    float getPositionY ();
    void setPositionX (float x);
    void setPositionY (float y);
    int getId ();
    std::string getName ();
  };

};

#endif
