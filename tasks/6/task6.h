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

void task6(matrix m) {
    int *firstRowValues = (int *)malloc(m.nCols * sizeof(int));
    int firstRowCount = 0;

    for (int i = 0; i < m.nCols; i++) {
        int isUnique = 1;
        for (int j = 0; j < firstRowCount; j++) {
            if (firstRowValues[j] == m.values[0][i]) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            firstRowValues[firstRowCount] = m.values[0][i];
            firstRowCount++;
        }
    }

    for (int k = 0; k < firstRowCount; k++) {
        int value = firstRowValues[k];
        int isInAllRows = 1;
        for (int i = 1; i < m.nRows; i++) {
            int foundInRow = 0;
            for (int j = 0; j < m.nCols; j++) {
                if (m.values[i][j] == value) {
                    foundInRow = 1;
                    break;
                }
            }
            if (!foundInRow) {
                isInAllRows = 0;
                break;
            }
        }
        if (isInAllRows) {
            printf("%d ", value);
        }
    }
    free(firstRowValues);
}


void tests_task6(){
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                   0, 1, 0,
                                   0, 0, 1}, 3, 3);
    task6(m); // Ожидаемый вывод: 0 1
    printf("\n");


    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    task6(m2); // Ожидаемый вывод: пустой вывод
    printf("\n");


    matrix m3 = createMatrixFromArray((int[]) {1, 2, 3,
                                               2, 3, 4,
                                               3, 4, 5}, 3, 3);
    task6(m3); // Ожидаемый вывод: 3
    printf("\n");
}

#endif //PRACTICE_2024_TASK6_H
