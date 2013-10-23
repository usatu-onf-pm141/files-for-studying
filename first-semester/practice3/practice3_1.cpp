#include <iostream>		// print need information to screen
#include <iomanip>		// for using setw()
#include <time.h>		// for using time(NULL)
#include <stdlib.h>		// for using srand()
#include <conio.h>		// for using _getch()

using namespace std;
int main()
{
	unsigned short int array_1[15], array_2[15]; // create two arrays
	
	// initialize by random elements with rand()

	srand(time(NULL));
	for (unsigned short int i = 0; i < 15; i++)
	{
		array_1[i] = rand() % 16; // random numbers [0; 15] in 1st array
		array_2[i] = rand() % 16; // random numbers [0; 15] in 2nd array

	}

	unsigned short int array_3[15]; // create 3d array

	// multiply two arrays
	
	for (unsigned short int i = 0; i < 15; i++)
		array_3[i] = array_1[i] * array_2[i];

	// print to screen

	cout << "The first array: " << endl;
	for (unsigned short int i = 0; i < 15; i++)
		cout << setw(5) << array_1[i];
	cout << "\n";
	
	cout << "The second array: " << endl;
	for (unsigned short int i = 0; i < 15; i++)
		cout << setw(5) << array_2[i];
	cout << "\n";
	
	cout << "The third array: " << endl;
	for (unsigned short int i = 0; i < 15; i++)
		cout << setw(5) << array_3[i];
	cout << "\n";

	_getch();
	return 0;
}