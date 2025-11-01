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
DEPFILES=$(SOURCES:.cpp=.d)

.PHONY: clean

all: craftplusplus

#include $(SOURCES:.cpp=.d)

craftplusplus: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) -MMD -MP $(CXXFLAGS) -c $< -o $@

clean:
	rm -f craftplusplus $(OBJECTS) $(DEPFILES)

#%.d: %.cpp
#	@set -e; rm -f $@; \
#	$(CXX) -MM $(CXXFLAGS) $< > $@.$$$$; \
#	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
#	rm -f $@.$$$$

-include $(DEPFILES)