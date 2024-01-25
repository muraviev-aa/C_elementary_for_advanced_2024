// 12. Работа с глобальной структурой

#include <stdio.h>
#include <string.h>

struct man
{
    char fullName[32];
    unsigned account;
    int money;
};

int main()
{
    struct man ivanov;
    strcpy(ivanov.fullName, "Ivanov Ivan Ivanovich");
    ivanov.account = 123456;
    ivanov.money = 1000;

    printf("Struct ivanov is situated in %p\n", &ivanov.fullName);
    printf("Struct ivanov has size of %zu\n", sizeof(ivanov));
    // printf("man has size of %zu", sizeof(man)); // this option does not compile
    printf("man has size of %zu", sizeof(struct man));

    return 0;
}
