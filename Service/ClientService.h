//
// Created by geo_r on 23/05/2021.
//

#ifndef APLICATIELIVRARI_CLIENTSERVICE_H
#define APLICATIELIVRARI_CLIENTSERVICE_H
#include <string>
#include "../Repo/RepoTemp.h"
#include "MasterService.h"

class ClientService:MasterService<Client, entityType_Client>{
private:
    string filename;
    clientRepo repo;

public:
    ClientService();
    ClientService(string filename);
    void setFilename(string filename);
    string getFilename();
    vector<Client> getPremium(); // gets all premium clients

};


#endif //APLICATIELIVRARI_CLIENTSERVICE_H
