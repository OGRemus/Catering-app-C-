//
// Created by geo_r on 23/05/2021.
//

#include "ClientService.h"

ClientService::ClientService() {
    this->repo = clientRepo ("defaultClient.txt");

}

ClientService::ClientService(string filename) {
    repo.setFileName(filename);
}


vector<Client> ClientService::getPremium() {
    vector<Client> result;
    for(auto &i : repo.getAll())
        if(i.isPremium())
            result.push_back(i);

    return result;
}

