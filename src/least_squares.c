#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "least_squares.h"

Dataset read_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return (Dataset){NULL, NULL, 0};
    }

    int n;
    fscanf(file, "%d", &n);

    double *x = malloc(n * sizeof(double));
    double *y = malloc(n * sizeof(double));

    if (!x || !y) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return (Dataset){NULL, NULL, 0};
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%lf,%lf", &x[i], &y[i]);
    }
    fclose(file);

    return (Dataset){x, y, n};
}

void solve_least_squares(const Dataset *data, double *slope, double *intercept) {
    double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x2 = 0.0;
    for (int i = 0; i < data->n; i++) {
        sum_x += data->x[i];
        sum_y += data->y[i];
        sum_xy += data->x[i] * data->y[i];
        sum_x2 += data->x[i] * data->x[i];
    }

    *slope = (data->n * sum_xy - sum_x * sum_y) / (data->n * sum_x2 - sum_x * sum_x);
    *intercept = (sum_y - *slope * sum_x) / data->n;
}

void print_solution(double slope, double intercept) {
    printf("Least squares regression line: y = %.4fx + %.4f\n", slope, intercept);
}
