//
// Created by you_never_know on 5. 12. 2021.
//

#include "simlib.h"
#include "covidProgress.hpp"
#include "demand.hpp"
#include "data.hpp"

int main(int argc, char** argv) {

    int startSupply = 800;
    int startDemand = 2000;
    double startTime = 0;
    double endTime = 2000;
    // Init the simulation with start and end time
    Init(startTime, endTime);
    CovidProgress *simulation = new CovidProgress();
    simulation->Activate();
    Data * globalData = new Data(startSupply, startDemand);
    (new Demand(simulation, globalData))->Activate();
    // Run the simulation
    Run();
    return 0;
}