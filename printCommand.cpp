//
// Created by eyal on 19/12/18.
//

#include "printCommand.h"
#include "ParserClass.h"
#include "symTblClass.h"

int printCommand::execute(int index, vector<string> Tokens) {
    index++; // from print -> "..."
    if(ParserClass::isQuotation(Tokens.at(index))){
        cout << Tokens.at(index).substr(1,Tokens.at(index).length()-2) << endl;
        return 2;
    }else{
        vector<string> expression = ParserClass::get1Expression(index-1,Tokens);
        double print = ParserClass::caculateExpression(expression);
        cout << "print" << endl;
        cout << "expression" << endl;
        for (auto s : expression){
            cout << s << "|";
        }
        cout << endl << print << endl;
        return expression.size()+1;
    }

}

printCommand::~printCommand() {

}
