#ifndef DSSTRING_H
#define DSSTRING_H


class DSString
{
private:
    char* chars;
public:
    DSString();
    DSString(char*);
    DSString(const DSString&);
    ~DSString();
    DSString& operator= (const char*);
    DSString& operator= (const DSString&);
    DSString operator+ (const DSString&);
    bool operator== (const char*);
    bool operator== (const DSString&);
    bool operator> (const DSString&);
    char& operator[] (const int);

    //Friend function for file stream
    //Rule of three
    //
};

#endif // DSSTRING_H
