//
// Created by Zack Clark-Kington on 11/05/2017.
//

#include "ReturnTypeMap.h"
ReturnTypeMap::ReturnTypeMap() {
    map = std::map<std::string,ReturnType>();
    map["string"] = string;
    map["int"] = integer;
    map["bool"] = boolean;
}