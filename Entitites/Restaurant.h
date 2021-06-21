//
// Created by geo_r on 22/05/2021.
//

#ifndef APLICATIELIVRARI_RESTAURANT_H
#define APLICATIELIVRARI_RESTAURANT_H
#include <string>
#include <ostream>
#include "../Entitites/Entity.h"


class Restaurant:public Entity<entityType_Restaurant>{
protected:
    string name;
    string address;

public:
    Restaurant();

    Restaurant(string name, string address);

    const string &getName() const;

    void setName(const string &name);

    const string &getAdress() const;

    void setAdress(const string &address);

    friend ostream &operator<<(ostream &os, const Restaurant &restaurant);

    friend istream &operator>>(istream &is, Restaurant& rest);

    bool operator==(const Restaurant &rhs) const;

    bool operator!=(const Restaurant &rhs) const;

    Restaurant& operator=(const Restaurant& restaurant);


};

#endif //APLICATIELIVRARI_RESTAURANT_H
