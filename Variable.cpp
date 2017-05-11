//
// Created by Zack Clark-Kington on 11/05/2017.
//

#include "Variable.h"
#include "ReturnTypeMap.h"

Variable::Variable(std::string type, VarStore *variables) {
    this->type = type;
    this->vars = variables;
}
void Variable::init(Command self, ReturnType returnType) {
    self.setReturnType(returnType);
    self.setResult((std::string) "");
}
Command Variable::executeCommand(std::vector<std::string> args) {
    Command currentCommand = Command();
    init(currentCommand,ReturnTypeMap().map.at(type));
    int i = 0;
    std::string resultS;
    std::string val;
    for(std::string n : args){
        if(i==1){
            resultS = n;
        }
        else if(i==2){
            val = n;
        }
        i++;
    }
    vars->addVar(resultS,val,type);
    currentCommand.setResult(resultS);
    return currentCommand;
}