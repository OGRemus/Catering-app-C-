//
// Created by geo_r on 22/05/2021.
//

#include "Courier.h"

Courier::Courier(const string &name) : name(name) {}

Courier::Courier() {
    name = "";
}

const string &Courier::getName() const {
    return name;
}

void Courier::setName(const string &name) {
    Courier::name = name;
}

ostream &operator<<(ostream &os, const Courier &courier) {
    os << courier.id << " " << " name: " << courier.name;
    return os;
}



