#include <conio.h>
#include <iostream>

using namespace std;

int main()
{
	unsigned long map_scale, distance;

	cout << "Enter positive number X where 1:X is a map scale: ";
	cin >> map_scale;
	cout << "\nEnter a distance between two points: ";
	cin >> distance;
	cout << "\nA distance between two localities: " << map_scale*distance;

	_getch();
	return 0;
}