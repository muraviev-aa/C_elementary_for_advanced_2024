// 21. Использование malloc() для динамического выделения памяти под массив указателей под структуры

#include <stdio.h>
#include <stdlib.h>

#define NUMS 2

struct cpu
{
    char model[3];
    unsigned freq;
};

int main()
{
    struct cpu * ptrCpu[NUMS];
    for(unsigned i = 0; i < NUMS; i++)
    {
        ptrCpu[i] = (struct cpu *)malloc(sizeof(struct cpu));
        if(ptrCpu[i] == NULL)
            exit(1);
        puts("Enter model of cpu:");
        fgets(ptrCpu[i]->model, 3, stdin);
        fflush(stdin);
        puts("Enter freq of cpu:");
        scanf("%u", &ptrCpu[i]->freq);
        fflush(stdin);
    }

    for(unsigned i = 0; i < NUMS; i++)
        printf("%u cpu: model is %s, freq is %u\n", i+1, ptrCpu[i]->model, ptrCpu[i]->freq);

    for(unsigned i = 0; i < NUMS; i++)
        free(ptrCpu[i]);

    return 0;
}
