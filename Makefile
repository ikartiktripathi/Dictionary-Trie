CC = gcc
CFLAGS = -Wall -Wextra -std=c99

TARGET = trie
SOURCE = trie.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

run: $(TARGET)
	./$(TARGET) words

clean:
	rm -f $(TARGET)

