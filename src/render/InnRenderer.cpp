// Generated by dia2code
#ifndef RENDER__INNRENDERER__C
#define RENDER__INNRENDERER__C

#include "InnRenderer.h"

namespace render {
  class Renderer;

}



namespace render {



    InnRenderer::InnRenderer(sf::RenderWindow *rwindow) : Renderer(rwindow) {
        background.loadFromFile("../res/innbackground.jpg");
        setBackground();
    }

    InnRenderer::~InnRenderer() {

    }

    void InnRenderer::render() {
        window->draw(spriteScreen);
    }

    void InnRenderer::setBackground() {
        spriteScreen.setTexture(background);

        spriteScreen.setOrigin((int)background.getSize().x/2, (int)background.getSize().y/2);
        spriteScreen.move(400, 300);
    }

    void InnRenderer::initRender() {

    }
};

#endif
