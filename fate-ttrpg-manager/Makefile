CXX=g++
CXXFLAGS= -Wall -g
OBJFLAG = -c
SRC=$(wildcard *.o)
objects=character.o lib/fancyTerminal.o

all: $(objects) main.cpp
	$(CXX) $(CXXFLAGS) -o main $^

$(objects): %.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) $(OBJFLAG) -o $^

test: main.o character.o lib/fancyTerminal.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean: 
	rm -f *.o
