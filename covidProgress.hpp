//
// Created by you_never_know on 5. 12. 2021.
//

#ifndef IMS_COVID_H
#define IMS_COVID_H

#include "simlib.h"
#include "covidPhase.hpp"

class CovidProgress : public Event {
private:
    covidPhase state = covidPhase::CovidFree;
    int wave = 0;

public:
    covidPhase getCovidPhase() { return state; }

    int getCovidWave() const { return wave; }

    void Behavior() {
        if (state == covidPhase::CovidFree) {
            state = covidPhase::CovidStart;
            wave++;
            Activate(Time + Exponential(30));
        } else if (state == covidPhase::CovidStart) {
            state = covidPhase::CovidPeak;
            Activate(Time + Exponential(40));
        } else if (state == covidPhase::CovidPeak) {
            state = covidPhase::CovidEnd;
            Activate(Time + Exponential(15));
        } else {
            state = covidPhase::CovidFree;
            Activate(Time + Exponential(60));
        }
    }
};


#endif //IMS_COVID_H
