TARGET = main.cpp
OUTPUT = edidmaker

all:
	g++ $(TARGET) -o $(OUTPUT) -std=c++11 -g

clean:
	rm -f *.o edidmaker