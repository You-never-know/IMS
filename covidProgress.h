//
// Created by you_never_know on 5. 12. 2021.
//

#ifndef IMS_COVID_H
#define IMS_COVID_H
#include "simlib.h"

enum covidStates {CovidFree, CovidStart, CovidPeak, CovidEnd};

class CovidProgress : public Event {
private:
    covidStates stateOfCovid = CovidFree;

public:
    covidStates getCovidState () { return stateOfCovid; }

    void Behavior() {
        if (stateOfCovid == CovidFree) {
            stateOfCovid = CovidStart;
            Activate(Time + Exponential(30));
        } else if (stateOfCovid == CovidStart) {
            stateOfCovid = CovidPeak;
            Activate(Time + Exponential(40));
        } else if (stateOfCovid == CovidPeak) {
            stateOfCovid = CovidEnd;
            Activate(Time + Exponential(15));
        } else {
            stateOfCovid = CovidFree;
            Activate(Time + Exponential(60));
        }
    }
};


#endif //IMS_COVID_H
