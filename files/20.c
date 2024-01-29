// 20. Использование malloc() для динамического выделения памяти под структур

#include <stdio.h>
#include <stdlib.h>

struct cpu
{
    char model[3];
    unsigned freq;
};

int main()
{
    struct cpu * myCpu;
    myCpu = (struct cpu *) malloc(sizeof(struct cpu *));
    if(myCpu == NULL)
        exit(1);

    puts("Enter model of cpu:");
    fgets(myCpu->model, 3, stdin);
    fflush(stdin);
    puts("Enter freq of cpu:");
    scanf("%d", &myCpu->freq);
    fflush(stdin);

    printf("cpu: model is %s, freq is %d\n", myCpu->model, myCpu->freq);

    free(myCpu);

    return 0;
}
