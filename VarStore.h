//
// Created by Zack Clark-Kington on 11/05/2017.
//

#ifndef LITECPP_VARSTORE_H
#define LITECPP_VARSTORE_H


#include <string>
#include <map>

class VarStore {
public:
    VarStore();

    void addVar(std::string key, std::string obj, std::string type);
    void removeVar(std::string key);
    std::map<std::string,std::string> getVar(std::string key);
private:
    std::map<std::string, std::map<std::string,std::string>> varMap;
};


#endif //LITECPP_VARSTORE_H
