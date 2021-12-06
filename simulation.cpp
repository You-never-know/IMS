//
// Created by you_never_know on 5. 12. 2021.
//

#include "simlib.h"
#include "covidProgress.h"
#include "demand.h"

int main(int argc, char** argv) {

    double startTime = 0;
    double endTime = 2000;
    // Init the simulation with start and end time
    Init(startTime, endTime);
    CovidProgress *simulation = new CovidProgress();
    simulation->Activate();
    (new Demand(simulation))->Activate();
    // Run the simulation
    Run();
    return 0;
}