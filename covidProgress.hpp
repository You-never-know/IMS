//
// Created by you_never_know on 5. 12. 2021.
//

#ifndef IMS_COVID_H
#define IMS_COVID_H

#include "simlib.h"
#include "covidPhase.hpp"
#include "data.hpp"

/**
 * @brief  Class for simulating covid progress
 */
class CovidProgress : public Event {
private:
    Data *globalData;

public:
    CovidProgress(Data *data) {
        globalData = data;
        if (globalData->getCovidPhase() == covidPhase::CovidFree) {
            globalData->setCovidPhase(covidPhase::CovidEnd);
        } else if (globalData->getCovidPhase() == covidPhase::CovidStart) {
            globalData->setCovidPhase(covidPhase::CovidFree);
        } else if (globalData->getCovidPhase() == covidPhase::CovidPeak) {
            globalData->setCovidPhase(covidPhase::CovidStart);
        } else {
            globalData->setCovidPhase(covidPhase::CovidPeak);
        }
    }

    void Behavior() {
        if (globalData->getCovidPhase() == covidPhase::CovidFree) {
            globalData->setCovidPhase(covidPhase::CovidStart);
            globalData->incrementCovidWave();
            Activate(Time + Exponential(42));
        } else if (globalData->getCovidPhase() == covidPhase::CovidStart) {
            globalData->setCovidPhase(covidPhase::CovidPeak);
            Activate(Time + Exponential(28));
        } else if (globalData->getCovidPhase() == covidPhase::CovidPeak) {
            globalData->setCovidPhase(covidPhase::CovidEnd);
            Activate(Time + Exponential(42));
        } else {
            globalData->setCovidPhase(covidPhase::CovidFree);
            Activate(Time + Exponential(28));
        }
    }
};


#endif //IMS_COVID_H
