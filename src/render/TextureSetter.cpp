// Generated by dia2code
#ifndef RENDER__TEXTURESETTER__C
#define RENDER__TEXTURESETTER__C

#include "TextureSetter.h"
#include <map>
#include <iostream>

namespace sf {
  class Texture;
};
namespace state {
  class State;
}

#include "state/State.h"

namespace render {


    TextureSetter::TextureSetter() {
        nodeTextureMap.insert(std::pair<std::string, sf::Texture*>("0_Midgare_150_450", new sf::Texture));
        nodeTextureMap.insert(std::pair<std::string, sf::Texture*>("1_Nibelheim_250_350", new sf::Texture));
        nodeTextureMap.insert(std::pair<std::string, sf::Texture*>("2_Besaid_100_150", new sf::Texture));
        nodeTextureMap.insert(std::pair<std::string, sf::Texture*>("3_Gagazet_300_200", new sf::Texture));
        nodeTextureMap.insert(std::pair<std::string, sf::Texture*>("4_Winhill_550_280", new sf::Texture));
        nodeTextureMap.insert(std::pair<std::string, sf::Texture*>("5_Terra_650_350", new sf::Texture));
        nodeTextureMap.insert(std::pair<std::string, sf::Texture*>("6_Kilika_750_325", new sf::Texture));
        nodeTextureMap.insert(std::pair<std::string, sf::Texture*>("7_Lindblum_700_200", new sf::Texture));
        nodeTextureMap.insert(std::pair<std::string, sf::Texture*>("8_Zanarkand_350_50", new sf::Texture));

        for(auto i : nodeTextureMap)
        {
            i.second->loadFromFile("res/red_circle.png");

        }

        sf::Texture* t1 = new sf::Texture();
        t1->loadFromFile("res/sprite_0.png");
        elementTextureMap.insert(std::pair<int, sf::Texture*>(0, t1));
        sf::Texture* t2 = new sf::Texture();
        t2->loadFromFile("res/sprite_0.png");
        elementTextureMap.insert(std::pair<int, sf::Texture*>(1, t2));
        sf::Texture* t3 = new sf::Texture();
        t3->loadFromFile("res/sprite_0.png");
        elementTextureMap.insert(std::pair<int, sf::Texture*>(2, t3));
        sf::Texture* t4 = new sf::Texture();
        t4->loadFromFile("res/sprite_0.png");
        elementTextureMap.insert(std::pair<int, sf::Texture*>(3, t4));
        sf::Texture* t5 = new sf::Texture();
        t5->loadFromFile("res/sprite_0.png");
        elementTextureMap.insert(std::pair<int, sf::Texture*>(4, t5));
        sf::Texture* t6 = new sf::Texture();
        t6->loadFromFile("res/sprite_0.png");
        elementTextureMap.insert(std::pair<int, sf::Texture*>(5, t6));
        sf::Texture* t7 = new sf::Texture();
        t7->loadFromFile("res/sprite_0.png");
        elementTextureMap.insert(std::pair<int, sf::Texture*>(6, t7));
        sf::Texture* t8 = new sf::Texture();
        t8->loadFromFile("res/sprite_0.png");
        elementTextureMap.insert(std::pair<int, sf::Texture*>(7, t8));
        sf::Texture* t9 = new sf::Texture();
        t9->loadFromFile("res/sprite_0.png");
        elementTextureMap.insert(std::pair<int, sf::Texture*>(8, t9));
        sf::Texture* t10 = new sf::Texture();
        t10->loadFromFile("res/sprite_0.png");
        elementTextureMap.insert(std::pair<int, sf::Texture*>(9, t10));


    }

    TextureSetter::~TextureSetter() {

    }

    sf::Texture TextureSetter::getTexture(state::ElementList* eList) {

        return sf::Texture();
    }
};

#endif
