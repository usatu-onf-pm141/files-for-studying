#include <iostream>
#include <conio.h>

using namespace std;

void enterAndCheck(float& number);
float divide(float firstNumber, float secondNumber);
int main()
{
	float firstNumber, secondNumber, resultOfDivision;
	
	enterAndCheck(firstNumber);
	enterAndCheck(secondNumber);
	
	resultOfDivision = divide(firstNumber, secondNumber);

	cout << "The result of division is : " << resultOfDivision << "\n";
	cout << "Press Enter to exit.";

	_getch();
	return 0;
};

void enterAndCheck(float& number)
{
	do
	{
		cin.sync();
		cin.clear();
		cout << "Enter the first number: ";
		cin >> number;
		if (!cin.good())
			cout << "Error! Please, type number again.\n";
	}
	while (!cin.good());
};
float divide(float firstNumber, float secondNumber)
{
	try
	{
		if (secondNumber == 0) throw "Division by zero";
		return firstNumber/secondNumber;
	}
	catch (const char* temporaryString)
	{
		cout << temporaryString << '\n';

		_getch();
		exit(1);
	};
};