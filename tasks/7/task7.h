//
// Created by ivanu on 28.06.2024.
//

#ifndef PRACTICE_2024_TASK7_H
#define PRACTICE_2024_TASK7_H

#include <stdio.h>
#include <math.h>

void task7() {
    int k, l, m = 0;
    int d = 0;
    int cnt = 0;

    while (cnt < 20) {
        for (int i = 1; i < d; i++) {
            k = d * d - i * i;
            l = 2 * d * i;
            m = d * d + i * i;

            printf("%d: %d, %d, %d\n", cnt + 1, k, l, m);
            cnt++;
        }
        d++;
    }
}

void tests_task7(){
    task7();
}

#endif //PRACTICE_2024_TASK7_H
