//
// Created by geo_r on 22/05/2021.
//

#include "Restaurant.h"


Restaurant::Restaurant() {
    this-> name = "";
    this->address = "";
}

Restaurant::Restaurant(string name, string address) : name(std::move(name)), address(std::move(address)) {}

const string &Restaurant::getName() const {
    return name;
}

ostream &operator<<(ostream &os, const Restaurant &restaurant) {
    if(&os == &cout)
    {
        os << "ID: "  << restaurant.getId()  << " name: " << restaurant.getName() << " address: "
           << restaurant.getAdress();
    }
    else
    {
        os<< restaurant.getId()  << " " << restaurant.getName() << " "
           << restaurant.getAdress();
    }

    return os;
}

void Restaurant::setName(const string &name) {
    Restaurant::name = name;
}

const string &Restaurant::getAdress() const {
    return address;
}

void Restaurant::setAdress(const string &address) {
    Restaurant::address = address;
}

bool Restaurant::operator==(const Restaurant &rhs) const {
    return name == rhs.name &&
           address == rhs.address;
}

bool Restaurant::operator!=(const Restaurant &rhs) const {
    return !(rhs == *this);
}

Restaurant &Restaurant::operator=(const Restaurant &restaurant) {
    this->setName(restaurant.getName());
    this->setAdress(restaurant.getAdress());
    return *this;
}

istream &operator>>(istream &is, Restaurant &rest) {
    int id;
    string name;
    string address;

    is >> id >> name >> address;

    rest.setId(id);
    rest.setName(name);
    rest.setAdress(address);

    return is;
}
