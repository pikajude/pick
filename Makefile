all:
	c99 heap.c main.c -o pick

clean:
	rm -f pick
