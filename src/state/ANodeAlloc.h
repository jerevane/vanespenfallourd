// Generated by dia2code
#ifndef STATE__ANODEALLOC__H
#define STATE__ANODEALLOC__H


namespace state {
  class Node;
}

namespace state {

  /// class ANodeAlloc - 
  class ANodeAlloc {
    // Operations
  public:
    ~ANodeAlloc ();
    virtual Node* newInstance () = 0;
  };

};

#endif
