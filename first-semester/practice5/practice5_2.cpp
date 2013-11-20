#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

float ref_power(float &ref_b, float &ref_d)
{
    float result = powf(ref_b, ref_d);
    float &ref_res = result;
    
    return ref_res;
}

int main()
{
    char local_str[255];
	
    float base, degree;
	float &ref_b = base;
	float &ref_d = degree;
    
    do
    {
        do
        {
            printf("Enter the base of number:\n");
            scanf("%s", &local_str);
            base = atof(local_str);
            if ((base == 0) && (local_str[0] != '0'))
               printf("It's a wrong value!\n");
        }
        while ((base == 0) && (local_str[0] != '0'));

        do
        {
            printf("Enter the power of number:\n");
            scanf("%s", &local_str);
            degree = atof(local_str);
            if ((degree == 0) && (local_str[0] != '0'))
               printf("It's a wrong value!\n");
        }
        while ((degree == 0) && (local_str[0] != '0'));
        
        if ((base == 0) && (degree <= 0))
           printf("Error! This operation is not defined. Please, try again!\n");
    }
    while ((base == 0) && (degree <= 0));

	printf("Result of a^b - %f", ref_power(base, degree));

	_getch();
    return 0;
}