//
// Created by eyal on 19/12/18.
//

#ifndef FLIGHTPROJECTA_SYMTBLCLASS_H
#define FLIGHTPROJECTA_SYMTBLCLASS_H

#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <regex>
#include "Command.h"
#include "TCPClient.h"

class symTblClass {
    static map<string,double> symTbl;
    static map<string,string> bindedSymTbl;//left is the symbol right is the adress i.e lo/ca/tio/n
public:
    static TCPClient client;
    static bool addSym(const string);
    static bool addBinded(const string, const string);
    static double getVlaue(const string);
    static bool isBinded(const string);
    static bool isSym(const string);
    static bool setSym(const string, const double);
    static string getBind(string);
};


#endif //FLIGHTPROJECTA_SYMTBLCLASS_H
