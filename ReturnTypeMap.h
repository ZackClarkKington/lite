//
// Created by Zack Clark-Kington on 11/05/2017.
//

#ifndef LITECPP_RETURNTYPEMAP_H
#define LITECPP_RETURNTYPEMAP_H


#include <string>
#include <map>
#include "ReturnType.h"

class ReturnTypeMap {
    public:
        ReturnTypeMap();
        std::map<std::string,ReturnType> map;
};


#endif //LITECPP_RETURNTYPEMAP_H
