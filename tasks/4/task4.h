//
// Created by ivanu on 27.06.2024.
//

#ifndef PRACTICE_2024_TASK4_H
#define PRACTICE_2024_TASK4_H

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void task4(const int *A, int size, int *result) {
    int sum = A[0];

    for (int i = 0; i < size; i++) {
        result[i] = sum;
        sum = 0;
        for (int j = 0; j < i + 1; j++) {
            sum += A[j];
        }
    }

    print_array(result, size);
    printf("\n");
}

void test1_task4() {
    int size = 5;
    int A[5] = {1, 2, 3, 4, 5};

    int result[size];
    task4(A, size, result);

    assert(result[0] == 1);
    assert(result[1] == 1);
    assert(result[2] == 3);
    assert(result[3] == 6);
    assert(result[4] == 10);
}

void test2_task4() {
    int size = 4;
    int A[4] = {0, 0, 1, 0};

    int result[size];
    task4(A, size, result);

    assert(result[0] == 0);
    assert(result[1] == 0);
    assert(result[2] == 0);
    assert(result[3] == 1);
}

void test3_task4() {
    int size = 8;
    int A[8] = {12, 3, 7, 23, 44, 1, 4, 45};

    int result[size];
    task4(A, size, result);

    assert(result[0] == 12);
    assert(result[1] == 12);
    assert(result[2] == 15);
    assert(result[3] == 22);
    assert(result[4] == 45);
    assert(result[5] == 89);
    assert(result[6] == 90);
    assert(result[7] == 94);
}

void tests_task4() {
    test1_task4();
    test2_task4();
    test3_task4();
}

#endif //PRACTICE_2024_TASK4_H
