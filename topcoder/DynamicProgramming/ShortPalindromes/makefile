BOOST_ROOT=/usr/include/boost
CXX=g++
CXXFLAGS= -g
TARGET=ShortPalindromes

all:example

OBJECTS=main.o

example:$(OBJECTS)
	$(CXX) -g -I/usr/include -o $(TARGET) $(OBJECTS)

clean:
	-rm -f $(TARGET) $(OBJECTS)
