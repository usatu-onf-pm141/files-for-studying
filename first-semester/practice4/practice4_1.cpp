#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char local_str[255];

void request()
{
	printf("Enter the length of sting: ");
	scanf("%s", &local_str);
}
void stars(unsigned short int N);

int main()
{
	unsigned short int length;

	do
        {
            request();
			if (atoi(local_str) == 0)
				printf("It's a wrong value!\n");
        }
    while (atoi(local_str) == 0);
    length = atoi(local_str);

    stars(length);

	_getch();
    return 0;
}

void stars(unsigned short int N)
{
	for (unsigned short int i = 1; i <= N; i++)
		printf("*");
}