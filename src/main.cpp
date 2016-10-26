#include <iostream>


#include "state.hpp"

using namespace std;
using namespace instance;

int main(int argc,char* argv[]) 
{
    //Init default state
    state::State* state = new state::State();
    Application* FinalFantastique = new Application();
    FinalFantastique->play(state);

    return 0;
}
