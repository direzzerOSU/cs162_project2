
CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = -lboost_date_time

OBJS = main.o menu.o game.o inputValidation.o zoo.o

SRCS = main.cpp menu.cpp game.cpp inputValidation.cpp zoo.cpp

HEADERS = menu.hpp game.hpp inputValidation.hpp zoo.hpp

#target: dependencies
#	rule to build
#

zooTycoon: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o zooTycoon

#${OBJS}: ${SRCS}
#	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
