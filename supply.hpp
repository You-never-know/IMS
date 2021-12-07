//
// Created by you_never_know on 6. 12. 2021.
//

#ifndef IMS_SUPPLY_H
#define IMS_SUPPLY_H

class Supply : public Process {
private:

public:
    Supply() {

    };

    void Behavior() {
        std::cout << stateSource->getCovidPhase() << " , ";
        (new Demand(stateSource))->Activate(Time + Exponential(10));
    };
};


#endif //IMS_SUPPLY_H
