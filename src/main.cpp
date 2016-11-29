#include <iostream>
#include <engine/Engine.h>
#include <thread>


#include "state.hpp"

using namespace std;
using namespace instance;

int main(int argc,char* argv[]) 
{
    //Init Node chain
    state::Node* n1 = new state::Node(0);
    n1->setPreviousNode(n1);
    state::Node* n2 = new state::Node(n1, 1);
    n1->setNextNode(n2);
    state::Node* n3 = new state::Node(n2, 2);
    n2->setNextNode(n3);
    state::Node* n4 = new state::Node(n3, 3);
    n3->setNextNode(n4);
    state::Node* n5 = new state::Node(n4, 4);
    n4->setNextNode(n5);
    state::Node* n6 = new state::Node(n5, 5);
    n5->setNextNode(n6);
    state::Node* n7 = new state::Node(n6, 6);
    n6->setNextNode(n7);
    state::Node* n8 = new state::Node(n7, 7);
    n7->setNextNode(n8);
    state::Node* n9 = new state::Node(n8, 8);
    n8->setNextNode(n9);
    n9->setNextNode(n9);

    //Init ElementList
    state::ElementList* e1 = new state::ElementList();

    //Init default state
    state::State* state = new state::State(e1, n1, 0);

    //Init default engine
    engine::Engine* engine = new engine::Engine();
    // first bool = aichar , second bool = aimonster, int = level AI
    //                                                      0 -> AI = RandomChoice
    //                                                      1 -> AI = RandomGoodChoice
    //                                                      2 -> AI = SmartChoice
    // abilities and items are configured in ElementList.cpp
    engine::Rules* rules = new engine::Rules(state, false, true, 1);
    engine->setRules(rules);
    engine->getRules()->setState(state);
    engine->getRules()->init();
    engine->turnInit(engine->getRules()->getTurnList()[0]);

    //Init Engine thread
    std::thread engThread(&engine::Engine::flush, engine);


    Application* FinalFantastique = new Application(state, engine);
    std::cout << std::to_string(e1->element.size()) << std::endl;

    FinalFantastique->play(state, engine);

    engThread.join();

    return 0;
}


