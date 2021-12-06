//
// Created by you_never_know on 6. 12. 2021.
//

#ifndef IMS_DATA_H
#define IMS_DATA_H

class Data {
private:
    int supply;
    int demand;
    int defaultSupply = 500;
    int defaultDemand = 1000;
public:
    Data(int supply, int demand) {
        supply = (supply > 0) ? supply : defaultSupply;
        demand = (demand > 0) ? demand : defaultDemand;
        this->supply = supply;
        this->demand = demand;
    }
    Data() {
        this->supply = defaultSupply;
        this->demand = defaultDemand;
    }
    int getDemand () { return demand; }
    int getSupply () { return supply; }

    void changeDemand (int change) {
        this->demand += change;
        if (this->demand < 0) {
            this->demand = 0;
        }
    }
    void changeSupply (int change) {
        this->supply += change;
        if (this->supply < 0) {
            this->supply = 0;
        }
    }
};

#endif //IMS_DATA_H
