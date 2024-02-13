// 29. Создаем однонаправленный связный список №6;
//   Изменения в коде файла 27:
// - после выбора действия в меню сперва очищается экран;
// - реализовано добавление промежуточного нового узла списка;
// - добавил новый элемент меню - "I - добавить элемент после указанного";
// - добавил новый элемент меню - "H - справка";
// - добавил макроподстановки #define.

#include <stdio.h>
#include <conio.h>
#include <windows.h> // SetConsoleCP(), SetConsoleOutputCP()
#include <stdlib.h>

#define NUMMODEL 15
#define NUMFREQ 11
#define CURCURNEXT current = current->next
#define CURNEXTNNODE current->next = newNode
#define NNODEFUNCMAKENODE newNode = makeNode()

struct cpu
{
    char model[NUMMODEL];
    char freq[NUMFREQ];
    struct cpu * next;
};

struct cpu * first;
struct cpu * newNode;
struct cpu * current;

int menu(void); // меню программы
void showList(void); // вывод на экран всего списка
void addNode(void); // добавляем узел в список
struct cpu * makeNode(void); // выделяем память под узел
void deleteNode(void); // удаляем узел из списка
char * myFgets(char * arr); // функция, заменяющая fgets()
void help(void); // справка по работе с программой
void freeInsert(void); // добавляем узел в произвольную часть списка

int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);

    int choice = 0;
    first = NULL;

    while(1)
    {
        choice = menu();
        switch(choice)
        {
            case 'S':
            showList();
            break;
        case 'A':
            addNode();
            break;
        case 'D':
            deleteNode();
            break;
        case 'I':
            freeInsert();
            break;
        case 'H':
            help();
            break;
        case 'Q':
            puts("Всего доброго!");
            exit(EXIT_SUCCESS);
            break;
        default:
            puts("Некорректный ввод.");
            break;
        }

    }

    return 0;
}

// меню программы
int menu(void)
{

    int ch = 0;
    puts("Меню:");
    printf("S - показать список,\nA - добавить элемент в конец списка,\n\
D - удалить элемент,\nI - добавить элемент после указанного,\n\
H - справка,\nQ - выход;\n");

    ch = getch(); // ожидает нажатия клавиши, после которого она немедленно возвращает значение

    putchar(ch); // вывод символа в стандартный поток вывода
    putch('\n'); // функция производит вывод прямо на экран
    ch = toupper(ch); // преобразование строчных букв в прописные
    // после выбора действия в меню сперва очищается экран
     if(ch == 'S' || ch == 'A'|| ch == 'D'|| ch == 'I'|| ch == 'H'|| ch == 'Q'||
        ch != 'S'|| ch != 'A'|| ch != 'D'|| ch != 'I'|| ch != 'H' || ch != 'Q')
    {
        system("cls");
    }
    return ch;
}

// вывод на экран всего списка
void showList(void)
{
    int count = 1; // номер выводимого элемента
    if(first == NULL) // если список пустой
    {
        printf("Список пуст! Сперва добавьте в него элементы.\n");
        return;
    }
    puts("Список:");
    current = first; // начинаем обход списка с первого элемента
    while(current != NULL)
    {
        printf("Запись №%d: %s %s\n", count, current->model, current->freq);
        CURCURNEXT; // делаем следующий узел текущим
        count++;
    }
}

// выделяем память под узел
struct cpu * makeNode(void)
{
    struct cpu * tempCpu;
    tempCpu = (struct cpu *) malloc(sizeof (struct cpu));
    if(tempCpu == NULL)
    {
        puts("Невозможно выделить память под новый элемент списка!\n");
        system("pause");
        exit(1);
    }
    return tempCpu;
}

