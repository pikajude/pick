// martinkunev's awesome heap implementation
// https://gist.github.com/martinkunev/1365481
//
// WARNING: Requires C99 compatible compiler

typedef struct {
    char *_line;
    int value;
} line;

typedef line *type;

struct heap
{
	unsigned int size; // Size of the allocated memory (in number of items)
	unsigned int count; // Count of the elements in the heap
	type *data; // Array with the elements
};

void heap_init(struct heap *restrict h);
void heap_push(struct heap *restrict h, type value);
void heap_pop(struct heap *restrict h);

// Returns the biggest element in the heap
#define heap_front(h) (*(h)->data)

// Frees the allocated memory
#define heap_term(h) (free((h)->data))

void heapify(type data[restrict], unsigned int count);
