#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_input(char* argv[]) {
        char* str_input = argv[1];
        return atoi(str_input);
}

char** init_grid(size_t size) {
        char** grid = (char**)malloc(size * sizeof(char*));
                for(int i = 0; i < size; i++) {
                        grid[i] = (char*)malloc(size * sizeof(char));
                
                        /* set every value to 32, which is decimal for \s char */
                        memset(grid[i], 32, size);
                }

                return(grid);
}

void gen_result(char** grid, size_t size) {
        for(int i = 0; i < size; i++) {
                int startpos = i, 
                    endindex = size - 1, 
                    endpos = endindex - i;

                for(int j = 0; j < size; j++) {
                        grid[i][startpos] = '*';
                        grid[i][endpos] = '*';
                }
        }
}

void display_result(char** grid, size_t size) {
        for(int i = 0; i < size; i++)
                printf("%s\n", grid[i]);
}

int main(int argc, char* argv[]) {
        size_t size = get_input(argv);
        char** grid = init_grid(size);
        gen_result(grid, size);
        display_result(grid, size);
        return(EXIT_SUCCESS);
}
