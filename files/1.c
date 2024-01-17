// 1. Работа с указателем
// при помощи указателя можно посмотреть что хранится в памяти,
// к сожалению, только в некоторых пределах своей программы

#include <stdio.h>

int main()
{
    int num = 0;
    int * pNum = &num;

    printf("%10d %p\n", *pNum, pNum);
    num++;
    printf("%10d %p\n", *pNum, pNum);
    pNum++;
    printf("%10d %p\n\n", *pNum, pNum);

    for (int i = 0; i < 10; i++)
    {
        pNum--;
        printf("%10d %p\n", *pNum, pNum);
    }

    return 0;
}
