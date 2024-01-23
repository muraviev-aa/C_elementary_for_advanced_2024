// 9. Проверяем выделена ли память под указатель

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define NUM 1500*1024*1024

int main()
{
    char * p1;
    p1 = (char*) malloc(NUM * sizeof(char));

    if(p1 == 0)
    {
        puts("Error! NULL pointer!");
        exit(1);
    }
    else
        printf("OK!\n%u byte is alloced!\n", NUM * sizeof(char));

    system("pause");

    for(unsigned i = 0; i < NUM; i++)
        p1[i] = i;

    system("pause");
    free(p1);

    return 0;
}
