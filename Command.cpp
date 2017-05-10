#include "ReturnType.h"
#include "Command.h"
//
// Created by Zack Clark-Kington on 10/05/2017.
//
void Command::setResult(std::string result) {this->result = result;}
void Command::setReturnType(ReturnType returnType) {this->returnType = returnType;}
std::string Command::getResult() { return this->result;}
ReturnType Command::getReturnType() {return this->returnType;}

Command::Command() {}
