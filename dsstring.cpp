#include "dsstring.h"
#include <cstring>

DSString::DSString()
{
  chars = nullptr;
}
DSString::DSString(char* cstring){
    chars = cstring;
}
DSString::DSString(const DSString& DSString){
  *DSString.chars; //Value of string's contents -  but where does it stop, will it just give the first value?


  //Copy constructor will assign pointer to same location
  //Not assigning proper pair
  //You are passing by value, what is the address of the value?
}
DSString::~DSString(){
    chars = nullptr;
    delete[] chars;
}

//Avoid passing vectors, or large objects by value


//Assignment operator, somehow...
//There was an operation that involved filestream which could be achieved with a friend function

