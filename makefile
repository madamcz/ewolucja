CXX      = g++
CPPFLAGS = -g -Wall -std=gnu++11
OMP      = -fopenmp
SHELL    = /bin/sh
DEBUG    = -O0
PROFILE  = -pq

SOURCES  = $(shell echo src/*.cpp)
HEADERS  = $(shell )
OBJECTS  = $(SOURCE:.cpp=.o)
TARGET   = ewolucja

.PHONY: clean cleanest rebuild all

profile: CPPFLAGS += $(PROFILE)
profile: rebuild

omp: CPPFLAGS += $(OMP)
omp: rebuild

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo Building target file
	$(CXX) $(CPPFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp $(HEADERS)
	@echo Building object files
	$(CXX) $(CPPFLAGS) -c -o $@ $^  

clean:
	rm -f $(OBJECTS)

cleanest: clean
	rm $(TARGET)

rebuild: cleanest all
