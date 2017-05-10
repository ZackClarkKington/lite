//
// Created by Zack Clark-Kington on 09/05/2017.
//

#ifndef LITECPP_COMMAND_H
#define LITECPP_COMMAND_H

#include "ReturnType.h"
#include <string>
class Command {
    public:
        Command();
        void setReturnType(ReturnType returnType);
        void setResult(std::string result);
        ReturnType getReturnType();
        std::string getResult();
        char *token;
        char *tokenProgress;
        bool foundInnerCommand;
        std::string innerCommand;
    private:
        std::string result;
        ReturnType returnType;
};


#endif //LITECPP_COMMAND_H
