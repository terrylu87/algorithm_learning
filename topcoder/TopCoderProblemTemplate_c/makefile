#CXX=mipsel-linux-gnu-g++
#CC=laura-linux-gnu-gcc
CC=gcc
CXX=g++
CFLAGS= -g -Wall -lpthread
#CFLAGS= -g -Wall -march=laura1x
TARGET_DIR=./bin
BUILD_DIR=./build

TARGET_NAME=hello_topcoder

PROJECT=$(TARGET_NAME)
TARGET=$(TARGET_DIR)/$(TARGET_NAME)

all:example

OBJ_DIR=$(BUILD_DIR)/$(PROJECT)

OBJECTS=main.o

INCPATH= -I.
#INCPATH+= -I../common
#INCPATH+= -I./list -I./common -I./testcase

#VPATH+= %.c ./list
#VPATH+= %.c ./testcase

SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

$(OBJECTS):%.o: %.c dir_ready
	$(CC) -g -c $(INCPATH) $< -o $(OBJ_DIR)/$@ $(CFLAGS)

example:$(OBJECTS)
	$(CC)  $(INCPATH) -o $(TARGET) $(OBJ) $(CFLAGS)

dir_ready:
	mkdir -p $(TARGET_DIR)
	mkdir -p $(OBJ_DIR)

clean:
	-rm -rf $(BUILD_DIR) $(TARGET_DIR)
