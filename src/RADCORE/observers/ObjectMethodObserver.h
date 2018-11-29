
#pragma once

#include "../util/Defines.h"
#include "../util/Types.h"
#include "Observer.h"

namespace RAD {

  class Feature;

  template <class O, class K, class T>
  class ObjectMethodObserver : public Observer<T> {

    protected:
    
      typedef void (K::*FuncPtr)(O*, T);

      K* _klass;

      FuncPtr _fx;

      O* _obj;
    
    public:
      
      ObjectMethodObserver(O* obj, Subject<T>* subject, K* klass, FuncPtr fx)
        : Observer<T>(subject), _obj(obj), _klass(klass), _fx(fx) { }

      void update();

  };


  template <class O, class K, class T>
  void ObjectMethodObserver<O, K, T>::update() {
    return (_klass->*_fx)(_obj, getSubject()->get());
  }

}
