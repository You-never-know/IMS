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
#include <iostream>

#define START_TIME 0

int main(int argc, char **argv) {

    ArgsParser args = ArgsParser(argc, argv);
    std::cout << args << std::endl;
    Statistics simulationStatistic = Statistics();
    double endTime = (args.getDaysCount() > 10) ? args.getDaysCount() : 1095;
    
    // Run the simulation x times
    for (unsigned i = 0; i < 100000; i++) {
        // Init the simulation with start and end time
        Init(START_TIME, endTime);
        // Create processes and events
        Data *globalData = new Data(args.getBaseDemand(), args.getCovidWave(), args.getCovidPhase(),
                                    &simulationStatistic);
        (new CovidProgress(globalData))->Activate();
        (new GenerateDemand(globalData, args.getDemandIncrease()))->Activate(Exponential(14));
        (new Production(globalData, args.getProductionCapacity()))->Activate(Exponential(84));
        (new DemandProcessing(globalData, &simulationStatistic))->Activate();
        // Run the simulation
        Run();
        // Process the demand to make the final state
        if (globalData->getChipDemandCount() != 0) {
            globalData->setChipDemandCount(globalData->sellChips(globalData->getChipDemandCount()));
            if (globalData->getChipDemandCount() == 0) {
                simulationStatistic.addEndTime(Time);
                simulationStatistic.addEndChipStorageCount(globalData->getStorageChipCount());
            } else {
                simulationStatistic.addUnfinishedSimulation();
                simulationStatistic.addEndChipDemand(globalData->getChipDemandCount());
            }
        }
        delete (globalData);
    }
    simulationStatistic.printStatistics(endTime);
    return 0;
}