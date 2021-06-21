//
// Created by geo_r on 23/05/2021.
//

#ifndef APLICATIELIVRARI_CLIENTSERVICE_H
#define APLICATIELIVRARI_CLIENTSERVICE_H
#include <string>
#include "../Repo/RepoTemp.h"
#include "MasterService.h"

class ClientService:public MasterService<Client, entityType_Client>{
private:

public:
    ClientService();
    ClientService(string filename);
    vector<Client> getPremium(); // gets all premium clients

};


#endif //APLICATIELIVRARI_CLIENTSERVICE_H
