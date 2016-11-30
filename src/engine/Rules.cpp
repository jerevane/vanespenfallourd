// Generated by dia2code
#ifndef INSTANCE__RULES__C
#define INSTANCE__RULES__C

#include <iostream>
#include "Rules.h"
#include "../state/State.h"
#include "algorithm"


namespace engine {


    Rules::Rules() {

    }

    Rules::Rules(state::State *state, bool aichar, bool aimonster, int levelai) {
        this->state = state;
        AICharNeeded = aichar;
        AIMonsterNeeded = aimonster;
        levelAI = levelai;
        init();
    }

    Rules::~Rules() {

    }

    bool Rules::getAICharNeeded() {
        return AICharNeeded;
    }

    void Rules::setAICharNeeded(bool aicharneeded) {
        AICharNeeded = aicharneeded;
    }

    bool Rules::getAIMonsterNeeded() {
        return AIMonsterNeeded;
    }

    void Rules::setAIMonsterNeeded(bool aimonsterneeded) {
        AIMonsterNeeded = aimonsterneeded;
    }

    std::vector<state::Element *> Rules::getTurnList() {
        return TurnList;
    }

    void Rules::setTurnList(std::vector<state::Element *> turnlist) {
        TurnList = turnlist;
    }

    void Rules::init() {
        std::vector<int> tab_agi_element;
        int i,j;
        tab_agi_element.clear();
        TurnList.clear();

        for(i=0; i<state->getElementList()->element.size();++i){
            tab_agi_element.push_back(state->getElementList()->element[i]->getAgility());
            TurnList.push_back(state->getElementList()->element[i]);
        }

        i=0;j=1;
        while(i<state->getElementList()->element.size()-1){
            if(tab_agi_element[i]<tab_agi_element[j]){
                std::swap(tab_agi_element[i],tab_agi_element[j]);
                std::swap(TurnList[i], TurnList[j]);

            }
            ++j;
            if(j==state->getElementList()->element.size()){
                ++i;
                j=i+1;
            }
        }

        std::cout << std::to_string(TurnList.size()) << std::endl;

    }

    void Rules::NextTurn() {
        std::vector<state::Element*> Turnlist = TurnList;
        state::Element* element_temp = Turnlist.at(0);

        Turnlist.erase(Turnlist.begin());
        Turnlist.push_back(element_temp);

        TurnList.swap(Turnlist);
        if(TurnList.at(0)->getIsDead()) NextTurn();

    }

    void Rules::setState(state::State *state) {
        this->state = state;
    }

    state::State *Rules::getState() {
        return state;
    }

    void Rules::PreviousTurn() {
        std::vector<state::Element*> Turnlist = TurnList;
        state::Element* element_temp = Turnlist.at(Turnlist.size()-1);

        Turnlist.pop_back();
        Turnlist.insert(Turnlist.begin(), element_temp);

        TurnList.swap(Turnlist);
        if(TurnList.at(0)->getIsDead()) PreviousTurn();
    }

    int Rules::getLevelAI() {
        return levelAI;
    }
};

#endif