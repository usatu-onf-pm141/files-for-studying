#include <conio.h>  //библиотека, необходимая для использования _getch()
#include <iostream> //библиотека, необходимая для использования потоков
                    //ввода\вывода

using namespace std;
int main()
{
    int a, b;
	cout << " Hello, world!!!" << endl;
    cout << " Enter two integer positive values" << endl;
    cout << " a = ";
    cin >> a;
    cout << " b = ";
    cin >> b;
    cout << " a+b = " << a+b << endl;
	_getch();
	return 0;
}