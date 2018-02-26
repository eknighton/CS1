#include "dsvector.h"


using namespace std;

//Rule of 3: Constructor, Copy Constructor, Destructor
template<typename T>
DSvector<T>::DSvector()
{
    length = 0;
    contents = new T[8];
    size = 8;
}
template<typename T>
DSvector<T>::DSvector(const DSvector<T>& parent){
    length = parent.updateLength();
    contents = new T[length];
    contents = parent.contents;
}
template<typename T>
DSvector<T>::~DSvector(){
    delete[] contents;
}

//Size management methods: updateLength, resize
template<typename T>
int DSvector<T>::updateLength(){
    int i = 0;
    while (contents[i]!= nullptr)
        i++;
    this->length = i;
    return i;
}
template<typename T>
void DSvector<T>::resize(){
    T* temp = new T[length];
    for (int i = 0; i < length; i++){
        temp[i] = (contents)[i];
    }
    delete[] contents;
    contents = new T[size*2];
    for (int i = 0; i < length; i++){
        (contents)[i] = temp[i];
    }
    size = size*2;
    delete[] temp;
}
template<typename T>
void DSvector<T>::scaleToFit(int delta){

}

//Insertion Methods: insert to index, sortedIn, append
template<typename T>
void DSvector<T>::insert(const T& insertion, int loc){
    T tempOut; T tempIn = insertion;
    if (length+1 > size){
        resize();
    }
    for (int i = loc; i< length; i++){
        tempOut = contents[i];
        contents[i] = tempIn;
        tempIn = tempOut;
    }
    length+=1;
}

template<typename T>
void DSvector<T>::sortedIn(const T& insertion){
    for (int i = 0; i< length; i++){
       if (contents[i] == nullptr || contents[i] <= insertion){
           insert(insertion, i);
           return;
       }
    }
}

template<typename T>
void DSvector<T>::append(const T& appendage){
    if (size = length){
        resize();
    }
    contents[length] = appendage;
    length+=1;
}

//Search methods
template<typename T>
int DSvector<T>::search(const T& target){
    for (int i = 0; i< length; i++){
        if (contents[i] != nullptr && contents[i] == target){
            return i;
        }
    }
    return -1;
}


//Deletion methods
template<typename T>
void DSvector<T>::remove(int loc){
    T tempOut; T tempIn = nullptr;
    for (int i = length; i > loc; i--){
        tempOut = contents[i];
        contents[i] = tempIn;
        tempIn = tempOut;
    }
    length-=1;
}







