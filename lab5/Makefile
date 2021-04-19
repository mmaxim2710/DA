CXX = g++
CXXFLAGS = -std=c++17 -pedantic -Wall -O2

EXECUTABLE = solution

EXE_SRC = main.cpp
EXE_OBJ = $(EXE_SRC:.cpp=.o)

all: $(EXECUTABLE)

$(EXECUTABLE) : $(EXE_OBJ)
	$(CXX) $(CXXFLAGS) $(EXE_OBJ) -o $(EXECUTABLE)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXECUTABLE) $(BENCH)
