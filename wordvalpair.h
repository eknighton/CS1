#ifndef WORDVALPAIR_H
#define WORDVALPAIR_H
#include "dsstring.h"

class WordValPair
{
    public:
        int val;
        DSString word;
        WordValPair();
        bool operator==(const WordValPair);
        bool operator==(const std::nullptr_t);
        bool operator<(const WordValPair);
        bool operator>(const WordValPair);
};
class IDSentimentPair
{
    public:
        DSString ID;
        int sentiment ;
        IDSentimentPair();
        bool operator==(const IDSentimentPair);
        bool operator==(const std::nullptr_t);
        bool operator<(const IDSentimentPair);
        bool operator>(const IDSentimentPair);
};

#endif // WORDVALPAIR_H
