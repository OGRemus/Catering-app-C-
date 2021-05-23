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

using namespace std;

void test() {

//    try
//    {
//        for(int i = 0; i < 5; i++)
//        {
//            cout << IdGenerator::getInstance().generateId(entityType_Client) << endl;
//
//        }
//    }
//    catch (runtime_error e) {
//        cout << e.what();
//    }
    Client c1 = Client("Strada zambilicii", "Relu69", true);
    Client c2 = Client();
    Client c3 = Client();
    Client c4 = Client();

    cout << c1.getId() << endl;
    cout << c2.getId() << endl;
    cout << c3.getId() << endl;
    cout << c4.getId() << endl;

    RepoTemp<Client, entityType_Client> repo = RepoTemp<Client, entityType_Client>("testRepo.txt");

    repo.addElem(c1);
    repo.addElem(c2);
    repo.addElem(c3);
    repo.addElem(c4);

    orderRepo repoOr = orderRepo("Ristorante_ragazzi.txt");
    Order order = Order();
    repoOr.addElem(order);
}
