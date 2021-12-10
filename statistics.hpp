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
public:
    Statistics() : unfinishedCount{0} {
        endTime.Clear();
        endChipDemand.Clear();
        endChipStorageCount.Clear();
    }

    void addEndTime(double time) {
        endTime(time);
    }

    void addUnfinishedSimulation() {
        unfinishedCount++;
    }

    void addEndChipStorageCount(unsigned long count) {
        endChipStorageCount(count);
    }

    void addEndChipDemand(unsigned long count) {
        endChipDemand(count);
    }

    void printStatistics(double days) {
        std::cout << "Day when the production reached the demand" << std::endl;
        endTime.Output();
        std::cout << "Chip count at the storage at the final day" << std::endl;
        endChipStorageCount.Output();

        if (unfinishedCount > 0) {
            std::cout << "Simulation did not finish in " << days << " days " << unfinishedCount << " /1000 times."
                      << std::endl;
            std::cout << "End demand:" << std::endl;
            endChipDemand.Output();
        }
    }

};


#endif //IMS_STATISTICS_HPP
