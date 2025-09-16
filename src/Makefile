# Creator: Kurt M. Weber
#
# Created on: 2025-09-10
# 
#  This file is part of CraftPlusPlus.
# 
#  Licensed under Hippocratic License with clauses:
#  HL3-CL-ECO-EXTR-FFD-MEDIA-MY-SUP-SV-TAL-USTA-XUAR See file LICENSE for full
#  licensing information.

export CXX = g++
export INCLUDE = -I$(shell pwd)
export CXXFLAGS = -std=c++20 ${INCLUDE}

SOURCES=$(shell find . -type f -iname '*.cpp' | sort)
OBJECTS=$(SOURCES:.cpp=.o)

#all: craftplusplus

all: craftplusplus

craftplusplus: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f craftplusplus $(OBJECTS)