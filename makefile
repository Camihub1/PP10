CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

all: gaussian_dist

gaussian_dist: main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp gaussiandist.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f gaussian_dist main.o
