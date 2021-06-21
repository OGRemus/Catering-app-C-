//
// Created by geo_r on 22/05/2021.
//

#ifndef APLICATIELIVRARI_ORDER_H
#define APLICATIELIVRARI_ORDER_H

#include <string>
#include <ostream>
#include "EntityType.h"
#include "Entity.h"

using namespace std;

class Order : public Entity<entityType_Order> {
protected:

    int courierId;
    int clientId;
    int restaurantId;
    string address;
    string details;
    double price;
public:
    int getRestaurantId() const;

    void setRestaurantId(int restaurantId);

    void setPrice1(double price);

    int getCourierId() const;

    void setCourierId(int courierId);

    int getClientId() const;

    void setClientId(int clientId);

    const string &getAdress() const;

    void setAdress(const string &address);

    const string &getDetails() const;

    void setDetails(const string &details);

    virtual double getPrice() const;

    void setPrice(double price);

    bool operator==(const Order &rhs) const;

    Order(int courierId, int clientId, int restaurantId, string address, string details, double price);

    Order();

    ~Order();

    friend ostream &operator<<(ostream &os, const Order &order);

    friend istream &operator>>(istream &is, Order &ord);

    Order &operator=(const Order &order);

};


#endif //APLICATIELIVRARI_ORDER_H
