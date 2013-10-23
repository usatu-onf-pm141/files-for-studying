#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	unsigned short int desired_number, entered_number;
	char local_str[2];
	bool flag = false;

	srand(time(NULL));
	desired_number = rand()%9 + 1;
	for (unsigned short int i = 1; i <= 5; i++)
	{
		do
		{
			printf("It is the %d attempt.\n", i);
			printf("Enter an expected number: ");
			scanf("%s", local_str);
			if (atoi(local_str) == 0)
			printf("It's a wrong value!\n");
			entered_number = atoi(local_str);
			if ((entered_number < 0) || (entered_number > 10))
				printf("It's a wrong value!\n");
		}
		while ((atoi(local_str) == 0) || ((entered_number < 0) || (entered_number > 10)));

		if (entered_number > desired_number)
			printf("Required number is smaller then your number!\n");
		else
		if (entered_number < desired_number)
			printf("Required number is bigger then your number!\n");
		else
		{
			flag = true;
			printf("Yes, you're right! It is %d\n", desired_number);
			_getch();
			return 0;
		}
	}

	if (!flag)
		printf("Unfortunately, you didn't guess! It was %d.\n", desired_number);

	_getch();
	return 0;
}