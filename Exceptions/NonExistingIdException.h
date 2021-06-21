//
// Created by geo_r on 24/05/2021.
//

#ifndef APLICATIELIVRARI_NONEXISTINGIDEXCEPTION_H
#define APLICATIELIVRARI_NONEXISTINGIDEXCEPTION_H
#include <string>
#include <exception>

using namespace std;

class NonExistingIdException: exception{
private:
    string msg;
public:
    NonExistingIdException(string message)
    {
        this->msg = message;
    }

    const string &getMsg() const {
        return msg;
    }
};
#endif //APLICATIELIVRARI_NONEXISTINGIDEXCEPTION_H
