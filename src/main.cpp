#include <iostream>


//Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>


// Fin test SFML

#include "state.hpp"

using namespace std;
using namespace instance;

int main(int argc,char* argv[]) 
{
    Application* FinalFantastique = new Application();
    FinalFantastique->play();

    return 0;
}
