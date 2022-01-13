#include <iostream>
#include <fstream>
using namespace std;

// output format to use IDENTICALLY:
//BSH:Saru> ./filesize input.3lines input.1line 
//program: ./filesize
// input.3lines: 3
// input.1line: 1

int main( int argc, char* argv[] )
{
    int lines = 0;
    string line;
    // just to get you started, this is how to refer to the arguments that were passed
    // for (int arg = 0; arg < argc; ++arg)
    //         std::cout << "argv[" << arg << "]: " << argv[arg] << '\n' ;
    cout << "program: " << argv[0] << endl;
    ifstream file;
    for (int i = 1; i < argc; ++i){
        file.open(argv[i]);
        if(!file.is_open()){
            cout << " " << argv[i] << ": -1" << endl;
        }
        else{
            while(!file.eof()){
                getline(file, line);
                ++lines; //adds a line 
            }
            lines--; //gets rid of extra line from eof 
            cout << " " << argv[i] << ": " << lines << endl; //correct spacing and print to user 
        file.close();
        lines = 0; //reset for next file 
        }
    };
    exit(0); // this means that the program executed correctly!
}

