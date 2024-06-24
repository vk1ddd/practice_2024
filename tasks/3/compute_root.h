//
// Created by Иван on 24.06.2024.
//

#ifndef PRACTICE_2024_COMPUTE_ROOT_H
#define PRACTICE_2024_COMPUTE_ROOT_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

double compute_root(double a, double p, double E, double x0) {
    double x_prev = x0;
    double x_next = 0.0;
    int iterations = 0;

    x_next = (x_prev / pow(p, 2)) * ((pow(p, 2) - 1) + 0.5 * (p + 1) * (a / pow(x_prev, p)) - 0.5 * (p - 1) * (pow(x_prev, p) / a));
    iterations++;

    while(fabs(x_next - x_prev) > E) {
        x_prev = x_next;
        x_next = (x_prev / pow(p, 2)) * ((pow(p, 2) - 1) + 0.5 * (p + 1) * (a / pow(x_prev, p)) - 0.5 * (p - 1) * (pow(x_prev, p) / a));
        iterations++;
    }

    printf("Количество итераций: %d\n", iterations);
    return x_next;
}

void test1_compute_root() {
    double a = 8.0;
    double p = 3.0;
    double E = 0.0001;
    double x0 = 1.0;

    double root = compute_root(a, p, E, x0);
    assert(fabs(root - pow(a, 1.0/p)) <= E);
}

void test2_compute_root() {
    double a = 27.0;
    double p = 3.0;
    double E = 0.0001;
    double x0 = 1.0;

    double root = compute_root(a, p, E, x0);
    assert(fabs(root - pow(a, 1.0/p)) <= E);
}

void tests_compute_root() {
    test1_compute_root();
    test2_compute_root();
}

#endif //PRACTICE_2024_COMPUTE_ROOT_H
