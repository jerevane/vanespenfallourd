// Generated by dia2code
#ifndef STATE__DOGNAR__H
#define STATE__DOGNAR__H

#include <string>

namespace state {
  class Element;
  class Boss;
}

#include "Element.h"
#include "Boss.h"

namespace state {

  /// class Dognar - 
  class Dognar : public state::Boss {
    // Operations
  public:
    Dognar ();
    std::string Overdrive (Element target);
  };

};

#endif
