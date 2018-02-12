#include <iostream>
#include <fstream>
#include <readerfunctions.cpp>


using namespace std;



int main(int argc,  char* argv[])
{
    cerr << "Starting! "<< argc << " argument(s)!" <<endl;
    if (argc < 4){
        cerr << "-r/-c and two files required" << endl;
        return 0;
    }
    else if (*argv[1] == '-r'){
        return 0;
    }else if(*argv[1] != '-c'){
        cerr << "Invalid arg: Use -r to train, -c to test." << endl;
        cerr << "You input: "<< argv[1] << endl;
        return 0;
    }
    ifstream data(argv[2]);
    ifstream ratings(argv[3]);
    if(!data||!ratings){
        cerr << "Files not found!" << endl;
        return 0;}
    cerr << "Files found!" << endl;
    char c[140];
    char n[20];
    char c2;

    for (int a = 0; a < 10000; a++){ //Iterates through tweets
        for (int i = 1; i < 20; i++){//Loop finds +/- indicator
            ratings.get(c2);
            if(c2==','){
                ratings.get(c2);
                cout << c2 << " ";
                i = 50;
            }
        }
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
           if(n[i]==',')
               i=20;
        }
        for (int i = 0; i < 140; i++){ //Captures message
            data.get(c[i]);
            cout << c[i];
            if(c[i]=='\n'){
                c[i+1];
                i = 140;
            }
        }
    }



    //What differences matter?
    //Word content
    //Word order
    //

    //

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

