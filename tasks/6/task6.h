//
// Created by ivanu on 28.06.2024.
//

#ifndef PRACTICE_2024_TASK6_H
#define PRACTICE_2024_TASK6_H

typedef struct matrix {
    int **values; //элементы  матрицы
    int nRows; //количество  рядов
    int nCols; //количество  столбцов
} matrix;

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    assert(values != NULL);
    for (int i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
        assert(values[i] != NULL);
    }
    return (matrix) {values, nRows, nCols};
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

void print_array_without_num(int *array, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (array[i] != num)
            printf("%d ", array[i]);
    }
    printf("\n");
}

void check(int *result, const int *row, int size, int sum) {
    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (result[i] == row[j])
                index = 1;
        }
        if (index == 0)
            result[i] = sum;
        index = 0;
    }
}

void task6(matrix m) {
    int *result = m.values[0];
    //sum - переменная, которая будет хранить в себе элемент,
    //которого точно нету в массиве result
    int sum = 0;
    for (int i = 0; i < m.nCols; i++) {
        sum += result[i] + 1;
    }

    for (int i = 0; i < m.nRows; i++) {
        check(result, m.values[i], m.nCols, sum);
    }

    print_array_without_num(result, m.nCols, sum);
}

void tests_task6() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1}, 3, 3);
    task6(m); // Ожидаемый вывод: 0 1


    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    task6(m2); // Ожидаемый вывод: пустой вывод


    matrix m3 = createMatrixFromArray((int[]) {1, 2, 3,
                                               2, 3, 4,
                                               3, 4, 5}, 3, 3);
    task6(m3); // Ожидаемый вывод: 3
}

#endif //PRACTICE_2024_TASK6_H
