CXX := g++

CPPFLAGS := -std=c++17 -Wall -Wextra -pedantic -O2
LDFLAGS := -lsimlib
APP := simulation

OBJS = \
	simulation.o

BUILD = $(OBJS) $(APP)

.PHONY: all clean
all: $(APP)

$(APP) : $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

simulation.o: simulation.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@


clean:
	rm -f $(BUILD)