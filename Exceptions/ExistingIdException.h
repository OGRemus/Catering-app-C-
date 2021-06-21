//
// Created by geo_r on 24/05/2021.
//

#ifndef APLICATIELIVRARI_EXISTINGIDEXCEPTION_H
#define APLICATIELIVRARI_EXISTINGIDEXCEPTION_H
#include <string>
#include <exception>

using namespace std;

class ExistingIdException: exception{
private:
    string msg;
public:
    ExistingIdException(string message)
    {
        this->msg = message;
    }

    const string &getMsg() const {
        return msg;
    }
};
#endif //APLICATIELIVRARI_EXISTINGIDEXCEPTION_H
