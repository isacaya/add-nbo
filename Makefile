CC = gcc

all: add-nbo

add-nbo: add-nbo.c
	$(CC) -o add-nbo add-nbo.c

clean:
	rm -f add-nbo