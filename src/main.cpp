#include <iostream>


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
    n8->setNextNode(n8);

    //Init ElementList
    state::ElementList* e1 = new state::ElementList();

    //Init default state
    state::State* state = new state::State(e1, n1, 0);
    Application* FinalFantastique = new Application();
    FinalFantastique->play(state);

    return 0;
}
