#include <iostream>
#include <fstream>
#include <readerfunctions.cpp>
#include <cstring>
#include "dsstring.h"

using namespace std;

//A to I : pass in a cstring number and it returns an integer
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



void trainWord(DSString word){ cerr << word.c_str();

    targetr = ifstream(targ);
    targetw = ofstream(targ);
    char* temp;
    //Will now iterate though file, locating the word if it occurs.
    for (int i = 0; i < 99999; i++){
        for (int k = 0; k < 10000; k++){
            targetr.get(temp[i]);
            if (temp[i] == '\n'){
                delete[] temp;
                temp=nullptr;
                k = 10000;
            }
            if (temp == word.c_str()){
                delete[] temp;
                temp = nullptr;
                for (int j = 0; j < 10000; j++){
                    targetr.get(temp[j]);
                    if (temp[j] == '\n'){
                       targetw<< sentiment << '\n'; //Will add to line reader is on
                       j = 10000;
                    }
                }
                k = 10000;
            }
        }
        return;
    }


    //If the word is not found, it is added on a
    return;
}
void checkWord(DSString word){
    targetr = ifstream(targ);
    targetw = ofstream(targ);
    char* temp;
    //Will now iterate though file, locating the word if it occurs.
    for (int i = 0; i < 99999; i++){
        for (int k = 0; k < 10000; k++){
            targetr.get(temp[i]);
            if (temp[i] == '\n'){
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
        return;
    }


    //If the word is not found, it is added on a
    return;
}

void doTweet(DSString tweet){
    char* ctweet = tweet.c_str();
    cerr << tweet.c_str();
    for (int i = 0; i < 2000; i++){
        if (ctweet[i] == ' ' || ctweet[i] == ',' || ctweet[i] == '.' || ctweet[i] == '!' || ctweet[i] == '?' || ctweet[i] == ';' || ctweet[i] == ':' || ctweet[i] == '-' || ctweet[i] == '"'){//Finds first non member
            if (mode){ //Ladder runs appropriate function on word
                checkWord(tweet.substring(0,i));
            }else{
                trainWord(tweet.substring(0,i));
            }
            doTweet(tweet.substring(i+1,tweet.getLength()-(i+1))); //Make sure this line is right
            delete[] ctweet;
            return;
        }
        if (ctweet[i] == '\n'){
            if (mode){ //Ladder runs appropriate function on word
                checkWord(tweet.substring(0,i));
            }else{
                trainWord(tweet.substring(0,i));
            }
            delete[] ctweet;
            return;
        }
    }

}
char* cstring = new char[5000];
DSString getNextTweet(){
    char* temp = new char;
    DSString result;
    int commaCount = 0;
        for (int i = 0; i < 2048; i++){
        /*Loop will stop when it hits end of line char*/
            subject.get(*temp);
            if (commaCount == 3){
            /*Now in tweet. Comma count ceases. Concatnation to return value initiated.*/
                 strcat(cstring, temp);
                 if (*temp == '\n'){
                   delete temp;
                    result =cstring;
                    cerr << result.c_str();
                   return result;
                 }
            }else if(*temp == ','){
                commaCount++;
            }else if(*temp == '\n'){
                delete temp;
                result =cstring;
                 cerr << result.c_str();
               return result;
            }
        }
    delete temp;
         cerr << result.c_str();
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
    //Training
    subject =ifstream(argv[2]); //Fstream is a more abstract
    targetr =ifstream(argv[3]);
    targetw =ofstream(argv[3]);//DO not open this with an fstream
    subj = argv[2]; targ = argv[3];
    DSString DStemp(" ");
    mode = false;

    if(!subject||!targetw){
        cerr << "Files not found!" << endl;
        return 0; }
    cerr << "Files found!" << endl;
    cerr << "Training!" << endl;
    getNextRating();
    for (int a = 0; a < 10; a++){ //Iterates through tweets
        DStemp = getNextTweet().c_str(); //Testing revealed that using the copy constructor or assignment operator corrupted the data.
        cerr << getNextTweet().c_str()<< endl;
        sentiment = getNextRating();
        doTweet(DStemp);
    }
    delete[] cstring;
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


//Find test.cpp file, this is supposed to be included -- Not expected to create a header file for test
//Find catch.hpp - this is required for test 
//These are not in repo bc SMU is bad

//Should each terminal command be in a separate file?




    //read from the file
    //check if it is positive or negative

    //iterate through the possibilities
    //find connections between pieces
    //avoid repeated operations, considertion
    //try and determine what context is significant

