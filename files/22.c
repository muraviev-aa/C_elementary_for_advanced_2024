// 22. Выделяем динамическую память под структуры без массива

#include <stdio.h>
#include <stdlib.h>

struct cpu
{
    char model[3];
    unsigned freq;
};

int main()
{
    unsigned nums;
    struct cpu * myFirmCpu;
    struct cpu * temp;

    puts("How many cpu you have?");
    scanf("%d", &nums);
    fflush(stdin);

    // выделенная память это по сути массив
    myFirmCpu = (struct cpu *) malloc(nums*sizeof(struct cpu));

    if(!myFirmCpu)
        exit(1);

    temp = myFirmCpu; // обязательно сохранить первоначальное значение указателя

    for(unsigned i = 0; i < nums; i++)
    {
        puts("Enter cpu model:");
        fgets(myFirmCpu->model, 3, stdin);
        fflush(stdin);
        puts("Enter cpu freq:");
        scanf("%u", &myFirmCpu->freq);
        fflush(stdin);
        myFirmCpu++;
    }

    myFirmCpu = temp; // в цикле значение указателя изменилось, теперь его надо вернуть

    for(unsigned i = 0; i < nums; i++)
    {
        printf("%u %s %u\n", i+1, myFirmCpu->model, myFirmCpu->freq);
        myFirmCpu++;
    }

    myFirmCpu = temp; // в цикле значение указателя изменилось, теперь его надо вернуть

    free(myFirmCpu);

    return 0;
}
