#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

void strcat_f1(char *str_1, char *str_2)
{
	int len_1 = strlen(str_1), len_2 = strlen(str_2);
	int j = 0;
	for (int i = len_1; i <= len_1 + len_2; i++)
	{
		str_1[i] = str_2[j];
		j++;
	}
}
void strcat_f2(char *str_1, char *str_2)
{
	int len_1 = strlen(str_1), len_2 = strlen(str_2);
	int j = 0;
	for (int i = len_1; i <= len_1 + len_2; i++)
	{
		*(str_1 + i) = *(str_2 + j);
		j++;
	}
}
int main()
{
	char str_1[255], str_2[255];
	bool flag = true;
	do
	{
		cin.sync();
		cin.clear();
		cout << "Enter the first string: ";
		cin.getline(str_1, 255);

		cout << "Enter the second string: ";
		cin.getline(str_2, 255);

		if (strlen(str_1)+strlen(str_2) < strlen(str_1))
		{
			cout << "The resulting concatenate string is too long! Please, try again." << endl;
			flag = false;
		}
		else
		{
			strcat_f1(str_1, str_2);
			cout << endl << str_1 << endl;
			strcat_f2(str_1, str_2);
			cout << endl << str_1 << endl;
		};

	}
	while (!flag);


	_getch();
	return 0;
}