CXX := g++

CPPFLAGS := -std=c++17 -Wall -Wextra -pedantic -O2
LDFLAGS := -lsimlib
APP := simulation

OBJS = \
	simulation.o \
	argsParser.o

BUILD = $(OBJS) $(APP)
HEADERS = \
	generateDemand.hpp \
	argsParser.hpp \
	production.hpp \
	covidProgress.hpp \
	covidPhase.hpp \
	data.hpp \
	demandProcessing.hpp \
	statistics.hpp

.PHONY: all clean
all: $(APP)

$(APP) : $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

simulation.o: simulation.cpp $(HEADERS)
	$(CXX) $(CPPFLAGS) -c $< -o $@

argsParser.o: argsParser.cpp argsParser.hpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

run:
	./simulation

clean:
	rm -f $(BUILD)