#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "heap.h"

line *make_ln(char *l) {
    line *le = malloc(sizeof(line));
    le->_line = malloc(sizeof(char) * (strlen(l) + 1));
    strcpy(le->_line, l);
    le->value = rand();
    return le;
}

int main(int argc, char **argv) {
    int count;

    if(argv[1] == NULL) {
        printf("Usage: %s count [input-file]\n", argv[0]);
        exit(0);
    } else
        count = atoi(argv[1]);

    FILE *input;
    if(argv[2] == NULL || strcmp(argv[2], "-") == 0)
        input = stdin;
    else
        input = fopen(argv[2], "r");

    if(input == NULL) {
        printf("Unable to open file %s for reading.\n", argv[2]);
        exit(1);
    }

    srand(time(NULL));
    struct heap *hs = malloc(sizeof(struct heap *));
    heap_init(hs);

    char l[24] = {0};
    while(fgets(l, sizeof l, input) != NULL) {
        heap_push(hs, make_ln(l));
        if(hs->count > count) heap_pop(hs);
    }

    while(hs->count > 0) {
        printf("%s", heap_front(hs)->_line);
        heap_pop(hs);
    }
    return 0;
}
