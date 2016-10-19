#include <iostream>


//Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.hpp"

using namespace std;
using namespace instance;

int main(int argc,char* argv[]) 
{
    Application* FinalFantastique = new Application();
    FinalFantastique->play();
    cout << "It works !" << endl;
    cout << "Mon binome est trop fort <3" << endl;
    return 0;
}
