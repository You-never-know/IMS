//
// Created by rinaen on 08.12.21.
//

#ifndef IMS_PRODUCTION_H
#define IMS_PRODUCTION_H

#include "simlib.h"
#include "data.hpp"

class Production : public Process {
    Data *_globalData;
    unsigned long _productionCapacity{};
    unsigned long _defaultProductionCapacity = 31'482'739'726; // number of chips made in 84 days

public:
    Production(Data *globalData, unsigned long productionCapacity) : _globalData(globalData) {
        _productionCapacity = (productionCapacity > 0) ? productionCapacity : _defaultProductionCapacity;
    };

    void Behavior() final {
        (new Production(_globalData, _productionCapacity))->Activate(Time + Exponential(84));
        Wait(Exponential(42)); /* testing */
        _globalData->add2storageChipCount(_productionCapacity);
    }

};

#endif //IMS_PRODUCTION_H
