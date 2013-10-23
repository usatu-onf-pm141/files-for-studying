#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
	long double big_rad, small_rad, local_var;
	char local_str[256];
	const float Pi = 3.14;
	bool flag = true;

	do
	{
		printf("Enter radius of big circle: ");
		scanf("%s", local_str);
		if (atof(local_str) == 0)
			printf("It's a wrong value!\n");
	}
	while (atof(local_str) == 0);
	big_rad = atof(local_str);

	do
	{
		printf("Enter radius of small circle: ");
		scanf("%s", local_str);
		if (atof(local_str) == 0)
			printf("It's a wrong value!\n");
	}
	while (atof(local_str) == 0);
	small_rad = atof(local_str);

	if (big_rad < small_rad)
	{
		local_var = big_rad;
		big_rad = small_rad;
		small_rad = local_var;
	};

	printf("\nSquare of the circle is: %lf", Pi*(pow(big_rad, 2) - pow(small_rad, 2)));

	_getch();
	return 0;
}