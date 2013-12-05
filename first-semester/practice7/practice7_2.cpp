#include <iostream>
#include <iomanip>

#include <time.h>
#include <stdlib.h>

#include <conio.h>

using namespace std;

template <class my_type_1>
void swaper(my_type_1 &var_1, my_type_1 &var_2)
{
    my_type_1 var_3 = var_1;
    var_1 = var_2;
    var_2 = var_3;
}

void buble_sort(int **arr, int line, int num)
{
	for (int i = 0; i < num - 1; i++)
        for (int j = 0; j < num - (i+1); j++)
        {
            if (arr[line][j] < arr[line][j+1])
            {
                swap(arr[0][j], arr[0][j+1]);
                swap(arr[1][j], arr[1][j+1]);
                swap(arr[2][j], arr[2][j+1]);
                swap(arr[3][j], arr[3][j+1]);
                swap(arr[4][j], arr[4][j+1]);
				swap(arr[5][j], arr[5][j+1]);
            }
        }
}

int main()
{
	int **arr, number_teams;
    
    // output of the number of teams
	
    do
	{
		cin.sync();
		cin.clear();
		cout << "Enter the number of teams: ";
		cin >> number_teams;
		if (!cin.good() || (number_teams <= 0))
			cout << "It's incorrect value!\n" << endl;
	}
	while(!cin.good() || (number_teams <= 0));

	arr = new int *[6];
	for (int i = 0; i < 6; i++)
        arr[i] = new int[number_teams];

	srand(time(NULL));
    
    // output of array (with calculations)
    
	cout << "Array of data: \n" << endl;
	for (int i = 0; i < number_teams; i++)
	{
		arr[5][i] = i+1;
		cout << setw(6) << left << arr[5][i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < number_teams; j++)
		{
			arr[i][j] = rand()%10;
			cout << setw(6) << left << arr[i][j] << " ";
		}
		cout << endl;
	}
    for (int i = 0; i < number_teams; i++)
    {
        arr[3][i] = 0;
        arr[4][i] = 0;
    }
    for (int i = 0; i < number_teams; i++)
    {
        arr[3][i] = arr[0][i] + arr[1][i] + arr[2][i];
        arr[4][i] = arr[0][i]*7 + arr[1][i]*6 + arr[2][i]*5;
    }
    for (int i = 3; i < 5; i++)
    {
        if (i == 3) cout << "The number of medals:" << endl;
        else        cout << "The score:" << endl;
        for (int j = 0; j < number_teams; j++)
            cout << setw(6) << left << arr[i][j] << " ";
        cout << endl;
    }
	
    buble_sort(arr, 4, number_teams);

    // output of array
    
    cout << "\nWinners of the olympiad: \n" << endl;
	for (int i = 0; i < 6; i++)
	{
        if (i == 3) cout << "The number of medals:" << endl;
        else
        if (i == 4) cout << "The score:" << endl;
        
        // input check the number of teams
        
        if (number_teams == 1)
           cout << setw(6) << left << arr[i][0];
        else
        if (number_teams == 2)
        for (int j = 0; j < 2; j++)
            cout << setw(6) << left << arr[i][j] << " ";
        else
        for (int j = 0; j < 3; j++)
            cout << setw(6) << left << arr[i][j] << " ";
        cout << endl;
	}
    
	for (int i = 0; i < 5; i++)
        delete [] arr[i];
    delete [] arr;
    
	_getch();
	return 0;
}