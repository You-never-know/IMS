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
    long currentDemand;
    Data *globalData;
    long defaultStartDemand = 7'815'612'903; // demand / 14 days ( calculated as average monthly car sales * average car chip count / 31 * 14)
public:
    GenerateDemand(Data *data, long startDemand) {
        currentDemand = (startDemand > 0) ? startDemand : defaultStartDemand;
        globalData = data;
    };

    void Behavior() {
        // change the monthly demand according to the covid phase and covid wave
        int wave = globalData->getCovidWave();
        if (globalData->getCovidPhase() == covidPhase::CovidFree) {

        } else if (globalData->getCovidPhase() == covidPhase::CovidStart) {

        } else if (globalData->getCovidPhase() == covidPhase::CovidPeak) {

        } else {
        }
        // add current Demand to the global Demand
        globalData->add2chipDemandCount(currentDemand);
        Activate(Time + Exponential(14));
    };
};


#endif //IMS_INQUIRY_H
