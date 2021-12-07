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

    int getDaysCount() const { return _daysCount; }

    int getCovidWave() const { return _covidWave; }

    covidPhase getCovidPhase() const { return _covidPhase; }

    int getBaseDemand() const { return _baseDemand; }

    int getDemandIncrease() const { return _demandIncrease; }

    int getProductionCapacity() const { return _productionCapacity; }

    void setDaysCount(int daysCount);

    void setCovidWave(int covidWave);

    void setCovidPhase(covidPhase covidPhase);

    void setBaseDemand(int baseDemand);

    void setDemandIncrease(int demandIncrease);

    void setProductionCapacity(int productionCapacity);

    void printHelp();

    bool isNumber(std::string str);

private:
    int _daysCount{};
    int _covidWave{};
    covidPhase _covidPhase{};
    int _baseDemand{};
    int _demandIncrease{};
    int _productionCapacity{};
};

std::ostream &operator<<(std::ostream &os, const ArgsParser &ap);

#endif