

// Generated by dia2code
#ifndef ENGINE__ENGINE__C
#define ENGINE__ENGINE__C


namespace engine {
  class Rules;
  class Command;


}

#include <iostream>
#include "Engine.h"

namespace engine {
    void Engine::addCmd(Command* cmd) {
        if (!cmd)
            throw std::runtime_error("Null command");
      std::lock_guard<std::mutex> lock(mtx);
      commandsToSwap.push_back(cmd);
    }

    Engine::Engine() {
    }

    Engine::~Engine() {

    }

    void Engine::turnInit(state::Element *element) {

      rules->getState()->currentTurn = element;
      rules->getState()->currentAction = "attack";
      rules->getState()->setPlayerFinishedTurn(false);
      if (!element->getIsCharacter())
      {
          //IA stuff here
      }
    }

    Rules* Engine::getRules() {
      return rules;
    }

    void Engine::setRules(Rules* rules) {
      this->rules = rules;
    }

    void Engine::flush() {
        std::cout << "Thread launched" << std::endl;
        while(1) {
            {
                std::lock_guard<std::mutex> lock(mtx);
                std::swap(commandsToFlush, commandsToSwap);
            }
            for (auto i : commandsToFlush) {
                i->exec();
            }
            commandsToFlush.clear();
        }
    }

};

#endif
