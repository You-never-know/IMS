//
// Created by rinaen on 08.12.21.
//

#ifndef IMS_PRODUCTION_H
#define IMS_PRODUCTION_H

#include "simlib.h"
#include "data.hpp"

class Production : public Process {
    Data *_globalData;
    long _productionCapacity{};

public:
    Production(Data *globalData, long productionCapacity) : _globalData(globalData),
                                                            _productionCapacity(productionCapacity) {};

    void Behavior() {
        (new Production(_globalData, _productionCapacity))->Activate(Time + Exponential(84));
        Wait(Exponential(42)); /* testing */
        _globalData->add2storageChipCount(_productionCapacity);
    }

};

#endif //IMS_PRODUCTION_H
