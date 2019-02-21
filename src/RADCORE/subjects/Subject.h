
#pragma once

#include "../util/Defines.h"
#include "../util/Types.h"
#include "../util/LinkedSet.h"
#include "../observers/Observer.h"


namespace RAD {


  template <class T>
  class Subject {

    private:

      LinkedSet<Observer<T> *> _observers;
      T _value;

    public:

      T get() { return _value; };
      void set(T value);
      
      void notify();
      
      void add(Observer<T>* observer);
      void remove(Observer<T>* observer);

  };


  template <class T>
  void Subject<T>::set(T value) {
    _value = value;
  }


  template <class T>
  void Subject<T>::notify() {
    Node<Observer<T> *>* temp = _observers.head;
    while(temp != NULL) {
      temp->data->update();
      temp = temp->next;
    }
  }


  template <class T>
  void Subject<T>::add(Observer<T>* observer) {
    _observers.add(observer);
  }

  
  template <class T>
  void Subject<T>::remove(Observer<T>* observer) {
    for(int i = 0; i < _observers.size(); i++) {
      if(_observers.get(i) == observer) {
        _observers.remove(i);
        break;
      }
    }
  }

}
