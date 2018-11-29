
#pragma once

#include "../util/Defines.h"
#include "../util/Types.h"
#include "Observer.h"

namespace RAD {

  template <class T>
  class FunctionObserver : public Observer<T> {

    private:
    
      typedef void (*FuncPtr)(T);

      FuncPtr _fx;
    
    public:
      
      FunctionObserver(Subject<T>* subject, FuncPtr fx) : Observer<T>(subject), _fx(fx) { }

      void update();

  };


  template <class T>
  void FunctionObserver<T>::update() {
    return (_fx)(getSubject()->get());
  }

}
