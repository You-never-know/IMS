//
// Created by you_never_know on 6. 12. 2021.
//

#ifndef IMS_DATA_H
#define IMS_DATA_H

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
    int covidWave;
    covidPhase phase;

public:
    Data(int startDemand, int startWave, covidPhase startPhase) : storageChipCount{0} {
        phase = startPhase;
        covidWave = startWave;
        chipDemandCount = startDemand;
    }

    unsigned long getStorageChipCount() { return storageChipCount; }

    unsigned long getChipDemandCount() { return chipDemandCount; }

    int getCovidWave() { return covidWave; }

    covidPhase getCovidPhase() { return phase; }

    void setStorageChipCount(unsigned long storageCount) { storageChipCount = storageCount; }

    void setChipDemandCount(unsigned long demandCount) { chipDemandCount = demandCount; }

    void setCovidWave(int wave) { covidWave = wave; }

    void setCovidPhase(covidPhase newPhase) { phase = newPhase; }

    void incrementCovidWave() { covidWave++; }

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
            return 0;
        } else {
            storageChipCount = 0;
            return demand - storageChipCount;
        }
    }
};


#endif //IMS_DATA_H
