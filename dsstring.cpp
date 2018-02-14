#include "dsstring.h"
#include <cstring>

DSString::DSString()
{
  chars = nullptr;
  length = 0;
}
DSString::DSString(const char* cstring){ //
  strcpy(chars, cstring);//Copies the value at pointed location
}
DSString::DSString(const DSString& DSString){
  this->length = DSString.length;
  *this->chars = *DSString.chars;
  //chars = new char []; //Must occur
  //*chars = DSString.chars*;
  //*DSString.chars; //Value of string's contents -  but where does it stop, will it just give the first value?
  //Copy constructor will assign pointer to same location
  //Not assigning proper pair
  //You are passing by value, what is the address of the value?
}
DSString::~DSString(){
    chars = nullptr;
    delete[] chars;
}
DSString& DSString::operator= (const char* cstring){
    strcpy(chars, cstring);
    this->length = 0;
    return *this;
}
DSString& DSString::operator= (const DSString& DSString){
    //Delete data
    this->length = DSString.length;
    *this->chars = *DSString.chars;
    return *this;
    //Tried to use copy constructor, some people do it the other way around
}

DSString DSString::operator+ (const DSString& DSString){
   this->chars = strcat(chars, DSString.chars);
   this->length = 0;
   return *this; //returns dereferenced this pointer
}
DSString DSString::operator+ (const char* cstring){
   this->chars = strcat(chars, cstring);
   this->length = 0;
   return *this; //returns dereferenced this pointer
}
DSString DSString::operator+ (const char achar){
   this->chars = strcat(chars, ""+achar);
   this->length = 0;
   return *this; //returns dereferenced this pointer
}

bool DSString::operator== (const char* cstring){
    return strcmp(chars, cstring)==0;//Returns 0 if true
}
bool DSString::operator== (const DSString& DSString){
    return strcmp(chars, DSString.chars)==0;//Returns 0 if true
}

bool DSString::operator> (const DSString& DSString){ //Alphabetising
   for (int i = 0; i < length; i++){
        if (chars[i] > DSString.chars[i]){
            return true;
        }else if (chars[i] < DSString.chars[i]){
            return false;
        }
   }
}

char& DSString::operator[] (const int length){
    delete[] chars;
    this->chars = new char[length];
}
int DSString::getLength(){
    return length;
}
DSString DSString::substring(int start, int numChars){
    DSString substring;
    for(start; start < length; start++){
        substring.chars = strcat(substring.chars, (const char*)chars[start]);
    }
    return substring;
}
char* DSString::c_str(){
    return chars;
}
/*friend std::ostream& operator<< (std::ostream&, const DSString&){

}*/



//Avoid passing vectors, or large objects by value - which is the default


//Assignment operator, somehow...
//There was an operation that involved filestream which could be achieved with a friend function

