// Generated by dia2code
#ifndef STATE__ELEMENT__H
#define STATE__ELEMENT__H

#include <string>
#include <map>

namespace state {
  class Element;
}


namespace state {

  /// class Element - 
  class Element {
    // Attributes
  public:
    std::map<std::string, int> abilities;
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
    // Operations
  public:
    std::string SpellCast (std::string abilityDamage, Element caster, Element target);
    std::string Attack (Element caster, Element target);
    void TakeDamage (std::string damage, Element target);
    void Heal (int heal, Element target);
    Element ();

      const std::map<std::string, int> &getAbilities() const;

      void setAbilities(const std::map<std::string, int> &abilities);

      int getHP() const;

      void setHP(int HP);

      int getMP() const;

      void setMP(int MP);

      int getMaxHP() const;

      void setMaxHP(int MaxHP);

      int getMaxMP() const;

      void setMaxMP(int MaxMP);

      int getStrength() const;

      void setStrength(int Strength);

      int getAgility() const;

      void setAgility(int Agility);

      int getIntelligence() const;

      void setIntelligence(int Intelligence);

      bool isIsDead() const;

      void setIsDead(bool IsDead);

      float getMagicResist() const;

      void setMagicResist(float MagicResist);

      float getPhysResist() const;

      void setPhysResist(float PhysResist);

      int getLevel() const;

      void setLevel(int Level);
  };

};

#endif
