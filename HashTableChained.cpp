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

#include "HashTableChained.h"
#include "Integer.h"
#include "Double.h"
#include "String.h"
#include "Entry.h"
#include <list>

/**
 *  Construct a new empty hash table intended to hold roughly sizeEstimate
 *  entries.  (The precise number of buckets is up to you, but we recommend
 *  you use a prime number, and shoot for a load factor between 0.5 and 1.)
 **/
template<typename K, typename V>
HashTableChained<K, V>::HashTableChained(int sizeEstimate) {
	this->BUCKET = static_cast<int>(sizeEstimate / 0.75); 
	this->table = new list<Entry<K, V> >[this->BUCKET]; 
	this->noe=0;
    // Your solution here.
}

/**
 *  Construct a new empty hash table with a default size.  Say, a prime in
 *  the neighborhood of 100.
 **/
template<typename K, typename V>
HashTableChained<K, V>::HashTableChained() {
    this->BUCKET = static_cast<int>(sizeestimate / 0.75);
	this->table = new list<Entry<K, V> >[this->BUCKET];  
	this->noe=0;
	// Your solution here.
}

/**
 *  Converts a hash code in the range Integer.MIN_VALUE...Integer.MAX_VALUE
 *  to a value in the range 0...(size of hash table) - 1.
 *
 *  This function should have package protection (so we can test it), and
 *  should be used by insert, find, and remove.
 **/
template<typename K, typename V>
int HashTableChained<K, V>::compFunction(int code) {
	code=(233333*code+23333333)%16908799;
	if(code<0){
		code = (code+16908799)%16908799;
	}
    // Replace the following line with your solution.
    return code%nob;
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template<typename K, typename V>
int HashTableChained<K, V>::size() {
	// Replace the following line with your solution.
    return this->BUCKET;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template<typename K, typename V>
bool HashTableChained<K, V>::isEmpty() {
    // Replace the following line with your solution.
    return this->noe==0;
}

/**
 *  Create a new Entry object referencing the input key and associated value,
 *  and insert the entry into the dictionary.
 *  Multiple entries with the same key (or even the same key and
 *  value) can coexist in the dictionary.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the key by which the entry can be retrieved.
 *  @param value an arbitrary object.
 **/
template<typename K, typename V>
void HashTableChained<K, V>::insert(const K& key, const V& value) {
    Entry<K,V> entry;
	entry->key = key;
	entry->value = value;
	int index = compFunction(key.hashCode());
	this->table[index].push_back(key); 
	this->noe++;
	return entry;
    // Replace the following line with your solution.
}

/**
 *  Search for an entry with the specified key.  If such an entry is found,
 *  return true; otherwise return false.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 *  @return true if an entry containing the key is found, or false if
 *          no entry contains the specified key.
 **/
template<typename K, typename V>
bool HashTableChained<K, V>::find(const K& key) {
	int index = compFunction(key.hashCode()); 
    list <int> :: iterator i; 
for (i = this->table[index].begin(); i != this->table[index].end(); i++) { 
	if (*i == key) 
	return true; 
	else
	return false;
} 

}

/**
 *  Remove an entry with the specified key.  If such an entry is found,
 *  remove it from the table.
 *  If several entries have the specified key, choose one arbitrarily, then
 *  remove it.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 */
template<typename K, typename V>
void HashTableChained<K, V>::remove(const K&  key) {
    int index = compFunction(key.hashCode()); 

// find the key in (inex)th list 
list <int> :: iterator i; 
for (i = this->table[index].begin(); 
		i != this->table[index].end(); i++) { 
	if (*i == key) 
	break; 
} 

// if key is found in hash table, remove it 
if (i != this->table[index].end()) 
	this->table[index].erase(i); 
	  /*catch (const InvalidNodeException &e)
	  {
		System::err::println(L"remove: " + e);
		exit(0);
	  }
	}*/ 
	// Replace the following line with your solution.
}

/**
 *  Remove all entries from the dictionary.
 */
template<typename K, typename V>
void HashTableChained<K, V>::makeEmpty() {

    this->table = new list<int>[this->BUCKET]; 
    this->noe = 0;
	// Your solution here.
}
