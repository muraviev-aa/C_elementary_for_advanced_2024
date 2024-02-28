// 45. Чтение бинарных данных с помощью ф-ции fread() №3

#include <stdio.h>
#define NUM 6

int main()
{
    unsigned short data[NUM] = {0};
    const char * filename = "array.dat";
    size_t result = 0;
    FILE * fptr;
    fptr = fopen(filename, "rb");

    // работаем с целым массивом
    result = fread(data, sizeof(data), 1, fptr);
    for(unsigned i = 0; i < NUM; i++)
        printf("%hu ", data[i]);
    printf("\n%zu elements were read\n", result);

    return 0;
}
