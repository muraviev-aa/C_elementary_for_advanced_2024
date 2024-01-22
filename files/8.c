// 8. Проверяем где и как хранятся данные "кучи"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int * p1, * p2, * p3;
    p1 = (int*) malloc(100 * sizeof(int));
    p2 = (int*) malloc(100 * sizeof(int));
    p3 = (int*) malloc(100 * sizeof(int));

    printf("p1 = %u\np2 = %u\np3 = %u\n", p1, p2, p3);
    system("pause");

    // не забываем освобождать динамическую память
    free(p1);
    free(p2);

    return 0;
}
