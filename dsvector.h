#ifndef DSVECTOR_H
#define DSVECTOR_H

#include "dsstring.h"
#include "wordvalpair.h"

template <typename T> class DSvector
{
private:
    int length;
    int size;
    T* contents;
public:
    //Rule of 3:
    DSvector();
    DSvector(const DSvector<T>&);
    ~DSvector();
    //Size management methods
    int updateLength();
    void resize();
    void scaleToFit(int);
    //Insertion
    void insert(const T&, int);
    void sortedIn(const T&);
    void append(const T&);
    //Search
    int search(const T&);//-1 if not found
    //Deletion
    void remove(int);
    //Retrieval
    T& get(int);

};
template class DSvector<DSString>;
template class DSvector<WordValPair>;
template class DSvector<IDSentimentPair>;

#endif // DSVECTOR_H
