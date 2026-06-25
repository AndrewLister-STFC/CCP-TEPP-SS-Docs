/// @file least_squares.h
/// Compute a least squares regression

#ifndef LEAST_SQUARES_H
#define LEAST_SQUARES_H

typedef struct {
    double *x;
    double *y;
    int n;
} Dataset;

Dataset read_data(const char *filename);
void solve_least_squares(const Dataset *data, double *slope, double *intercept);
void print_solution(double slope, double intercept);

#endif // LEAST_SQUARES_H
