CXX= g++
CXXFLAGS= -Wall -g
LIB = -lncurses
OBJFLAG = -c
SRCS = main.o ncurses-menu.o character.o

all: $(SRCS)
	$(CXX) $^ -o $@

*.o: *.cpp
	$(CXX) $(CXXFLAGS) $< $(OBJFLAG) $(LIB)

clean:
	rm -f *.o
