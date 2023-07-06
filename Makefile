CC = g++

SRCDIR := src

CFLAGS = -std=c++11

TARGET = heap_operations

DEPENDENCIES = ${SRCDIR}/heap.cpp ${SRCDIR}/heap.h

all: $(TARGET)

$(TARGET): ${SRCDIR}/main.cpp $(DEPENDENCIES)
	$(CC) $(CFLAGS) -o $(TARGET) ${SRCDIR}/main.cpp $(DEPENDENCIES)

clean:
	rm -f $(TARGET)