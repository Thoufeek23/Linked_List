# Compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Target executable name
TARGET = linkedlist

# Source files
SRCS = main.cpp LinkedList.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Compile the program
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp files into .o object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)
