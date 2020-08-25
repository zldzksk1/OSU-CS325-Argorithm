
CXX = g++
CXXFLAGS = -std=c++0x

SRCS1 = badsort_fa.cpp
SRCS2 = modified_badsort.cpp

all: program1 program2

program1: ${SRCS1}
	${CXX} ${CXXFLAGS} ${SRCS1} -o badTest

program2: ${SRCS2}
	${CXX} ${CXXFLAGS} ${SRCS2} -o badTtest
	
clean:
	rm badTest badTtest
