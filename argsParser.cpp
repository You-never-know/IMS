#include "argsParser.hpp"
#include <getopt.h>

/**
 * @brief Operator (<<) applied to an output stream
 * @param  &os: pointer to a streambuf object from whose controlled input
 * sequence the characters are copied.
 * @param  &ap: a function that takes and returns a stream object. It generally
 * is a manipulator function.
 * @retval streambuf object
 */
std::ostream &operator<<(std::ostream &os, const ArgsParser &ap) {
    os << "Days count: " << ap.getDaysCount() << std::endl
       << "Covid wave: " << ap.getCovidWave() << std::endl
       << "Covid phase: " << getValueKey(ap.getCovidPhase()) << std::endl
       << "Initial chip demand: " << ap.getBaseDemand() << std::endl
       << "Regular increase in chip demand: " << ap.getDemandIncrease() << std::endl
       << "Chip production capacity: " << ap.getProductionCapacity() << std::endl;
    return os;
}

/**
 * @brief  Prints program help
 * @retval None
 */
void ArgsParser::printHelp() {
    std::cout << "usage: ./simulation [ <option> ]"
              << std::endl
              << "Options:" << std::endl
              << "[-h | --help]" << std::endl
              << "  Show this help" << std::endl
              << "[-t | --days-count]  <days-count>" << std::endl
              << "  Number of days to simulate"
              << std::endl
              << "[-w | --covid-wave]    <covid-wave>" << std::endl
              << "  The current wave of covid" << std::endl
              << std::endl
              << "[-f | --covid-phase]    <covid-phase>" << std::endl
              << "  The current phase of covid" << std::endl
              << std::endl
              << "[-d | --base-demand]    <base-demand>" << std::endl
              << "  Initial chip demand" << std::endl
              << std::endl
              << "[-i | --demand-increase]    <demand-increase>" << std::endl
              << "  The value of the regular increase in chip demand" << std::endl
              << std::endl
              << "[-c | --production-capacity]    <production-capacity>" << std::endl
              << "  Chip production capacity" << std::endl
              << std::endl;
}

/**
 * @brief  Checks if string is a number
 * @param  str: string to be checked
 * @retval True: string is a number | False: string is not a number
 */
bool ArgsParser::isNumber(const std::string str) {
    for (auto c: str) {
        if (!std::isdigit(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;
}

ArgsParser::ArgsParser(int argc, char **argv) {
    int c;


    /* Process arguments */
    static struct option _long_options[] = {
            {"days-count",          required_argument, 0, 't'},
            {"covid-wave",          required_argument, 0, 'w'},
            {"covid-phase",         required_argument, 0, 'f'},
            {"base-demand",         required_argument, 0, 'd'},
            {"demand-increase",     required_argument, 0, 'i'},
            {"production-capacity", required_argument, 0, 'c'},
            {"help",                no_argument,       0, 'h'},
            {0, 0,                                     0, 0}};

    int option_index;
    while ((c = getopt_long(argc, argv, "t:w:f:d:i:c:h", _long_options, &option_index)) !=
           -1) {
        switch (c) {

            case 0: {
                break;
            }
            case 't': {
                if (!isNumber(std::string(optarg))) {
                    std::cerr << "Invalid days-count argument - must be a number!" << std::endl;
                    exit(1);
                }
                _daysCount = std::stod(std::string(optarg));
                break;
            }
            case 'w': {
                if (!isNumber(std::string(optarg))) {
                    std::cerr << "Invalid covid-wave argument - must be a number!" << std::endl;
                    exit(1);
                }
                _covidWave = std::stoi(std::string(optarg));
                break;
            }
            case 'f': {
                if (covidPhaseMap.find(std::string(optarg)) != covidPhaseMap.end()) {
                    _covidPhase = covidPhaseMap.find(std::string(optarg))->second;
                } else {
                    std::cerr
                            << "Invalid covid-phase argument - must be one of: CovidFree, CovidStart, CovidPeak or CovidEnd"
                            << std::endl;
                    exit(1);
                }
                break;
            }
            case 'd': {
                if (!isNumber(std::string(optarg))) {
                    std::cerr << "Invalid base-demand argument - must be a number!" << std::endl;
                    exit(1);
                }
                _baseDemand = std::stoul(std::string(optarg));
                break;
            }
            case 'i': {
                if (!isNumber(std::string(optarg))) {
                    std::cerr << "Invalid demand-increase argument - must be a number!" << std::endl;
                    exit(1);
                }
                _demandIncrease = std::stoul(std::string(optarg));
                break;
            }
            case 'c': {
                if (!isNumber(std::string(optarg))) {
                    std::cerr << "Invalid production-capacity argument - must be a number!" << std::endl;
                    exit(1);
                }
                _productionCapacity = std::stoul(std::string(optarg));
                break;
            }
            case 'h': {
                printHelp();
                exit(0);
            }
            default: {
                std::cerr << "Invalid arguments" << std::endl;
                exit(1);
            }
        }
    }

    int i = optind;
    if (i < argc) {
        std::cerr << "Invalid arguments" << std::endl;
        exit(1);
    }
}
