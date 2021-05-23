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
