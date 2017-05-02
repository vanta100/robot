# Makefile for Robot
CXXFLAGS = -std=c++11
LDFLAGS = -L/usr/local/lib -lfltk -lXext -lX11 -lm


all: gui

debug: CXXFLAGS += -g
debug: gui

rebuild: clean gui


gui: Duh_Robot_Proposal_Sprint_6.cpp
	$(CXX) $(CXXFLAGS) $(fltk-config --cxxflags) -o gui Duh_Robot_Proposal_Sprint_6.cpp $(LDFLAGS)

clean:
	-rm -f *.o gui

