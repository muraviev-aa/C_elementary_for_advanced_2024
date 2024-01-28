// 18. Массивы структур

#include <stdio.h>
#define SIZE 3

typedef struct cpu
{
    char name[30];
    unsigned freq; // частота процессора
} CPU;

int main()
{
    CPU officeCPU[SIZE];
    for(unsigned i = 0; i < SIZE; i++)
    {
        printf("Enter name of CPU %d\n", i+1);
        scanf("%s", officeCPU[i].name);
        printf("Enter frequency of CPU %d\n", i+1);
        scanf("%u", &officeCPU[i].freq);
    }

    for(unsigned j = 0; j < SIZE; j++)
        printf("CPU %d %s %u\n", j+1, officeCPU[j].name, officeCPU[j].freq);

    return 0;
}
