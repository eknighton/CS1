#include <iostream>
#include <fstream>
#include <readerfunctions.cpp>
#include <cstring>
#include "dsvector.h"
#include "dsstring.h"
#include "wordvalpair.h"

using namespace std;

//atoi : pass in a cstring number and it returns an integer
bool mode;
int sentiment;
ifstream subject;
ofstream targetw; //Global write to target stream object
ifstream targetr;//Global read from target stream object
ofstream instructw; //Global write to instructions stream object
ifstream instructr; //Global read from instructions stream object
char* subj{nullptr}; //Global pointer to subject filename
char* targ{nullptr}; //Global pointer to target filename
char* instr{nullptr}; //Global pointer to instruction filename

DSvector<DSString> wordVec;
DSvector<WordValPair> trainPairVec;
DSvector<IDSentimentPair> testPairVec;


void processWord(DSString word){
    cerr << "word" << word.c_str() << endl;
    int loc = wordVec.search(word);
    if (loc > -1){
        trainPairVec.get(loc).val+=sentiment;

    }else{
        WordValPair input; input.word = word; input.val = sentiment;
        trainPairVec.sortedIn(input);
    }

}
void ratingsLoad(){
    targetr = ifstream(instr);
    while(false){

    }
}

int wordCheck(DSString word){

}



void writeTaughtVector(){
    targetw = ofstream(targ);
    targetw.open(targ);
    for (int i = 0; i < trainPairVec.updateLength(); i++){
        targetw << trainPairVec.get(i).word.c_str();
        cerr<< trainPairVec.get(i).word.c_str();
        targetw << " " << trainPairVec.get(i).val;
        targetw << endl;
    }
    targetw.close();

}
void writeTestVector(){
    targetw = ofstream(targ);
    for (int i = 0; i < testPairVec.updateLength(); i++){
        targetw << testPairVec.get(i).ID.c_str();
        if (testPairVec.get(i).sentiment > 0){
            targetw << '"'<< 4 << '"';
        }else{
             targetw << '"'<< 0 << '"';
        }
        targetw << endl;
    }
}



void trainWord(DSString word){
   // cerr << "In trainWord" << endl;
   //cerr << "Training: " << word.c_str();

    targetr = ifstream(targ);
    targetw = ofstream(targ);
    char* temp = new char[10000];

    //cerr << "  Variables Allocated" << endl;
    //Will now iterate though file, locating the word if it occurs.
    for (int i = 0; i < 10; i++){
        for (int k = 0; k < 10000; k++){
           // cerr << "First call to targetr.get" << endl;
            targetr.get(temp[k]);
            cerr << "temp" << k << temp[k] << " ";
            if (temp[k] == '\n'){
                delete[] temp;
                temp = new char[10000];
                k = 10000;
            }
            //cerr << "making comparison" << endl;
            if (temp == word.c_str()){
                cerr << "Word found";
                for (int j = 0; j < 10000; j++){
                    targetr.get(temp[j]);
                    if (temp[j] == '\n'){
                       targetw<< sentiment << '\n'; //Will add sentiment value to line reader is on
                       //cerr << "trainword complete (1)" << endl;
                       delete[] temp;
                       return;
                    }
                }
                //cerr << "trainword complete (2)" << endl ;
                delete[] temp;
                return;
            }
        }
    }
    targetw << word.c_str() << sentiment << '\n'; //If the word is not found, it is added on the last line.
    cerr << "trainword complete: not found, written" << word.c_str()<< endl;
    return;
}

void checkWord(DSString word){
    targetr = ifstream(targ);
    targetw = ofstream(targ);
    char* temp;
    cerr  << "checkword forloop";
    //Will now iterate though file, locating the word if it occurs.
    for (int i = 0; i < 1000000; i++){
        for (int k = 0; k < 10000; k++){
            targetr.get(temp[k]);
            if (temp[k] == '\n'){
                delete[] temp;
                temp=nullptr;
                k = 10000;
            }
            if (temp == word.c_str()){
                delete[] temp;
                temp = nullptr;
                for (int j = 0; j < 10000; j++){
                    targetr.get(temp[j]);
                    sentiment+= (temp[j] - '0')%48-2; //AscII conversion then subtract 2.
                    if (temp[j] == '\n'){
                       j = 10000;
                    }
                }
                k = 10000;
            }
        }

    }
    return;//No effect if not found.
}
char* ctweet;
void doTweet(DSString tweet){ //fix memory leaks
    ctweet = tweet.c_str();
    //cerr << tweet.c_str();
    cerr << "In doTweet" << endl;
    for (int i = 0; i < 2000; i++){
        if (ctweet[i] == ' ' || ctweet[i] == ',' || ctweet[i] == '.' || ctweet[i] == '!' || ctweet[i] == '?' || ctweet[i] == ';' || ctweet[i] == ':' || ctweet[i] == '-' || ctweet[i] == '"'){//Finds first non member
            if (mode){ //Ladder runs appropriate function on word
                checkWord(tweet.substring(0,i));
                cerr << "wordchecked!" << endl;
            }else{
                processWord(tweet.substring(0,i));
                cerr << "wordtrained!" << endl;
            }
            //delete[] ctweet;
            //cerr << "ctweet deleted[]!";
            doTweet(tweet.substring(i,tweet.getLength()-(i))); //Make sure this line is right
            return;
        }
        if (ctweet[i] == '\n'){
            if (mode){ //Ladder runs appropriate function on word
                checkWord(tweet.substring(0,i));
                cerr << "wordchecked!" <<endl;
            }else{
                processWord(tweet.substring(0,i));
                cerr << "wordtrained!" <<endl;
            }
            cerr << "endline mode!";
            //delete[] ctweet;
            return;
        }
    }

}
char* cstring = new char[5000];
char* temp = new char[200];



