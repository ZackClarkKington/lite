//
// Created by Zack Clark-Kington on 10/05/2017.
//
#include <cstdlib>
#include <string>
#include "Sub.h"
Sub::Sub() {}
void Sub::init(Command self, ReturnType returnType) {
    self.setReturnType(returnType);
    self.setResult((std::string) "");
}
Command Sub::executeCommand(std::vector<std::string> args) {
    Command currentCommand = Command();
    init(currentCommand,integer);
    int result = 0;
    int i = 0;
    for(std::string n : args){
        try{
            if(i == 0){
                result = std::stoi(n);
            }
            else{
                result -= std::stoi(n);
            }
            i++;
        }catch (std::exception& e){}
    }
    std::string resultS = std::to_string(result);
    currentCommand.setResult(resultS);
    return currentCommand;
}