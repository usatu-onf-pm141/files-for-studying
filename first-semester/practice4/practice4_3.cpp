#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

long double recursive_sum(long double x)
{
    if (x == 1)
       return (x*x)/((x+2)*(x+2));
    else
       return (x*x)/((x+2)*(x+2))+recursive_sum(x-1);
}

long double iteration_sum(long double x)
{
    long double sum = 0;
    
    for (long double i = 1; i <= x; i = i + 1)
        sum = sum + (i*i)/((i+2)*(i+2));
    
    return sum;
}

int main()
{
    char local_str[255];
    unsigned short int flag;
    long int n;
    
    do
	{
        printf("Choose one of the next options:\n");
        printf("1) calculate sum (n^2)/((n+2)^2) with recursive function\n");
        printf("2) calculate sum (n^2)/((n+2)^2) with with iteration cycle\n");
        printf("Please, press 1 or 2: \n");
        scanf("%s", &local_str);
        flag = atoi(local_str);
        if ((flag == 0) || ((flag != 0) && (flag != 1) && (flag != 2)))
           printf("It's a wrong value!\n");
    }
    while ((flag == 0) || ((flag != 0) && (flag != 1) && (flag != 2)));
    
    do
	{
        printf("Please, enter the number \"n\":\n");
        scanf("%s", &local_str);
        if (atof(local_str) == 0)
           printf("It's a wrong value!\n");
    }
    while (atof(local_str) == 0);
    n = atof(local_str);
    
    if (flag == 1)
       printf("%10.10lf", recursive_sum(n));
    else
       printf("%10.10lf", iteration_sum(n));

	_getch();
    return 0;
}