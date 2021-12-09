//
// Created by you_never_know on 9. 12. 2021.
//

#ifndef IMS_ORDERPROCESSING_H
#define IMS_ORDERPROCESSING_H

#include "simlib.h"
#include "data.hpp"
#include "statistics.hpp"

/**
 * @brief  Class for processing orders and taking statistics
 */
class DemandProcessing : public Event {
private:
    Data *globalData;
    Statistics *stats;
public:
    DemandProcessing(Data *data, Statistics *stat) {
        globalData = data;
        stats = stat;
    }

    void Behavior() {

        Activate(Time + 1);
    }
};


#endif //IMS_ORDERPROCESSING_H
