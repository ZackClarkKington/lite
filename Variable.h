//
// Created by Zack Clark-Kington on 11/05/2017.
//

#ifndef LITECPP_VARIABLE_H
#define LITECPP_VARIABLE_H


#include <vector>
#include "Command.h"
#include "VarStore.h"

class Variable : public Command{
public:
    Variable(std::string type, VarStore *variables);
    void init(Command self, ReturnType returnType);
    Command executeCommand(std::vector<std::string> args);

private:
    std::string result;
    std::string type;
    ReturnType returnType;
    VarStore *vars;
};


#endif //LITECPP_VARIABLE_H
