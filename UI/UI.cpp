//
// Created by geo_r on 24/05/2021.
//

#include "UI.h"
#include <iostream>
#include "../Validator/ClientValidator.h"
#include "..//Exceptions/ExistingIdException.h"


using namespace std;

UI::UI() {
    this->clServ = ClientService("ClientRepo.txt");
    this->couServ = CourierService("CourierRepo.txt");
    this->resServ = RestaurantService("RestaurantRepo.txt");
    this->ordServ = OrderService("OrderRepo.txt");

}

void UI::menu() {
    bool run = true;
    int option;
    while (run) {
        cout << endl;
        cout << "Choose an option: " << endl;
        cout << "1.Crud client" << endl;
        cout << "2.Crud courier" << endl;
        cout << "3.Crud order" << endl;
        cout << "4.Crud restaurant" << endl;
        cout << "5.Exit ";
        cout << endl;
        cin >> option;
        switch (option) {
            case 1:
                menuCrudClient();
                break;
            case 2:
                menuCrudCourier();
                break;
            case 3:
                menuCrudOrder();
                break;
            case 4:
                menuCrudRestaurant();
                break;
            case 5:
                run = false;
                break;
            default:
                cout << endl << "Invalid option " << endl;
                break;
        }

    }

}

void UI::menuCrudClient() {
    bool run = true;
    int option;

    while (run) {
        cout << endl;
        cout << "Choose an option " << endl;
        cout << "1.Add client" << endl;
        cout << "2.Delete client" << endl;
        cout << "3.Update client " << endl;
        cout << "4.Show all " << endl;
        cout << "5.Back " << endl;

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
                break;
            case 4:
                for (auto &i : clServ.getAll())
                    cout << i << endl;
                break;
            case 5:
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

    while (run) {
        cout << endl;
        cout << "Choose an option " << endl;
        cout << "1.Add courier" << endl;
        cout << "2.Delete courier" << endl;
        cout << "3.Update courier " << endl;
        cout << "4.Show all " << endl;
        cout << "5.Back " << endl;

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
                break;
            case 4:
                for (auto &i: couServ.getAll())
                    cout << i << endl;
                break;
            case 5:
                run = false;
                break;
            default:
                cout << endl << "Optiune invalida" << endl;
                break;
        }
    }

}


void UI::menuCrudRestaurant() {
    bool run = true;
    int option;

    while (run) {
        cout << endl;
        cout << "Choose an option " << endl;
        cout << "1.Add restaurant" << endl;
        cout << "2.Delete restaurant" << endl;
        cout << "3.Update restaurant " << endl;
        cout << "4.Show all " << endl;
        cout << "5.Back " << endl;

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
                break;
            case 4:
                for(auto &i : resServ.getAll())
                    cout << i << endl;
                break;
            case 5:
                run = false;
                break;
            default:
                cout << endl << "Optiune invalida" << endl;
                break;
        }
    }
}

void UI::uiClientAdd() {
    ClientValidator validate;
    try {
        string address;
        string username;
        bool premium;
        cout << "Offer the address, username and premium status(0 = false/1 = true) ";
        cin >> address >> username >> premium;
        Client cl = Client(address, username, premium);
        validate.validate(cl);
        clServ.addElem(cl);
    }
    catch (ValidationException &msg) {
        cout << msg.toString() << endl;
    }
}

void UI::uiClientDelete() {
    try {
        int id;
        cout << "Give client's id to be deleted ";
        cin >> id;
        Client cl = clServ.getById(id);
        clServ.deleteElem(cl);
    }
    catch (NonExistingIdException &e) {
        cout << e.getMsg() << endl;
    }


}

void UI::uiClientUpdate() {
    try {
        int oldId;
        cout << "Offer the id of the client to be updated ";
        cin >> oldId;
        Client cl = clServ.getById(oldId);

        string address;
        string user;
        bool premium;
        cout << "Offer the details of the new client ";
        cin >> address >> user >> premium;

        ClientValidator validate;

        Client newCl = Client(address, user, premium);
        validate.validate(newCl);

        clServ.updateElem(cl, newCl);
    }
    catch (NonExistingIdException &e) {
        cout << e.getMsg() << endl;
    }
    catch (ValidationException &v) {
        cout << v.toString() << endl;
    }
    catch (ExistingIdException &ex) {
        cout << ex.getMsg() << endl;
    }
}

void UI::uiCourierAdd() {
    try {
        string name;
        cout << "Offer the courier's name ";
        cin >> name;

        if (name == "")
            throw (runtime_error("Name cant be empty "));
        Courier c = Courier(name);
        couServ.addElem(c);

    }
    catch (runtime_error &e) {
        cout << e.what();
    }
    catch (ExistingIdException &e) {
        cout << e.getMsg() << endl;
    }
}

