//
// Created by eyal on 19/12/18.
//

#include "ConditionParser.h"
#include "ParserClass.h"

bool ConditionParser::CalculateCondition(vector<string> Tokens) {
    vector<string> left;
    vector<string> right;
    string condition;
    int conditionCounter = 0;
    for (auto token : Tokens){// checking the sign condition
        if (token == "<"){
            condition = token;
            conditionCounter++;
        }else if(token == ">"){
            condition = token;
            conditionCounter++;
        }else if(token == "<="){
            condition = token;
            conditionCounter++;
        }else if(token == ">="){
            condition = token;
            conditionCounter++;
        }else if (token == "!="){
            condition = token;
            conditionCounter++;
        }else if(token == "=="){
            condition = token;
            conditionCounter++;
        }
    }
    if(conditionCounter != 1)
        throw "more or less than one condition";
    int firstExpCounter = 0;
    while(Tokens.at(firstExpCounter) != condition){
        left.emplace_back(Tokens.at(firstExpCounter));
        firstExpCounter++;
    }
    firstExpCounter++;
    while(firstExpCounter != Tokens.size()){
        right.emplace_back(Tokens.at(firstExpCounter));
        firstExpCounter++;
    }
    if (condition == "<"){
        return (ParserClass::caculateExpression(left) < ParserClass::caculateExpression(right));
    }else if(condition == ">"){
        return (ParserClass::caculateExpression(left) > ParserClass::caculateExpression(right));
    }else if(condition == "<="){
        return (ParserClass::caculateExpression(left) <= ParserClass::caculateExpression(right));
    }else if(condition == ">="){
        return (ParserClass::caculateExpression(left) >= ParserClass::caculateExpression(right));
    }else if (condition == "!="){
        return (ParserClass::caculateExpression(left) != ParserClass::caculateExpression(right));
    }else{
        return (ParserClass::caculateExpression(left) == ParserClass::caculateExpression(right));
    }
}

