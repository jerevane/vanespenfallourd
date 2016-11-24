// Generated by dia2code
#ifndef ENGINE__ACTION__C
#define ENGINE__ACTION__C

#include "Action.h"



namespace engine {


    Action::Action() {

    }

    Action::~Action() {

    }

    void Action::apply(state::State *state, state::Element *caster, int action,
                       state::Element *target, bool notify) {
        if(action == 15){
            Attack(caster, target);
        }
        else if (action > 15){
            UseItem(action, caster, target);
        }
        else SpellCast(action, caster, target);
        notify = true;
    }

    void Action::SpellCast(int ability, state::Element *caster, state::Element *target) {
        std::string result;
        result = caster->getAbility().LaunchAbility(ability, caster);
        TakeDamage(result,target);
    }

    void Action::Attack(state::Element *caster, state::Element *target) {
        std::string result = "P_";
        int dmg;
        dmg = caster->getStrength() *2;
        result = result + std::to_string(dmg) + "_X_-";
        TakeDamage(result, target);
    }

    void Action::TakeDamage(std::string damage, state::Element *target) {
        std::string delimiter = "_";
        std::string typedmg = damage.substr(0, damage.find(delimiter));
        std::string dmg = damage.substr(1, damage.find(delimiter));
        std::string dot = damage.substr(2, damage.find(delimiter));
        std::string isHeal = damage.substr(3, damage.find(delimiter));
        std::string dot_target = target->getDot();
        int dot_target_dmg = stoi(dot_target.substr(0,dot_target.find(delimiter)));
        int dot_target_turn = stoi(dot_target.substr(1,dot_target.find(delimiter)));
        int temp = stoi(dmg);
        // Si Soin
        if(isHeal.compare("+")){
            Heal(temp, target);
        }
            // Sinon damage
        else{
            // Prise en charge resistance + dot
            if(typedmg.compare("M") ==0) {
                temp = temp - (int) (temp * target->getMagicResist());
            }
            else {
                temp = temp - (int) (temp * target->getPhysResist());
            }
            temp = target->getHP() - temp - stoi(dot_target.substr(0,dot_target.find(delimiter)));
            if(temp<=0){
                // Si mort alors reset dot et set IsDead
                target->setIsDead(true);
                target->setHP(0);
                target->setDot("0_0");
            }
            else {
                // Inflige les degats et prise en charge dot
                target->setHP(temp);
                // Si tech inflige dot
                if (dot.compare("0") != 0) {
                    target->setDot(dot + "4");
                }
                else{
                    // Si dot enlève un tour au dot
                    if(dot_target_turn !=0){
                        dot_target_turn = dot_target_turn -1;
                        target->setDot(std::to_string(dot_target_dmg)+std::to_string(dot_target_turn));
                    }
                    else target->setDot("0_0");
                }
            }
        }
    }

    void Action::Heal(int heal, state::Element *target) {
        int hp_target = target->getHP();
        if(hp_target+heal>= target->getMaxHP()){
            target->setHP(target->getMaxHP());
        }
        else target->setHP(hp_target+heal);
    }

    void Action::exec() {

    }

    void Action::UseItem(int id_item, state::Element *caster, state::Element *target) {
        std::string result;
        result = caster->getItem()->UseItem(target,id_item);
        TakeDamage(result,target);
    }
};

#endif