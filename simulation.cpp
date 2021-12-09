//
// Created by you_never_know on 5. 12. 2021.
//

#include "simlib.h"
#include "covidProgress.hpp"
#include "generateDemand.hpp"
#include "data.hpp"
#include "argsParser.hpp"
#include "production.hpp"
#include "demandProcessing.hpp"
#include "statistics.hpp"

#define START_TIME 0

int main(int argc, char **argv) {

    ArgsParser args = ArgsParser(argc, argv);
    std::cout << args << std::endl;

    // Init the simulation with start and end time
    Statistics simulationStatistic = Statistics();
    double endTime = (args.getDaysCount() > 10) ? args.getDaysCount() : 1095;
    Init(START_TIME, endTime);
    // create
    Data *globalData = new Data(args.getBaseDemand(), args.getCovidWave(), args.getCovidPhase(), &simulationStatistic);
    (new CovidProgress(globalData))->Activate();
    (new GenerateDemand(globalData, args.getDemandIncrease()))->Activate(Exponential(14));
    (new Production(globalData, args.getProductionCapacity()))->Activate(Exponential(84));
    (new DemandProcessing(globalData, &simulationStatistic))->Activate();
    // Run the simulation
    Run();

    delete (globalData);
    return 0;
}