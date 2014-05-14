ARCH = $(shell uname)

ifeq ($(ARCH),Darwin)
	CXX	 = g++
	LINK     = g++
else
	CXX	 = g++
	LINK     = g++
endif

DEBUG    = -g
CXXFLAGS = $(shell fltk-config --cxxflags ) -std=c++11 -I.
LDFLAGS  = $(shell fltk-config --ldflags )
LDSTATIC = $(shell fltk-config --ldstaticflags )

OBJS = stack.o calculator.o calc_button.o

.o:	$@.cpp $@.h
	$(CXX) $(CXXFLAGS) $(DEBUG) -c $@.cpp


main: 	main.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) main.cpp $(OBJS) $(LDFLAGS) -o main


clean: 
	rm -f *.o 2> /dev/null
	rm -f main