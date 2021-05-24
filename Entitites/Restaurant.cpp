//
// Created by geo_r on 22/05/2021.
//

#include "Restaurant.h"


Restaurant::Restaurant() {
    this-> name = "";
    this->adress = "";
}

Restaurant::Restaurant(string name, string adress) : name(std::move(name)), adress(std::move(adress)) {}

const string &Restaurant::getName() const {
    return name;
}

ostream &operator<<(ostream &os, const Restaurant &restaurant) {
    if(&os == &cout)
    {
        os << "ID: "  << restaurant.getId()  << " name: " << restaurant.getName() << " adress: "
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
    return adress;
}

void Restaurant::setAdress(const string &adress) {
    Restaurant::adress = adress;
}

bool Restaurant::operator==(const Restaurant &rhs) const {
    return name == rhs.name &&
           adress == rhs.adress;
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
    string adress;

    is >> id >> name >> adress;

    rest.setId(id);
    rest.setName(name);
    rest.setAdress(adress);

    return is;
}
