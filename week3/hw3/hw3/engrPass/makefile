
CXX = g++
CXXFLAGS = -std=c++0x

SRCS1 = knapsack.cpp
SRCS2 = knapsack_extra_done.cpp

all: program1 program2

program1: ${SRCS1}
	${CXX} ${CXXFLAGS} ${SRCS1} -o knapsackTest
	
program2: ${SRCS2}
	${CXX} ${CXXFLAGS} ${SRCS2} -o knapsackAllTest
	
clean:
	rm knapsackTest knapsackAllTest
