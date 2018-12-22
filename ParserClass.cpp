#include "ParserClass.h"
#include "symTblClass.h"
#include "ConditionParser.h"
#include "ifCommand.h"
#include "assignmentCommand.h"
#include "printCommand.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "sleepCommand.h"
#include "loopCommand.h"



void ParserClass::Parser(vector<string> Tokens){
    //intislizing commands map
    map<string,Command*> Commands;
    Commands["var"] = new DefineVarCommand();
    Commands["if"] = new ifCommand();
    Commands["while"] = new loopCommand();
    Commands["="] = new assignmentCommand();
    Commands["print"] = new printCommand();
    Commands["openDataServer"] = new OpenServerCommand();
    Commands["connect"] = new ConnectCommand();
    Commands["sleep"] = new sleepCommand();

    //parsing the input
    for(int index = 0; index < Tokens.size();) {
        if(isCommand(Tokens.at(index)))
            index += Commands[Tokens.at(index)]->execute(index,Tokens);
        else if(symTblClass::isSym(Tokens.at(index))) {
            index++;
        } else{
            throw "unknown command";
        }
    }

    // deleting all the pointers to the commands
    delete Commands["var"];
    delete Commands["if"];
    delete Commands["while"];
    delete Commands["="];
    delete Commands["print"];
    delete Commands["openDataServer"];
    delete Commands["connect"];
    delete Commands["sleep"];
}

bool ParserClass::isCommand(const string &str) {
    vector<string> Commands = {"var"
                               ,"if"
                               ,"while"
                               ,"="
                               ,"print"
                               ,"openDataServer"
                               ,"connect"
                               ,"sleep"};

    for(auto com : Commands){
        if(str == com)
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
    if(str.at(0) == '"' && str.at(str.length()-1) != '"')
        throw "starts with quoutation mark but doesnt end";
    if(str.at(0) != '"' && str.at(str.length()-1) == '"')
        throw "ends with quoutation mark but doesnt starts with one";
    return false;
}


// returns the expression
vector<string> ParserClass::get1Expression(const int index, vector<string>Tokens) {
    int ind = index;
    ind++;
    vector<string> expression = {};
    while(ind < Tokens.size() && Tokens.at(ind) != "}" && !isCommand(Tokens.at(ind)) && !(symTblClass::isSym(Tokens.at(ind)) && Tokens.at(ind+1) == "=")){
        expression.emplace_back(Tokens.at(ind));
        ind++;
    }
    return expression;
}


double ParserClass::caculateExpression(const vector<string> expression) {
    vector<string> onlyNums;
    //loop  for replaceing the names for values
    for(int i=0; i<expression.size(); i++){
        if(symTblClass::isSym(expression.at(i)))
            onlyNums.emplace_back(to_string(symTblClass::getVlaue(expression.at(i))));
        else
            onlyNums.emplace_back(expression.at(i));
    }
    //TODO: need to send now to the shuting yard algo and send the value back
    return 1.0;
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

