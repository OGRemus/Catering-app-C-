//
// Created by geo_r on 23/05/2021.
//

#ifndef APLICATIELIVRARI_COURIERSERVICE_H
#define APLICATIELIVRARI_COURIERSERVICE_H
#include "MasterService.h"

class CourierService : public MasterService<Courier, entityType_Courier> {
public:
    CourierService(string filename);
    CourierService();
};


#endif //APLICATIELIVRARI_COURIERSERVICE_H
