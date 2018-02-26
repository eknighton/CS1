#ifndef DSVECTOR_H
#define DSVECTOR_H

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

};

#endif // DSVECTOR_H
