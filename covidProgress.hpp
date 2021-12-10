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
    explicit CovidProgress(Data *data) {
        globalData = data;
    }

    void Behavior() final {
        if (globalData->getCovidPhase() == covidPhase::CovidFree) {
            globalData->setCovidPhase(covidPhase::CovidStart);
            globalData->incrementCovidWave();
            if (globalData->getCovidWave() == 1) {
                Activate(Time + Exponential(126));
            } else if (globalData->getCovidWave() == 2) {
                Activate(Time + Exponential(56));
            } else {
                Activate(Time + Exponential(49));
            }
        } else if (globalData->getCovidPhase() == covidPhase::CovidStart) {
            globalData->setCovidPhase(covidPhase::CovidPeak);
            if (globalData->getCovidWave() == 1) {
                Activate(Time + Exponential(63));
            } else if (globalData->getCovidWave() == 2) {
                Activate(Time + Exponential(70));
            } else {
                Activate(Time + Exponential(28));
            }
        } else if (globalData->getCovidPhase() == covidPhase::CovidPeak) {
            globalData->setCovidPhase(covidPhase::CovidEnd);
            if (globalData->getCovidWave() == 1) {
                Activate(Time + Exponential(7));
            } else if (globalData->getCovidWave() == 2) {
                Activate(Time + Exponential(42));
            } else {
                Activate(Time + Exponential(49));
            }
        } else {
            globalData->setCovidPhase(covidPhase::CovidFree);
            Activate(Time + Exponential(42));
        }
    }
};


#endif //IMS_COVID_H
