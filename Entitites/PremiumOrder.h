//
// Created by geo_r on 22/05/2021.
//

#ifndef APLICATIELIVRARI_PREMIUMORDER_H
#define APLICATIELIVRARI_PREMIUMORDER_H
#include "Order.h"

class PremiumOrder: public Order {
public:
    double getPrice() const override;
};


#endif //APLICATIELIVRARI_PREMIUMORDER_H
