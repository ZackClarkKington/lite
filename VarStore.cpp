//
// Created by Zack Clark-Kington on 11/05/2017.
//

#include "VarStore.h"

VarStore::VarStore() {
    varMap = std::map<std::string, std::map<std::string,std::string>>();
}
void VarStore::addVar(std::string key, std::string obj, std::string type) {
    std::map<std::string,std::string> toAdd = std::map<std::string,std::string>();
    toAdd["type"] = type;
    toAdd["value"] = obj;
    varMap[key] = toAdd;
}
void VarStore::removeVar(std::string key) {
    varMap.erase(key);
}
std::map<std::string,std::string> VarStore::getVar(std::string key) {
    return varMap.at(key);
}