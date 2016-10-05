// Generated by dia2code
#ifndef STATE__ABILITY__H
#define STATE__ABILITY__H

#include <string>

namespace state {
  class Character;
  class Element;
}

#include "Character.h"
#include "Element.h"

namespace state {

  /// class Ability - 
  class Ability {
    // Associations
    // Operations
  public:
    Ability ();
    void LearnAbility (Character target, std::string learnedAbility);
    std::string Brazier ();
  };

};

#endif
