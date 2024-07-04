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

matrix transposeSquareMatrix(matrix *m) {
    matrix transposed = getMemMatrix(m->nCols, m->nRows);

    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            transposed.values[j][i] = m->values[i][j];
        }
    }

    return transposed;
}

matrix multiplyMatrices(matrix *a, matrix *b) {
    assert(a->nCols == b->nRows);

    matrix result = getMemMatrix(a->nRows, b->nCols);

    for (int i = 0; i < a->nRows; i++) {
        for (int j = 0; j < b->nCols; j++) {
            result.values[i][j] = 0;
            for (int k = 0; k < a->nCols; k++) {
                result.values[i][j] += a->values[i][k] * b->values[k][j];
            }
        }
    }

    return result;
}

void print_packed_result(matrix m){
    int index = m.nCols - 1;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols - index; j++) {
            printf("%d ", m.values[i][j]);
        }
        printf("\n");
        index--;
    }
    printf("\n");
}

void task9(matrix *m) {
    matrix t_m = transposeSquareMatrix(m);
    matrix result = multiplyMatrices(m, &t_m);
    print_packed_result(result);
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
