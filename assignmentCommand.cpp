//
// Created by eyal on 19/12/18.
//

#include "assignmentCommand.h"
#include "symTblClass.h"
#include "ParserClass.h"
#include "LexerClass.h"

int assignmentCommand::execute(int index, vector<string> Tokens) {
    int counter = 1;
    vector<string> expression ={};
    if (index == 0)
        throw "= is a binary operator";
    if (!(symTblClass::isSym(Tokens.at(index-1)))){//if the value is not an existing symbol
        throw "unknown symbol";
    }
    if (Tokens.at(index+1) == "bind"){//if its sym = bind ....
        if(Tokens.at(index+2).at(0) == '\"'){//if its sym = bind "..."
            string noQoutationMarks = Tokens.at(index+2).substr(1,Tokens.at(index+2).length()-2);
            symTblClass::addBinded(Tokens.at(index-1),noQoutationMarks);// add new bind to bind table
            counter += 2;
        }
        else if(symTblClass::isBinded(Tokens.at(index+2))){//if its sym = bind sym
            symTblClass::addBinded(Tokens.at(index-1),symTblClass::getBind(Tokens.at(index+2)));// add new bind to bind table
            counter += 2;
        }
        else{
            throw "could not bind";
        }
    }else if(symTblClass::isSym(Tokens.at(index+1))) {//if its sym1 = sym2
        symTblClass::setSym(Tokens.at(index-1),symTblClass::getVlaue(Tokens.at(index+1)));
        // ^ puts sym1 <- sym2 ^
    }else{// if its sym = expression
        expression = ParserClass::get1Expression(index, Tokens);
        counter += expression.size();
        double num = ParserClass::caculateExpression(expression);
        symTblClass::setSym(Tokens.at(index-1),num);
    }

    return counter;
}

assignmentCommand::~assignmentCommand() {

}

