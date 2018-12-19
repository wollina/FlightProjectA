//
// Created by eyal on 19/12/18.
//

#include "ConnectCommand.h"
#include "ParserClass.h"

int ConnectCommand::execute(int index, vector<string> Tokens) {
    index++;
    int counter = 1;
    string ip = Tokens.at(index);
    for(auto c : ip){//checks the ip if its valid
        if(!isdigit(c) && c != '.')
            throw "not a valid ip";
    }
    vector<string> expression = ParserClass::get1Expression(index,Tokens);
    cout << "expression length:" << expression.size() << endl;
    counter += expression.size()+1 ;
    cout << "ip:" << ip << endl;
    cout << "expression:" << endl;
    for (auto s : expression){
        cout << s << "|";
    }
    cout << endl;
    //TODO: need to connect here to server with the 2 expressions
    return counter;
}

ConnectCommand::~ConnectCommand() {}
