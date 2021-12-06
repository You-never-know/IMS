#pragma once
#ifndef ARGS_PARSER_HPP
#define ARGS_PARSER_HPP
#include <iostream>

/**
 * @brief  Class for parsing program arguments
 * @retval None
 */
class ArgsParser {
public:
  ArgsParser(int argc, char **argv);
  ~ArgsParser() = default;

  int getDaysCount() { return _daysCount; }
  int getCovidWave() { return _covidWave; }
  int getCovidPhase() { return _covidPhase; }
  int getBaseDemand() { return _baseDemand; }
  int getProductionCapacity() { return _productionCapacity; }

  void setDaysCount(int daysCount);
  void setCovidWave(int covidWave);
  void setCovidPhase(int covidPhase);
  void setBaseDemand(int baseDemand);
  void setProductionCapacity(int productionCapacity);

private:
  int _daysCount{};
  int _covidWave{};  /* TODO is int? enum? */
  int _covidPhase{}; /* TODO is int? enum? */
  int _baseDemand{};
  int _productionCapacity{};
};

std::ostream &operator<<(std::ostream &os, const ArgsParser &ap);

#endif