//
// Created by you_never_know on 5. 12. 2021.
//

#ifndef IMS_COVID_H
#define IMS_COVID_H
#include "simlib.h"

enum covidState {CovidFree, CovidStart, CovidPeak, CovidEnd};

class CovidProgress : public Event {
private:
    covidState state = CovidFree;
    int wave = 0;

public:
    covidState  getCovidState () { return state; }
    int         getCovidWave () { return wave; }

    void Behavior() {
        if (state == CovidFree) {
            state = CovidStart;
            wave++;
            Activate(Time + Exponential(30));
        } else if (state == CovidStart) {
            state = CovidPeak;
            Activate(Time + Exponential(40));
        } else if (state == CovidPeak) {
            state = CovidEnd;
            Activate(Time + Exponential(15));
        } else {
            state = CovidFree;
            Activate(Time + Exponential(60));
        }
    }
};


#endif //IMS_COVID_H
