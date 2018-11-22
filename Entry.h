/**
 * Briefly explain the function of this class.
 *
 * @author 			Chen,Yi-Chou
 * @ID 				B06505006
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	National Taiwan University
 *
 */

/**
 *  A DListNode is a node in a DList (doubly-linked list).
 */

/**
 *  A class for dictionary entries.
 *
 *  DO NOT CHANGE THIS FILE.  It is part of the interface of the
 *  Dictionary ADT.
 **/

#ifndef ENTRY_H
#define ENTRY_H

template<typename K, typename V>
class Entry {
protected:
  K key;
  V value;

public:
  Entry(K k, V v) {
    key = k;
    value = v;
  }

  K& getkey() const {
    return key;
  }

  V& getvalue() const {
    return value;
  }

};

#endif
