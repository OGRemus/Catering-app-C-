//
// Created by geo_r on 23/05/2021.
//

#include "RestaurantService.h"

RestaurantService::RestaurantService(string filename) {
    repo.setFileName(filename);
}

RestaurantService::RestaurantService() {
    repo.setFileName("defaultRestaurant.txt");
}

restaurantRepo RestaurantService::getRepo() {
    return this->repo;
}

vector <Restaurant> RestaurantService::getByName(string name) {
    vector<Restaurant> res;
    for(auto&i : repo.getAll())
        if(i.getName() == name)
            res.push_back(i);

    return res;
}
