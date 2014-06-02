#pragma once
#include "class_list.h"

void binaryMode(char& binMode)
{
	do
	{
		cin.sync();
		cin.clear();
		cout << "\nDo you want to open or write your file in text or binary mode? [y/n]: ";
		cin >> binMode;
		if (!cin.good() || (binMode != 'y') && (binMode != 'n'))
			cout << "It's an incorrect value!\n";
	}
	while(!cin.good() || (binMode != 'y') && (binMode != 'n'));
	cin.sync();
	cin.clear();
};
void NameOfFile(char* fileName)
{
	cin.sync();
	cin.clear();
	cout << "\nEnter the name of file, that you want to open or create: ";
	cin.getline(fileName, 255);
};
int writeTableC(FILE** filePtr, char* fileName, char binMode)
{
	system("cls");
	
	bool flag = false;
	if (_access(fileName, 0) == -1)
		flag = true;

	if (binMode == 'y')
		fopen_s(filePtr, fileName, "ab+");
	else
		fopen_s(filePtr, fileName, "a+");
	
	char temp[255];

	Table MyTable;
	
	int numberOfLines;
	do
	{
		printf("\nHow many lines do you want to add in the table? [1..%d]: ", MAX_LINES);
		gets_s(temp);
		numberOfLines = atoi(temp);
		if (numberOfLines < 1)
			printf("It's an incorrect value!\n");
		else if (numberOfLines > MAX_LINES)
			printf("Limit of lines: %d. Your request: %d. Please, try again!\n", MAX_LINES, numberOfLines);
	}
	while((numberOfLines < 1) || (numberOfLines > MAX_LINES));

	for (int i = 0; i < numberOfLines; i++)
	{
		printf("\nEnter the name of software: ");
		gets_s(MyTable.infoLine[i].title);
		printf("Enter the name of developer: ");
		gets_s(MyTable.infoLine[i].manufacturer);
		printf("Enter the type of software: ");
		gets_s(MyTable.infoLine[i].typeSoftware);
		do
		{
			printf("Enter the merory capacity (Gb): ");
			gets_s(temp);
			MyTable.infoLine[i].memoryCapacity = atoi(temp);
			if ((temp[0] != '0') && (MyTable.infoLine[i].memoryCapacity == 0))
				printf("It's an incorrect value!\n");
		} while ((temp[0] != '0') && (MyTable.infoLine[i].memoryCapacity == 0));
		do
		{
			printf("Enter the price (в USD): ");
			gets_s(temp);
			MyTable.infoLine[i].price = atoi(temp);
			if ((temp[0] != '0') && (MyTable.infoLine[i].price == 0))
				printf("It's an incorrect value!\n");
		} while ((temp[0] != '0') && (MyTable.infoLine[i].price == 0));
	};
	
	system("cls");
	if (flag)
	{
		MyTable.header_fprintf(&filePtr);
	};

	for (int j = 0; j < numberOfLines; j++)
	{
		fprintf(*filePtr, "\n| ");

		fprintf(*filePtr, MyTable.infoLine[j].title);
		for (int i = 0; i < WIDTH_TITLE - strlen(MyTable.infoLine[j].title); i++)
			fprintf(*filePtr, " ");
		fprintf(*filePtr, " | ");
	
		fprintf(*filePtr, MyTable.infoLine[j].manufacturer);
		for (int i = 0; i < WIDTH_MANUF - strlen(MyTable.infoLine[j].manufacturer); i++)
			fprintf(*filePtr, " ");
		fprintf(*filePtr, " | ");

		fprintf(*filePtr, MyTable.infoLine[j].typeSoftware);
		for (int i = 0; i < WIDTH_TYSOF - strlen(MyTable.infoLine[j].typeSoftware); i++)
			fprintf(*filePtr, " ");
		fprintf(*filePtr, " | ");
		
		char* temp_number;

		fprintf(*filePtr, "%d", MyTable.infoLine[j].memoryCapacity);
		_itoa_s(MyTable.infoLine[j].memoryCapacity, temp, 10);
		for (int i = 0; i < WIDTH_MEMCP - strlen(temp); i++)
			fprintf(*filePtr, " ");
		fprintf(*filePtr, " | ");
	
		fprintf(*filePtr, "%d", MyTable.infoLine[j].price);
		_itoa_s(MyTable.infoLine[j].price, temp, 10);
		for (int i = 0; i < WIDTH_PRICE - strlen(temp); i++)
			fprintf(*filePtr, " ");
		fprintf(*filePtr, " |\n");
	
		for (int i = 0; i < WIDTH_TOTAL; i++)
			fprintf(*filePtr, "-");
	};

	fclose(*filePtr);
	_getch();
	return 0;
};
int readTableC(FILE** filePtr, char* fileName, char binMode)
{
	
	
	char temp[2] = "";
	if (binMode == 'y')
		strcat_s(temp, "rb");
	else
		strcat_s(temp, "r");

	if((fopen_s(filePtr, fileName, temp)) != NULL)
	{
		printf("Error with opening file!\n");
		_getch();
		return 0;
	};

	system("cls");

	char ch;
	while(!feof(*filePtr))
	{
		ch = getc(*filePtr);
		if (ch != EOF)
			printf("%c", ch);
	};

	fclose(*filePtr);
	_getch();
	return 0;
};
void writeTableCPP(ofstream& text, ifstream& tempIn, char* fileName, char binMode)
{
	system("cls");

	bool flag = false;
	if (_access(fileName, 0) == -1)
		flag = true;

	if (binMode == 'y')
		text.open(fileName, ios::binary);
	else
		text.open(fileName, ios::app);

	Table myTable;
	
	int numberOfLines;
	do
	{
		cin.sync();
		cin.clear();
		cout << "\nHow many lines do you want to add in the table? [1.." << MAX_LINES << "]: ";
		cin >> numberOfLines;
		if (!cin.good() || (numberOfLines < 1))
			cout << "It's an incorrect value!\n";
		else if (numberOfLines > MAX_LINES)
			cout << "Limit of lines: " << MAX_LINES << ". Your request: " << numberOfLines << ". Please, try again!\n";
	}
	while(!cin.good() || (numberOfLines < 1) || (numberOfLines > MAX_LINES));

	for (int i = 0; i < numberOfLines; i++)
		cin >> myTable.infoLine[i];
	
	system("cls");

	if (flag)
		myTable.header(text);
	for (int i = 0; i < numberOfLines; i++)
	{
		text << myTable.infoLine[i];
	};

	text.close();
};
void readTableCPP(ifstream& text, char* fileName, char binMode)
{
	system("cls");

	if (binMode == 'y')
		text.open(fileName, ios::binary);
	else
		text.open(fileName, ios::in);

	char str[255];
	while(!text.eof())
	{
		text.getline(str, 255, '\n');
		cout << str << '\n';
	};

	_getch();
};
bool exit()
{
    cout << "Thank you for using the program. Goodbye!\n";
    return true;
};

