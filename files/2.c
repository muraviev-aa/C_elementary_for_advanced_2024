// 2. Массив-указатель

#include <stdio.h>

int main()
{
    int arr[4] = {-100, 10, 3, 200};
    printf("%p\n%p\n", arr, &arr[0]);

    // используем нотацию массива
    // i - индекс элемента массива
    for(int i = 0; i < 4; i++)
        printf("arr[%d] = %d\n", i, arr[i]);

    // используем нотацию указателя
    // i- смещение относительно первого элемента
    for(int i = 0; i < 4; i++)
        printf("arr[%d] = %d\n", i, *(arr+i));

    return 0;
}
