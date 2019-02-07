
#pragma once

#include "Types.h"
#include "Defines.h"

namespace RAD {

  template <class K, class V>
  class MapNode
  {
    public:
      MapNode<K, V>* next;
      K key;
      V value;

    bool operator==(const MapNode<K, V>& a) const {
        return (key == a.key);
    }
  };

  template <class K, class V>
  class LinkedMap
  {


    private:
      MapNode<K, V>* _temp;
      int _size;

    public:
      MapNode<K, V>* head;
      const MapNode<K, V>* tail = nullptr;

      LinkedMap();
      ~LinkedMap();

      bool set(K key, V value);
      bool remove(K key);
      bool contains(K key);
      V value(K key);

      uint8_t size() { return _size; };

      class Iterator {

        friend class LinkedMap;

        private:

          MapNode<K, V> *nodePtr;
          // The constructor is private, so only our friends
          // can create instances of iterators.
          Iterator(MapNode<K, V> *newPtr) : nodePtr(newPtr) {}

        public:

          Iterator() : nodePtr(nullptr) {}
          // Overload for the comparison operator !=
          bool operator!=(const Iterator& itr) const {
            return nodePtr != itr.nodePtr;
          }

          // Overload for the dereference operator *
          MapNode<K, V>& operator*() const {
            return nodePtr;
          }

          K key() const {
              nodePtr->key;
          }

          V value() const {
              nodePtr->value;
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


  template <class K, class V>
  LinkedMap<K, V>::LinkedMap() {
    _size = 0;
    head = nullptr;
  }


  template <class K, class V>
  LinkedMap<K, V>::~LinkedMap() {
    if(_size != 0) {
      _temp = head;
      MapNode<K, V>* prev = nullptr;
      while(_temp != nullptr) {
        prev = _temp;
        _temp = _temp->next;
        delete prev;
      }
    }
  }


  template <class K, class V>
  bool LinkedMap<K, V>::set(K key, V value) {
    for(_temp = head; _temp->next != nullptr && _temp->key != key; _temp = _temp->next);
    if(_temp->key == key) {
      _temp->value = value;
    } else {
      if(_size >= LS_MAX_SIZE) return false;
      MapNode<K, V>* node = new MapNode<K, V>();
      node->key = key;
      node->value = value;
      node->next = head;
      head = node;
      _size++;
    }
    return true;
  }


  template <class K, class V>
  bool LinkedMap<K, V>::remove(K key) {
    if(_size == 0) return false;
    _temp = head;
    MapNode<K, V>* prev = nullptr;
    while(_temp->next != nullptr && _temp->key != key) {
      prev = _temp;
      _temp = _temp->next;
    }
    if(_temp->key == key) {
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


  template <class K, class V>
  bool LinkedMap<K, V>::contains(K key) {
    if(_size == 0) return nullptr;
    for(_temp = head; _temp->next != nullptr && _temp->key != key; _temp = _temp->next);
    if(_temp->key == key) {
      return true;
    } else {
      return false;
    }
  }


  template <class K, class V>
  V LinkedMap<K, V>::value(K key) {
    if(_size == 0) return nullptr;
    for(_temp = head; _temp->next != nullptr && _temp->key != key; _temp = _temp->next);
    return _temp->value;
  }

}
