// 50. Проверяем работу ftell() и rewind()

#include <stdio.h>
#define PRINTftell(x) printf("%ld\n", ftell(x))

// long int ftell( FILE * filestream );
// ftell() возвращает значение указателя текущего положения потока

// void rewind ( FILE * filestream );
// rewind() устанавливает внутренний указатель положения файла в начало файла

int main()
{
    FILE * fptr;
    fptr = fopen("simple.txt", "wb+");

    PRINTftell(fptr);
    fputs("12345", fptr);
    PRINTftell(fptr);
    rewind(fptr);
    PRINTftell(fptr);

    return 0;
}
