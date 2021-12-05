//
// Created by you_never_know on 5. 12. 2021.
//

#include "simlib.h"

int main(int argc, char** argv) {

    double startTime = 0;
    double endTime = 2000;
    // Init the simulation with start and end time
    Init(startTime, endTime);
    // Run the simulation
    Run();
    return 0;
}