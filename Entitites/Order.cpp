//
// Created by geo_r on 22/05/2021.
//

#include "Order.h"

ostream &operator<<(ostream &os, const Order &order) {
    os << "Id: " <<order.id <<" courierId: " << order.courierId << " clientId: " << order.clientId << " adress: " << order.adress
       << " details: " << order.details << " price: " << order.price;
    return os;
}

int Order::getCourierId() const {
    return courierId;
}

void Order::setCourierId(int courierId) {
    Order::courierId = courierId;
}

int Order::getClientId() const {
    return clientId;
}

void Order::setClientId(int clientId) {
    Order::clientId = clientId;
}

const string &Order::getAdress() const {
    return adress;
}

void Order::setAdress(const string &adress) {
    Order::adress = adress;
}

const string &Order::getDetails() const {
    return details;
}

void Order::setDetails(const string &details) {
    Order::details = details;
}

double Order::getPrice() const {
    return price;
}

void Order::setPrice(int price) {
    Order::price = price;
}

bool Order::operator==(const Order &rhs) const {
    return
    courierId == rhs.courierId &&
           clientId == rhs.clientId &&
           adress == rhs.adress &&
           details == rhs.details &&
           price == rhs.price;
}

Order::Order(int courierId, int clientId, string adress, string details, int price) : courierId(
        courierId), clientId(clientId), adress(std::move(adress)), details(std::move(details)), price(price) {}

Order::Order() {
    courierId = 0;
    clientId = 0;
    adress = "";
    details = "";
    price = 0;
}

Order::~Order() = default;




