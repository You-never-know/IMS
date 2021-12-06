//
// Created by you_never_know on 6. 12. 2021.
//

#ifndef IMS_INQUIRY_H
#define IMS_INQUIRY_H
#include "covidProgress.hpp"
#include "data.hpp"
#include <iostream>

class Demand : public Process {
private:
    CovidProgress * stateSource;
    Data * data;
public:
    Demand(CovidProgress * simulation, Data * data) {
        stateSource = simulation;
        this->data = data;
    };
    void Behavior() {
        std::cout << stateSource->getCovidState() << " , ";
        (new Demand(stateSource, data))->Activate(Time + Exponential(10));
    };
};


#endif //IMS_INQUIRY_H
