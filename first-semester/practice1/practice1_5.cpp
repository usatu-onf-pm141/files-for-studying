#include <conio.h>
#include <iostream>

using namespace std;
int main()
{
    //cout << "-2=" << -(-1) << endl;
    double val;
    cout << "Enter negative value \n";
    cin >> val;
    if (!cin.good()) // cin.good() - возвращает 0, если ввод успешен
    {
        cout << " It's not a value!\n";
        getch();
        return 0;
    }
    if (val>=0)
    {
        cout << "This value is not negative!\n";
        getch();
        return 0;
    }
    cout << "This value is correct \n";
    getch();
    return 0;
}