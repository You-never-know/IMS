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
                globalData->changeCurrentDemandIncreaseByPercent(-48.313);
                Activate(Time + Exponential(126));
            } else if (globalData->getCovidWave() == 2) {
                globalData->changeCurrentDemandIncreaseByPercent(-3.086);
                Activate(Time + Exponential(56));
            } else {
                if (globalData->getCovidWave() == 3) {
                    globalData->changeCurrentDemandIncreaseByPercent(-5.189);
                } else if (globalData->getCovidWave() == 4) {
                    globalData->changeCurrentDemandIncreaseByPercent(-19.558);
                } else {
                    double percentage = -1 * Normal(19.0365, 8);
                    globalData->changeCurrentDemandIncreaseByPercent(percentage);
                }
                Activate(Time + Exponential(49));
            }
        } else if (globalData->getCovidPhase() == covidPhase::CovidStart) {
            globalData->setCovidPhase(covidPhase::CovidPeak);
            if (globalData->getCovidWave() == 1) {
                globalData->changeCurrentDemandIncreaseByPercent(74.947);
                Activate(Time + Exponential(63));
            } else if (globalData->getCovidWave() == 2) {
                globalData->changeCurrentDemandIncreaseByPercent(2.633);
                Activate(Time + Exponential(70));
            } else {
                if (globalData->getCovidWave() == 3) {
                    globalData->changeCurrentDemandIncreaseByPercent(9.70);
                } else if (globalData->getCovidWave() == 4) {
                    globalData->changeCurrentDemandIncreaseByPercent(-10.604);
                } else {
                    double percentage = Normal(39.169, 8) - 20.0;
                    globalData->changeCurrentDemandIncreaseByPercent(percentage);
                }
                Activate(Time + Exponential(28));
            }
        } else if (globalData->getCovidPhase() == covidPhase::CovidPeak) {
            globalData->setCovidPhase(covidPhase::CovidEnd);
            if (globalData->getCovidWave() == 1) {
                globalData->changeCurrentDemandIncreaseByPercent(6.143);
                Activate(Time + Exponential(7));
            } else if (globalData->getCovidWave() == 2) {
                globalData->changeCurrentDemandIncreaseByPercent(2.094);
                Activate(Time + Exponential(42));
            } else {
                if (globalData->getCovidWave() == 3) {
                    globalData->changeCurrentDemandIncreaseByPercent(2.314);
                } else if (globalData->getCovidWave() == 4) {
                    globalData->changeCurrentDemandIncreaseByPercent(-0.807);
                } else {
                    double percentage = Normal(22.436, 8) - 20.0;
                    globalData->changeCurrentDemandIncreaseByPercent(percentage);
                }
                Activate(Time + Exponential(49));
            }
        } else {
            if (globalData->getCovidWave() == 1) {
                globalData->changeCurrentDemandIncreaseByPercent(0.880);
            } else if (globalData->getCovidWave() == 2) {
                globalData->changeCurrentDemandIncreaseByPercent(1.029);
            } else if (globalData->getCovidWave() == 3) {
                globalData->changeCurrentDemandIncreaseByPercent(1.131);
            } else if (globalData->getCovidWave() == 4) {
                globalData->changeCurrentDemandIncreaseByPercent(-0.388);
            } else {
                double percentage = Normal(10.663, 8) - 10.0;
                globalData->changeCurrentDemandIncreaseByPercent(percentage);
            }
            globalData->setCovidPhase(covidPhase::CovidFree);
            Activate(Time + Exponential(42));
        }
    }
};


#endif //IMS_COVID_H
