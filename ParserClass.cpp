//
// Created by eyal on 19/12/18.
//


#include "ParserClass.h"
#include "symTblClass.h"
#include "ConditionParser.h"
#include "ifCommand.h"
#include "assignmentCommand.h"
#include "printCommand.h"
#include "OpenServerCommand.h"


map<int,string> ParserClass::Precedence = {{0,"+"},{0,"-"},{1,"/"},{1,"*"},{2,"^"}};

map<string,string> ParserClass::Expressions ={
        {"+", "Plus"},
        {"-", "Minus"},
        {"/", "Div"},
        {"*", "Mult"},
        {"^", "Pow"}
};

//{"bind",bindCommand},

map<string,Command*> ParserClass::Commands;



void ParserClass::Parser(vector<string> Tokens){
    Commands["var"] = new DefineVarCommand();
    Commands["if"] = new ifCommand();
    Commands["="] = new assignmentCommand();
    Commands["print"] = new printCommand();
    Commands["openDataServer"] = new OpenServerCommand();
    for(int index = 0; index < Tokens.size();) {
        if(isCommand(Tokens.at(index)))
            index += Commands[Tokens.at(index)]->execute(index,Tokens);
        else if(symTblClass::isSym(Tokens.at(index))) {
            index++;
        } else{
            throw "unknown command";
        }
    }
    //TODO: need to delete all of the memory assigned
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

bool ParserClass::isNumber(const string str) {
    double doub;
    istringstream iss(str);
    return (!(iss >> doub).fail());//retruns true if its a number
}

bool ParserClass::isQuotation(const string str) { //checks if a expression is a string
    if(str.at(0) == '"' && str.at(str.length()-1) == '"')
        return true;
    return false;
}


// returns the expression
vector<string> ParserClass::get1Expression(const int index, vector<string>Tokens) {
    int ind = index;
    ind++;
    vector<string> expression = {};
    while(ind < Tokens.size() && Tokens.at(ind) != "}" && !isCommand(Tokens.at(ind)) && !symTblClass::isSym(Tokens.at(ind))){
        expression.emplace_back(Tokens.at(ind));
        ind++;
    }
    return expression;
}


double ParserClass::caculateExpression(const vector<string> expression) {
    return 4.0; //TODO: need to fix this method
}

int ParserClass::ExpressionLength(int index, vector<string> Tokens) {
    int counter = 1;
    while(index < Tokens.size() && !ParserClass::isCommand(Tokens.at(index)) && Tokens.at(index) != ","){
        if(ParserClass::isNumber(Tokens.at(index))){
            if(ParserClass::isNumber(Tokens.at(index+1)))
                return counter;
            else if(Tokens.at(index+1) == "(")
                return counter;
            else if(symTblClass::isSym(Tokens.at(index+1)))
                return counter;
        }
        else if(Tokens.at(index) == ")"){
            if(ParserClass::isNumber(Tokens.at(index+1)))
                return counter;
            else if(Tokens.at(index+1) == "(")
                return counter;
            else if(symTblClass::isSym(Tokens.at(index+1)))
                return counter;
        }
        else if(symTblClass::isSym(Tokens.at(index))){
            if(ParserClass::isNumber(Tokens.at(index+1)))
                return counter;
            else if(Tokens.at(index+1) == "(")
                return counter;
            else if(symTblClass::isSym(Tokens.at(index+1)))
                return counter;
        }
        index++;
        counter++;
    }

    return counter;
}

