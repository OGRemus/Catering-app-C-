//
// Created by geo_r on 22/05/2021.
//
#include "..//Entitites/IdGenerator.h"
#include "..//Entitites/EntityType.h"
#include <iostream>
#include "..//Entitites/Client.h"
#include "testGenerateId.h"
#include "..//Repo/RepoTemp.h"
#include "../Entitites/EntityType.h"
#include <cassert>

using namespace std;

void test() {
    Client c1 = Client("Strada zambilicii", "Relu65", true);
    int id = c1.getId();
    bool wasExcepted = false;
    try
    {
        for(int i = 0; i < 101; i++)
        {
            Client c = Client();
           assert(id != c.getId());
           // generam mai mult de 100 de iduri diferite si se arunca exceptie dupa ce depasim 100 id uri
        }
    }
    catch (runtime_error e) {
        wasExcepted = true;
        IdGenerator::getInstance().clearMemory();

    }


    assert(wasExcepted == true);

}
