#include <stdio.h>
#include <stdlib.h>

#include "least_squares.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    Dataset data = read_data(argv[1]);
    if (data.n == 0) {
        fprintf(stderr, "No data or error reading file\n");
        return 1;
    }

    double slope, intercept;
    solve_least_squares(&data, &slope, &intercept);
    print_solution(slope, intercept);

    free(data.x);
    free(data.y);
    return 0;
}
