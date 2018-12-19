//
// Created by eyal on 19/12/18.
//

#ifndef FLIGHTPROJECTA_OPENSERVERCOMMAND_H
#define FLIGHTPROJECTA_OPENSERVERCOMMAND_H


#include "Command.h"
#include <pthread.h>
class OpenServerCommand : public Command{
public:
    int execute(int index, vector<string> Tokens) override;
    ~OpenServerCommand() override;
};


#endif //FLIGHTPROJECTA_OPENSERVERCOMMAND_H
