// 19. Находим размер массива и структуры

#include <stdio.h>

// глобальный шаблон структуры
struct cpu
{
    char model[35];
    unsigned freq;
};

int main()
{
    int arr[10];
    printf("Size of arr is %u\n", sizeof arr);

    // локальный шаблон структуры
    struct computerFirm
    {
        char name[13];
        unsigned hdd;
        unsigned ram;
        struct cpu cpuFirm; // вложенная структура
    };

    struct computerFirm myFirm;

    printf("Size of myComp is %u\n", sizeof myFirm);
    printf("Size of struct computerFirm is %u\n", sizeof(struct computerFirm));
    printf("Size of struct cpu is %u\n", sizeof(struct cpu));

    return 0;
}
