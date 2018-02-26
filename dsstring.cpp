#include "dsstring.h"
#include <cstring>
#include <iostream>

DSString::DSString()
{
  chars = nullptr;
}
DSString::DSString(const char* cstring){ //
    chars = strdup(cstring);
}
DSString::DSString(const DSString& DSString){
    chars = strdup(DSString.chars);
}
DSString::~DSString(){
    delete[] chars; chars = nullptr;
}
DSString& DSString::operator= (const char* cstring){
    if (cstring != this->c_str()){
        delete[] chars;
    }
    chars = strdup(cstring);
    return *this;
}
DSString& DSString::operator= (const DSString& DSString){
    chars = strdup(DSString.chars);
    return *this;
    //Tried to use copy constructor, some people do it the other way around
}

DSString DSString::operator+ (const DSString& DSString){
   std::cerr << "   OP+ ?";
   char* temp; temp = new char[strlen(chars)+strlen(DSString.chars)+1];
   strcat(temp, chars);
   strcat(temp, DSString.chars);
   delete[] chars;
   chars = strdup(temp);
   std::cerr << "   OP+ :)";
   return *this; //returns dereferenced 'this' pointer
}
DSString DSString::operator+ (const char* cstring){
    std::cerr << "   OP+ ?";
    char* temp;
    temp = new char[strlen(chars)+strlen(cstring)+1];
    strcat(temp, chars);
    strcat(temp, cstring);
    delete[] chars;
    chars = strdup(temp);
    std::cerr << "   OP+ :)";
   return *this; //returns dereferenced this pointer
}
/*DSString DSString::operator+ (const char achar){
   strcat(chars, achar);
   return *this; //returns dereferenced this pointer
}*/

bool DSString::operator== (const char* cstring){
    return strcmp(chars, cstring)==0;//Returns 0 if true
}
bool DSString::operator== (const DSString& DSString){
    return strcmp(chars, DSString.chars)==0;//Returns 0 if true
}

bool DSString::operator> (const DSString& DSString){ //Alphabetising
   for (int i = 0; i < this->getLength(); i++){
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
    //std::cerr << "getting length" <<std::endl;
    int i = 0;
    while (chars[i] != '\0'){
        i++;
    }
    //std::cerr << "got length" <<std::endl;
    return i;
}
DSString DSString::substring(int start, int numChars){
    //std::cerr << "In substring" << std::endl;
    //std::cerr << start << numChars;
    //std::cerr << this->getLength();
    DSString substring;
    substring.chars = new char[numChars+1];
        //std::cerr << " substring ITERATION BEGINING" << std::endl;
    for(int i = start; i < this->getLength() && i-start < numChars; i++){
        //std::cerr << " ITERATION   substring" << std::endl;
        substring.chars[i-start] = this->chars[i];
        //substring = strcat(substring.chars, (char*) this->chars[i]);
    }
    //std::cerr << "Exiting substring" << std::endl;
    std::cerr<<this->c_str();
    std::cerr<< substring.c_str();
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

