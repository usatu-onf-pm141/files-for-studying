#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main()
{
    char local_str[255];
	
    float side_1, side_2, angle;
	float &ref_s1 = side_1;
	float &ref_s2 = side_2;
	float &ref_a = angle;
    
    do
	{
        printf("Enter the 1st side of triangle:\n");
        scanf("%s", &local_str);
		side_1 = atof(local_str);
        if (side_1 <= 0)
           printf("It's a wrong value!\n");
    }
    while (side_1 <= 0);
	
    do
	{
        printf("Enter the 2st side of triangle:\n");
        scanf("%s", &local_str);
		side_2 = atof(local_str);
        if (side_2 <= 0)
           printf("It's a wrong value!\n");
    }
    while (side_2 <= 0);
	
    do
	{
        printf("Enter the angle of triangle:\n");
        scanf("%s", &local_str);
		angle = atof(local_str);
        if ((angle <= 0) || (angle >= 180))
           printf("It's a wrong value!\n");
    }
    while ((angle <= 0) || (angle >= 180));
	
	float square = (1.0/2)*ref_s1*ref_s2*sin(ref_a*3.14/180);
	float &ref_sq = square;

	printf("Square of triangle - %f", ref_sq);
    
	_getch();
    return 0;
}