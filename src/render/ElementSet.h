// Generated by dia2code
#ifndef RENDER__ELEMENTSET__H
#define RENDER__ELEMENTSET__H


namespace render {
  class Element;
}

namespace render {

  /// class ElementSet - 
  class ElementSet {
    // Operations
  public:
    ElementSet ();
    ~ElementSet ();
    const char* getImageFile ( );
    Element*  getElement (state::Entity* entity);
  };

};

#endif
