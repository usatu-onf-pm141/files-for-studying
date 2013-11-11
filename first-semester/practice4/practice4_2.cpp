#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

double matrix[2][2];

inline double determinant()
{
	return matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
}

int main()
{
    char local_str[255];

	for (unsigned short int i = 1; i <= 2; i++)
    {
        for (unsigned short int j = 1; j <= 2; j++)
            {
                do
                    {
                        printf("Enter the [%d][%d]-element of the matrix[2][2]: \n", i, j);
                        scanf("%s", &local_str);
                        if (atof(local_str) == 0)
                           printf("It's a wrong value!\n");
                    }
                while (atof(local_str) == 0);
                matrix[i][j] = atof(local_str);
            }
    }
    printf("Your matrix is:\n %-10.3f %-10.3f \n %-10.3f %-10.3f \n", matrix[1][1], matrix[1][2], matrix[2][1], matrix[2][2]);
	printf("%-10.3f", determinant());

	_getch();
    return 0;
}