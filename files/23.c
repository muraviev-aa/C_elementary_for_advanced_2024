// 23. Пример передачи указателя структуры в функцию

#include <stdio.h>

struct comp
{
    unsigned cpu_freq;
    unsigned hdd_volume;
    char model[12];
}myComp = {2600000, 4, "Lenovo Z51"};

void print(struct comp * anyStruct)
{
    printf("Model PC is %s\n", anyStruct->model);
    anyStruct->cpu_freq = 3000000;
    printf("Frequency of your CPU is %u\n", anyStruct->cpu_freq);
}

int main()
{
    print(&myComp);
    printf("Frequency of your CPU is %u\n", myComp.cpu_freq);

    return 0;
}
