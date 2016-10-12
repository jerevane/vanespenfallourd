// Generated by dia2code
#ifndef STATE__ELEMENTFACTORY__H
#define STATE__ELEMENTFACTORY__H

#include <map>

namespace state {
  class AElementAlloc;
  class ElementList;
}

#include "ElementList.h"
#include "AElementAlloc.h"

namespace state {

  /// class ElementFactory - 
  class ElementFactory {
    // Associations
    // Attributes
  protected:
    std::map<char,AElementAlloc*> list;
    // Operations
  public:
    ~ElementFactory ();
    Element* const newInstance (char id);
    void registerType (AElementAlloc* a, char id);

      const std::map<char, AElementAlloc *> &getList() const;

      void setList(const std::map<char, AElementAlloc *> &list);
  };


};

#endif
