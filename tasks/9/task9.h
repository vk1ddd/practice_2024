//
// Created by ivanu on 02.07.2024.
//

#ifndef PRACTICE_2024_TASK9_H
#define PRACTICE_2024_TASK9_H

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; ++i) {
        free(m->values[i]);
    }
    free(m->values);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.values[i][j]);
        }
        printf("\n");
    }
}

void print_packed_result(matrix m, int *result){
    int index = 0;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = i; j < m.nCols; j++) {
            printf("%d ", result[index++]);
        }
        printf("\n");
    }
    printf("\n");
}

void task9(matrix *a) {
    int n = a->nRows;
    int* result = (int*) malloc(sizeof(int) * ((n * (n + 1)) / 2));
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += a->values[i][k] * a->values[j][k];
            }
            result[index++] = sum;
        }
    }

    print_packed_result(*a, result);
}

void test1_task9(){
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1}, 3, 3);

    task9(&m);

    freeMemMatrix(&m);
}

void test2_task9(){
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);

    task9(&m);

    freeMemMatrix(&m);
}

void test3_task9(){
    matrix m= createMatrixFromArray((int[]) {1, 2, 3,
                                               2, 3, 4,
                                               3, 4, 5}, 3, 3);

    task9(&m);

    freeMemMatrix(&m);
}

void tests_task9(){
    test1_task9();
    test2_task9();
    test3_task9();
}

#endif //PRACTICE_2024_TASK9_H
