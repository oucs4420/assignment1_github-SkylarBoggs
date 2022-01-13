//  Author: Skylar Boggs
//  Program: Assignment 1 OS
//  Professor: Dr. S Ostermann
//  Date: 13 January 2022

#include <iostream>
#include <fstream>
using namespace std;

// output format to use IDENTICALLY:
//BSH:Saru> ./filesize input.3lines input.1line 
// input.3lines: 3
// input.1line: 1

int main( int argc, char* argv[] )
{
    int lines = 0; //counting for total line # 
    string line = " ";
    cout << "program: " << argv[0] << endl; //prog name 
    ifstream file; //file based on arguments 
    for (int i = 1; i < argc; ++i){
        file.open(argv[i]); //opens files one by one until all arguments gone through 
        if(!file.is_open()){ //failed to open, error count message 
            cout << " " << argv[i] << ": -1" << endl; //error 
        }//end of if 
        else{
            while(file.peek() != EOF){ //Resolves issue w/eof running one more time for some files 
                getline(file, line); //reads each lines
                ++lines; //counts total lines in file i 
            } //end of while 
            cout << " " << argv[i] << ": " << lines << endl; //correct spacing and print to user 
        file.close(); //closes file i 
        lines = 0; //reset for next file 
        }//end of else 
    };//end of for 
    exit(0); // this means that the program executed correctly!
}//end of main  