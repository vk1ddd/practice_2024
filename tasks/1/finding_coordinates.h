//
// Created by ivanu on 24.06.2024.
//

#ifndef PRACTICE_2024_FINDING_COORDINATES_H
#define PRACTICE_2024_FINDING_COORDINATES_H
#include <assert.h>

//координаты вершин
typedef struct coordinates_of_vertex{
    int x;
    int y;
}coordinates_of_vertex;

// принимает коэффиценты квадратной функции и выводит координаты вершины
coordinates_of_vertex finding_coordinates(int a, int b, int c){
    coordinates_of_vertex vertices;
    vertices.x = -b / (2*a);
    vertices.y = a * ((vertices.x) * (vertices.x)) + b * (vertices.x) + c;

    return vertices;
}

void test1(){
    int a = 2;
    int b = 4;
    int c = 1;

    coordinates_of_vertex answer;
    answer = finding_coordinates(a, b, c);

    assert(answer.x == -1);
    assert(answer.y == -1);
}

void test2(){
    int a = -3;
    int b = 6;
    int c = -2;

    coordinates_of_vertex answer;
    answer = finding_coordinates(a, b, c);

    assert(answer.x == 1);
    assert(answer.y == 1);
}

void test3(){
    int a = 1;
    int b = -4;
    int c = 5;

    coordinates_of_vertex answer;
    answer = finding_coordinates(a, b, c);

    assert(answer.x == 2);
    assert(answer.y == 1);
}

void tests_finding_coordinates(){
    test1();
    test2();
    test3();
}

#endif //PRACTICE_2024_FINDING_COORDINATES_H