DSString getNextTweetTwo(int line){

}

DSString getNextTweet(){
    cerr << "In getNextTweet!" << endl;
    delete[] temp;
    delete[] cstring;
    cstring = new char[50000];
    temp = new char[200];
    DSString result;
    int commaCount = 0;
        for (int i = 0; i < 1024; i++){
        /*Loop will stop when it hits end of line char*/
            cerr<< "temp: " << temp[0];
            subject.get(temp[0]);
            if (commaCount == 3){
            /*Now in tweet. Comma count ceases. Concatnation to return value initiated.*/
                 strcat(cstring, temp);
                 if (temp[0] == '\n'){
                   result =cstring;
                   return result;
                 }
            }else if(temp[0] == ','){
                commaCount++;
            }else if(temp [0]== '\n'){
               result =cstring;
               return result;
            }
        }
         cerr << "nextTweet3";
         //cerr << result.c_str() <<endl;
    return result;// = "\n"; //Failure case.
}
int getNextRating(){
    int result = 0; char temp; int commaCount = 0;
        for (int i = 0; i < 2048; i++){
            targetr.get(temp);
            if (commaCount == 1){
                commaCount++;
                targetr.get(temp);
                result = (temp - '0') % 48;
                cerr<<"3";
                if (temp == '\n'){
                   return result;
                }
            }else if(temp == ','){
                commaCount++;
            }else if(temp == '\n'){
                return result;
            }
        }
    return result; //Failure case.
}

int train(char* argv[]){// TRAINER OP
    cerr << "In Train!" << endl;
    //Training
    subject =ifstream(argv[2]); //Fstream is a more abstract
    targetr =ifstream(argv[3]);
    targetw =ofstream(argv[3]);//DO not open this with an fstream
    cerr << "   Stream Assignment Step Done" << endl;
    subj = argv[2]; targ = argv[3];
    cerr << "   Cstring Assignment Step Done" << endl;
    DSString DStemp(" ");
    cerr << "   String Initiation Step Done" << endl;
    mode = false;

    cerr << "   " << endl;
    if(!subject||!targetw){
        cerr << "Files not found!" << endl;
        return 0; }
    cerr << "Files found!" << endl;
    cerr << "Training!" << endl;
    getNextRating();
    for (int a = 0; a < 3; a++){ //Iterates through tweets
        DStemp = getNextTweet().c_str();
        cerr << "Tweet: ";
        cerr << DStemp.c_str() << endl;
        cerr << "Got Tweet!"<< endl;
        sentiment = getNextRating();
        cerr << "sentiment: " << sentiment << endl;
        //doTweet(DStemp);
    }
    writeTaughtVector();
    delete[] cstring;
    subject.close();
    targetr.close();
    targetw.close();
    return 0;
}
int test(char* argv[]){// TESTER OP
           subject = ifstream(argv[2]);
    instructr = ifstream(argv[3]);
    targetw = ofstream(argv[4]);
    DSString DStemp;
    subj = argv[2]; instr = argv[3]; targ = argv[4];
    mode = true;

    if(!subject||!instructr){
        cerr << "Files not found!" << endl;
        return 0; }
    cerr << "Files found!" << endl;
    cerr << "Testing!" << endl;
    for (int a = 0; a < 10000; a++){ //Iterates through tweets
         DStemp = getNextTweet();
         cerr << DStemp.c_str();
         doTweet(DStemp);
         if (sentiment > 0){
             targetw << "4";
         }
    }
    delete[] cstring;
    return 0;
}




int main(int argc,  char* argv[])
{
    DSString TESTER = "HEYOBAYO";
    cerr << TESTER.getLength() <<endl;
    cerr << TESTER.substring(0,2).c_str() <<endl;
    DSString TESTY= DSString("WOOO");
    cerr << TESTY.substring(0,2).c_str() <<endl;
    TESTER = TESTY;TESTER = TESTY;TESTER = TESTY;TESTER = TESTY;
    cerr << TESTER.substring(0,2).c_str() <<endl;
    cerr << DSString("WOO").c_str() << endl;

    cerr << "Starting! "<< argc << " argument(s)!" <<endl;
    if (argc < 4){
        cerr << "-r/-c and <subject> <target> required" << endl;
        return 0;
    }
    else if (strcmp(argv[1], "-r")==0){
        cerr << "Training mode!" << endl;
        return train(argv); //Calls training op
    }else if(strcmp(argv[1], "-c")==0){
         cerr << "Testing mode!" << endl;
         if (argc < 5){
             cerr << "In testing mode, <subject> <reference> <target> required!"<<endl;
         }
        return test(argv); //Calls testing op
    }
    cerr << "Invalid arg: Use -r to train, -c to test." << endl;
    return 0;

}

