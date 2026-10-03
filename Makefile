CC = gcc
CFLAGS = -fopenmp -O2

all: exercise1 exercise2 exercise3 exercise4 exercise5 exercise6 exercise7 exercise8

exercise1: exercise1.c
	$(CC) $(CFLAGS) exercise1.c -o exercise1

exercise2: exercise2.c
	$(CC) $(CFLAGS) exercise2.c -o exercise2

exercise3: exercise3.c
	$(CC) $(CFLAGS) exercise3.c -o exercise3

exercise4: exercise4.c
	$(CC) $(CFLAGS) exercise4.c -o exercise4

exercise5: exercise5.c
	$(CC) $(CFLAGS) exercise5.c -o exercise5

exercise6: exercise6.c
	$(CC) $(CFLAGS) exercise6.c -o exercise6

exercise7: exercise7.c
	$(CC) $(CFLAGS) exercise7.c -o exercise7

exercise8: exercise8.c
	$(CC) $(CFLAGS) exercise8.c -o exercise8

clean:
	rm -f exercise1 exercise2 exercise3 exercise4 exercise5 exercise6 exercise7 exercise8

