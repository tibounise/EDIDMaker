TARGET = main.cpp
OUTPUT = edidmaker

CXX = g++
FLAGS = -std=c++11

all:
	$(CXX) $(TARGET) -o $(OUTPUT) $(FLAGS)

debug:
	$(CXX) $(TARGET) -o $(OUTPUT) $(FLAGS) -g

clean:
	rm -f *.o edid.bin $(OUTPUT)
	rm -rf $(OUTPUT).dSYM/