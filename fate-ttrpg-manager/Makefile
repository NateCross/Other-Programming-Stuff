CXX=g++
CXXFLAGS= -Wall -g
OBJFLAG = -c

main: main.o fancyTerminal.o character.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(OBJFLAG) $^

fancyTerminal.o: lib/fancyTerminal.cpp lib/fancyTerminal.hpp
	$(CXX) $(CXXFLAGS) $(OBJFLAG) $^

character.o: character.cpp character.hpp
	$(CXX) $(CXXFLAGS) $(OBJFLAG) $^

clean:
	rm -f *.o
