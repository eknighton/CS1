#ifndef DSSTRING_H
#define DSSTRING_H
#include <ostream>


class DSString
{
private:
    char* chars;
    int length;
public:
    DSString();
    DSString(const char*);
    DSString(const DSString&);
    ~DSString();
    DSString& operator= (const char*);
    DSString& operator= (const DSString&);
    DSString operator+ (const DSString&);
    DSString operator+ (const char*);
    DSString operator+ (const char);
    bool operator== (const char*);
    bool operator== (const DSString&);
    bool operator> (const DSString&);
    char& operator[] (const int);
    int getLength();
    DSString substring(int start, int numChars);
    char* c_str();
    void resize(int);
    friend std::ostream& operator<< (std::ostream&, const DSString&);
};

#endif //DSSTRING_H
