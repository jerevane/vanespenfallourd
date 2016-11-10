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

ai::RandomChoice::RandomChoice(instance::Fight *fight) : AI(fight) {
    Id = 0;

}

void ai::RandomChoice::run() {
    srand((unsigned int) time(NULL));

    std::vector<state::Element*> tab_element;
    std::vector<int> tab_utilities = fight->getRules()->getTurnList()[0]->CanUse();
    auto size = tab_utilities.size();
    auto rdm = rand()%size;
    tab_element.clear();

    tab_utilities.push_back(15);
    ChoiceAction = tab_utilities[rdm];

    size =0;
    for(int i=1; i<fight->getRules()->getTurnList().size();++i) {
        if (fight->getRules()->getTurnList()[0]->getIsCharacter() ==
            !fight->getRules()->getTurnList()[i]->getIsCharacter()) {
            tab_element.push_back(fight->getRules()->getTurnList()[i]);
            ++size;
        }
    }
    rdm = rand()%size;
    ChoiceTarget = tab_element[rdm];

}




#endif


