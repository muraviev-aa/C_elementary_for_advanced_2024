// 5. Передача массива в функцию №2
#include <stdio.h>
#define COUNT(x) (sizeof(x)/sizeof(x[0]))

void summArray(int * array, unsigned num);

int main()
{
    int myArr[] = {-100, 200, -300, 400, -500};
    summArray(myArr, COUNT(myArr));

    return 0;
}

void summArray(int * array, unsigned num)
{
    long long summa = 0;
    for(unsigned i = 0; i < num; i++)
        summa += *(array+i);
    printf("Summa = %lld\n", summa);
}
