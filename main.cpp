//
// Created by eyal on 19/12/18.
//


#include <iostream>
#include <vector>
#include <queue>
#include "cmake-build-debug/LexerClass.h"
#include "cmake-build-debug/ParserClass.h"
#include "cmake-build-debug/symTblClass.h"


using namespace std;


int main () {
    /*string input = "openDataServer 5400 10 connect 127.0.0.1 5402 var=breaks != bind \"/controls/flight/speedbrake\" rudder = (h0 – heading)/20 "
                   "test 5 + 35, 4\n"
                   "while alt< -1000{\n"
                   "rudder = (h0 –heading)/20\n"
                   "aileron = -roll / 70\n"
                   "elevator = pitch / 50\n"
                   "print alt\n"
                   " sleep "
                   " 250 }";
                   */

    string input2 = "openDataServer 5+3 ,-4 "
                    "print 5 + 3 "
                    "print \"done\" "
                    "var x "
                    "if x == 5 {var plane print \"inside if \"} "
                    "x = 3 "
                    "print plane ";
    vector<string> take_chunks = LexerClass::Lexer(input2);

    try {
        ParserClass::Parser(take_chunks);
    }catch(char* x){
        cout << x << endl;
    }

    //cout << symTblClass::getVlaue("plane") << endl;
    for(auto i : take_chunks){
        cout << i << "|";
    }

}
