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


class ParserClass {

    static map<int,string> Precedence;
    static map<string,string> Expressions;
    static map<string,Command*> Commands;
    static bool isOperator(const string &str);
    static bool isCommand(const string& str);
public:

    static void Parser(vector<string> Tokens);
    static double caculateExpression(const vector<string>);
    static int ExpressionLength(int, vector<string>);
    static bool isQuotation(const string);
    static bool isNumber(const string);
    static vector<string> get1Expression(const int, vector<string>);
};


#endif //FLIGHTPROJECTA_PARSERCLASS_H
