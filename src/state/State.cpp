// Generated by dia2code
#ifndef STATE__STATE__C
#define STATE__STATE__C

#include "State.h"

namespace state {


    State::State() {

    }

    State::State(ElementList *elementList,state::Node *node, int id) {
        this->elementlist = elementList;
        this->node = node;
        Id = id;
    }

    State::~State() {

    }

    void State::setNode(state::Node *node) {
        this->node = node;
    }

    state::Node *State::getNode() {
        return node;
    }


    ElementList *State::getElementList() {
        return elementlist;
    }

    void State::setElementList(ElementList *elementlist) {
        this->elementlist = elementlist;
    }

    int State::getId() {
        return Id;
    }

    void State::setId(int id) {
        Id = id;
    }

    bool State::getPlayerFinishedTurn() {
        return playerFinishedTurn;
    }

    void State::setPlayerFinishedTurn(bool pft) {
        playerFinishedTurn = pft;
    }

    State* State::clone() {
        State* s = new State(this->elementlist->clone(), this->node->clone(), this->Id);
        return s;
    }

};

#endif
