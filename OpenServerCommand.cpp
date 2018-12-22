//
// Created by eyal on 19/12/18.
//

#include "OpenServerCommand.h"
#include "ParserClass.h"
#include "DataReaderServer.h"
atomic<int> OpenServerCommand::connection_indicator(0);

int OpenServerCommand::execute(int index, vector<string> Tokens) {
    index++; //goes from osc -> expression

    cout << "Please open the simulator" << endl << "Waiting for connection to the simulator..." << endl;

    int counter = 1;

    vector<string> firstExpression = {};
    vector<string> secondExpression = {};

    int firstExpLen = ParserClass::ExpressionLength(index,Tokens);

    // adding t the expression and remving the ',' if there is one

    for (int j = 0; j < firstExpLen; j++){
        if(Tokens.at(index) != ",") {
            firstExpression.emplace_back(Tokens.at(index));
        }
        index++;
        counter++;
    }

    secondExpression = ParserClass::get1Expression(index-1,Tokens);
    counter += secondExpression.size();

    //TODO: need to send port number and the timing

    DataReaderServer::CreateServerThread(5400, 10);

    //stoping the program untill we know we are connected to the simulator and we got the first values
    while(OpenServerCommand::connection_indicator.load(memory_order_seq_cst) != 1){
        sleep(0.5);
    }

    cout <<endl<< "Connected Successfully" << endl;

    //TODO: remove prints

    cout << "Opened new server" << endl;

    return counter;
}

OpenServerCommand::~OpenServerCommand() {
}
