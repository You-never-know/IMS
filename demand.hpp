//
// Created by you_never_know on 6. 12. 2021.
//

#ifndef IMS_INQUIRY_H
#define IMS_INQUIRY_H

#include "covidProgress.hpp"
#include "data.hpp"
#include <iostream>

class Demand : public Event {
private:
    int currentDemand;
    Data *globalData;
public:
    Demand(Data *data, int startDemand) {
        currentDemand = startDemand;
        globalData = data;
    };

    void Behavior() {
        // change the monthly demand according to the covid phase and covid wave
        // maybe make even the demand Exponential ?
        if (globalData->getCovidPhase() == covidPhase::CovidFree) {

        } else if (globalData->getCovidPhase() == covidPhase::CovidStart) {

        } else if (globalData->getCovidPhase() == covidPhase::CovidPeak) {

        } else {
        }
        // add current Demand to the global Demand
        globalData->add2chipDemandCount(currentDemand);
        Activate(Time + Exponential(14))
    };
};


#endif //IMS_INQUIRY_H
