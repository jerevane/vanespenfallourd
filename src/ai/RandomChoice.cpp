// Generated by dia2code
#ifndef AI__RANDOMCHOICE__C
#define AI__RANDOMCHOICE__C

#include "RandomChoice.h"
#include "stdlib.h"
#include "time.h"


ai::RandomChoice::RandomChoice() {

}

ai::RandomChoice::~RandomChoice() {

}

ai::RandomChoice::RandomChoice(engine::Engine* engine) : AI(engine) {
    Id = 0;

}

void ai::RandomChoice::run() {
    srand((unsigned int) time(NULL));

    std::vector<state::Element*> tab_element;
    std::vector<int> tab_utilities = engine->getRules()->getTurnList()[0]->CanUse();
    auto size = tab_utilities.size();
    auto rdm = rand()%size;
    tab_element.clear();

    tab_utilities.push_back(15);
    ChoiceAction = tab_utilities[rdm];

    size =0;
    for(int i=1; i<engine->getRules()->getTurnList().size();++i) {
        if (engine->getRules()->getTurnList()[0]->getIsCharacter() ==
            !engine->getRules()->getTurnList()[i]->getIsCharacter()) {
            tab_element.push_back(engine->getRules()->getTurnList()[i]);
            ++size;
        }
    }
    rdm = rand()%size;
    ChoiceTarget = tab_element[rdm];

}




#endif


