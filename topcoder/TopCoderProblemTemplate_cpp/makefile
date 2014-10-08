.PHONY	= all clean distclean
TARGET	= app
OPT		= -g -O0 -Wall
CC		= gcc
CXX		= g++
SOURCES	= $(wildcard *.c) $(wildcard *.cc) $(wildcard *.cxx) $(wildcard *.cpp) 
OBJS	= $(addsuffix .o, $(basename $(SOURCES)))
CFLAGS		+= $(OPT)
CXXFLAGS	+= $(OPT)
all : $(TARGET)
$(TARGET) :$(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@
clean:
	rm -rf *.o *.d core* *.bak
distclean: clean
	rm -rf $(TARGET)

# common block
# add auto dependency generation to default rule
COMPILE.c	+= -MMD
COMPILE.cc	+= -MMD
DFILES   := $(OBJS:.o=.d)
ifneq (${MAKECMDGOALS}, clean)
 -include $(DFILES)
endif
# end of common block