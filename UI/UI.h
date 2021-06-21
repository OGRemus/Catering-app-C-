//
// Created by geo_r on 24/05/2021.
//

#ifndef APLICATIELIVRARI_UI_H
#define APLICATIELIVRARI_UI_H

#include "..//Service/ClientService.h"
#include "..//Service/CourierService.h"
#include "..//Service/RestaurantService.h"
#include "..//Service/OrderService.h"


#include <iostream>

using namespace std;

class UI {
private:
    ClientService clServ;
    CourierService couServ;
    RestaurantService resServ;
    OrderService ordServ;
public:
    UI();
    void console();
    void menu();
    void menuCrudClient();
    void menuCrudCourier();
    void menuCrudOrder();
    void menuCrudRestaurant();

    void uiClientAdd();
    void uiClientDelete();
    void uiClientUpdate();

    void uiCourierAdd();
    void uiCourierDelete();
    void uiCourierUpdate();

    void uiOrderAdd();
    void uiOrderDelete();
    void uiOrderUpdate();

    void uiRestaurantAdd();
    void uiRestaurantDelete();
    void uiRestaurantUpdate();

    void uiOrderGetGreaterThan();
    void uiOrderGetSmallerThan();
    void uiOrderSortBySum();
    void uiOrderSortById();
    void uiOrderFilterBySum();
    void uiOrderFilterByAdress();
    void uiOrderGetTotalSumOfRestaurant();
    void uiOrderFunctionalities();


};


#endif //APLICATIELIVRARI_UI_H
