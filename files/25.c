// 25. Создаем связный список №2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 3

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

// прототипы функций
struct cpu * makeNode(void);
void fillNode(struct cpu * ptr, unsigned num);
void showNode(struct cpu * ptr);

int main()
{
    for(unsigned i = 0; i < COUNT; i++)
    {
        if(i == 0)
        {
            first = makeNode(); // создаем первый узел
            current = first;    // узел first сделали текущим
        }
        else
        {
            newNode = makeNode();    // создаем следующий узел
            current->next = newNode; // связали узел first и newNode
            current = newNode;       // узел newNode сделали текущим
        }
        fillNode(current, i+1); // сразу после создания заполняем
    }
    current->next = NULL;

    puts("I have cpu:");

    current = first;

    while(current)
    {
        showNode(current);
        current = current->next;
    }

    return 0;
}

struct cpu * makeNode(void)
{
    struct cpu * a;
    a = (struct cpu*) malloc(sizeof(struct cpu));
    if(!a)
    {
        puts("Error! It is impossible to create node!\n");
        exit(1);
    }
    return a;
};

void fillNode(struct cpu * ptr, unsigned num)
{
    printf("Cpu %u of %u\n", num, COUNT);
    puts("Enter cpu model");
    fgets(ptr->model, 15, stdin);
    // замена "\n" на '\0' с помощью ф-ии strcspn()
    ptr->model[strcspn(ptr->model, "\n")] = '\0';
    fflush(stdin);
    puts("Enter cpu freq");
    scanf("%u", &ptr->freq);
    fflush(stdin);
}

void showNode(struct cpu * ptr)
{
    printf("Model is %s, freq is %u\n", ptr->model, ptr->freq);
}




