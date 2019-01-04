
#pragma once

#include "../util/Defines.h"
#include "../util/Types.h"
#include "Observer.h"

namespace RAD {

  template <class O, class T>
  class MethodObserver : public Observer<T> {

    protected:
    
      typedef void (O::*FuncPtr)(T);

      O* _obj;

      FuncPtr _fx;
    
    public:
      
      MethodObserver(Subject<T>* subject, O* obj, FuncPtr fx)
        : Observer<T>(subject), _obj(obj), _fx(fx) { }

      void update();

  };


  template <class O, class T>
  void MethodObserver<O, T>::update() {
    return (_obj->*_fx)(this->getSubject()->get());
  }

}
