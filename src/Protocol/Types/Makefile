# Creator: Kurt M. Weber
#
# Created on: 2025-09-10
# 
#  This file is part of CraftPlusPlus.
# 
#  Licensed under Hippocratic License with clauses:
#  HL3-CL-ECO-EXTR-FFD-MEDIA-MY-SUP-SV-TAL-USTA-XUAR See file LICENSE for full
#  licensing information.

AR = ar
ARFLAGS = -crsT

SUBDIRS = $(wildcard */)
SUBMODULES = $(foreach dir, $(SUBDIRS),$(dir)$(subst /,.a,$(dir)))
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

CURDIR = $(shell basename `pwd`)
CURMODULE = $(CURDIR).a

.PHONY: clean

all: $(CURMODULE)

$(CURMODULE): $(OBJECTS) $(SUBMODULES)
	$(AR) $(ARFLAGS) $@ $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.a:
	cd $(dir $@) && make

clean-subdirs: $(SUBDIRS)
	$(foreach dir,$(SUBDIRS),cd $(dir) && make clean)

clean: clean-subdirs
	rm -f *.o *.a