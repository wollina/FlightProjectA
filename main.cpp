//
// Created by eyal on 19/12/18.
//


#include <iostream>
#include <vector>
#include "LexerClass.h"
#include "ParserClass.h"
#include "symTblClass.h"


using namespace std;


int main () {
    string input = //"openDataServer 5400 10 connect 127.0.0.1 5402 var "
                   "var breaks = bind \"/controls/flight/speedbrake\" "
                   "var rudder = (h0 – heading)/20 "
                   "test 5 + 35, 4\n"
                   "while alt< -1000{\n"
                   "rudder = (h0 –heading)/20\n"
                   "aileron = -roll / 70\n"
                   "elevator = pitch / 50\n"
                   "print alt\n"
                   "sleep 250 }"
                    "while 5!= 5{"
                    "openDataServer 5+3 ,-4 "
                    "print  ( 5+ 3)/ 20 *10 "
                    "print \"done\" "
                    "connect 12.0.0.127 (54*100) + 2 "
                    "sleep 12+2+ x "
                    "";
                    //"if x == 5 {var plane print \"inside if \"} "
                    //"x = 3 "
                    //"print plane ";
    vector<string> take_chunks = LexerClass::Lexer(input);
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
