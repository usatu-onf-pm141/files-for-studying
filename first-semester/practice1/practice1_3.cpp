#include <conio.h> //библиотека, необходимая для использования _getch()
#include <iostream> //библиотека, необходимая для использования потоков ввода\ввывода

using namespace std;
int main()
{
    int a, b;
    char str1[5], str2[5]; //массивы символов
                //необходимые для хранения введённых данных
    cout << " Hello, world!!!" << endl;
    cout << " Enter two integer positive values" << endl;
    cout << " a = ";
    cin >> str1;
    cout << " b = ";
    cin >> str2;
    //функция atoi(str) переводит строку str в целое число,
    //возвращает введённое число, если ввод корректен,
    //в противном случае возвращает 0,
    a = atoi(str1); //перевод символов в целочисленный тип
    b = atoi(str2); //перевод символов в целочисленный тип
    if (a*b > 0)
       cout << " a+b = " << a+b << endl;
    else cout << "Error: incorrect entering!!!" << endl;
    _getch();
    return 0;
}