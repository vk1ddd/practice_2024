//
// Created by ivanu on 24.06.2024.
//

#ifndef PRACTICE_2024_FEED_FOR_COWS_H
#define PRACTICE_2024_FEED_FOR_COWS_H
#include <stdio.h>

//получает кол-во коров, сколько они едят и кол-во оставшегося корма
//выводит на сколько дней осталось корма и какой корм закончится первым
// u, v, w - виды кормов (сено, силос, комбикорм)
//s, t, f - сколько осталось корма (центнеров сена, тонн силоса, мешков комбикорма по 50кг)
void feed_for_cows(int u, int v, int w, int s, int t, int f, int cows) {
    //приводим к кг
    s = s * 100;
    t = t * 1000;
    f = f * 50;


    int min_day = s / (cows * u);

    if (min_day > t / (cows * v) && (t / (cows * v)) < (f / (cows * w))){
        min_day = t / (cows * v);
        printf("%d, Silo \n", min_day);
        return;
    }else if (min_day > f / (cows * w)) {
        min_day = f / (cows * w);
        printf("%d, compound feed \n", min_day);
        return;
    }

    printf("%d, straw \n", min_day);
}

void test1_feed_for_cows(){
    int straw_consumption = 10;
    int silage_consumption = 15;
    int feed_consumption = 20;

    int straw_left = 100;
    int silage_left = 10;
    int feed_left = 20;

    int cows  = 5;

    // ответ верный (10 дней осталось, первым закончится комбикорм), считал вручную
    feed_for_cows(straw_consumption, silage_consumption, feed_consumption, straw_left, silage_left, feed_left, cows);
}

void test2_feed_for_cows(){
    int straw_consumption = 12;
    int silage_consumption = 18;
    int feed_consumption = 25;

    int straw_left = 96;
    int silage_left = 15;
    int feed_left = 12;

    int cows  = 8;

    // ответ верный (3 дней осталось, первым закончится комбикорм), считал вручную
    feed_for_cows(straw_consumption, silage_consumption, feed_consumption, straw_left, silage_left, feed_left, cows);
}

void test3_feed_for_cows(){
    int straw_consumption = 8;
    int silage_consumption = 10;
    int feed_consumption = 12;

    int straw_left = 80;
    int silage_left = 5;
    int feed_left = 150;

    int cows  = 10;

    // ответ верный (50 дней осталось, первым закончится Силос), считал вручную
    feed_for_cows(straw_consumption, silage_consumption, feed_consumption, straw_left, silage_left, feed_left, cows);
}

void tests_feed_for_cows(){
    test1_feed_for_cows();
    test2_feed_for_cows();
    test3_feed_for_cows();
}

#endif //PRACTICE_2024_FEED_FOR_COWS_H
