//
// Created by geo_r on 22/05/2021.
//

#ifndef APLICATIELIVRARI_COURIER_H
#define APLICATIELIVRARI_COURIER_H
#include "Entity.h"
#include "EntityType.h"
#include <string>
#include <ostream>

class Courier : public Entity<entityType_Courier> {
protected:
    string name;

public:
    explicit Courier(const string &name);
    Courier();

    const string &getName() const;

    void setName(const string &name);

    friend ostream &operator<<(ostream &os, const Courier &courier);

};


#endif //APLICATIELIVRARI_COURIER_H
