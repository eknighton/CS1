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
    bool operator== (const char*);
    bool operator== (const DSString&);
    bool operator> (const DSString&);
    char& operator[] (const int);
    int getLength();
    DSString substring(int start, int numChars);
    char* c_str();
    friend std::ostream& operator<< (std::ostream&, const DSString&);

    //Friend function for file stream
    //Rule of three
    //
};

#endif // DSSTRING_H
