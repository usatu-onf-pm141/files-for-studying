#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

void selection_sort(char **strings, int number_strings)
{
	char temp[255];
    int ind;
    for (int i = 0; i < number_strings - 1; i++)
    {
        ind = i;
        for (int j = i + 1; j < number_strings; j++)
            if (strlen(*(strings + ind)) > strlen(*(strings + j)))
               ind = j;
        strcpy(temp, *(strings + i));
        strcpy(*(strings + i), *(strings + ind));
        strcpy(*(strings + ind), temp);
    };
};
int main()
{
    const int n = 255;
    char **strings;
    int number_strings;
    
// output of the number of strings
	
    do
	{
		cin.sync();
		cin.clear();
		cout << "Enter the number of strings: ";
		cin >> number_strings;
		if (!cin.good() || (number_strings <= 0))
			cout << "It's incorrect value!\n" << endl;
	}
	while(!cin.good() || (number_strings <= 0));

	strings = new char *[number_strings];
	for (int i = 0; i < number_strings; i++)
        strings[i] = new char[n];
    
	cin.sync();
	cin.clear();
    for (int i = 0; i < number_strings; i++)
    {
		bool fl = true;
		while (fl)
		{
			cout << "Enter the string: ";
			while (!cin.getline(strings[i], n))
			{
				cin.sync();
				cin.clear();
				cout << "Your string is too long. Please, try again: ";
			};
			if (*(*(strings + i) + 0) == '\0')
			{
				cout << "You've pressed \"Enter\" :). Please, try again" << endl; 
				fl = true;
			}
			else
				fl = false;
		};
	};
    
    selection_sort(strings, number_strings);

	for (int i = 0; i < number_strings; i++)
    {
        cout << "String #" << i + 1 << " - " << *(strings + i);
        cout << "; length - " << strlen(*(strings + i)) << endl;
    };
    
	for (int i = 0; i < number_strings; i++)
        delete [] strings[i];
    delete [] strings;
    
    _getch();
    return 0;
}