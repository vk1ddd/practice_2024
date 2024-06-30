//
// Created by ivanu on 27.06.2024.
//

#ifndef PRACTICE_2024_TASK5_H
#define PRACTICE_2024_TASK5_H

void task5(const int *A, int size, int *result) {
    int l_index = 0;
    int r_index = size - 1;
    int min_num = A[0];

    for (int i = 0; i < size; i++) {
        if (A[i] < min_num) {
            min_num = A[i];
        }
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
        if (index == 0) {
            result[l_index] = min_num;
            l_index++;
            index = 1;
        } else {
            result[r_index] = min_num;
            r_index--;
            index = 0;
        }

        int last_min = min_num;
        min_num = 999999999;
        for (int j = 0; j < size; j++) {
            if (A[j] < min_num && A[j] > last_min) {
                min_num = A[j];
            }
        }
    }

    print_array(result, size);
    printf("\n");
}

void test1_task5() {
    int size = 5;
    int A[5] = {1, 2, 3, 4, 5};

    int result[size];
    task5(A, size, result);

    assert(result[0] == 1);
    assert(result[1] == 3);
    assert(result[2] == 5);
    assert(result[3] == 4);
    assert(result[4] == 2);
}

void test2_task5() {
    int size = 8;
    int A[8] = {12, 3, 7, 23, 44, 1, 4, 45};

    int result[size];
    task5(A, size, result);

    assert(result[0] == 1);
    assert(result[1] == 4);
    assert(result[2] == 12);
    assert(result[3] == 44);
    assert(result[4] == 45);
    assert(result[5] == 23);
    assert(result[6] == 7);
    assert(result[7] == 3);
}

void tests_task5() {
    test1_task5();
    test2_task5();
}

#endif //PRACTICE_2024_TASK5_H
