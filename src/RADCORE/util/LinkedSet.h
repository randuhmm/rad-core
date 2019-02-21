
#pragma once

#include "Types.h"
#include "Defines.h"


namespace RAD {

  template <class T>
  class Node
  {
    public:
      Node<T>* next;
      T data;
  };

  template <class T>
  class LinkedSet
  {

    private:
      Node<T>* _temp;
      int _size;

    public:
      Node<T>* head;
      Node<T>* tail = nullptr;

      LinkedSet();
      ~LinkedSet();

      bool add(T data);
      bool remove(T data);
      uint8_t find(T data);
      bool contains(T data);

      uint8_t size() { return _size; };

      T get(uint8_t index);

      class Iterator {

        friend class LinkedSet;

        private:

          Node<T> *nodePtr;
          // The constructor is private, so only our friends
          // can create instances of iterators.
          Iterator(Node<T> *newPtr) : nodePtr(newPtr) {}

        public:

          Iterator() : nodePtr(nullptr) {}
          // Overload for the comparison operator !=
          bool operator!=(const Iterator& itr) const {
            return nodePtr != itr.nodePtr;
          }

          // Overload for the dereference operator *
          T& operator*() const {
            return nodePtr->data;
          }

          // Overload for the postincrement operator ++
          Iterator operator++(int) {
            Iterator temp = *this;
            nodePtr = nodePtr->next;
            return temp;
          }
      };

      Iterator begin() const {
        return Iterator(head);
      }

      Iterator end() const {
        return Iterator(tail);
      }

  };


  template <class T>
  LinkedSet<T>::LinkedSet() {
    _size = 0;
    head = nullptr;
  }


  template <class T>
  LinkedSet<T>::~LinkedSet() {
    if(_size != 0) {
      _temp = head;
      Node<T>* prev = nullptr;
      while(_temp != nullptr) {
        prev = _temp;
        _temp = _temp->next;
        delete prev;
      }
    }
  }


  template <class T>
  bool LinkedSet<T>::add(T data) {
    if(_size >= LS_MAX_SIZE || contains(data)) return false;
    Node<T>* node = new Node<T>();
    node->data = data;
    node->next = head;
    head = node;
    _size++;
    return true;
  }


  template <class T>
  bool LinkedSet<T>::remove(T data) {
    if(_size == 0) return false;
    _temp = head;
    Node<T>* prev = nullptr;
    while(_temp->next != nullptr && _temp->data != data) {
      prev = _temp;
      _temp = _temp->next;
    }
    if(_temp->data == data) {
      if(prev == nullptr) {
        head = _temp->next;
      } else {
        prev->next = _temp->next;
      }
      _size -= 1;
      delete _temp;
      return true;
    }
    return false;
  }


  template <class T>
  uint8_t LinkedSet<T>::find(T data) {
    if(_size == 0) return LS_ITEM_NOT_FOUND;
    uint8_t i;
    for(i = 0, _temp = head; _temp->next != nullptr && _temp->data != data; _temp = _temp->next, i++);
    if(_temp->data == data) {
      return i;
    } else {
      return LS_ITEM_NOT_FOUND;
    }
  }


  template <class T>
  bool LinkedSet<T>::contains(T data) {
    return find(data) != LS_ITEM_NOT_FOUND;
  }


  template <class T>
  T LinkedSet<T>::get(uint8_t index) {
    if(_size == 0 || index >= _size) return nullptr;
    uint8_t i;
    for(i = 0, _temp = head; _temp->next != nullptr && i < index; _temp = _temp->next, i++);
    return _temp->data;
  }

}
