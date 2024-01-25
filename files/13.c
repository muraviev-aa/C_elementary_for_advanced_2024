// 13. Работа с локальной структурой

#include <stdio.h>

int main()
{
    struct man
    {
        char fullName[32];
        unsigned account;
        int money;
    };

    // так можно инициализировать только при создании
    struct man ivanov = {"Ivanov Ivan Ivanovich", 123456, 1000};

    printf("Struct ivanov is situated in %p\n", &ivanov.fullName);
    printf("Struct ivanov has size of %zu\n", sizeof(ivanov));
    printf("man has size of %zu\n", sizeof(struct man));

    return 0;
}
