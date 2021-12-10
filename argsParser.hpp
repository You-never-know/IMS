#pragma once
#ifndef ARGS_PARSER_HPP
#define ARGS_PARSER_HPP

#include <iostream>
#include "covidPhase.hpp"

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
    double _daysCount{};
    int _covidWave{};
    covidPhase _covidPhase{};
    unsigned long _baseDemand{};
    unsigned long _demandIncrease{};
    unsigned long _productionCapacity{};
};

std::ostream &operator<<(std::ostream &os, const ArgsParser &ap);

#endif