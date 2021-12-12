//
// Created by you_never_know on 9. 12. 2021.
//

#ifndef IMS_STATISTICS_HPP
#define IMS_STATISTICS_HPP

#include "simlib.h"
#include <iostream>

class Statistics {
private:
    Stat endTime;
    Stat endChipStorageCount;
    Stat endChipDemand;
    unsigned int unfinishedCount;
    Stat sellCount;
    Stat demand;
public:
    Statistics() : unfinishedCount{0} {
        endTime.Clear();
        endChipDemand.Clear();
        endChipStorageCount.Clear();
        sellCount.Clear();
        demand.Clear();
    }

    void addEndTime(double time) {
        endTime(time);
    }

    void addUnfinishedSimulation() {
        unfinishedCount++;
    }

    void addEndChipStorageCount(unsigned long count) {
        endChipStorageCount(static_cast<double>(count));
    }

    void addEndChipDemand(unsigned long count) {
        endChipDemand(static_cast<double>(count));
    }

    void addDemand(unsigned long count) {
        demand(static_cast<double>(count));
    }

    void addSellCount(unsigned long count) {
        sellCount(static_cast<double>(count));
    }

    void printStatistics(double days) {
        std::cout << "Day when the production reached the demand" << std::endl;
        endTime.Output();
        std::cout << "Chip count at the storage at the final day in successful runs" << std::endl;
        endChipStorageCount.Output();
        std::cout << "Average demand" << std::endl;
        demand.Output();
        std::cout << "Chip sold" << std::endl;
        endChipStorageCount.Output();

        if (unfinishedCount > 0) {
            std::cout << "Simulation did not finish " << unfinishedCount << " of 100 000 times in " << days << " days."
                      << std::endl;
            std::cout << "End demand in simulations that did not finish:" << std::endl;
            endChipDemand.Output();
        }
    }

};


#endif //IMS_STATISTICS_HPP
