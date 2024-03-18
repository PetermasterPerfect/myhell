CXX=g++
TARGET=myhell
CFLAGS=-Wall -Wextra -g -o $(TARGET)
SOURCES=main.cpp interpreter.cpp string_logic.cpp
$(TARGET):
	$(CXX) $(CFLAGS) $(SOURCES)
