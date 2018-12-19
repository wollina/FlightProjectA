//
// Created by eyal on 19/12/18.
//

#include "DefineVarCommand.h"
#include "symTblClass.h"
#include "ParserClass.h"

//this execute just puts the symbol to the sybol table nothing else
int DefineVarCommand::execute(int index, vector<string> Tokens) {
    if(!(isalpha(Tokens.at(index+1).at(0))))//check if doesnt starts with letter
        throw("argument name must start with a letter");
    if(symTblClass::addSym(Tokens.at(index+1))) {
        return 2; //adding the symbol to the table
    }
    else
        throw("alredy exist in map");
}

DefineVarCommand::~DefineVarCommand() {
}
