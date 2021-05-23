//
// Created by geo_r on 23/05/2021.
//

#include "ClientService.h"

ClientService::ClientService() {
    this->filename = "default.txt";
    this->repo = clientRepo (filename);

}

ClientService::ClientService(string filename) {
    this->filename = filename;
    this->repo = clientRepo (this->filename);

}

void ClientService::setFilename(string filename) {
    this->filename = filename;
}

string ClientService::getFilename() {
    return filename;
}

vector<Client> ClientService::getPremium() {
    vector<Client> result;
    for(auto &i : repo.getAll())
        if(i.isPremium())
            result.push_back(i);

    return result;
}

