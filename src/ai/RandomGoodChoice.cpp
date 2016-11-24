// Generated by dia2code
#ifndef AI__RANDOMGOODCHOICE__C
#define AI__RANDOMGOODCHOICE__C

#include "RandomGoodChoice.h"

namespace ai {


    RandomGoodChoice::RandomGoodChoice() {

    }

    RandomGoodChoice::~RandomGoodChoice() {

    }

    RandomGoodChoice::RandomGoodChoice(instance::Fight* fight, engine::Engine* engine) : AI(fight) {
        Id = 1;
        this->engine = engine;
        choiceList = new ChoiceList(engine);
    }

    void RandomGoodChoice::run() {
        srand((unsigned int) time(NULL));

        std::multimap<int, state::Element*> temp = choiceList->getRandomGoodChoicePossibilities();
        auto rdm = rand()%19;

        while(temp.find(rdm) == temp.end()){
            rdm = rand()%19;
        }

        ChoiceAction = temp.find(rdm)->first;
        ChoiceTarget = temp.find(rdm)->second;

        setNotify(true);
    }
};

#endif