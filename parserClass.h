//
// Created by eyal on 19/12/18.
//

#ifndef FLIGHTPROJECTA_PARSERCLASS_H
#define FLIGHTPROJECTA_PARSERCLASS_H


#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <regex>
#include "Command.h"
#include "DefineVarCommand.h"

using namespace std;

#ifndef FLIGHTPROJECT_PARSER_H
#define FLIGHTPROJECT_PARSER_H


class ParserClass {

    static map<int,string> Precedence;
    static map<string,string> Expressions;
    static map<string,Command*> Commands;

    static bool isOperator(const string &str);
    static bool isCommand(const string& str);

public:

    static void Parser(vector<string> Tokens);
    static vector<string> get1Expression(const int, vector<string>);
};


#endif //FLIGHTPROJECTA_PARSERCLASS_H
