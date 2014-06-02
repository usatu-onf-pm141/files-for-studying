#include <stdio.h>
#include <conio.h>
#include <io.h>

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const short int MAX_LINES = 100;
const short int WIDTH_TITLE = 15;
const short int WIDTH_MANUF = 20;
const short int WIDTH_TYSOF = 13;
const short int WIDTH_MEMCP = 17;
const short int WIDTH_PRICE = 10;
const short int WIDTH_TOTAL = WIDTH_TITLE + WIDTH_MANUF + WIDTH_TYSOF + WIDTH_MEMCP + WIDTH_PRICE + 16;

int writeTableC(FILE** filePtr, char* fileName, char binMode);
int readTableC(FILE** filePtr, char* fileName, char binMode);
void writeTableCPP(ofstream& text, ifstream& tempIn, char* fileName, char binMode);
void readTableCPP(ifstream& text, char* fileName, char binMode);
bool exit();

void binaryMode(char& binMode);
void NameOfFile(char* fileName);

class AbstractTable
{
private:
	virtual void header(ostream &text) = 0;
};
class InfoOfTable
{
public:
	char title[255];
	char manufacturer[255];
	char typeSoftware[255];
	int memoryCapacity;
	int price;
	friend ostream& operator <<(ostream& out, InfoOfTable& Line);
	friend istream& operator >>(istream& in, InfoOfTable& Line);
};
class Table : protected AbstractTable
{
public:
	InfoOfTable infoLine[MAX_LINES];
	void header(ostream &text);
	void header_cout();
	void header_fprintf(FILE*** filePtr);
	void header_printf();
};