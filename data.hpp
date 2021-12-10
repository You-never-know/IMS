//
// Created by you_never_know on 6. 12. 2021.
//

#ifndef IMS_DATA_H
#define IMS_DATA_H

#include <cmath>
#include "covidPhase.hpp"
#include "simlib.h"
#include "statistics.hpp"

/**
 * @brief  Class for storing relevant program data
 */
class Data {
private:
    unsigned long storageChipCount;
    unsigned long chipDemandCount;
    unsigned long currentDemandIncrease;
    int covidWave;
    covidPhase phase;
    unsigned long sellCount;

public:
    Data(unsigned long startDemand, unsigned long startDemandIncrease, int startWave, covidPhase startPhase)
            : storageChipCount{0}, sellCount{0} {
        phase = startPhase;
        covidWave = startWave;
        chipDemandCount = startDemand;
        currentDemandIncrease = startDemandIncrease;
    }

    unsigned long getStorageChipCount() { return storageChipCount; }

    unsigned long getChipDemandCount() { return chipDemandCount; }

    unsigned long getSellCount() { return sellCount; }

    unsigned long getCurrentDemandIncrease() { return currentDemandIncrease; }

    int getCovidWave() { return covidWave; }

    covidPhase getCovidPhase() { return phase; }

    void setStorageChipCount(unsigned long storageCount) { storageChipCount = storageCount; }

    void setChipDemandCount(unsigned long demandCount) { chipDemandCount = demandCount; }

    void setCovidWave(int wave) { covidWave = wave; }

    void setCovidPhase(covidPhase newPhase) { phase = newPhase; }

    /**
     * @brief change the Current Demand Increase by the given percentage
     * @param percentage by which to increase/decrease
     */
    void changeCurrentDemandIncreaseByPercent(double percentage) {
        //std::cout << " Before: " << currentDemandIncrease << std::endl;
        double newPercent = 100.0 + percentage;
        long double newDemand = static_cast<long double>(currentDemandIncrease) / 100.0 * newPercent;
        currentDemandIncrease = static_cast<unsigned long>(newDemand);
        //std::cout << "After: " << currentDemandIncrease << " Percentage: " << newPercent << std::endl;

    }

    void incrementCovidWave() {
        covidWave++;
    }

    void add2storageChipCount(unsigned long addition) { storageChipCount += addition; }

    void add2chipDemandCount(unsigned long addition) { chipDemandCount += addition; }

    /**
     * @brief process demand with chips in stock
     * @param demand
     * @return demand after processing
     */
    unsigned long sellChips(unsigned long demand) {
        if (storageChipCount >= demand) {
            storageChipCount -= demand;
            sellCount += demand;
            return 0;
        } else {
            sellCount += storageChipCount;
            storageChipCount = 0;
            return demand - storageChipCount;
        }
    }
};


#endif //IMS_DATA_H
