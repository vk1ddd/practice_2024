//
// Created by ivanu on 01.07.2024.
//

#ifndef PRACTICE_2024_TASK9_H
#define PRACTICE_2024_TASK9_H

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

//проверка, содержит ли строка хотя бы одно ключевое слово
int contains_keyword(char *str, char *keywords[], int num_keywords) {
    int i;
    for (i = 0; i < num_keywords; ++i) {
        if (strstr(str, keywords[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

void task9(char *filename, char *keywords[], int num_keywords) {
    char line[MAX_LINE_LENGTH];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error");
        return;
    }

    // чтение файла построчно
    while (fgets(line, sizeof(line), file)) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        if (contains_keyword(line, keywords, num_keywords)) {
            printf("%s\n", line);
        }
    }

    fclose(file);
}

void tests_task9() {
    char filename[] = "C:\\Users\\ivanu\\CLionProjects\\practice_2024\\tasks\\9\\books.txt";
    int num_keywords = 3;
    char *keywords[] = {"Algorithm", "Artificial", "Network"};

    task9(filename, keywords, num_keywords);
}

#endif //PRACTICE_2024_TASK9_H
