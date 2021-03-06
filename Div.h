//
// Created by Zack Clark-Kington on 10/05/2017.
//

#ifndef LITECPP_DIV_H
#define LITECPP_DIV_H


#include <vector>
#include "Command.h"

class Div : public Command{
public:
    Div();
    void init(Command self, ReturnType returnType);
    Command executeCommand(std::vector<std::string> args);
private:
    std::string result;
    ReturnType returnType;
};


#endif //LITECPP_DIV_H
