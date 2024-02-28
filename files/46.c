// 46. Изучаем параметры функции main()

#include <stdio.h>
#include <windows.h>

int main(int argc, char * argv[])
{
    system("chcp>1251");
    printf("argc - %d\n", argc);
    for(unsigned i = 0; i < argc; i++)
        printf("%s ", argv[i]);
    putchar('\n');
    return 0;
}
