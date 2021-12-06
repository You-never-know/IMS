//
// Created by you_never_know on 6. 12. 2021.
//

#ifndef IMS_INQUIRY_H
#define IMS_INQUIRY_H
#include "covidProgress.h"
#include <iostream>

class Demand : public Process {
private:
    CovidProgress * stateSource;
public:
    Demand(CovidProgress * simulation) {
        stateSource = simulation;
    };
    void Behavior() {
        std::cout << stateSource->getCovidState() << " , ";
        (new Demand(stateSource))->Activate(Time + Exponential(10));
    };
};


#endif //IMS_INQUIRY_H
