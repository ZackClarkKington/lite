//
// Created by Zack Clark-Kington on 10/05/2017.
//

#ifndef LITECPP_ADD_H
#define LITECPP_ADD_H

#include <vector>
#include "Command.h"

class Add : public Command{
public:
    Add();
    void init(Command self, ReturnType returnType);
    Command executeCommand(std::vector<std::string> args);
private:
    std::string result;
    ReturnType returnType;
};
#endif //LITECPP_ADD_H
