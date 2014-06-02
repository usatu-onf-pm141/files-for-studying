#pragma once
#include <iostream>
#include <cstring>
#include <conio.h>
#include <string.h>

using namespace std;

void getString(char *str, char *part_FIO)
{
	bool flag;
	char temp[255];
	do
	{
		flag = 0;
		cin.sync();
		cin.clear();
		cout << "Enter " << part_FIO << " of student: ";
		cin >> temp;
		for(int i = 0; i < strlen(temp); i++)
			if (((temp[i] < 'a') || (temp[i] > 'z')) && ((temp[i] < 'A') || (temp[i] > 'Z')))
			{
				cout << "It's incorrect value, please, try again!\n";
				flag = 1;
				break;
			};
	}
	while (flag);

	for (int i = 0; i < strlen(temp); i++)
    {
		*str = temp[i];
		str++;
    };
	*str = '\0';
};
void getNumber(int &number, char *part_student)
{
	do
	{
		cin.sync();
		cin.clear();
		cout << "Enter " << part_student << " of student: ";
		cin >> number;
		if(!cin.good() || (number < 0))
			cout << "It's incorrect value! Please, try again.\n";
	}
	while (!cin.good() || (number < 0));
};

class Student
{
protected:
	char *name;
	char *surname;
	char *father_name;
	int course, ID;

public:
	void SetID(int ID)
	{
		this->ID = ID;
	};
	void SetStudent(char *name, char *surname, char *father_name, int course, int ID)
	{
		this->name = name;
		this->surname = surname;
		this->father_name = father_name;
		
		this->course = course;
		SetID(ID);
	};
	Student(char* name, char* surname, char* father_name, int course, int ID)
	{
		SetStudent(name, surname, father_name, course, ID);
	};
	void PrintStudent()
	{
		cout << "FIO of student: \n";
		cout << "Name - " << name << "; \n";
		cout << "Surname - " << surname << "; \n";
		cout << "Father name - " << father_name << "; \n";
		cout << "Course - " << course << "; \n";
		cout << "ID - " << ID << ".\n\n";
	};
	~Student()
	{

	};
};

class StudentDiploma : public Student
{
private:
	char* diploma;

public:
	void SetDiploma(char* diploma)
	{
		this->diploma = diploma;
	};
	StudentDiploma(char* name = "ERROR", char* surname = "ERROR", char* father_name = "ERROR", int course = 4, int ID = 0, char* diploma = "ERROR") : Student(name, surname, father_name, course, ID)
	{
		SetDiploma(diploma);
	};
	void SetStudent(char *name, char *surname, char *father_name, int course, int ID)
	{
		this->name = name;
		this->surname = surname;
		this->father_name = father_name;
		
		this->course = course;
		SetID(ID);
	};
	void PrintStudent()
	{
		cout << "FIO of student with diploma: \n";
		cout << "Name - " << name << "; \n";
		cout << "Surname - " << surname << "; \n";
		cout << "Father name - " << father_name << "; \n";
		cout << "Course - " << course << "; \n";
		cout << "ID - " << ID << ";\n";
		cout << "The name of diploma - " << diploma << ".\n\n";
	};
	~StudentDiploma()
	{

	};
};