CXX      = g++
<<<<<<< HEAD
CXXFLAGS = -g -Wall -std=gnu++11
=======
CPPFLAGS = -g -Wall -std=gnu++11
>>>>>>> seq_alt
OMP      = -fopenmp
SHELL    = /bin/sh
DEBUG    = -O0
PROFILE  = -pq

SOURCES  = $(shell echo *.cpp)
HEADERS  = $(shell echo *.h)
OBJECTS  = $(SOURCES:.cpp=.o)
TARGET   = ewolucja

.PHONY: clean cleanest rebuild all

profile: CPPFLAGS += $(PROFILE)
profile: rebuild

omp: CPPFLAGS += $(OMP)
omp: rebuild

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo Building target file
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	@echo Building object files
	$(CXX) $(CXXFLAGS) -c -o $@ $^  

clean:
	rm -f $(OBJECTS)

cleanest: clean
	rm $(TARGET)

rebuild: cleanest all
