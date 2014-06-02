#include "practice4_1.h"

int main()
{
	char *name_ptr, name[255];
	char *surname_ptr, surname[255];
	char *father_name_ptr, father_name[255];
	char *diploma_ptr, diploma[255];
	int ID, course;
	
	getString(name, "name"); name_ptr = name;
	getString(surname, "surname"); surname_ptr = surname;
	getString(father_name, "father name"); father_name_ptr = father_name;
	getNumber(course, "course");
	getNumber(ID, "ID");
	
	Student Student_1(name_ptr, surname_ptr, father_name_ptr, course, ID);
	Student_1.PrintStudent();
	
	getString(name, "name"); name_ptr = name;
	getString(surname, "surname"); surname_ptr = surname;
	getString(father_name, "father name"); father_name_ptr = father_name;
	getString(diploma, "diploma"); diploma_ptr = diploma;
	getNumber(ID, "ID");
	
	StudentDiploma Student_2(name_ptr, surname_ptr, father_name_ptr, 4, ID, diploma_ptr);
	Student_2.PrintStudent();
	
	_getch();
	return 0;
}