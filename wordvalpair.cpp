#include "wordvalpair.h"

WordValPair::WordValPair()
{

}
bool WordValPair::operator ==(const WordValPair pair){
    return (word == pair.word);
}
bool WordValPair::operator > (const WordValPair pair){
    return (word > pair.word);
}
bool WordValPair::operator < (const WordValPair pair){
    return (word < pair.word);
}
bool WordValPair::operator ==(const std::nullptr_t){
    return (word.c_str() == nullptr);
}
IDSentimentPair::IDSentimentPair()
{

}
bool IDSentimentPair::operator ==(const IDSentimentPair pair){
    return (ID == pair.ID);
}
bool IDSentimentPair::operator > (const IDSentimentPair pair){
    return (ID > pair.ID);
}
bool IDSentimentPair::operator < (const IDSentimentPair pair){
    return (ID < pair.ID);
}
bool IDSentimentPair::operator ==(const std::nullptr_t){
    return (ID.c_str() == nullptr);
}

