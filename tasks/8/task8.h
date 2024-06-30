//
// Created by ivanu on 30.06.2024.
//

#ifndef PRACTICE_2024_TASK8_H
#define PRACTICE_2024_TASK8_H

#include <stdbool.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector createVector(size_t n) {
    vector a;
    a.capacity = n;
    a.size = 0;
    a.data = malloc(sizeof(int) * n);

    if (a.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return a;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
        v->size = 0;
    } else if (v->size > newCapacity) {
        v->size = newCapacity;
    } else if (v->capacity < newCapacity) {
        v->data = realloc(v->data, sizeof(int) * newCapacity);
    }

    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    v->capacity = newCapacity;
}

void pushBack(vector *v, int x) {
    if (v->size < v->capacity) {
        v->data[v->size] = x;
        v->size++;
    } else {
        size_t size = v->size == 0 ? 1 : 2 * v->size;
        reserve(v, size);
        v->data[v->size] = x;
        v->size++;
    }
}

void deleteVector(vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

// проверка ортогональности двух векторов
bool areOrthogonal(vector *v1, vector *v2) {
    if (v1->size != v2->size) {
        return false;
    }

    int result = 0;
    for (size_t i = 0; i < v1->size; i++) {
        result += v1->data[i] * v2->data[i];
    }
    return result == 0;
}

// проверка коллинеарности двух векторов
bool areCollinear(vector *v1, vector *v2) {
    if (v1->size != v2->size) {
        return false;
    }

    double ratio;
    bool ratioSet = false;

    for (size_t i = 0; i < v1->size; i++) {
        if (v1->data[i] == 0 && v2->data[i] == 0) {
            continue;
        }
        if (v1->data[i] == 0 || v2->data[i] == 0) {
            return false;
        }

        double currentRatio = (double) v2->data[i] / v1->data[i];

        if (!ratioSet) {
            ratio = currentRatio;
            ratioSet = true;
        } else if (currentRatio != ratio) {
            return false;
        }
    }

    return ratioSet;
}

void task8(vector *vectors, size_t vector_count) {
    for (size_t i = 0; i < vector_count; i++) {
        for (size_t j = i + 1; j < vector_count; j++) {
            if (areOrthogonal(&vectors[i], &vectors[j])) {
                printf("%zu and %zu orthogonal\n", i, j);
            }
            if (areCollinear(&vectors[i], &vectors[j])) {
                printf("%zu and %zu collinear\n", i, j);
            }
        }
    }
    printf("\n");
}

void test1_task8() {
    vector v1 = createVector(3);
    pushBack(&v1, 1);
    pushBack(&v1, 2);
    pushBack(&v1, 3);

    vector v2 = createVector(3);
    pushBack(&v2, 2);
    pushBack(&v2, 4);
    pushBack(&v2, 6);

    vector v3 = createVector(3);
    pushBack(&v3, -2);
    pushBack(&v3, 1);
    pushBack(&v3, 0);

    vector vectors[] = {v1, v2, v3};

    task8(vectors, 3);

    deleteVector(&v1);
    deleteVector(&v2);
    deleteVector(&v3);
}

void test2_task8() {
    vector v1 = createVector(2);
    pushBack(&v1, 1);
    pushBack(&v1, 0);

    vector v2 = createVector(2);
    pushBack(&v2, 0);
    pushBack(&v2, 1);

    vector v3 = createVector(2);
    pushBack(&v3, 2);
    pushBack(&v3, 4);

    vector v4 = createVector(2);
    pushBack(&v4, -1);
    pushBack(&v4, 0);

    vector v5 = createVector(2);
    pushBack(&v5, 3);
    pushBack(&v5, 6);

    vector vectors[] = {v1, v2, v3, v4, v5};

    task8(vectors, 5);

    deleteVector(&v1);
    deleteVector(&v2);
    deleteVector(&v3);
    deleteVector(&v4);
    deleteVector(&v5);
}

void tests_task8() {
    test1_task8();
    test2_task8();
}

#endif //PRACTICE_2024_TASK8_H
