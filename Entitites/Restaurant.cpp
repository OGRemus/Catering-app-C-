//
// Created by geo_r on 22/05/2021.
//

#include "Restaurant.h"

#include <utility>

Restaurant::Restaurant() {
    this-> name = "";
    this->adress = "";
}

Restaurant::Restaurant(string name, string adress) : name(std::move(name)), adress(std::move(adress)) {}

const string &Restaurant::getName() const {
    return name;
}

ostream &operator<<(ostream &os, const Restaurant &restaurant) {
    os << ""  << restaurant.id  << " name: " << restaurant.name << " adress: "
       << restaurant.adress;
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
