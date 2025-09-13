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
export CXXFLAGS = ${INCLUDE}

SUBDIRS = $(wildcard */)
SUBMODULES = $(foreach dir, $(SUBDIRS),$(dir)$(subst /,.a,$(dir)))
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: clean

#all: craftplusplus
all: craftplusplus

craftplusplus: $(OBJECTS) $(SUBMODULES)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.a:
	cd $(dir $@) && make

clean-subdirs: $(SUBDIRS)
	@for d in $(SUBDIRS); do \
		cd $$d && make clean; \
		cd ..; \
    done

clean: clean-subdirs
	rm -f craftplusplus *.o *.a