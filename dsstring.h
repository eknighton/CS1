#ifndef DSSTRING_H
#define DSSTRING_H


class DSString
{
private:
    char* chars;
public:
    DSString();
    DSString(const DSString& string);
    ~DSString();

    //Friend function for file stream
    //Rule of three
    //
};

#endif // DSSTRING_H
