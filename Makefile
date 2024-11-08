CXX = g++

CXXFLAGS = -std=c++11 -Wall

SOURCES = driver.cpp Book.cpp LibraryMember.cpp Library.cpp

OBJECTS = $(SOURCES:.CPP=.O)

EXECUTABLE = group_lab

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJECTS) $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)