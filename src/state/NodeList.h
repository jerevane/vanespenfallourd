// Generated by dia2code
#ifndef STATE__NODELIST__H
#define STATE__NODELIST__H


namespace state {
  class Node;
  class NodeFactory;
  class State;
}

#include "NodeFactory.h"
#include "State.h"
#include "Node.h"

namespace state {

  /// class NodeList - 
  class NodeList {
    // Associations
    // Attributes
  protected:
    Node* CurrentNode;
    // Operations
  public:
    /// Changes CurrentNode
    void NextNode ();
    void PreviousNode ();
    NodeList ();

      Node *getCurrentNode() const;

      void setCurrentNode(Node *CurrentNode);
  };


};

#endif