void UI::uiCourierDelete() {
    try {
        int id;
        cout << "Offer the id of the courier to be deleted ";
        cin >> id;
        Courier del = couServ.getById(id);

        couServ.deleteElem(del);

    }
    catch (NonExistingIdException &e) {
        cout << e.getMsg();
    }
}

void UI::uiCourierUpdate() {
    try {
        int id;
        cout << "Offer the id of the courier to be updated ";
        cin >> id;
        Courier old = couServ.getById(id);

        string name;
        cout << "Offer the new courier name ";
        cin >> name;
        if (name == "")
            throw (runtime_error("Courier name cant be empty"));
        Courier newCou = Courier(name);
        couServ.updateElem(old, newCou);
    }
    catch (NonExistingIdException &e) {
        cout << e.getMsg() << endl;
    }
    catch (runtime_error &r) {
        cout << r.what() << endl;
    }
}

void UI::menuCrudOrder() {
    bool run = true;
    int option;
    while (run) {
        cout << endl;
        cout << "Choose an option " << endl;
        cout << "1.Add order " << endl;
        cout << "2.Delete order " << endl;
        cout << "3.Update order " << endl;
        cout << "4.Functionalities " << endl;
        cout << "5.Show all " << endl;
        cout << "6.Back ";
        cout << endl;

        cin >> option;

        switch (option) {
            case 1:
                uiOrderAdd();
                break;
            case 2:
                uiOrderDelete();
                break;
            case 3:
                uiOrderUpdate();
                break;
            case 4:
                uiOrderFunctionalities();
                break;
            case 5:
                for (auto &i: ordServ.getAll())
                    cout << i << endl;
                break;
            case 6:
                run = false;
                break;
            default:
                cout << "Invalid option " << endl;

        }

    }
}

void UI::uiOrderAdd() {
    try {
        int courierId;
        int clientId;
        int restaurantId;
        string address;
        string details;
        double price;

        cout << "Courier id : ";
        cin >> courierId;
        cout << endl;
        cout <<"Client id ";
        cin >>clientId;
        cout << endl;
        cout << "RestaurantId ";
        cin >> restaurantId ;
        cout << endl;
        cout << "Address ";
        cin >> address ;
        cout << endl;
        cout << "Details ";
        cin >> details ;
        cout << endl;
        cout << "Price ";
        cin >> price;
        cout << endl;
        if(price < 0)
            throw runtime_error("Price should be positive ");
        couServ.getById(courierId).getId();
//        if (couServ.getById(courierId).getId() == 0)

//            throw NonExistingIdException("The courier with the id provided does not exist !");
        if (clServ.getById(clientId).getId() == 0)
            throw NonExistingIdException("The client with the id provided does not exist ! ");

        if (resServ.getById(restaurantId).getId() == 0)
            throw NonExistingIdException("The restaurant with the id provided does not exist");


        if (clServ.getById(clientId).isPremium()) {

            Order add = Order(courierId, clientId, restaurantId, address, details, price * 0.9);
            ordServ.addElem(add);
        } else {
            Order add = Order(courierId, clientId, restaurantId, address, details, price);
            ordServ.addElem(add);
        }


    }
    catch (NonExistingIdException &e) {
        cout << e.getMsg() << endl;
    }
    catch (ExistingIdException &e) {
        cout << e.getMsg();
    }
    catch (runtime_error& e) {
        cout << e.what() << endl;

    }
}

void UI::uiOrderDelete() {
    try {
        int id;
        cout << "Ofer the order id to be deleted  ";
        cin >> id;
        Order o = ordServ.getById(id);
        ordServ.deleteElem(o);
    }
    catch (NonExistingIdException &e) {
        cout << e.getMsg();
    }
}

void UI::uiOrderUpdate() {
    try {
        int oldId;
        cout << "Offer the id of the order to be updated";
        cin >> oldId;
        Order old = ordServ.getById(oldId);

        cout << "Offer the new information about the order ";
        int courierId;
        int clientId;
        int restaurantId;
        string address;
        string details;
        double price;
        cout << "Courier id : ";
        cin >> courierId;
        cout << endl;
        cout <<"Client id ";
        cin >>clientId;
        cout << endl;
        cout << "RestaurantId ";
        cin >> restaurantId ;
        cout << endl;
        cout << "Address ";
        cin >> address ;
        cout << endl;
        cout << "Details ";
        cin >> details ;
        cout << endl;
        cout << "Price ";
        cin >> price;
        cout << endl;

        if(price < 0)
            throw runtime_error("Price should be positive ");

        if (couServ.getById(courierId).getId() == 0)
            throw NonExistingIdException("The courier with the id provided does not exist !");
        if (clServ.getById(clientId).getId() == 0)
            throw NonExistingIdException("The client with the id provided does not exist ! ");

        if (resServ.getById(restaurantId).getId() == 0)
            throw NonExistingIdException("The restaurant with the id provided does not exist !");


        if (clServ.getById(clientId).isPremium()) {
            price = price * 0.9;
            Order newOrd = Order(courierId, clientId, restaurantId, address, details, price);

        } else {
            Order newOrd = Order(courierId, clientId, restaurantId, address, details, price);
            ordServ.updateElem(old, newOrd);
        }

    }
    catch (NonExistingIdException &e) {
        cout << e.getMsg() << endl;
    }
    catch (runtime_error& r) {
        cout << r.what() << endl;
    }

}


