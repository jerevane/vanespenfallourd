// Generated by dia2code
#ifndef STATE__ELEMENT__H
#define STATE__ELEMENT__H

#include <string>
#include <vector>

namespace state {
  class Ability;
}

#include "Ability.h"

namespace state {

  /// class Element - 
  class Element {
    // Attributes
  protected:
    int HP;
    int MP;
    int MaxHP;
    int MaxMP;
    int Strength;
    int Agility;
    int Intelligence;
    bool IsDead;
    float MagicResist;
    float PhysResist;
    int Level;
    Ability abilities;
    std::string Dot;
    bool IsCharacter;
    std::string name;
    // Operations
  public:
    Element ();
    int getHP ();
    void setHP (int hp);
    int getMP ();
    void setMP (int mp);
    int getMaxHP ();
    void setMaxHP (int maxhp);
    int getMaxMP ();
    void setMaxMP (int maxmp);
    int getStrength ();
    void setStrength (int strength);
    int getAgility ();
    void setAgility (int agility);
    int getIntelligence ();
    void setIntelligence (int intelligence);
    bool getIsDead ();
    void setIsDead (bool isdead);
    float getMagicResist ();
    void setMagicResist (float magicresist);
    float getPhysResist ();
    void setPhysResist (float physresist);
    int getLevel ();
    void setLevel (int level);
    std::string getDot ();
    void setDot (std::string dot);
    bool getIsCharacter ();
    void setIsCharacter (bool ischaracter);
    void setName (std::string name);
    Ability getAbility ();
    std::vector<int> CanUse ();
  };

};

#endif
