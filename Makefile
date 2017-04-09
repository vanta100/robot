# Makefile for Robot
CXXFLAGS += --std=c++11


all: robot

debug: CXXFLAGS += -g
debug: robot

rebuild: clean robot

robot: Duh_Robot_Proposal_Sprint_3.o
	$(CXX) $(CXXFLAGS) Duh_Robot_Proposal_Sprint_3.o

robot.o: Duh_Robot_Proposal_Sprint_3.cpp
	$(CXX) $(CXXFLAGS) -c Duh_Robot_Proposal_Sprint_3.cpp

clean:
	-rm -f *.o *~ a.out

