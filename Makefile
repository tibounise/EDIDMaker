TARGET = main.cpp
OUTPUT = edidmaker

all:
	g++ $(TARGET) -o $(OUTPUT)

clean:
	rm -f *.o edidmaker