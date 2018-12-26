//
// Created by eyal on 19/12/18.
//

#include <sys/socket.h>
#include "ConnectCommand.h"
#include "ParserClass.h"
#include "symTblClass.h"

int ConnectCommand::execute(int index, vector<string> Tokens) {
    index++;
    int counter = 1;
    string ip = Tokens.at(index);
    for(auto c : ip){//checks the ip if its valid
        if(!isdigit(c) && c != '.')
            throw "not a valid ip";
    }
    vector<string> expression = ParserClass::get1Expression(index,Tokens);
    counter += expression.size()+1 ;
    symTblClass::client.conn(ip,5402);
    //TODO: need to change 5402 to the expression after interpetation
    return counter;
}

ConnectCommand::~ConnectCommand() {}
