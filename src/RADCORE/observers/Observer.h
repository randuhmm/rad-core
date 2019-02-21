
#pragma once

#include "../util/Defines.h"
#include "../util/Types.h"

namespace RAD {
  
  // Forward declaration of Subject class
  template <class T>
  class Subject;

  template <class T>
  class Observer {

    private:

      Subject<T>* _subject;

    public:

      Observer(Subject<T>* subject) {
          _subject = subject;
          _subject->add(this);
      }
      virtual ~Observer() {};
      virtual void update() = 0;

    protected:

      Subject<T>* getSubject() {
          return _subject;
      }

  };

}
