//
// Created by geo_r on 24/05/2021.
//
#include "../Repo/RepoTemp.h"
#include <cassert>

using namespace std;

void testRepo(){
    clientRepo repo = clientRepo("testRepo2.txt");

    Client c1 = Client("Strada Bucuresti", "Rares222", false);

    repo.addElem(c1);

    assert(repo.getAll().size() == 1);
    assert(repo.getAll()[0].getAdress() == "Strada Bucuresti");

    Client c2 = Client("Strada Zambilicii", "AlexBos231", true);

    repo.addElem(c2);

    assert(repo.getAll().size() == 2);
    assert(repo.getAll()[1].getAdress() == "Strada Zambilicii");

    repo.deleteElem(c2);

    assert(repo.getAll().size() == 1);
    assert(repo.getAll()[0].isPremium() == false);

    repo.updateElem(c1,c2);
    assert(repo.getAll()[0] == c2);
    assert(repo.getAll()[0].getId() == repo.getById(repo.getAll()[0].getId()).getId());

    restaurantRepo resRepo = restaurantRepo("testLoadFromFile.txt");
    resRepo.addElem(Restaurant("BurgerStore", "Adresa"));
    resRepo.addElem(Restaurant("Pasta","Adresa"));


    // test load from file
    resRepo.clearData();
    resRepo.loadFromFile();

    assert(resRepo.getAll().size() == 2);
    assert(resRepo.getAll()[0].getName() == "BurgerStore");
    assert(resRepo.getAll()[1].getName() == "Pasta");

}