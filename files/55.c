// 55. Запись и чтение массива структур в бинарный файл

#include <stdio.h>

int main()
{
    struct cpu
    {
        char model[3];
        unsigned freq;
    } intel[2] = {{"i7", 2600000}, {"i9", 4000000}}, temp[2];

    FILE * fIntel = fopen("intel.dat", "wb+");

    // запишем массив структур в бинарный файл
    fwrite(intel, sizeof(intel), 1, fIntel);
    rewind(fIntel); // смещаем курсор в начало файла

    // прочитаем информацию из файла
    fread(temp, sizeof(temp), 1, fIntel);
    printf("Model is %s, freq is %u\n", temp[0].model, temp[0].freq);
    printf("Model is %s, freq is %u\n", temp[1].model, temp[1].freq);

    return 0;
}
