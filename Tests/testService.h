//
// Created by geo_r on 24/05/2021.
//

#ifndef APLICATIELIVRARI_TESTSERVICE_H
#define APLICATIELIVRARI_TESTSERVICE_H
#include "../Service/OrderService.h"
#include <cassert>

void testService(){
    OrderService serv = OrderService("testService.txt");

    Order ord = Order(1,1,1,"Strada 1mai","bagati carne sa fie", 38);//taco bell
    Order ord2 = Order(2,1,1,"Strada 1mai","dau un ciubuc cash la adresa pentru deranj", 17); // clientul a scapat iqosu
    //heets bronze

    serv.addElem(ord);

    assert(serv.getAll().size() == 1);

    serv.addElem(ord2);

    assert(serv.getAll().size() == 2);
    assert(serv.getAll()[0].getCourierId() == 1);

    serv.deleteElem(ord2);

    assert(serv.getAll().size() == 1);

    serv.updateElem(ord,ord2);
    assert(serv.getAll()[0].getCourierId() == 2);

    serv.deleteElem(ord2);

    Order ord10 = Order(31,10,4,"Strada 1mai","gol", 100);
    Order ord11 = Order(12,12,22,"Strada 1mai","gol", 22);
    Order ord3 = Order(44,11,10,"Strada 1mai","gol", 3);
    Order ord4 = Order(3,13,2,"Strada 1mai","gol", 40);
    Order ord5 = Order(4,14,3,"Strada 1mai","gol", 1);
    Order ord6 = Order(5,15,4,"Strada 1mai","gol", 33);
    Order ord7 = Order(9,11,13,"Strada 1mai","gol", 44);
    Order ord8 = Order(1,13,2,"Strada 1mai","gol", 38);
    Order ord9 = Order(2,11,11,"Strada 1mai","gol", 38);

    serv.addElem(ord10);
    serv.addElem(ord11);
    serv.addElem(ord3);
    serv.addElem(ord4);
    serv.addElem(ord5);
    serv.addElem(ord6);
    serv.addElem(ord7);
    serv.addElem(ord8);
    serv.addElem(ord9);


    assert(serv.getGreaterThan(44).size() == 1);
    assert(serv.getGreaterThan(44)[0].getPrice() == 100);

    assert(serv.getSmallerThan(4).size() == 2);
    assert(serv.getSmallerThan(4)[0].getPrice() == 3);

    assert(serv.sortBySum().size() == 9);
    assert(serv.sortBySum()[0].getPrice() == 1);


    assert(serv.sortById().size() == 9);
    serv.sortById();
    assert(serv.sortById()[0].getId() < serv.sortById()[1].getId());

    serv.filterBySum(38);

    assert(serv.getAll().size() == 2);
    Order ord12 = Order(2,11,11,"Strada Pavlov","gol", 38);
    serv.addElem(ord12);

    serv.filterByAdress("Strada 1mai");

    assert(serv.getAll().size() == 2);
    assert(serv.getAll()[0].getAdress() == "Strada 1mai");
    assert(serv.getAll()[1].getAdress() == "Strada 1mai");

    restaurantRepo repoRes = restaurantRepo ("testRepoRes.txt");


    repoRes.addElem(Restaurant("Soviet","Str"));
    int id = repoRes.getAll()[0].getId();

    Order ord13 = Order(2,11,id,"Strada Pavlov","gol", 1);
    Order ord14 = Order(2,11,id,"Strada Pavlov","gol", 1);
    Order ord15 = Order(2,11,id,"Strada Pavlov","gol", 1);

    serv.addElem(ord13);
    serv.addElem(ord14);
    serv.addElem(ord15);

    assert(serv.getTotalSumOfRestaurant("Soviet",repoRes) == 3);


}


#endif //APLICATIELIVRARI_TESTSERVICE_H
