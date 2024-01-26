// 14. Псевдоним шаблона

#include <stdio.h>

int main()
{
    typedef struct man
    {
        char fullName[50];
        unsigned account;
        int money;
    } MAN; // MAN - псевдоним шаблона man

    MAN petrov  =
    {
        .fullName = "Petrov Petr Petrovich",
        .account = 123,
        .money = 1000
    };

    printf("%zu\n", sizeof(MAN));

    return 0;
}
