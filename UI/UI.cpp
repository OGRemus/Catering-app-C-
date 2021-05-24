//
// Created by geo_r on 24/05/2021.
//

#include "UI.h"
#include <iostream>

using namespace std;

UI::UI() {
    this->clServ = ClientService("ClientRepo.txt");
    this->couServ = CourierService("CourierRepo.txt");
    this->resServ = RestaurantService("RestaurantRepo.txt");
    this->ordServ = OrderService("OrderRepo.txt");

}

void UI::menu() {

    cout << "Choose an option: " << endl;
    cout << "1.Crud client" << endl;
    cout << "2.Crud courier" << endl;
    cout << "3.Crud order" << endl;
    cout << "4.Crud restaurant" << endl;
    cout << "5.Iesire ";
}

void UI::menuCrudClient() {
    bool run = true;
    int option;

    while (run) {
        cout << "Choose an option " << endl;
        cout << "1.Add client" << endl;
        cout << "2.Delete client" << endl;
        cout << "3.Update client " << endl;
        cout << "4.Back " << endl;

        cin >> option;
        switch (option) {
            case 1:
                uiClientAdd();
                break;
            case 2:
                uiClientDelete();
                break;
            case 3:
                uiClientUpdate();
            case 4:
                run = false;
                break;
            default:
                cout << endl << "Optiune invalida" << endl;
                break;

        }
    }
}

void UI::menuCrudCourier() {

    bool run = true;
    int option;

    while (run)
    {
        cout << "Choose an option " << endl;
        cout << "1.Add courier" << endl;
        cout << "2.Delete courier" << endl;
        cout << "3.Update courier " << endl;
        cout << "4.Back " << endl;

        cin >> option;
        switch (option) {
            case 1:
                uiCourierAdd();
                break;
            case 2:
                uiCourierDelete();
                break;
            case 3:
                uiCourierUpdate();
            case 4:
                run = false;
                break;
            default:
                cout << endl << "Optiune invalida" << endl;
                break;
        }
    }

}

void UI::menuCrudOrder() {

}

void UI::menuCrudRestaurant() {
    bool run = true;
    int option;

    while (run)
    {
        cout << "Choose an option " << endl;
        cout << "1.Add restaurant" << endl;
        cout << "2.Delete restaurant" << endl;
        cout << "3.Update restaurant " << endl;
        cout << "4.Back " << endl;

        cin >> option;
        switch (option) {
            case 1:
                uiRestaurantAdd();
                break;
            case 2:
                uiRestaurantDelete();
                break;
            case 3:
                uiRestaurantUpdate();
            case 4:
                run = false;
                break;
            default:
                cout << endl << "Optiune invalida" << endl;
                break;
        }
    }
}

void UI::uiClientAdd() {

}

void UI::uiClientDelete() {

}

void UI::uiClientUpdate() {

}

void UI::uiCourierAdd() {

}

void UI::uiCourierDelete() {

}

void UI::uiCourierUpdate() {

}

void UI::uiOrderAdd() {

}

void UI::uiOrderDelete() {

}

void UI::uiOrderUpdate() {

}

void UI::uiRestaurantAdd() {

}

void UI::uiRestaurantDelete() {

}

void UI::uiRestaurantUpdate() {

}

void UI::uiOrderGetGreaterThan() {

}

void UI::uiOrderGetSmallerThan() {

}

void UI::uiOrderSortBySum() {

}

void UI::uiOrderSortById() {

}

void UI::uiOrderFilterBySum() {

}

void UI::uiOrderFilterByAdress() {

}

void UI::uiOrderGetTotalSumOfRestaurant() {

}

void UI::console() {

}
