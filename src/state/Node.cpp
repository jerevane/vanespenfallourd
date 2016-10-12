// Generated by dia2code
#ifndef STATE__NODE__C
#define STATE__NODE__C

#include <string>
#include "Node.h"

namespace state {
  class Node;
}


namespace state {


    const std::string &Node::getNodeName() const {
      return NodeName;
    }

    void Node::setNodeName(const std::string &NodeName) {
      Node::NodeName = NodeName;
    }

    bool Node::isWasVisited() const {
      return WasVisited;
    }

    void Node::setWasVisited(bool WasVisited) {
      Node::WasVisited = WasVisited;
    }

    Node *Node::getPrevious() const {
      return Previous;
    }

    void Node::setPrevious(Node *Previous) {
      Node::Previous = Previous;
    }

    Node *Node::getNext() const {
      return Next;
    }

    void Node::setNext(Node *Next) {
      Node::Next = Next;
    }

};

#endif
