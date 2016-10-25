// Generated by dia2code
#ifndef STATE__NODE__H
#define STATE__NODE__H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

namespace state {
  class Node;
};
namespace sf {
  class Texture;
  class Sprite;
}


namespace state {

  /// class Node - 
  class Node : public sf::Sprite {
    // Associations
    // Attributes
  protected:
    int Id;
    bool WasVisited;
    Node* Previous;
    Node* Next;
    int px;
    int py;
    sf::Texture* texture;
    // Operations
  public:
    Node (int id, int px, int py);
    Node (Node* previousNode, int id, int px, int py);
    void RandomEvent ();
    void StoryEvent ();
    int getId ();
    void setId (int id);
    bool getWasVisited ();
    void setWasVisited (bool wasvisited);
    Node* getPreviousNode ();
    void setPreviousNode (Node* previousnode);
    Node* getNextNode ();
    void setNextNode (Node* nextnode);
    int getPositionX ();
    int getPositionY ();
  };

};

#endif
