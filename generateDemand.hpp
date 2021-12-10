//
// Created by you_never_know on 6. 12. 2021.
//

#ifndef IMS_INQUIRY_H
#define IMS_INQUIRY_H

#include "covidProgress.hpp"
#include "data.hpp"
#include <iostream>

/**
 * @brief  Class for generating demand according to the covid phase and wave
 */
class GenerateDemand : public Event {
private:
    Data *globalData;
public:
    explicit GenerateDemand(Data *data) {
        globalData = data;
    };

    void Behavior() final {
        // add current Demand to the global Demand
        globalData->add2chipDemandCount(globalData->getCurrentDemandIncrease());
        Activate(Time + Exponential(14));
    };
};


#endif //IMS_INQUIRY_H
