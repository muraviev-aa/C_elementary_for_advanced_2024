// 54. Запись и чтение структуры в бинарный файл

#include <stdio.h>

int main()
{
    struct cpu
    {
        char model[3];
        unsigned freq;
    } intel = {"i7", 2600000}, temp;

    FILE * fIntel = fopen("intel.dat", "wb+");
    // запишем структуру intel в бинарный файл
    fwrite(&intel, sizeof(intel), 1, fIntel);
    // вернул указатель в начало файла
    rewind(fIntel);

    // запишем данные из бинарного файла в структуру temp
    fread(&temp, sizeof(temp), 1, fIntel);
    printf("%s %u", temp.model, temp.freq);
    fclose(fIntel);

    return 0;
}
