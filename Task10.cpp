// Task10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
char* str_remove(char* s, const char* s0) {
    char* t = s, * p = s;
    size_t n = strlen(s0);

    for (; *s; *s = *p) {
        if (strncmp(p, s0, n) != 0)
            ++s;
        else {
            p += n;
            continue;
        }
        ++p;
    }
    return t;
}


void prog1(){
    char str[100] = { 0 };
    char str1[100] = { 0 };
    printf("\nВведите вашу строчку: ");
    getchar();
    fgets(str, 100, stdin);
    strcpy(str1, str);
    char* pch = strtok(str, " ,.-");
    printf("Удаленные пробелы:");
    while (pch != NULL)
    {

        printf("%s ", pch);
        pch = strtok(NULL, " ,.-");

    }

    // printf("%s", strtok(str, " ,.-"));
     //printf("%d", strlen(strtok(str, " ,.-")));
    pch = strtok(str, " ,.-");
    strcat(pch, " ");
    strcat(str1, " ");
    str_remove(str1, pch);
    pch = strtok(str1, " ,.-");
    printf("Удаленные последние слова:");
    while (pch != NULL)
    {

        printf("%s ", pch);
        pch = strtok(NULL, " ,.-");

    }
}

int getWord(char str[], char** begin, char** end) {
    for (; *str && !isalpha(*str); ++str) { ; }
    *begin = str;

    for (; isalpha(*str); ++str) { ; }
    *end = str;

    return *end - *begin;
}

int isUnique(char word[], int len) {
    int alpha[26] = { 0 };

    while (0 < len--) {
        if (1 < ++alpha[tolower(*word++) - 'a']) {
            return 0;
        }
    }

    return 1;
}

void func(char str[]) {
    char* begin, * end;
    int len;
    while ((len = getWord(str, &begin, &end))) {
        if (isUnique(begin, len)) {
            printf("%.*s\n", len, begin);
        }
        str = end;
    }
}

void prog2() {
    printf("Введите словечки:");
    char str[100] = "";
    getchar();
    fgets(str, 100, stdin);
    func(str);

}

void prog3() {
    FILE* fp;
    char s1[100];
    printf("Что вы хотите записать в файл?");
    fp = fopen("task10.txt", "w");
    fgets(s1, 100, stdin);
    fputs(s1, fp);
    fclose(fp);
    fp = fopen("text.txt", "r");
    fscanf(fp, "%[^\n]", s1);
    printf("Файл создан и называется task10.txt ");
    fclose(fp);
    
}
int main()
{
    int q = -1;
    setlocale(LC_ALL, "Rus");
    printf("\n1) убрать пробелы,повторяющиеся слова");
    printf("\n2) убрать слова с повторяющимися буквами");
    printf("\n3) работаа с файлами");

    while (q != 0) {
        printf("\n\nВведите номер задания: ");
        scanf_s("%d", &q);
        switch (q) {

        case 1: {
            prog1();
            break;
        }
        case 2: {
            prog2();

            break;
        }
        case 3: {
            prog3();
            break;
        }
        }
    }






    return 0;

}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
