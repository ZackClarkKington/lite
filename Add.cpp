//
// Created by Zack Clark-Kington on 09/05/2017.
//
#include <cstdlib>
#include <string>
#include "Command.h"
#include "Add.h"

Add::Add() {}
void Add::init(Command self, ReturnType returnType) {
    self.setReturnType(returnType);
    self.setResult((std::string) "");
}
Command Add::executeCommand(std::vector<std::string> args) {
    Command currentCommand = Command();
    init(currentCommand, integer);
    int result = 0;
    for (std::string n : args) {
        try {
            result += std::stoi(n);
        }catch (const std::exception& e){
        }
    }
    std::string resultS = std::to_string(result);
    currentCommand.setResult(resultS);
    return currentCommand;
}
