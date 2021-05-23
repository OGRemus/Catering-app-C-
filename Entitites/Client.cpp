//
// Created by geo_r on 22/05/2021.
//

#include "Client.h"

#include <utility>

const string &Client::getAdress() const {
    return adress;
}

void Client::setAdress(const string &adress) {
    Client::adress = adress;
}

const string &Client::getUsername() const {
    return username;
}

void Client::setUsername(const string &username) {
    Client::username = username;
}

bool Client::isPremium() const {
    return premium;
}

void Client::setPremium(bool premium) {
    Client::premium = premium;
}

Client::Client() {
    this->adress = "";
    this->username = "";
    this->premium = false;
}

Client::Client(string adress, string username, bool premium) {
    this->adress = std::move(adress);
    this->username = std::move(username);
    this-> premium = premium;

}

ostream &operator<<(ostream &os, const Client &client) {
    os  << " id: " << client.id << " adress: " << client.adress
       << " username: " << client.username << " premium: " << client.premium;
    return os;
}

