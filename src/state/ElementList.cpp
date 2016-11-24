// Generated by dia2code
#ifndef STATE__ELEMENTLIST__C
#define STATE__ELEMENTLIST__C

#include "ElementList.h"
#include "Character.h"
#include "Monster.h"

namespace state {

    ElementList::ElementList() {
        element.push_back(new state::Character("Claude"));
        element.push_back(new state::Monster());
        element.push_back(new state::Monster());
    }

    ElementList *ElementList::clone() {
        ElementList* e = new ElementList(element);
        return e;
    }

    ElementList::ElementList(std::vector<Element *> elements) {
        for(unsigned int i=0;i<elements.size();++i){
            element.push_back( elements.at(i)->clone());
        }
    }

};

#endif
