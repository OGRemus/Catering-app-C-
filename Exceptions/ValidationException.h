//
// Created by geo_r on 24/05/2021.
//

#ifndef APLICATIELIVRARI_VALIDATIONEXCEPTION_H
#define APLICATIELIVRARI_VALIDATIONEXCEPTION_H
#include <string>
#include <exception>

using namespace std;

class ValidationException:exception{
private:
    string message;
public:
    ValidationException(string msg) : message(msg)
    {}

    string toString()
    {
        return message;
    }
};
#endif //APLICATIELIVRARI_VALIDATIONEXCEPTION_H
