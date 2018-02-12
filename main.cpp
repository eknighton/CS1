#include <iostream>
#include <fstream>
#include <readerfunctions.cpp>
#include <cstring>
#include "dsstring.h"

using namespace std;

char* tweetIn(fstream&, fstream&);

int checkWord(char* word, fstream& reference){ //Used to see
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
int checkTweet(char* tweet, fstream& sample, fstream& reference){
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

char* tweetIn(fstream& data, fstream& ratings){
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
}

int train(char* const argv[]){// TRAINER OP
    fstream data(argv[2]);
    fstream target(argv[3]);
    if(!data||!target){
        cerr << "Files not found!" << endl;
        return 0; }
    cerr << "Files found!" << endl;
    cerr << "Training!" << endl;
    tweetIn(data, target);
    for (int a = 0; a < 10000; a++){ //Iterates through tweets
        target << ',' << a << (tweetIn(data, target)); //Writes cstring to target file
        target.write((tweetIn(data, target)),100);
    }
    return 0;
}
int test(char* const argv[]){// TESTER OP
    fstream sample(argv[2]);
    fstream records(argv[3]);
    fstream target(argv[4]);
    if(!sample||!records){
        cerr << "Files not found!" << endl;
        return 0; }
    cerr << "Files found!" << endl;
    cerr << "Testing!" << endl;

    for (int a = 0; a < 10000; a++){ //Iterates through tweets
        if (checkTweet(tweetIn(sample, records), sample, records) > 2){
            target << '\t' << ' ' << '4';
        }else{
            target << '\t' << ' ' << '4';
        }
        //Iterates through the the lines in the train target, counting positive, negatives
    }

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

