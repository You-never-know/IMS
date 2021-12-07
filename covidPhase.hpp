#ifndef COVID_PHASE
#define COVID_PHASE

#include <string>
#include <iostream>
#include <unordered_map>

enum class covidPhase {
    CovidFree, CovidStart, CovidPeak, CovidEnd
};

static std::unordered_map<std::string, covidPhase> const covidPhaseMap{
        {"CovidFree",  (covidPhase::CovidFree)},
        {"CovidStart", (covidPhase::CovidStart)},
        {"CovidPeak",  (covidPhase::CovidPeak)},
        {"CovidEnd",   (covidPhase::CovidEnd)}
};

static std::string getValueKey(covidPhase _covidPhase) {
    for (std::unordered_map<std::string, covidPhase>::const_iterator it = covidPhaseMap.begin();
         it != covidPhaseMap.end(); ++it) {
        if (it->second == _covidPhase) return it->first;
    }
    return NULL;
}

#endif