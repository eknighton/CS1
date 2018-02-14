#include "dsstring.h"
#include <cstring>
#include <iostream>

DSString::DSString()
{
  chars = nullptr;
  length = 0;
}
DSString::DSString(const char* cstring){ //
    chars = nullptr;
    if(strlen(cstring)>length){
        this->resize(strlen(cstring));
        strcpy(chars, cstring);
    }else{
        std::cerr << "Passed cstring has length 0.";
    }
}
DSString::DSString(const DSString& DSString){
  this->resize(DSString.length);
  char* temp = DSString.chars;
  *chars = *temp;
  delete[] temp;
}
DSString::~DSString(){
    delete[] chars; chars = nullptr;
}
DSString& DSString::operator= (const char* cstring){
    if(strlen(cstring)>length){
        this->resize(strlen(cstring));
    }
    strcpy(chars, cstring);\
    return *this;
}
DSString& DSString::operator= (const DSString& DSString){
    if (this != &DSString){
        char* temp = DSString.chars;
        this->resize(DSString.length);
        *chars = *temp;
        delete[] temp; temp = nullptr;
    }
    return *this;
    //Tried to use copy constructor, some people do it the other way around
}

DSString DSString::operator+ (const DSString& DSString){
   this->chars = strcat(chars, DSString.chars);
   this->length = 0;
   return *this; //returns dereferenced this pointer
}
DSString DSString::operator+ (const char* cstring){
   chars = new char[5000];
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

void DSString::resize(int len){
    if (chars == nullptr){ chars = new char[len]; length = len; return;}
    char* temp = new char[length];
    delete chars; chars = nullptr;
    length = len;
    chars = new char[length];
    *chars = *temp;
}

/*friend std::ostream& operator<< (std::ostream&, const DSString&){

}*/



//Avoid passing vectors, or large objects by value - which is the default


//Assignment operator, somehow...
//There was an operation that involved filestream which could be achieved with a friend function

