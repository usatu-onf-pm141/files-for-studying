#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int *find_max_el(int *local_arr, int local_size)
{
    int *max_el = local_arr;
    for (int i = 0; i < local_size; i++)
        if (*max_el < *(local_arr + i))
            max_el = local_arr + i;
    
    return max_el;
}

int main()
{
	int *arr, size_arr;
    
    // pointer on to array and the size of array
	cout << "Enter the size of array: " << endl;
	cin >> size_arr;
    
     // checked the entered value
	if (!cin.good() || (size_arr <= 0))
    {
        cout << "It's an incorrect value!" << endl;
        getch();
        return 0;
    }
    
    // allocate dynamic memory for array and enter elements
    arr = new int[size_arr];
    for (int i = 0; i < size_arr; i++)
    {
        cout << "Enter the element arr[" << i << "] : " << endl;
        cin >> arr[i];
    
        // checked the entered value
        if (!cin.good())
        {
            cout << "It's an incorrect value!" << endl;
            getch();
            return 0;
        }
    }
    
    // print the array (formatted output)
    cout << "Your array (size of " << size_arr << "): " << endl; 
    for (int i = 0; i < size_arr; i++)
        cout << setw(6) << arr[i];

	// our function trying to find max element in array
	cout << endl << "The value of max element: " << *find_max_el(arr, size_arr);
	cout << endl << "The adress of max element: " << find_max_el(arr, size_arr);

	delete[] arr;

	_getch();
    return 0;
}