void UI::uiRestaurantAdd() {
    try {
        string name;
        string address;
        cout << "Offer name and the address of the restaurant ";
        cin >> name >> address;
        Restaurant r = Restaurant(name, address);
        resServ.addElem(r);

    }
    catch (ExistingIdException &e) {
        cout << e.getMsg() << endl;
    }
}

void UI::uiRestaurantDelete() {
    try {
        int id;
        cout << "Offer the id of the restaurant to be deleted ";
        cin >> id;
        Restaurant r = resServ.getById(id);

    }
    catch (NonExistingIdException &e) {
        cout << e.getMsg() << endl;
    }

}

void UI::uiRestaurantUpdate() {
    try {
        int id;
        cout << "Offer the id of the restaurant to be updated ";
        cin >> id;
        Restaurant old = resServ.getById(id);

        string name;
        string address;

        cin >> name >> address;
        if (name == "" || address == "")
            throw runtime_error("Name or address cant be empty");

        Restaurant newRes = Restaurant(name, address);

        resServ.updateElem(old, newRes);
    }
    catch (runtime_error &r) {
        cout << r.what();
    }
    catch (NonExistingIdException &e) {
        cout << e.getMsg() << endl;
    }
}

void UI::uiOrderGetGreaterThan() {
    double sum;
    cout << "Offer the value to compare to ";
    cin >> sum;
    vector<Order> res = ordServ.getGreaterThan(sum);
    for (auto &i : res)
        cout << i << endl;
}

void UI::uiOrderGetSmallerThan() {
    double sum;
    cout << "Offer the value to compare to ";
    cin >> sum;
    vector<Order> res = ordServ.getSmallerThan(sum);
    for (auto &i : res)
        cout << i << endl;
}

void UI::uiOrderSortBySum() {
    vector<Order> res = ordServ.sortBySum();
    for (auto &i : res)
        cout << i << endl;
}

void UI::uiOrderSortById() {
    vector<Order> res = ordServ.sortById();
    for (auto &i : res)
        cout << i << endl;
}

void UI::uiOrderFilterBySum() {
    double sum;
    cout << "Offer the sum to filter by ";
    cin >> sum;
    ordServ.filterBySum(sum);
}

void UI::uiOrderFilterByAdress() {
    string address;
    cout << "Offer the address to filter by ";
    cin >> address;

    ordServ.filterByAdress(address);
}

void UI::uiOrderGetTotalSumOfRestaurant() {
    string restaurant;
    cout << "Offer the name o the restaurant to compute total sum of orders ";
    cin >> restaurant;
    vector<Restaurant> miniRepo = resServ.getByName(restaurant);
    double sum = ordServ.getTotalSumOfRestaurant(restaurant, miniRepo);
    cout << "The total value of deliveries is " << sum;
}


void UI::uiOrderFunctionalities() {
    bool run = true;
    int option;
    while (run) {
        cout << endl;
        cout << "Choose an option " << endl;
        cout << "1.Get all orders with the price greater than a value " << endl;
        cout << "2.Get all orders with the price smaller than a value " << endl;
        cout << "3.Print the orders sorted by price " << endl;
        cout << "4.Print all orders sorted by id " << endl;
        cout << "5.Filter orders by a certain sum " << endl;
        cout << "6.Filter orders by a certain address " << endl;
        cout << "7.Print the total price of ordres for a certain restaurant " << endl;
        cout << "8.Back";
        cout << endl;

        cin >> option;

        switch (option) {
            case 1:
                uiOrderGetGreaterThan();
                break;
            case 2:
                uiOrderGetSmallerThan();
                break;
            case 3:
                uiOrderSortBySum();
                break;
            case 4:
                uiOrderSortById();
                break;
            case 5:
                uiOrderFilterBySum();
                break;
            case 6:
                uiOrderFilterByAdress();
                break;
            case 7:
                uiOrderGetTotalSumOfRestaurant();
            case 8:
                run = false;
                break;
            default:
                cout << "Invalid option " << endl;

        }

    }
}

void UI::console() {

    clServ.loadFromFile();
    couServ.loadFromFile();
    ordServ.loadFromFile();
    resServ.loadFromFile();
    menu();
}
