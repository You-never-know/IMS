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
    long storageChipCount;
    long chipDemandCount;
    int covidWave;
    covidPhase phase;
    int defaultStartDemand = 200;
    Statistics *stats;

public:
    Data(int startDemand, int startWave, covidPhase startPhase, Statistics *stat) : storageChipCount{0} {
        phase = startPhase;
        covidWave = (startWave >= 0) ? startWave : 0;
        chipDemandCount = (startDemand > 0) ? startDemand : defaultStartDemand;
        stats = stat;
    }

    Data() : storageChipCount{0} {
        phase = covidPhase::CovidFree;
        covidWave = 0;
        chipDemandCount = defaultStartDemand;
    }

    long getStorageChipCount() { return storageChipCount; }

    long getChipDemandCount() { return chipDemandCount; }

    int getCovidWave() { return covidWave; }

    covidPhase getCovidPhase() { return phase; }

    void setStorageChipCount(int storageCount) { storageChipCount = storageCount; }

    void setChipDemandCount(int demandCount) { chipDemandCount = demandCount; }

    void setCovidWave(int wave) { covidWave = wave; }

    void setCovidPhase(covidPhase newPhase) { phase = newPhase; }

    void incrementCovidWave() { covidWave++; }

    void add2storageChipCount(long addition) { storageChipCount += addition; }

    void add2chipDemandCount(long addition) { chipDemandCount += addition; }
};

#endif //IMS_DATA_H
