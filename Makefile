TARGET = main.cpp
OUTPUT = edidmaker

CXX = clang++
FLAGS = -std=c++0x

all:
	$(CXX) $(TARGET) -o $(OUTPUT) $(FLAGS)

debug:
	$(CXX) $(TARGET) -o $(OUTPUT) $(FLAGS) -g

clean:
	rm -f *.o edid.bin $(OUTPUT)
	rm -rf $(OUTPUT).dSYM/