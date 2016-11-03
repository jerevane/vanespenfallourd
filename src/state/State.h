// Generated by dia2code
#ifndef STATE__STATE__H
#define STATE__STATE__H

#include <vector>

namespace state {
  class Node;
  class ElementList;
  class Observer;
};
namespace instance {
  class Screen;
}

#include "Observer.h"
#include "StateTypeID.h"
#include "ElementList.h"
#include "instance/Screen.h"
#include "Node.h"

namespace state {

  /// class State - 
  class State : public state::Observer {
    // Associations
    // Attributes
  public:
    std::vector<state::Node*> tabNode;
  protected:
    Node* node;
    ElementList* elementlist;
    int Id;
    // Operations
  public:
    State ();
    State (ElementList* elementlist, Node* node, int id);
    ~State ();
    Node* getNode ();
    void setNode (Node* node);
    ElementList* getElementList ();
    void setElementList (ElementList* elementlist);
    int getId ();
    void setId (int id);
    void run (int id);
  };

};

#endif
