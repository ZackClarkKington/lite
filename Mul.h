//
// Created by Zack Clark-Kington on 10/05/2017.
//

#ifndef LITECPP_MUL_H
#define LITECPP_MUL_H


#include <vector>
#include "Command.h"

class Mul : public Command{
public:
    Mul();
    void init(Command self, ReturnType returnType);
    Command executeCommand(std::vector<std::string> args);
private:
    std::string result;
    ReturnType returnType;
};


#endif //LITECPP_MUL_H
