// Generated by dia2code
#ifndef STATE__VARYTHRIX__H
#define STATE__VARYTHRIX__H

#include <string>

namespace state {
  class Element;
  class Boss;
}

#include "Boss.h"

namespace state {

  /// class Varythrix - 
  class Varythrix : public state::Boss {
    // Operations
  public:
    Varythrix ();
    ~Varythrix ();
    std::string Overdrive (Element* target);
  };

};

#endif
