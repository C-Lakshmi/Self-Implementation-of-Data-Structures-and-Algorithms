CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall 

# Target executable
TARGET = bfsdfs

# Source files
SRCS = bfsdfs.cpp
HEADERS = bfsdfs.h
# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to link object files and create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ 

# Rule to compile source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean