all:
	c99 -O2 heap.c main.c -o pick

clean:
	rm -f pick
