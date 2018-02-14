#include <iostream>
#include <fstream>
#include <readerfunctions.cpp>
#include <cstring>
#include "dsstring.h"

using namespace std;

/*char* tweetIn(ifstream&, ofstream&);

int checkWord(char* word, ifstream& reference){ //Used to see
    char c[141];
    char n[20];
    char indicator;
    int results = 0;
    reference.get(indicator); //Takes next symbol from file, expecting and assuming it is the 0-4 sentiment value
    if (strcmp(word, tweetIn(reference, reference)) == 0){ //Assumes that after 3 commas it will find a single word then an end line
       results+=(int)indicator; //If the word is the tweet, this operation will add the sentiment value associated with it.
    }
    return results;
}
int checkTweet(char* tweet, ifstream& sample, ofstream& reference){
    int result;
    char c[140];
    char* word;
    for (int i = 0; i < 140; i++){ //"Dumb" iterator
        sample.get(word[i]);
        if(c[i] == ' ' || c[i] == ',' || c[i] == '.' || c[i] == '?' || c[i] == '!'){
           result+=checkWord(word, reference);
           word = "";
           i = 0; //Refresh iteration limit
        }else if (c[i] == '\n'){
            i = 140; //End iteration
        }
    }
    return result;
}

char* tweetIn(ifstream& data, ofstream& ratings){
    char c[141];
    char n[20];
    char c2;
    DSString result;
        for (int i = 1; i < 20; i++){//Loop finds sentiment indicator,
            ratings.get(c2);
            if(c2==','){
                ratings.get(c2);
                //cerr << c2 << " ";
                i = 20;
            }
        }
        for (int i = 0; i < 10; i++){//Moves cursor past tweet ID
            ratings.get(c2);
        }//Cursor is now at endline character
        for (int i = 0; i < 20; i++){ //Iterates to first comma
           data.get(n[i]);

           if(n[i]==',')
               i=20;
        }
        for (int i = 0; i < 20; i++){ //Iterates to second comma

           data.get(n[i]);
           if(n[i]==',')
               i=20;
        }
        for (int i = 0; i < 20; i++){ //Iterates to third comma

           data.get(n[i]);
           if(n[i]==',' || n[i] == '\n')
               i=20;
        }
        for (int i = 0; i < 141; i++){ //Captures message
            data.get(c[i]);
            //cout << c[i];
            if(c[i]=='\n'){
                c[i+1];
                i = 141;
            }
        }
        //cerr << "a-ok";
        //result = c;
    return c;
}*/
//A to I : pass in a cstring number and it returns an integer
bool mode;
int sentiment;
ifstream* subject;
ofstream* targetw; //Global write to target stream object
ifstream* targetr;//Global read from target stream object
ofstream* instructw; //Global write to instructions stream object
ifstream* instructr; //Global read from instructions stream object
char* subj{nullptr};
char* targ{nullptr};
char* instr{nullptr};


void trainWord(DSString word){
    delete targetr;
    targetr = new ifstream(targ);
    //Will now iterate though document, locating the word if it occurs.
    for (int i = 0; i < 10000; i++){
        //When the word is found, global int sentiment value is added to the int read on its line (-2,-1,1, or 2)

        delete targetr;
        return;
    }

    //If the word is not found, it is added on a

    delete targetr;
    return;
}
void checkWord(DSString word){

}

void doTweet(DSString tweet){
    cerr<<"doWord initd";
    cerr<<tweet.c_str();
    char* ctweet = tweet.c_str();

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



int train(char* const argv[]){// TRAINER OP
    //Training
    subject = new ifstream(argv[2]); //Fstream is a more abstract
    targetr = new ifstream(argv[3]);
    targetw = new ofstream(argv[3]);//DO not open this with an fstream
    subj = argv[2];
    targ = argv[3];
    if(!*subject||!*targetw){
        cerr << "Files not found!" << endl;
        return 0; }
    cerr << "Files found!" << endl;
    cerr << "Training!" << endl;

    for (int a = 0; a < 10000; a++){ //Iterates through tweets

    }
    cerr << "1";
    delete subject; cerr << "2"; delete targetr; cerr << "3"; delete targetw; cerr << "4";
    delete subj; cerr << "5"; delete targ; cerr << "6";
    return 0;
}
int test(char* const argv[]){// TESTER OP
    subject = new ifstream(argv[2]);
    instructr = new ifstream(argv[3]);
    targetw = new ofstream(argv[4]);
    subj = argv[2];
    instr = argv[3];
    targ = argv[4];

    if(!*subject||!*instructr){
        cerr << "Files not found!" << endl;
        return 0; }
    cerr << "Files found!" << endl;
    cerr << "Testing!" << endl;

    for (int a = 0; a < 10000; a++){ //Iterates through tweets

    }
    cerr << "1";
    delete subject; cerr << "2";delete instructr;cerr << "3"; delete targetw;cerr << "4";
    delete subj; cerr << "5";delete instr; cerr << "6"; delete targ; cerr << "7";
    return 0;
}


int main(int argc,  char* const argv[])
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

