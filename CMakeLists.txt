cmake_minimum_required(VERSION 3.28)
project(practice_2024 C)

set(CMAKE_C_STANDARD 11)

add_executable(practice_2024 main.c
        tasks/1/finding_coordinates.h
        tasks/2/feed_for_cows.h)
