//
// Created by eyal on 19/12/18.
//

#include "LexerClass.h"

void LexerClass::ReplaceAll(string &str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
}


queue<string> LexerClass::SaveQuotations(string &str){
    queue<string> quotations;
    unsigned int start = 0;
    unsigned int finish = 0;
    bool inQuotationMark = false;
    for(unsigned int i = 0; i<str.length();i++) {
        if (str.at(i) == '"') {
            inQuotationMark = !inQuotationMark;
            if (inQuotationMark)
                start = i;
            else {
                finish = i;
                quotations.push(str.substr(start, finish - start + 1));
                for(unsigned j = start; j <= finish; j++)
                    str.at(j) = '#';
            }
        }
    }
    /*
     * need to add exception if the quotation marks didnot close!!!
     */
    return  quotations;
}


vector<string> LexerClass::Lexer(string input){
    queue<string> quotations = SaveQuotations(input);
    ReplaceAll(input,"("," ( ");
    ReplaceAll(input,")"," ) ");
    ReplaceAll(input,"["," [ ");
    ReplaceAll(input,"]"," ] ");
    ReplaceAll(input,"{"," { ");
    ReplaceAll(input,"}"," } ");
    ReplaceAll(input,"*"," * ");
    ReplaceAll(input,"/"," / ");
    ReplaceAll(input,"+"," + ");
    ReplaceAll(input,"="," = ");
    ReplaceAll(input,"<"," < ");
    ReplaceAll(input,">"," > ");
    ReplaceAll(input,"!"," ! ");
    ReplaceAll(input,"-"," - ");
    ReplaceAll(input,"–"," – ");
    ReplaceAll(input,","," , ");
    ReplaceAll(input,"=  ="," == ");
    ReplaceAll(input,"<  ="," <= ");
    ReplaceAll(input,">  ="," >= ");
    ReplaceAll(input,"!  ="," != ");
    //ReplaceAll(input,"\n"," $ "); need to think if need to be added
    istringstream iss(input);
    string token;
    vector<string> take_chunks;
    while(iss >> token){
        if(token.at(0) == '#'){
            take_chunks.emplace_back(quotations.front());
            quotations.pop();
        }else{take_chunks.emplace_back(token);}
    }
    return take_chunks;
}
