//
// Created by geo_r on 22/05/2021.
//

#include "Client.h"

#include <utility>

const string &Client::getAdress() const {
    return address;
}

void Client::setAdress(const string &address) {
    Client::address = address;
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
    this->address = "";
    this->username = "";
    this->premium = false;
}

Client::Client(string address, string username, bool premium) {
    this->address = std::move(address);
    this->username = std::move(username);
    this-> premium = premium;

}

ostream &operator<<(ostream &os, const Client &client) {
    if(&os == &cout)
    {
        os  << " id: " << client.id << " address: " << client.address
            << " username: " << client.username << " premium: " << client.premium;
    }

    else
    {
        os  << client.id << " " << client.address
            << " " << client.username << " " << client.premium;
    }

    return os;
}

bool Client::operator==(const Client &rhs) const {
    return
            address == rhs.address &&
           username == rhs.username &&
           premium == rhs.premium;
}

bool Client::operator!=(const Client &rhs) const {
    return !(rhs == *this);
}

Client &Client::operator=(const Client &client) {
    this->setAdress(client.getAdress());
    this->setPremium(client.isPremium());
    this->setUsername(client.getUsername());
    return *this;
}

istream &operator>>(istream &is, Client &cl) {

    string address;
    string username;
    bool premium;
    int id;
    is >> id;
    is >> address >> username >> premium;

    cl.setId(id);
    cl.setAdress(address);
    cl.setUsername(username);
    cl.setPremium(premium);

    return is;
}

