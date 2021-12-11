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

public:
    Production(Data *globalData, unsigned long productionCapacity) : _globalData(globalData),
                                                                     _productionCapacity(productionCapacity) {};

    void Behavior() final {
        (new Production(_globalData, _productionCapacity))->Activate(Time + Normal(84, 8));
        Wait(Normal(42, 8)); /* testing */
        _globalData->add2storageChipCount(_productionCapacity);
    }

};

#endif //IMS_PRODUCTION_H
