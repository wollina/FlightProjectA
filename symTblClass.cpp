//
// Created by eyal on 19/12/18.
//

#include "symTblClass.h"

map<string,double> symTblClass::symTbl = {};// the symbol table
map<string,string> symTblClass::bindedSymTbl = {};// binded symbols table
TCPClient symTblClass::client = TCPClient();

//add symbol to the map
bool symTblClass::addSym(const string newSym) {
    for(auto oldSym : symTbl) {
        if (newSym == oldSym.first)
            return false; //returns false if the symbol already exist in the table
    }
    symTbl.emplace(pair<string,double>(newSym,0.0));
    return true;// emplaced successfully
}

bool symTblClass::addBinded(const string newBinded, const string newBind) {
    bindedSymTbl[newBinded] = newBind;
}

//method to set the values in the symbol table
bool symTblClass::setSym(const string symbl, const double newVal) {
    //if its binded need to send set command
    double test = -1; //TODO: need to remove
    if(isBinded(symbl)){
        string setCommand = "set " + bindedSymTbl[symbl] + " " + to_string(test) + "\r\n\r\n";
        symTblClass::client.send_data(setCommand);
    }
    auto it = symTbl.find(symbl);
    if (it != symTbl.end()){
        (*it).second = newVal;
        return true;//return true if changed sucessefully
    }
    // if we got here it means there is no symbol with this name
    return false;
}

//gets value of a certain symbol
double symTblClass::getVlaue(const string symbl) {
    if(isBinded(symbl)){
        // TODO: need to add get from the simulator
    }
    for(auto pair : symTbl) {
        if (symbl == pair.first)
            return pair.second; //returns the value of the symbol
    }
    //if we got here it means the symbl doesnt exist in the map
    throw("symbl doesnt exist in the map");
}

//looking if the string is a valid symbol
bool symTblClass::isSym(const string symbl) {
    for(auto pair : symTbl) {
        if (symbl == pair.first)
            return true;
    }
    return false;
}
// check if a symbol is binded
bool symTblClass::isBinded(const string binded) {
    for(auto pair : bindedSymTbl) {
        if (binded == pair.first)
            return true;
    }
    return false;
}

string symTblClass::getBind(string binded) {
    return bindedSymTbl[binded];
}

