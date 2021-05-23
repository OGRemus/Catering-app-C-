//
// Created by geo_r on 23/05/2021.
//

#ifndef APLICATIELIVRARI_MASTERSERVICE_H
#define APLICATIELIVRARI_MASTERSERVICE_H

#include "../Repo/RepoTemp.h"


using namespace std;

template<class T, entityType type>
class MasterService {
protected:
    RepoTemp<T, type> repo;

public:
    void addElem(T &);

    void deleteElem(T &);

    void updateElem(T &old, T &newItem);

    T getById(int id);


};

template<class T, entityType type>
void MasterService<T, type>::addElem(T &t) {
    repo.addElem(t);
}

template<class T, entityType type>
void MasterService<T, type>::deleteElem(T &t) {
    repo.deleteElem(t);

}

template<class T, entityType type>
void MasterService<T, type>::updateElem(T &old, T &newItem) {
    repo.updateElem(old, newItem);

}

template<class T, entityType type>
T MasterService<T, type>::getById(int id) {
    return repo.getById(id);
}

#endif //APLICATIELIVRARI_MASTERSERVICE_H
