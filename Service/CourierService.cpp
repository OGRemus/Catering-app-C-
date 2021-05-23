//
// Created by geo_r on 23/05/2021.
//

#include "CourierService.h"

CourierService::CourierService(string filename) {
    repo.setFileName(filename);

}

CourierService::CourierService() {
    repo.setFileName("defaultService.txt");

}
