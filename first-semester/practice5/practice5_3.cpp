#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*template <class my_type_1>
void swap(my_type_1 &var_1, my_type_1 &var_2)
{
    my_type var_3 = var_1;
    var_1 = var_2;
    var_2 = var_3;
}*/

template <class my_type_2>
void sort(my_type_2 num_arr[])
{
    unsigned short int min_elem;
    my_type_2 temp;
	for (unsigned short int i = 0; i < 3; i++)
    {
        min_elem = i;
        for (unsigned short int k = i+1; k < 3; k++)
            if (num_arr[min_elem] > num_arr[k])
               min_elem = k;
        temp = num_arr[i];
        num_arr[i] = num_arr[min_elem];
        num_arr[min_elem] = temp;
        /*swap(num_arr[i], num_arr[min_elem]);*/
    }
}

int main()
{
    char local_str[255];
	
    int number_int[3];
    
	for (unsigned short int i = 0; i < 3; i++)
	{
		 do
		 {
               printf("Enter the #%d number (integer value):\n", i);
			   scanf("%s", &local_str);
			   number_int[i] = atoi(local_str);
		       if ((number_int[i] == 0) && (local_str[0] != '0'))
		          printf("It's a wrong value!\n");
		 }
	     while ((number_int[i] == 0) && (local_str[0] != '0'));
	}
    
    for (unsigned short int i = 0; i < 3; i++)
        printf("%5d ", number_int[i]);
    printf("\n");
    sort(number_int);
    for (unsigned short int i = 0; i < 3; i++)
        printf("%5d ", number_int[i]);
    printf("\n\n");
    
    float number_flt[3];
    
    for (unsigned short int i = 0; i < 3; i++)
	{
		 do
		 {
               printf("Enter the #%d number (float value):\n", i);
			   scanf("%s", &local_str);
			   number_flt[i] = atof(local_str);
		       if ((number_flt[i] == 0) && (local_str[0] != '0'))
		          printf("It's a wrong value!\n");
		 }
	     while ((number_flt[i] == 0) && (local_str[0] != '0'));
	}
    
    for (unsigned short int i = 0; i < 3; i++)
        printf("%-5.3f ", number_flt[i]);
    printf("\n");
    sort(number_flt);
    for (unsigned short int i = 0; i < 3; i++)
        printf("%5.3f ", number_flt[i]);
    printf("\n\n");
    
    char number_chr[3];
    
    for (unsigned short int i = 0; i < 3; i++)
	{
        printf("Enter the #%d symbol (char value):\n", i);
		scanf("%s", &local_str);
		number_chr[i] = local_str[0];
	}
    
    for (unsigned short int i = 0; i < 3; i++)
        printf("%c ", number_chr[i]);
    printf("\n");
    sort(number_chr);
    for (unsigned short int i = 0; i < 3; i++)
        printf("%c ", number_chr[i]);
    printf("\n\n");
    
	_getch();
    return 0;
}