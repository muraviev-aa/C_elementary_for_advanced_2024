// 56. Чтение структур из бинарного файла

#include <stdio.h>

int main()
{
    struct cpu
    {
      char model[3];
      unsigned freq;
    } temp;

    FILE * fIntel = fopen("intel.dat", "rb+");
    /* fread() возвращает кол-во считанных эл-ов и пока не
     * вернёт 0 - цикл будет выполняться. Здесь нет счётчика
     * цикла! Но вместо него есть внутренний указатель в файле */
    while(fread(&temp, sizeof(temp), 1, fIntel))
    {
        printf("Model is %s, freq is %u\n", temp.model, temp.freq);
        printf(" offset - %ld\n", ftell(fIntel));
    }
    fclose(fIntel);
    return 0;
}
