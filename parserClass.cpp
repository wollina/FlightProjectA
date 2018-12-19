//
// Created by eyal on 19/12/18.
//


#include "ParserClass.h"
#include "symTblClass.h"
#include "ConditionParser.h"
#include "ifCommand.h"
#include "assignmentCommand.h"


map<int,string> ParserClass::Precedence = {{0,"+"},{0,"-"},{1,"/"},{1,"*"},{2,"^"}};

map<string,string> ParserClass::Expressions ={
        {"+", "Plus"},
        {"-", "Minus"},
        {"/", "Div"},
        {"*", "Mult"},
        {"^", "Pow"}
};
//{"openDataServer",OpenServerCommand},
//{"bind",bindCommand},

map<string,Command*> ParserClass::Commands;



void ParserClass::Parser(vector<string> Tokens){
    Commands["var"] = new DefineVarCommand();
    Commands["if"] = new ifCommand();
    Commands["="] = new assignmentCommand();
    for(int index = 0; index < Tokens.size(); index++) {
        index += Commands[Tokens.at(index)]->execute(index,Tokens);
    }
}

bool ParserClass::isOperator(const string &str) {
    vector<string> ops = {"+", "-", "/", "*", "^"};
    for(auto op : ops) {
        if (str == op)
            return true;
    }
    return false;
}

bool ParserClass::isCommand(const string &str) {
    for(auto com : Commands){
        if(str == com.first)
            return true;
    }
    return false;
}
// returns the expression
vector<string> ParserClass::get1Expression(const int index, vector<string>Tokens) {
    int ind = index;
    vector<string> expression = {};
    ind++;
    while(ind < Tokens.size() && Tokens.at(ind) != "}" && !isCommand(Tokens.at(ind)) && !symTblClass::isSym(Tokens.at(ind))){
        expression.emplace_back(Tokens.at(ind));
        ind++;
    }
}
