CC = gcc
CFLAGS = -g -std=c99 -w -pipe -O3

all: kp7

print:    raz_matrix.o
	$(CC) $^ -o $@

kp7:  raz_matrix.o kp7.o
	$(CC) $^ -o $@

clean:
	rm -f *.o

cleanall:
	rm -f kp7 *.o