// добавляем узел в список
void addNode(void)
{
    char arrModel[NUMMODEL];
    char arrFreq[NUMFREQ];
    if(first == NULL) // сперва проверка есть ли хоть 1 элемент
    {
        first = makeNode(); // создать первый элемент
        current = first; // сделать его текущим
    }
    else // если в списке уже есть элементы
    {
        current = first; // сделать первый текущим
        while(current->next != NULL) // ищем последний элемент списка
            CURCURNEXT; // и делаем его текущим
        NNODEFUNCMAKENODE; // создали новый элемент
        CURNEXTNNODE; // поставили его в конец списка
        current = newNode; // сделал его текущим
    }
    printf("Введите название модели процессора (не более 14 символов): ");
    scanf("%s", arrModel);
    fflush(stdin);
    strcpy(current->model, myFgets(arrModel));

    printf("Введите тактовую частоту процессора в Гц (не более 10 символов): ");
    scanf("%s", arrFreq);
    fflush(stdin);
    strcpy(current->freq, myFgets(arrFreq));
    current->next = NULL; // закрываем список
}

// удаляем узел из списка
void deleteNode(void)
{
    struct cpu * previous; // адрес предшевствующего элемента удаляемому
    unsigned delNum; // номер удаляемого элемента
    unsigned num = 1; // текущий по порядку элемент

    if(first == NULL) // проверка есть ли хотя бы 1 элемент
    {
        puts("Список пустой - удалять нечего!");
        return;
    }
    puts("Пожалуйста, выберите узел для удаления:");
    showList(); // выводим список
    printf("Удалить узел: ");
    scanf("%u", &delNum);
    fflush(stdin);
    current = first; // Делаем первый узел текущим
    previous = NULL; // У первого элемента нет предыдущего
    while(num != delNum) // в цикле проверим есть ли такой элемент
    {
        previous = current; // сохраняем текущее значение
        CURCURNEXT; // обходим список по порядку
        num++;
        if(current == NULL) // достигли конца списка
        {
            puts("Такой записи в списке нет.");
            return;
        }
    }
    if(previous == NULL) // если удаляем первый элемент
        first = current->next; // сделать первым следующий элемент
    else // предыдущая запись должна указывать на следующую
         // как бы перескакивая текущую
        previous->next = current->next;

    printf("Запись №%u удалена\n", delNum);
    free(current); // высвобождаем память от удалённого узла
    return;
}

// производим замену '\n' на '\0' в массиве символов
char * myFgets(char * arr)
{
     unsigned i = 0;
    // меняем '\n' на '\0'
    while(arr[i] != '\n' && arr[i] != '\0')
        i++;
    if(arr[i] == '\n')
        arr[i] = '\0';
    return arr;
}

// справка по работе с программой
void help(void)
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("О, сколько нам открытий чудных\n");
    printf("Готовят просвещенья дух,\n");
    printf("И опыт, сын ошибок трудных,\n");
    printf("И гений, парадоксов друг,\n");
    printf("И случай, бог изобретатель.\n");
    printf("\t\tА.С. Пушкин\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}

//  добавляем узел в произвольную часть списка
void freeInsert(void)
{
    char arrModel[NUMMODEL];
    char arrFreq[NUMFREQ];
    unsigned freeIns; // номер элемента после которого будет вставлен новый
    unsigned num = 1; // текущий по порядку элемент
    if(first == NULL) // проверка есть ли два элемента
    {
        puts("Список пуст! Создайте элемент.");
        return;
    }
    puts("Укажите узел, после которого будет вставлен новый:");
    showList(); // выводим список
    printf("Вставить новый узел после: ");
    scanf("%u", &freeIns);
    fflush(stdin);
    current = first; // Делаем первый узел текущим
    while(num != freeIns) // в цикле проверим есть ли такой элемент
    {
        CURCURNEXT; // обходим список по порядку
        num++;
        if(current == NULL) // достигли конца списка
        {
            puts("Такой записи в списке нет.");
            return;
        }
    }
    NNODEFUNCMAKENODE; // создали новый элемент
    newNode->next = current->next; // поставили его в конец списка
    CURNEXTNNODE; // сделал его текущим
    current = newNode;

    printf("Введите название модели процессора (не более 14 символов): ");
    scanf("%s", arrModel);
    fflush(stdin);
    strcpy(current->model, myFgets(arrModel));

    printf("Введите тактовую частоту процессора в Гц (не более 10 символов): ");
    scanf("%s", arrFreq);
    fflush(stdin);
    strcpy(current->freq, myFgets(arrFreq));
}

















