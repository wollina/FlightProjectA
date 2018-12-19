//
// Created by eyal on 19/12/18.
//

#include "ifCommand.h"
#include "ParserClass.h"

ifCommand::~ifCommand()=default;

int ifCommand::execute(int index, vector<string> Tokens) {
    int counter = 1; //counter to return to parser
    index++;
    vector<string> commands = {};
    vector<string> condition = {};
    while (index < Tokens.size() && Tokens.at(index) != "{"){
        condition.emplace_back(Tokens.at(index)); // puttng the condition in another vector
        counter++;
        index++;
    }
    counter++;
    index++;
    while (index < Tokens.size() && Tokens.at(index) != "}"){
        commands.emplace_back(Tokens.at(index)); // puttng the commands in another vector
        counter++;
        index++;
    }
    if(index == Tokens.size()-1 && Tokens.at(index) != "}")
        throw "did not close brackets }";
    counter++;

    if(true){
        ParserClass::Parser(commands);
    }

    return counter;
}
