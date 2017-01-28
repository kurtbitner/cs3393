#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define DEFAULT_COLUMNS 10
#define DEFAULT_ROWS 10

/* typedef struct line {
	int num_of_chars;
	int num_of_cells;
} */

typedef struct {
	int neighbors;
} CELL;

typedef struct {
	uintptr_t* cells;
} LINE;

int main(int argc, char* argv[])
{
	FILE* f = fopen("life.txt", "r");
	LINE* *lines = malloc(DEFAULT_ROWS * sizeof(LINE*));
	/* for (int i = 0; i < DEFAULT_ROWS; i++) {
    	lines[i] = NULL;
	} */

	if (f) {
		for (int i = 0; i < DEFAULT_ROWS; i++) {
    		char* s = malloc(DEFAULT_COLUMNS);
			s = fgets(s, DEFAULT_COLUMNS, f);
			if (s) {
    			uintptr_t* cells = malloc(DEFAULT_COLUMNS * sizeof(uintptr_t));
					for (int i = 0; i < DEFAULT_COLUMNS; i++) {
    					char c = s[i];
    					if (c) {
    						CELL* cell = malloc(sizeof(CELL));
    						cell->neighbors = 0;
    						cells[i] = (uintptr_t)cell;
						}
				}
				LINE *line = malloc(sizeof(LINE));
				line->cells = cells;
				lines[i] = line;
			}
		}
	}
	if (lines) {
		for (int i = 0; i < DEFAULT_ROWS; i++) {
			for (int j = 0; j < DEFAULT_COLUMNS; j++) {
				if (lines[i]) {
    				if (lines[i]->cells[j]) {
    				printf("*");
					}
					else {
    					printf(" ");
					}
					
				}
			}
			printf("\n");
		}
		
	}
	else {
    printf("failure\n");
	}
	//printf("x is %i", x);
}
