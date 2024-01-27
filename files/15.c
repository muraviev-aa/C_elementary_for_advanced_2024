// 15. Копирование значений всех полей одной структуры в другую

#include <stdio.h>

struct man
    {
        unsigned account;
        int money;
    };

int main()
{
    struct man ivanov, petrov;
    ivanov.account = 1;
    ivanov.money = 100;

    petrov = ivanov;

    printf("%d\n", ivanov.account);
    printf("%d\n", petrov.account);

    return 0;
}
