cmake_minimum_required(VERSION 3.28)
project(practice_2024 C)

set(CMAKE_C_STANDARD 11)

add_executable(practice_2024 main.c
        tasks/1/finding_coordinates.h
        tasks/2/feed_for_cows.h
        tasks/3/compute_root.h
        tasks/4/task4.h
        tasks/5/task5.h
        tasks/6/task6.h
        tasks/7/task7.h
        tasks/8/task8.h
        tasks/10/task10.h
        tasks/9/task9.h)
