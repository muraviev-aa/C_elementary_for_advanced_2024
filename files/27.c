// 27. Создаем однонаправленный связный список №4

#include <stdio.h>
#include <conio.h> // SetConsoleCP(), SetConsoleOutputCP()
#include <windows.h>

struct cpu
{
    char model[15];
    char freq[11]; // ранее было unsigned freq
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
    printf("S - показать список, A - добавить элемент, \
D - удалить элемент, Q - выход\n");
    ch = getch(); // ожидает нажатия клавиши, после которого она немедленно возвращает значение
    putchar(ch); // вывод символа в стандартный поток вывода
    putch('\n'); // функция производит вывод прямо на экран
    ch = toupper(ch); // преобразование строчных букв в прописные
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
        current = current->next; // делаем следующий узел текущим
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
    if(first == NULL) // сперва проверка есть ли хоть 1 элемент
    {
        first = makeNode(); // создать первый элемент
        current = first; // сделать его текущим
    }
    else // если в списке уже есть элементы
    {
        current = first; // сделать первый текущим
        while(current->next != NULL) // ищем последний элемент списка
            current = current->next; // и делаем его текущим
        newNode = makeNode(); // создали новый элемент
        current->next = newNode; // поставили его в конец списка
        current = newNode; // сделал его текущим
    }
    printf("Введите название модели процессора (не более 14 символов): ");
    fgets(current->model, 15, stdin);
    printf("Введите тактовую частоту процессора в Гц (не более 10 символов): ");
    fgets(current->freq, 11, stdin);
    current->next = NULL; // закрываем список
}

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
        current = current->next; // обходим список по порядку
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

















