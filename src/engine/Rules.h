// Generated by dia2code
#ifndef ENGINE__RULES__H
#define ENGINE__RULES__H

#include <vector>

namespace state {
  class State;
  class Element;
}

#include "state/State.h"

namespace engine {

  /// class Rules - 
  class Rules {
    // Attributes
  protected:
    state::State* state;
    bool AICharNeeded;
    bool AIMonsterNeeded;
    std::vector<state::Element*> TurnList;
    int levelAI;
    // Operations
  public:
    Rules ();
    Rules (state::State* state, bool aichar, bool aimonster, int levelai);
    ~Rules ();
    bool getAICharNeeded ();
    void setAICharNeeded (bool aicharneeded);
    bool getAIMonsterNeeded ();
    void setAIMonsterNeeded (bool aimonsterneeded);
    std::vector<state::Element*> getTurnList ();
    void setTurnList (std::vector<state::Element*> turnlist);
    void init ();
    void NextTurn ();
    void setState (state::State* state);
    state::State* getState ();
    void PreviousTurn ();
    int getLevelAI ();
  };

};

#endif
