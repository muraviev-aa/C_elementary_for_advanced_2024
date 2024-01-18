// 3. Проход массива неопределенной длины
// выводим значения массива
// сколько элементов в массиве неизвестно,
// это определяется компилятором во время сборки

#include <stdio.h>
#define MAX sizeof(arr)/sizeof(arr[0])

int main()
{
    int arr[] = {100, -12, 45, 72, 68, 123, -19};

    printf("Size of arr is %zu\n", sizeof(arr));
    printf("Size of arr[0] is %zu\n", sizeof(arr[0]));

    for(unsigned i = 0; i < MAX; i++)
        printf("arr[%d] = %d\n", i, *(arr+i));

    return 0;
}
