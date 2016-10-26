// Generated by dia2code
#ifndef STATE__STATE__H
#define STATE__STATE__H


namespace state {
  class Node;
  class ElementList;
  class Observer;
}

#include "Observer.h"
#include "StateTypeID.h"
#include "Node.h"

namespace state {

  /// class State - 
  class State : public state::Observer {
    // Associations
    // Attributes
  protected:
    Node* node;
    ElementList* Elementlist;
    int Id;
    // Operations
  public:
    State ();
    State (ElementList* elementList, Node* node, int id);
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
