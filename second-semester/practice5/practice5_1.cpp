#include "class_list.h"

int main()
{
    setlocale(LC_ALL, "Russian");
	FILE *filePtr;
	ifstream textIn;
	ofstream textOut;
	char binMode;
	char fileName[255];

	cout << "Hello! This program works with text and binary files and can help you to create the table of software.\n\n";
	
	bool flag_exit = false;
	while(!flag_exit)
    {
		system("cls");
        cout << "Menu of the program:\n\n";
        
        cout << "1 - Write a new table in file with functions of C\n";
        cout << "2 - Write a new table in file with functions of C++\n";
        cout << "3 - Read data from file with functions of C\n";
        cout << "4 - Read data from file with functions of C++\n";
        cout << "5 - Exit the program\n";
        
        int menu_item;
		do
		{
			cin.sync();
			cin.clear();
			cout << "\nPlease select one of the menu item [1-5]: ";
			cin >> menu_item;
			if (!cin.good() || (menu_item < 1) || (menu_item > 5))
				cout << "It's an incorrect value!" << endl;
		}
		while(!cin.good() || (menu_item < 1) || (menu_item > 5));
        
		if (menu_item != 5)
		{
			NameOfFile(fileName);
			binaryMode(binMode);
		};
		switch(menu_item)
		{
		case 1 : {writeTableC(&filePtr, fileName, binMode);} break;
		case 2 : {writeTableCPP(textOut, textIn, fileName, binMode);} break;
		case 3 : {readTableC(&filePtr, fileName, binMode);} break;
		case 4 : {readTableCPP(textIn, fileName, binMode);} break;
		case 5 : {flag_exit = exit();} break;
		default : break;
		};
    };

	_getch();
	return 0;
};