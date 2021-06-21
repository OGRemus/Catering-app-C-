//
// Created by geo_r on 24/05/2021.
//

#ifndef APLICATIELIVRARI_NAMEVALIDATOR_H
#define APLICATIELIVRARI_NAMEVALIDATOR_H
#include <algorithm>
#include <string>
#include <stdio.h>
#include <ctype.h>
bool isNotAlnum(char c)
{
    return !isalnum(c);
}

bool string_is_valid(const std::string &str)
{
    return find_if(str.begin(), str.end(), isNotAlnum) == str.end();
}

class NameValidator {
public:
    virtual string validate(string str) {
        if(!string_is_valid(str))
            return "Name should only contain alphanumeric chars";
        return "";
    }
};

#endif //APLICATIELIVRARI_NAMEVALIDATOR_H
