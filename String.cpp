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
 *  A class that stores a string and generates a hash code for it.
 *
 **/

#include "String.h"
#include <string>
#include <sstream>
#include <typeinfo>
using namespace std; 
/**
 *  Construct a new String with the given variable.
 *  @param str the string by which the String stores.
 */
String::String(const string& str) {
    this->str = str;
}

/**
 *  Get the value of the string variable.
 *  @return the stored value.
 */
string String::getvalue() const {
    return str;
}

/**
 *  Returns true if "this" String and "strg" have identical values.
 *  @param strg is the second String.
 *  @return true if the string values are equal, false otherwise.
 */
bool String::equals(const String& strg) {
    if (typeid(String) != typeid(strg))
		return false;
	if (strg.getvalue() == str)
		return true;
	return false;
}

/**
 *  Returns a hash code for this String.
 *  @return a number between Integer.MIN_VALUE and Integer.MAX_VALUE.
 */
int String::hashCode() {
    // Replace the following line with your solution.
    int hashVal=0;
    int x = 0; 
    string s;
    for(int i=0;i<str.size();i++){
	s=str.substr(i,1);
    stringstream strrr(s); 
    strrr >> x; 
    	hashVal=(127*hashVal+x)%16908799;
	}
    
    return hashVal;
}
