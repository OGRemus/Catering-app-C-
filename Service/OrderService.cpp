//
// Created by geo_r on 23/05/2021.
//

#include "OrderService.h"

OrderService::OrderService() {
    repo.setFileName("defaultOrder.txt");
}

OrderService::OrderService(string filename) {
    repo.setFileName(filename);
}

vector<Order> OrderService::getGreaterThan(double sum) {
    vector<Order> result;

    for (auto &i : repo.getAll())
        if (i.getPrice() > sum)
            result.push_back(i);
    return result;
}

vector<Order> OrderService::sortBySum() {
    vector<Order> all = repo.getAll();

    sort(all.begin(), all.end(), compareSum);

    return all;
}

vector<Order> OrderService::sortById() {
    vector<Order> all = repo.getAll();

    sort(all.begin(), all.end(), compareId);

    return all;
}

void OrderService::filterBySum(double sum) {
    vector<Order> all = repo.getAll();
    vector<Order> replace;
    copy_if(all.begin(), all.end(), back_inserter(replace), [sum](const Order& o) { return o.getPrice() == sum; });

    repo.setData(replace);
}

void OrderService::filterByAdress(string address) {
    vector<Order> all = repo.getAll();
    vector<Order> replace;
    copy_if(all.begin(), all.end(), back_inserter(replace), [address](const Order& o) { return o.getAdress() == address; });

    repo.setData(replace);
}

vector<Order> OrderService::getSmallerThan(double sum) {
    vector<Order> result;

    for (auto &i : repo.getAll())
        if (i.getPrice() < sum)
            result.push_back(i);
    return result;
}

bool OrderService::compareSum(Order& o1, Order& o2) {
    return o1.getPrice() < o2.getPrice();

}

bool OrderService::compareId(Order& o1, Order& o2) {
    return o1.getId() < o2.getId();
}

double OrderService::getTotalSumOfRestaurant(string restaurant, vector<Restaurant> res) {

    double sum = 0;
    for(auto &i : repo.getAll())
    {
        for(auto&j : res)
            if(i.getRestaurantId() == j.getId())
                sum+= i.getPrice();
    }

    return sum;
}
