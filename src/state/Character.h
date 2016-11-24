// Generated by dia2code
#ifndef STATE__CHARACTER__H
#define STATE__CHARACTER__H

#include <string>

namespace state {
  class SphereGrid;
  class Item;
  class Element;
}

#include "Element.h"
#include "SphereGrid.h"

namespace state {

  /// class Character - 
  class Character : public state::Element {
    // Associations
    // Attributes
  protected:
    SphereGrid* SphereGridInstance;
    int XPToNextLevel;
    int PowerToOverdrive;
    // Operations
  public:
    Character (std::string name);
    Character (std::string name, int characterID, Item* item);
    Character (int characterID, std::string name);
    void LevelUp ();
    void GainXP (int xp);
    SphereGrid* getSphereGridInstance ();
    void setSphereGridInstance (SphereGrid* spheregridinstance);
    int getXpToNextLevel ();
    void setXpToNextLevel (int xptonextlevel);
    int getPowerToOverdrive ();
    void setPowerToOverdrive (int powertooverdrive);
    void managementOverdrive (int overdiveAbility);
    Element* clone ();
    void setXPtoNextLevel (int xptonextlevel);
  };

};

#endif
