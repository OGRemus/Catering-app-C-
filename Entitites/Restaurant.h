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
    string adress;

public:
    Restaurant();

    Restaurant(string name, string adress);

    const string &getName() const;

    void setName(const string &name);

    const string &getAdress() const;

    void setAdress(const string &adress);

    friend ostream &operator<<(ostream &os, const Restaurant &restaurant);
};





#endif //APLICATIELIVRARI_RESTAURANT_H