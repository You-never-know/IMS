//
// Created by you_never_know on 5. 12. 2021.
//

#ifndef IMS_COVID_H
#define IMS_COVID_H

#include "simlib.h"
#include "covidPhase.hpp"

class CovidProgress : public Event {
private:
    covidStates stateOfCovid = CovidFree;

public:
    covidStates getCovidPhase() { return stateOfCovid; }

    void Behavior() {
        if (stateOfCovid == covidPhase::CovidFree) {
            stateOfCovid = covidPhase::CovidStart;
            Activate(Time + Exponential(30));
        } else if (stateOfCovid == covidPhase::CovidStart) {
            stateOfCovid = covidPhase::CovidPeak;
            Activate(Time + Exponential(40));
        } else if (stateOfCovid == covidPhase::CovidPeak) {
            stateOfCovid = covidPhase::CovidEnd;
            Activate(Time + Exponential(15));
        } else {
            stateOfCovid = covidPhase::CovidFree;
            Activate(Time + Exponential(60));
        }
    }
};


#endif //IMS_COVID_H
