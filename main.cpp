#include <iostream>
#include <vector>
#include <regex>
#include "Add.h"
#include "Sub.h"
#include "Div.h"
#include "Mul.h"
#include "VarStore.h"
#include "Variable.h"

std::string versionNum = "0.2";
std::string command;

Command runCommand(char *command);
VarStore *variables;
int virtReg[100]; //Currently not in use, may be deleted
bool compareCommand(std::string command, std::string compare){
    const char *commandArr = command.c_str();
    const char *compareArr = compare.c_str();
    return (strncmp(commandArr, compareArr, command.length()) == 0);
}
std::vector<std::string> constructArgs(Command command, char *token, char *tokenProgress){
    command.token = token;
    command.tokenProgress = tokenProgress;
    command.foundInnerCommand = false;
    std::vector<std::string> args;
    int bCount = 0; //Counts opening brackets
    int eCount = 0; //Counts closing brackets
    while(command.token != NULL){
        if(std::string(command.token).find("(") != std::string::npos){
            std::regex pattern("\\(");
            if(bCount == 0) {
                command.foundInnerCommand = true;
                command.innerCommand = std::regex_replace(command.token, pattern, "");
            }
            else{
                command.innerCommand += ",";
                command.innerCommand += (std::string) command.token;
            }
            bCount++;
        }
        else if(std::string(command.token).find(")") != std::string::npos && command.foundInnerCommand){
            eCount++;
            if(eCount == bCount) { //If as many closing brackets as opening brackets have been found then a complete command has been assembled
                std::regex pattern("\\)");
                command.innerCommand += ",";
                command.innerCommand += std::regex_replace(command.token, pattern, "");
                char *toRun = new char[command.innerCommand.length() + 1];
                strcpy(toRun, command.innerCommand.c_str());
                Command innerCommand = runCommand(toRun);
                args.push_back(innerCommand.getResult());
                command.foundInnerCommand = false;
                command.innerCommand = "";
            }
            else{
                command.innerCommand += ",";
                command.innerCommand += (std::string) command.token;
            }
        }
        else if(command.foundInnerCommand){
            command.innerCommand += ",";
            command.innerCommand += (std::string) command.token;
        }
        else {
            args.push_back(std::string(command.token));
        }
        command.token = strtok_r(NULL,",",&command.tokenProgress);
    }
    return args;
}
Command runCommand(char *command){
    char *token;
    char *tokenProgress;
    token = strtok_r(command,",",&tokenProgress);
    if(compareCommand(token,"add")){
        Add add = Add();
        std::vector<std::string> args = constructArgs(add,token,tokenProgress);
        return add.executeCommand(args);
    }
    else if(compareCommand(token,"sub")){
        Sub sub = Sub();
        std::vector<std::string> args = constructArgs(sub,token, tokenProgress);
        return sub.executeCommand(args);
    }
    else if(compareCommand(token, "div")){
        Div div = Div();
        std::vector<std::string> args = constructArgs(div,token,tokenProgress);
        return div.executeCommand(args);
    }
    else if(compareCommand(token,"mul")){
        Mul mul = Mul();
        std::vector<std::string> args = constructArgs(mul,token,tokenProgress);
        return mul.executeCommand(args);
    }
    else if(compareCommand(token,"run")){
        int i = 0;
        while(token!=NULL){
            if(i == 1){
                printf("Running: %s\n",token);
                try {
                    FILE *fp = fopen(token, "r");
                    char *line;
                    line = (char *) malloc(100);
                    while (fgets(line, 100, fp) != NULL) {
                        Command fCommand = runCommand(line);
                        printf("%s\n",fCommand.getResult().c_str()); //run is not implemented as its' own class because it requires recursive use of the runCommand function
                    }
                    free(line);
                    fclose(fp);
                }catch (std::exception& e){
                    printf(e.what());
                    printf(strerror(errno));
                }
            }
            token = strtok_r(NULL,",",&tokenProgress);
            i++;
        }
        Command empty = Command();
        empty.setReturnType(string);
        empty.setResult("EOF");
        return empty;
    }
    else if(compareCommand(token,"exit")){
        exit(0);
    }
    else if(compareCommand(token,"bool") || compareCommand(token,"int") || compareCommand(token,"string")){
        std::string type = token;
        Variable var = Variable(type,variables);
        std::vector<std::string> args = constructArgs(var,token,tokenProgress);
        return var.executeCommand(args);
    }
    else{
        Command empty = Command();
        empty.setReturnType(string);
        empty.setResult("Invalid syntax");
        return empty;
    }
}

int main() {
    variables = new VarStore();
    while(true){
        printf("Lite Interpreter V%s:\n", versionNum.c_str());
        std::string command;
        std::cin >> command;
        char *cmd = &command[0u];
        Command toRun = runCommand(cmd);
        printf("%s\n",toRun.getResult().c_str()); //Currently verbosely prints result of commands, in future will simply return but only print when told to
    }
    return 0;
}