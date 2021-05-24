//
// Created by geo_r on 22/05/2021.
//

#ifndef APLICATIELIVRARI_ENTITY_H
#define APLICATIELIVRARI_ENTITY_H
#include "IdGenerator.h"
template<entityType T>
class Entity {
protected:
    int id;
    entityType type;
    void setId(int id)
    {
        this->id = id;
    }
public:

    Entity()
    {
        id = IdGenerator::getInstance().generateId(T);

    }
    ~Entity()= default;

    int getId() const;
};

template<entityType T>
int Entity<T>::getId() const {
    return this->id;
}


#endif //APLICATIELIVRARI_ENTITY_H
