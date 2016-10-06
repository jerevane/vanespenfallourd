// Generated by dia2code
#ifndef STATE__BOSS__H
#define STATE__BOSS__H

#include <string>

namespace state {
  class Element;
  class Monster;
}

#include "Element.h"
#include "Monster.h"

namespace state {

  /// class Boss - 
  class Boss : public state::Monster {
    // Attributes
  protected:
    int PowerToOverdrive;
    // Operations
  public:
    Boss ();
    virtual std::string Overdrive (Element target) = 0;
  };

};

#endif
