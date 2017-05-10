//
// Created by Zack Clark-Kington on 10/05/2017.
//

#ifndef LITECPP_SUB_H
#define LITECPP_SUB_H

#include <vector>
#include "Command.h"

class Sub : public Command{
public:
    Sub();
    void init(Command self, ReturnType returnType);
    Command executeCommand(std::vector<std::string> args);
private:
    std::string result;
    ReturnType returnType;
};


#endif //LITECPP_SUB_H
