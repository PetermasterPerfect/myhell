CXX=g++
CFLAGS=-Wall -Wextra -g
SOURCES=main.cpp interpreter.cpp string_logic.cpp
TARGET=myhell
$(TARGET):
	$(CXX) $(CFLAGS) $(SOURCES)
