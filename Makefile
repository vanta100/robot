# Makefile for Robot
CXXFLAGS += --std=c++11
LDFLAGS = -L/usr/local/lib -lfltk -lXext -lX11 -lm


all: robot

debug: CXXFLAGS += -g
debug: robot

rebuild: clean robot


robot: Duh_Robot_Proposal_Sprint_4.cpp
	$(CXX) $(CXXFLAGS) $(fltk-config --cxxflags) -o robot Duh_Robot_Proposal_Sprint_4.cpp $(LDFLAGS)

clean:
	-rm -f *.o robot

