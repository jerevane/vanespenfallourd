// Generated by dia2code
#ifndef AI__RANDOMCHOICE__H
#define AI__RANDOMCHOICE__H


namespace engine {
  class Engine;
};
namespace instance {
  class Fight;
};
namespace ai {
  class AI;
}

#include "AI.h"

namespace ai {

  /// class RandomChoice - 
  class RandomChoice : public ai::AI {
    // Attributes
  public:
    engine::Engine* engine;
    // Operations
  public:
    RandomChoice ();
    ~RandomChoice ();
    void run ();
    RandomChoice (instance::Fight* fight, engine::Engine* engine);
  };

};

#endif
