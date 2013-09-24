#include <conio.h> //библиотека, необходимая для использования _getch()
#include <iostream> //библиотека, необходимая для использования потоков ввода\ввывода

using namespace std;
int main()
{
    float a, b;
    char str1[5], str2[5]; //массивы символов
                //необходимые для хранения введённых данных
    cout << " Hello, world!!!" << endl;
    cout << " Enter two integer positive values" << endl;
    cout << " a = ";
    cin >> str1;
    cout << " b = ";
    cin >> str2;
    //функция atof(str) переводит строку str в вещественное число,
    //возвращает введённое число, если ввод корректен,
    //в противном случае возвращает 0,
    a = atof(str1); //перевод символов в вещественный тип
    b = atof(str2); //перевод символов в вещественный тип
    if (a*b > 0)
       cout << " a+b = " << a+b << endl;
    else cout << "Error: incorrect entering!!!" << endl;
    _getch();
    return 0;
}