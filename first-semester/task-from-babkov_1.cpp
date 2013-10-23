#define line 3
#define column 3

#include <iostream>
#include <conio.h>

using namespace std;

void main()
{
    char matrix[line][column], required_matrix[line][column];
    long int determinant = 0;
    unsigned int k = 0;
    
    for (matrix[0][0] = -9; matrix[0][0] <= 9; matrix[0][0]++){
    for (matrix[0][1] = -9; matrix[0][1] <= 9; matrix[0][1]++){
    for (matrix[0][2] = -9; matrix[0][2] <= 9; matrix[0][2]++){
    for (matrix[1][0] = -9; matrix[1][0] <= 9; matrix[1][0]++){
    for (matrix[1][1] = -9; matrix[1][1] <= 9; matrix[1][1]++){
    for (matrix[1][2] = -9; matrix[1][2] <= 9; matrix[1][2]++){
    for (matrix[2][0] = -9; matrix[2][0] <= 9; matrix[2][0]++){
    for (matrix[2][1] = -9; matrix[2][1] <= 9; matrix[2][1]++){
    for (matrix[2][2] = -9; matrix[2][2] <= 9; matrix[2][2]++){
		long int intermediate_value = matrix[0][0]*matrix[1][1]*matrix[2][2] + matrix[0][1]*matrix[1][2]*matrix[2][0] + matrix[0][2]*matrix[1][0]*matrix[2][1] - matrix[0][2]*matrix[1][1]*matrix[2][0] - matrix[0][0]*matrix[1][2]*matrix[2][1] - matrix[0][1]*matrix[1][0]*matrix[2][2];
        cout << "Determinant is " << intermediate_value << ". Number " << k << ".\n";
           k++;
        if (intermediate_value > determinant)
        {
           determinant = intermediate_value;
           required_matrix[0][0] = matrix[0][0];
           required_matrix[0][1] = matrix[0][1];
           required_matrix[0][2] = matrix[0][2];
           required_matrix[1][0] = matrix[1][0];
           required_matrix[1][1] = matrix[1][1];
           required_matrix[1][2] = matrix[1][2];
           required_matrix[2][0] = matrix[2][0];
           required_matrix[2][1] = matrix[2][1];
           required_matrix[2][2] = matrix[2][2];
        }
    }}}}}}}}};
    
    cout << required_matrix[0][0] << " " << required_matrix[0][1] << " " << required_matrix[0][2] << endl;
    cout << required_matrix[1][0] << " " << required_matrix[1][1] << " " << required_matrix[1][2] << endl;
    cout << required_matrix[2][0] << " " << required_matrix[2][1] << " " << required_matrix[2][2] << endl;
    cout << determinant << endl;
    _getch();
}