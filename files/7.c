// 7. Пример использования быстрой сортировки №2

#include <stdio.h>
#define COUNT(x) (sizeof(x) / sizeof(x[0]))

int main()
{
    int arr[] = {-1, 1, 0, 44, 5975, -3375, 4386, 333, 234, 333};
    int temp, num, next = 0;
    for (int num = 0; num < COUNT(arr); num++)
    {
        for(next = num + 1; next < COUNT(arr); next++)
        {
            if (arr[num] < arr[next])
            {
                temp = arr[num];
                arr[num] = arr[next];
                arr[next] = temp;
            }
        }
    }

    for (int ctr = 0; ctr <COUNT(arr); ctr++)
        printf("%d ", arr[ctr]);

    return 0;
}
