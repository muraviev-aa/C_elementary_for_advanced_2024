// 17. Выравнивание в структурах №2

#include <stdio.h>
#pragma pack(1) // выравнивает структуру по 1 байту, можно 1 2 4 8 16

struct alfa
{
    char a;
    char b;
    char c;
    int num;
};

int main()
{
    struct alfa test = {'x', 'y', 'z', 123};

    printf("%c %c %c %d\n", test.a, test.b, test.c, test.num);
    printf("%lu %lu %lu %lu\n", &test.a, &test.b, &test.c, &test.num);
    printf("%p %p %p %p\n", &test.a, &test.b, &test.c, &test.num);

    return 0;
}
