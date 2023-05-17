#include<iostream>

using namespace std;

struct Data // структура, описывающая дату
{
    int day;    // день
    int mon;    // месяц
    int year;   // год
};

struct File// структура, описывающая файл
{
    char name[20];  // имя
    Data date;      // дата
    int kol;        // количество обращений

    void data_in()  // функция ввода даты
    {
        cin >> date.day;    // ввод дня
        cin >> date.mon;    // ввод месяца
        cin >> date.year;   // ввод года
    }

    void data_out() // функция ввода даты
    {
        cout << date.day << "  ";   // вывод дня
        cout << date.mon << "  ";   // вывод месяца
        cout << date.year << "  ";  // вывод года
    }
};

File* a;    // массив файлов
int n;      // количество файлов
int j;

int operator <(File a, File b)
{
    if (a.date.year <= b.date.year)
    {
        if (a.date.mon < b.date.mon)
            return 1;
        if (a.date.mon == b.date.mon)
        {
            if (a.date.day < b.date.day)
                return 1;
        }
        return 0;
    }
    return 0;
}

int operator >(File a, File b)
{
    if (a.kol > b.kol)
        return 1;
    else
        return 0;
}

void Del(int k)
{
    File* b = new File[n - 1];
    int r = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (i < k)
            r = 0;
        else
            r = 1;
        b[i] = a[i + r];
    }
    a = b;
    j = k - 1;
    --n;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите количество файлов:  ";
    cin >> n;

    a = new File[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Введите имя файла №" << i + 1 << ":  ";
        cin >> a[i].name;
        cout << "Введите дату создания файла №" << i + 1 << "  (дд мм гггг):  ";
        a[i].data_in();
        cout << "Введите количество обращений к файлу №" << i + 1 << ":  ";
        cin >> a[i].kol;
        cout << endl;
    }

    cout << "Вывод каталога файлов\n";

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << endl << " " << a[i].name << endl;
        a[i].data_out();
        cout << endl << " " << a[i].kol << endl;
    }

    cout << "Удаление файлов, дата создания которых меньше заданной: \n\t введите дату:  ";
    /* cout << L"Удаление файлов, дата создания которых меньше заданной: введите дату: ";

     File temp;

     temp.data_in();
     j = 0;

     for (int i = 0; i < n; i++)

     {

         if (a[i] < temp)Del(j);

     }*/

    File temp;

    temp.data_in();

    j = 0;
    while (j < n)
    {
        if (a[j] < temp)
            Del(j);
        j++;
    }

    cout << "Оставшиеся файлы\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << endl << "\t" << a[i].name << endl << "\t";
        a[i].data_out();
        cout << endl << "\t" << a[i].kol << endl;
    }

    cout << "Файл с наибольшим количеством обращений\n";
    File max = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    cout << '\t' << max.name << endl << "\t";
    max.data_out();
    cout << "\n\t" << max.kol << endl;
    system("pause");
    return 0;
}

