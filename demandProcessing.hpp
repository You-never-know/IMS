//
// Created by you_never_know on 9. 12. 2021.
//

#ifndef IMS_ORDERPROCESSING_H
#define IMS_ORDERPROCESSING_H

#include "simlib.h"
#include "data.hpp"
#include "statistics.hpp"

/**
 * @brief  Class for processing orders
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

    void Behavior() final {
        processDemand();
        Activate(Time + 30); // activate every month
    }

    void processDemand() {
        globalData->setChipDemandCount(globalData->sellChips(globalData->getChipDemandCount()));
        if (globalData->getChipDemandCount() == 0) {
            stats->addEndTime(Time);
            stats->addEndChipStorageCount(globalData->getStorageChipCount());
            Stop();
        }
    }
};


#endif //IMS_ORDERPROCESSING_H
