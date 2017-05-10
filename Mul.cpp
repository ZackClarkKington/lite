//
// Created by Zack Clark-Kington on 10/05/2017.
//

#include "Mul.h"
Mul::Mul() {}
void Mul::init(Command self, ReturnType returnType) {
    self.setReturnType(returnType);
    self.setResult((std::string) "");
}
Command Mul::executeCommand(std::vector<std::string> args) {
    Command currentCommand = Command();
    init(currentCommand,integer);
    int result = 0;
    int i = 0;
    for(std::string n : args){
        try{
            result = (i==0)? std::stoi(n) : result * std::stoi(n);
            i++;
        }catch(std::exception& e){

        }
    }
    std::string resultS = std::to_string(result);
    currentCommand.setResult(resultS);
    return currentCommand;
}