//
// Created by eyal on 19/12/18.
//


#include <iostream>
#include <vector>
#include <fstream>
#include "LexerClass.h"
#include "ParserClass.h"
#include "symTblClass.h"


using namespace std;


int main () {

    cout << "Hello, you waiting for your input. \n"
            "If you want to run commands from a file please write \"run path/from/this/directory\" \n"
            "If you want to run commands from here just type the commands here just type it there and press enter to finish \n"
            "If you want to finish please enter \"EXIT\"" << endl;

    vector<string> Lexed;
    string input = "";
    getline(cin,input);
    ifstream myReadFile;
    string CommandsFromFile;
    string FilePath;
    string nextLine;

    while(input != "EXIT"){

        if (input.length() > 3 && input.at(0) == 'r' && input.at(1) == 'u' && input.at(2) == 'n'){

            FilePath = input.substr(4,input.length()-4);

            myReadFile.open(FilePath);

            if (myReadFile.is_open()) {
                while (!myReadFile.eof()) {
                    getline(myReadFile,nextLine);
                    CommandsFromFile += " " + nextLine ;
                }

                myReadFile.close();
                Lexed = LexerClass::Lexer(CommandsFromFile);
                ParserClass::Parser(Lexed);
                CommandsFromFile = "";
                cout << "We are finished with the file you can choose to run another file or just write the commands here." << endl;
            }else{
                cout << "Could not find the file please try again"<< endl;
            }
            getline(cin, input);
        }else{
            Lexed = LexerClass::Lexer(input);
            ParserClass::Parser(Lexed);
            getline(cin, input);
        }
    }
    return 0;
}