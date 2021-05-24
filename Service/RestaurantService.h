//
// Created by geo_r on 23/05/2021.
//

#ifndef APLICATIELIVRARI_RESTAURANTSERVICE_H
#define APLICATIELIVRARI_RESTAURANTSERVICE_H
#include "MasterService.h"

class RestaurantService: public MasterService<Restaurant, entityType_Restaurant> {
public:
    RestaurantService(string filename);
    RestaurantService();
};


#endif //APLICATIELIVRARI_RESTAURANTSERVICE_H
