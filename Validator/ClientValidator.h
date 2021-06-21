//
// Created by geo_r on 24/05/2021.
//

#ifndef APLICATIELIVRARI_CLIENTVALIDATOR_H
#define APLICATIELIVRARI_CLIENTVALIDATOR_H
#include "..//Exceptions/ValidationException.h"
#include "..//Entitites/Client.h"
#include "NameValidator.h"

class ClientValidator :public NameValidator {
public:
    ClientValidator();
    ~ClientValidator();
    void validate(Client cl);
};

ClientValidator::ClientValidator() {

}

ClientValidator::~ClientValidator() {

}

void ClientValidator::validate(Client cl) {
    string errorMsg = "";
    if(cl.getAdress().empty())
    {
        errorMsg += "Address cant be empty \n";
    }
    if(cl.getUsername().empty())
    {

        errorMsg += "Username cant be empty \n";
    }
    errorMsg += NameValidator::validate(cl.getUsername());

    if(cl.getId() < 1)
    {
        errorMsg += "Id cant be smaller than 1";
    }

    if(errorMsg.length() > 0)
    {
        throw ValidationException(errorMsg);
    }
}


#endif //APLICATIELIVRARI_CLIENTVALIDATOR_H
