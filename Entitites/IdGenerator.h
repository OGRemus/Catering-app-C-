//
// Created by geo_r on 22/05/2021.
//

#ifndef APLICATIELIVRARI_IDGENERATOR_H
#define APLICATIELIVRARI_IDGENERATOR_H

#include <map>
#include <vector>
#include "EntityType.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

class IdGenerator {
private:
    map<entityType, vector<int>> memory;

    IdGenerator() {};
public:
    void clearMemory()
    {
        memory.clear();
    }
    static IdGenerator &getInstance() {
        static IdGenerator instance;
        return instance;
    }

    int generateId(entityType type) {
        int id;
        srand(time(nullptr));
        if(memory[type].size() == 100)
        {
            throw runtime_error("Am atins limita de id uri");
        }
        do {
            id = rand() % 100 + 1;

        } while (count(memory[type].begin(), memory[type].end(), id) != 0);

        memory[type].push_back(id);

        return id;
    }

    IdGenerator(IdGenerator const &) = delete;

    void operator=(IdGenerator const &) = delete;


};

#endif //APLICATIELIVRARI_IDGENERATOR_H
