// 24. Создаем связный список

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct cpu
    {
        char model[14];
        unsigned freq;
        struct cpu * next; // указатель на следующий элемент
    };

    // указатели для работы со списком
    struct cpu * first;
    struct cpu * current; // через него будем работать
    struct cpu * newNode;

    // создаем элемент first
    first = (struct cpu*) malloc(sizeof(struct cpu));
    if(!first)
    {
        puts("Error!");
        exit(1);
    }

    // обрабатываем элемент first
    // для этого делаем его текущим
    current = first;
    strcpy(current->model, "Intel i7");
    current->freq = 2600000;
    current->next = NULL;

    // создаем элемент newNode
    newNode = (struct cpu*) malloc(sizeof(struct cpu));
    if(!newNode)
    {
        puts("Error!");
        exit(1);
    }
    // когда мы создали элемент newNode
    // мы знаем его адрес
    current->next = newNode;

    // обрабатываем элемент newNode
    // для этого делаем его текущим
    current = newNode;
    strcpy(current->model, "Intel i9");
    current->freq = 3000000;
    current->next = NULL;

    // переходим к элементу first, выводим его данные
    current = first;
    printf("model %s, freq %u\n", current->model, current->freq);

    // переходим к элементу newNode, выводим его данные
    current = newNode; //current = current->next;
    printf("model %s, freq %u\n", current->model, current->freq);

    return 0;
}
