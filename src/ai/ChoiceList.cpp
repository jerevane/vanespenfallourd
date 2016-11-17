// Generated by dia2code
#ifndef AI__CHOICELIST__C
#define AI__CHOICELIST__C

#include "ChoiceList.h"
#include "state/State.h"
#include "instance/Fight.h"


namespace ai {


    ChoiceList::ChoiceList() {

    }

    ChoiceList::~ChoiceList() {

    }

    ChoiceList::ChoiceList(instance::Fight *fight) {
        allAction.clear();
        ennemyTarget.clear();
        allyTarget.clear();

        allAction = fight->getRules()->getTurnList().at(0)->CanUse();

        for(int i=1; i<fight->getRules()->getTurnList().size();++i) {
            if (fight->getRules()->getTurnList().at(0)->getIsCharacter() ==
                !fight->getRules()->getTurnList()[i]->getIsCharacter()) {
                ennemyTarget.push_back(fight->getRules()->getTurnList().at(i));
            }
            else allyTarget.push_back(fight->getRules()->getTurnList().at(i));
        }
    }

    std::multimap<int, state::Element *> ChoiceList::getRandomChoicePossibilities() {
        std::multimap<int,state::Element* > result;
        result.clear();

        for(int i=0; i<allAction.size(); ++i){
            if( i == 3|4|5|16|17|18 ){
                for(int j=0; j<allyTarget.size(); ++j){
                    result.insert(std::make_pair(i,allyTarget.at(j)));
                }
            }
            else{
                for(int j=0; j<ennemyTarget.size(); ++j){
                    result.insert(std::make_pair(i,ennemyTarget.at(j)));
                }
            }

        }

        return result;
    }

    std::multimap<int, state::Element *> ChoiceList::getRandomGoodChoicePossibilities() {
        std::multimap<int, state::Element *> result = getRandomChoicePossibilities();
        std::vector<state::Element*> temp;
        temp.clear();

        for(int i=0; i<19; ++i){
            int j=0,k=1,t=0;
            auto iter = result.find(i);
            if(iter != result.end()){
                // Construction du tableau des targets des actions
                for (auto it=result.equal_range(i).first; it!=result.equal_range(i).second; ++it){
                    temp.at((unsigned long) t) = it->second;
                    ++t;
                }
                switch(i){
                    case 0|1|2|6|7 :
                        // Spell Offensif -> best choice = lower HP && lower magic resist
                        // Tri ordre croissant HP puis erase si magic resist >0.6
                        // S'il existe plus d'une possibilité erase les suivantes

                        while(j<temp.size()-1){
                            if(temp.at((unsigned long) j)->getHP() > temp.at((unsigned long) k)->getHP()){
                                std::swap(temp.at((unsigned long) j), temp.at((unsigned long) k));
                            }
                            ++k;
                            if(k==temp.size()){
                                ++j;
                                k=j+1;
                            }
                        }
                        for(int l=0; l<temp.size(); ++l){
                            if(temp.at((unsigned long) l)->getMagicResist() > 0.6){
                                // On cherche l'équivalent dans la multimap
                                iter = result.equal_range(i).second;
                                while(iter->second != temp.at((unsigned long) l)) ++iter;
                                result.erase(iter);
                                temp.erase(temp.begin()+l);
                                --l;
                            }
                        }
                        // Attention, s'il n'existe plus de possibilité on supprime la key
                        if(temp.size()>=1){
                            while(temp.size()!=1){
                                // On cherche l'équivalent dans la multimap
                                iter = result.equal_range(i).second;
                                while(iter->second != temp.at(1)) ++iter;
                                result.erase(iter);
                                temp.erase(temp.begin()+1);

                            }
                        }
                        else result.erase(i);

                        // Fin Spell Offensif

                        // Spell Defensif
                    case 3|5|8|16|18 :
                        // Type Heal
                        // Best choice = target lower HP
                        // Keep only the lower

                        while(j<temp.size()-1){
                            if(temp.at((unsigned long) j)->getHP() > temp.at((unsigned long) k)->getHP()){
                                std::swap(temp.at((unsigned long) j), temp.at((unsigned long) k));
                            }
                            ++k;
                            if(k==temp.size()){
                                ++j;
                                k=j+1;
                            }
                        }
                        // Attention, s'il n'existe plus de possibilités on supprime la key
                        if(temp.size()>=1){
                            while(temp.size()!=1){
                                // On cherche l'équivalent dans la multimap
                                iter = result.equal_range(i).second;
                                while(iter->second != temp.at(1)) ++iter;
                                result.erase(iter);
                                temp.erase(temp.begin()+1);

                            }
                        }
                        else result.erase(i);

                    case 4|17 :
                        // Type Rez
                        // Best choice = ally if he is dead
                        // Erase all other possibilities

                        for(int l=0; l<temp.size(); ++l){
                            if(!temp.at((unsigned long) l)->getIsDead()){
                                // On cherche l'équivalent dans la multimap
                                iter = result.equal_range(i).second;
                                while(iter->second != temp.at((unsigned long) l)) ++iter;
                                result.erase(iter);
                                temp.erase(temp.begin()+l);
                                --l;
                            }
                        }
                        if(temp.size()>=1){
                            while(temp.size()!=1){
                                // On cherche l'équivalent dans la multimap
                                iter = result.equal_range(i).second;
                                while(iter->second != temp.at(1)) ++iter;
                                result.erase(iter);
                                temp.erase(temp.begin()+1);

                            }
                        }
                        else result.erase(i);

                        // Fin Spell Defensif

                    case 9|10|11|12|13|14 :
                        // Attack Offensif
                        // Best choice = lower HP && lower physic resist

                        while(j<temp.size()-1){
                            if(temp.at((unsigned long) j)->getHP() > temp.at((unsigned long) k)->getHP()){
                                std::swap(temp.at((unsigned long) j), temp.at((unsigned long) k));
                            }
                            ++k;
                            if(k==temp.size()){
                                ++j;
                                k=j+1;
                            }
                        }
                        for(int l=0; l<temp.size(); ++l){
                            if(temp.at((unsigned long) l)->getPhysResist() > 0.6){
                                // On cherche l'équivalent dans la multimap
                                iter = result.equal_range(i).second;
                                while(iter->second != temp.at((unsigned long) l)) ++iter;
                                result.erase(iter);
                                temp.erase(temp.begin()+l);
                                --l;
                            }
                        }
                        // Attention, s'il n'existe plus de possibilité on supprime la key
                        if(temp.size()>=1){
                            while(temp.size()!=1){
                                // On cherche l'équivalent dans la multimap
                                iter = result.equal_range(i).second;
                                while(iter->second != temp.at(1)) ++iter;
                                result.erase(iter);
                                temp.erase(temp.begin()+1);

                            }
                        }
                        else result.erase(i);

                        // Fin Attack Offensif

                    default:break;
                }
            }
        }


        return result;
    }
};

#endif
