#pragma once
#ifndef ARGS_PARSER_HPP
#define ARGS_PARSER_HPP

#include <iostream>
#include "covidPhase.hpp"
#include "simlib.h"

/**
 * @brief  Class for parsing program arguments
 * @retval None
 */
class ArgsParser {
public:
    ArgsParser(int argc, char **argv);

    ~ArgsParser() = default;

    double getDaysCount() const { return _daysCount; }

    int getCovidWave() const { return _covidWave; }

    covidPhase getCovidPhase() const { return _covidPhase; }

    unsigned long getBaseDemand() const { return _baseDemand; }

    unsigned long getDemandIncrease() const { return _demandIncrease; }

    unsigned long getProductionCapacity() const { return _productionCapacity; }

    void printHelp();

    bool isNumber(std::string str);

private:
    double _daysCount{1095};
    int _covidWave{0};
    covidPhase _covidPhase{covidPhase::CovidFree};
    unsigned long _baseDemand{static_cast<unsigned long>(Normal(2'500'000'000, 1'000'000))};
    unsigned long _demandIncrease{7'933'333'333}; // demand / 14 days
    unsigned long _productionCapacity{31'482'739'726}; // production / 84 days (production takes ~84 days)
};

std::ostream &operator<<(std::ostream &os, const ArgsParser &ap);

#endif