//
// Created by geo_r on 23/05/2021.
//

#ifndef APLICATIELIVRARI_ORDERSERVICE_H
#define APLICATIELIVRARI_ORDERSERVICE_H
#include "MasterService.h"

class OrderService: public MasterService<Order, entityType_Order> {
public:
    OrderService();
    OrderService(string filename);
    vector<Order> getGreaterThan(double sum);
    vector<Order> getSmallerThan(double sum);
    vector<Order> sortBySum();
    vector<Order> sortById();
    void filterBySum(double sum);
    void filterByAdress(string adress);
    static bool compareSum(Order& o1, Order& o2);
    static bool compareId(Order& o1, Order& o2);
    double getTotalSumOfRestaurant(string restaurant, restaurantRepo&);
};


#endif //APLICATIELIVRARI_ORDERSERVICE_H
