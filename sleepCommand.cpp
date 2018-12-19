//
// Created by eyal on 19/12/18.
//

#include "sleepCommand.h"
#include "ParserClass.h"

int sleepCommand::execute(int index, vector<string> Tokens) {
    int counter = 1;
    vector<string> expression = ParserClass::get1Expression(index, Tokens);
    counter += expression.size();
    cout << "expression sleep:" << endl;
    for (auto s : expression){
        cout << s << "|";
    }
    cout << endl;
    //TODO: need to convert expression to double and do the sleep command
    return counter;
}

sleepCommand::~sleepCommand() {}
