//
// Created by eyal on 19/12/18.
//

#include "OpenServerCommand.h"
#include "ParserClass.h"

int OpenServerCommand::execute(int index, vector<string> Tokens) {
    index++; //goes from osc -> expression
    int counter = 1;
    vector<string> firstExpression = {};
    vector<string> secondExpression = {};
    int firstExpLen = ParserClass::ExpressionLength(index,Tokens);
    for (int j = 0; j < firstExpLen; j++){
        if(Tokens.at(index) != ",") {
            firstExpression.emplace_back(Tokens.at(index));
        }
        index++;
        counter++;
    }

    secondExpression = ParserClass::get1Expression(index-1,Tokens);
    counter += secondExpression.size();

    //TODO: need to add thread and connecting to the server
    //TODO: remove prints
    cout << "opened server" << endl;
    cout << "\nfirst" << endl;
    for (auto s : firstExpression){
        cout << s << "|" ;
    }
    cout << "\nsecond" << endl;
    for (auto s : secondExpression){
        cout << s << "|" ;
    }
    return counter;
}

OpenServerCommand::~OpenServerCommand() {
}
