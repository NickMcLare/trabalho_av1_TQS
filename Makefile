CC = gcc
CFLAGS = -Wall -Wextra -g -Isrc -lm
SRC = src/bilhetes_zoo.c
TEST = test/test.c
OUTPUT = output/test.exe

all: dirs build

dirs:
	mkdir -p output

build: $(SRC) $(TEST)
	$(CC) $(CFLAGS) $(SRC) $(TEST) -o $(OUTPUT)

run: build
	./$(OUTPUT)

test: build
	@echo "Running tests..."
	@./$(OUTPUT)

clean:
	rm -rf output

.PHONY: all dirs build run test clean