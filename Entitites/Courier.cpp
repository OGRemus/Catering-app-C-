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
    if(&os == &cout)
    {
        os << courier.id << " " << " name: " << courier.name;
    }
    else
    {
        os << courier.id << " " << courier.name;
    }

    return os;
}
bool Courier::operator==(const Courier &rhs) const {
    return name == rhs.name;
}

bool Courier::operator!=(const Courier &rhs) const {
    return !(rhs == *this);
}

Courier &Courier::operator=(const Courier &courier) {
    this->setName(courier.getName());
    return *this;
}

istream &operator>>(istream &is, Courier &cr) {
    int id;
    is >> id;
    string name;

    is >> name;

    cr.setId(id);
    cr.setName(name);

    return is;
}






