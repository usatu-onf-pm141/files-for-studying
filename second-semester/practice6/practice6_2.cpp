#include <iostream>
#include <fstream>
#include <conio.h>
#include <io.h>

using namespace std;

class analysisException
{
private:
    string myString;
public:
    analysisException(string myString)
    {
        setMyString(myString);
    };
    void setMyString(string myString)
    {
        this->myString = myString;
    };
    string getMyString()
    {
        return myString;
    };
};
int main()
{
	unsigned const int MaxLength = 255;
	char temp[MaxLength];
	string myString;
    fstream myFileStream;

    cout << "Please, enter the name of your file: ";
    cin.getline(temp, MaxLength);
	myString = temp;

	try
	{
		if (_access(temp, 0) == -1)
			throw analysisException(myString);
		myFileStream.open(myString, ios::out);
		cout << "Your file is successfully opened.\n";
	}
	catch(analysisException myException)
	{
		if (myException.getMyString().size() == 0)
			cout << "You didn't entered the name of your file. Please, try again.\n";
		else
			cout << "Your file doesn't exist. Please, enter the name again.\n";
	};

    cout << "Press Enter to exit.\n";

    myFileStream.close();
	_getch();
    return 0;
};
