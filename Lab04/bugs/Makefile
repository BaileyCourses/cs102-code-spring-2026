CXX = g++
CXXFLAGS = -g -Wall -std=c++17

all: test run

test: tests.cc bug2.cpp
	$(CXX) $(CXXFLAGS) -o test tests.cc bug2.cc

run: test
	./test

clean:
	rm -f test
