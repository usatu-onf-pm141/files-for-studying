#include <iostream>
#include <conio.h>

using namespace std;

float array_temp[7];
bool flag = false, flag_exit = false;

void task();
void input();
void min_temp();
void max_temp();
void avg_temp();
void exit();

int main()
{
    
    void (* Main_Menu[6])(void) =
    {task, input, min_temp, max_temp, avg_temp, exit};
    
    cout << "Hello! This program processes the results of the weather forecast.\n" << endl;
    while(!flag_exit)
    {
        cout << "Menu of the program:\n" << endl;
        
        cout << "1 - Task of the program" << endl;
        cout << "2 - Input of data" << endl;
        cout << "3 - Minimum temperature for the week" << endl;
        cout << "4 - Maximum temperature for the week" << endl;
        cout << "5 - Average temperature for the week" << endl;
        cout << "6 - Exit the program" << endl;
        
        int menu_item;
        cout << "\nPlease select one of the menu item [1-6]:";
        cin >> menu_item;
        if (!cin.good() || (menu_item < 1) || (menu_item > 6))
        {
            cout << "It's an incorrect value!" << endl;
            getch();
            return 0;
        }
        
        Main_Menu[menu_item - 1]();
    };
    
    _getch();
	return 0;
}

void task()
{
    cout << "This program processes the results of the weather forecast. You should enter the temperature information for the week." << endl;
    cout << "After that, you can know the minimum, maximum and average temperature for the week. Good luck!\n" << endl;
}
 
void input()
{
    char local_str[255];
    
    for (int i = 0; i < 7; i++)
    {
        do
        {
            cout << "Enter the temperature of the day #" << i << ": ";
            scanf("%s", &local_str);
            array_temp[i] = atof(local_str);
            if ((array_temp[i] == 0) && (local_str[0] != '0'))
               printf("It's a wrong value!\n");
        }
        while((array_temp[i] == 0) && (local_str[0] != '0'));
     
    }
    
    flag = true;
}
 
void min_temp()
{
    if (flag)
    {
        float min_t = array_temp[0];
        for (int i = 0; i < 7; i++)
            if (min_t > array_temp[i])
               min_t = array_temp[i];
        cout << "\n The minimum temperature for the week - " << min_t << "\n" << endl;
    }
    else
        cout << "\nYou didn't enter the temperature inforamtion!\n" << endl;
}
 
void max_temp()
{
    if (flag)
    {
        float max_t = array_temp[0];
        for (int i = 0; i < 7; i++)
            if (max_t < array_temp[i])
               max_t = array_temp[i];
        cout << "\n The maximum temperature for the week - " << max_t << "\n" << endl;
    }
    else
        cout << "\nYou didn't enter the temperature inforamtion!\n" << endl;
}
 
void avg_temp()
{
    if (flag)
    {
        float avg_t = 0;
        for (int i = 0; i < 7; i++)
            avg_t = avg_t + array_temp[i];
        avg_t = avg_t / 7.0;
        cout << "\n The average temperature for the week - " << avg_t << "\n" << endl;
    }
    else
        cout << "\nYou didn't enter the temperature inforamtion!\n" << endl;
}

void exit()
{
    cout << "Thank you for using my program. Goodbye!" << endl;
    flag_exit = true;
}