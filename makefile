CC = gcc

SRC = QuickSort.c QS.c stack.c

TARGET = quicksort

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -Wall -Wextra -std=c11 -Wno-unused-result -o $(TARGET) $(SRC)


clean:
	rm -f $(TARGET) *.o


run: $(TARGET)
	./$(TARGET)