ostream& operator <<(ostream& out, InfoOfTable& Line)
{
	out << "\n| ";
	out << setw(WIDTH_TITLE);
	out << left << Line.title;
	out << " | ";
	out << setw(WIDTH_MANUF);
	out << left << Line.manufacturer;
	out << " | ";
	out << setw(WIDTH_TYSOF);
	out << left << Line.typeSoftware;
	out << " | ";
	out << setw(WIDTH_MEMCP);
	out << left << Line.memoryCapacity;
	out << " | ";
	out << setw(WIDTH_PRICE);
	out << left << Line.price;
	out << " |\n";
	
	for (int i = 0; i < WIDTH_TOTAL; i++)
		out << "-";

	return out;
};
istream& operator >>(istream& in, InfoOfTable& Line)
{
	in.sync();
	in.clear();
	cout << "\nEnter the name of software: ";
	in.getline(Line.title, 255);
	cout << "Enter the name of developer: ";
	in.getline(Line.manufacturer, 255);
	cout << "Enter the type of software: ";
	in.getline(Line.typeSoftware, 255);
	do
	{
		in.sync();
		in.clear();
		cout << "Enter the merory capacity (Gb): ";
		in >> Line.memoryCapacity;
		if (!cin.good())
			cout << "It's an incorrect value!\n";
	}
	while(!cin.good());
	do
	{
		in.sync();
		in.clear();
		cout << "Enter the price (в USD): ";
		in >> Line.price;
		if (!cin.good())
			cout << "It's an incorrect value!\n";
	}
	while(!cin.good());

	return in;
};
void Table::header(ostream& text)
{
	for (int i = 0; i < WIDTH_TOTAL; i++)
		text << "-";

	text << "\n| ";
	text << setw(WIDTH_TITLE);
	text << left << "Название";
	text << " | ";
	text << setw(WIDTH_MANUF);
	text << left << "Фирма-производитель";
	text << " | ";
	text << setw(WIDTH_TYSOF);
	text << left << "Вид продукта";
	text << " | ";
	text << setw(WIDTH_MEMCP);
	text << left << "Объём памяти, Гб";
	text << " | ";
	text << setw(WIDTH_PRICE);
	text << left << "Цена, USD";
	text << " |\n";
	
	for (int i = 0; i < WIDTH_TOTAL; i++)
		text << "-";
}
void Table::header_cout()
{
	for (int i = 0; i < WIDTH_TOTAL; i++)
		cout << "-";

	cout << "\n| ";
	cout << setw(WIDTH_TITLE);
	cout << left << "Название";
	cout << " | ";
	cout << setw(WIDTH_MANUF);
	cout << left << "Фирма-производитель";
	cout << " | ";
	cout << setw(WIDTH_TYSOF);
	cout << left << "Вид продукта";
	cout << " | ";
	cout << setw(WIDTH_MEMCP);
	cout << left << "Объём памяти, Гб";
	cout << " | ";
	cout << setw(WIDTH_PRICE);
	cout << left << "Цена, USD";
	cout << " |\n";
	
	for (int i = 0; i < WIDTH_TOTAL; i++)
		cout << "-";
};
void Table::header_fprintf(FILE*** filePtr)
{
	for (int i = 0; i < WIDTH_TOTAL; i++)
		fprintf(**filePtr, "-");
	fprintf(**filePtr, "\n| ");

	fprintf(**filePtr, "Название");
	for (int i = 0; i < WIDTH_TITLE - strlen("Название"); i++)
		fprintf(**filePtr, " ");
	fprintf(**filePtr, " | ");
	
	fprintf(**filePtr, "Фирма-производитель");
	for (int i = 0; i < WIDTH_MANUF - strlen("Фирма-производитель"); i++)
		fprintf(**filePtr, " ");
	fprintf(**filePtr, " | ");

	fprintf(**filePtr, "Вид продукта");
	for (int i = 0; i < WIDTH_TYSOF - strlen("Вид продукта"); i++)
		fprintf(**filePtr, " ");
	fprintf(**filePtr, " | ");
	
	fprintf(**filePtr, "Объём памяти, Гб");
	for (int i = 0; i < WIDTH_MEMCP - strlen("Объём памяти, Гб"); i++)
		fprintf(**filePtr, " ");
	fprintf(**filePtr, " | ");
	
	fprintf(**filePtr, "Цена, USD");
	for (int i = 0; i < WIDTH_PRICE - strlen("Цена, USD"); i++)
		fprintf(**filePtr, " ");
	fprintf(**filePtr, " |\n");
	
	for (int i = 0; i < WIDTH_TOTAL; i++)
		fprintf(**filePtr, "-");
	fprintf(**filePtr, "\n");
};