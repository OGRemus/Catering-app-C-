//
// Created by geo_r on 22/05/2021.
//

#include "Order.h"



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
    return address;
}

void Order::setAdress(const string &address) {
    Order::address = address;
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

void Order::setPrice(double price) {
    Order::price = price;
}

bool Order::operator==(const Order &rhs) const {
    return
    courierId == rhs.courierId &&
           clientId == rhs.clientId &&
           address == rhs.address &&
           details == rhs.details &&
           price == rhs.price;
}

Order::Order(int courierId, int clientId,int restaurantId ,string address, string details, double price) : courierId(
        courierId), clientId(clientId), address(std::move(address)), details(std::move(details)), price(price), restaurantId(restaurantId) {}

Order::Order() {
    courierId = 0;
    clientId = 0;
    address = "";
    details = "";
    price = 0;
}

int Order::getRestaurantId() const {
    return restaurantId;
}

void Order::setRestaurantId(int restaurantId) {
    Order::restaurantId = restaurantId;
}

void Order::setPrice1(double price) {
    Order::price = price;
}

ostream &operator<<(ostream &os, const Order &order) {
    if(&os == &cout)
    {
        os << "ID: " <<order.id << " courierId: " << order.courierId << " clientId: " << order.clientId
           << " restaurantId: " << order.restaurantId << " address: " << order.address << " details: " << order.details
           << " price: " << order.price;
    }
    else
    {
        os <<order.id << " " << order.courierId << " " << order.clientId
           << " " << order.restaurantId << " " << order.address << " " << order.details
           << " " << order.price;
    }

    return os;
}

Order &Order::operator=(const Order &order) {

    this->setId(order.getId());
    this->setAdress(order.getAdress());
    this->setClientId(order.getClientId());
    this->setCourierId(order.getCourierId());
    this->setDetails(order.getDetails());
    this->setPrice(order.getPrice());
    return *this;
}

istream &operator>>(istream &is, Order &ord) {
    int id;
    int courierId;
    int clientId;
    int restaurantId;
    string address;
    string details;
    double price;

    is >> id >> courierId >> clientId >> restaurantId >> address >> details >> price;
    ord.setId(id);
    ord.setCourierId(courierId);
    ord.setClientId(clientId);
    ord.setRestaurantId(restaurantId);
    ord.setAdress(address);
    ord.setDetails(details);
    ord.setPrice(price);
    return is;
}

Order::~Order() = default;





