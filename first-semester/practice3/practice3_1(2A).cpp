#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>;

using namespace std;

void main()
{
srand(time(NULL));
int mas1[15], mas2[15], mas3[15], mas4[15]; 
cout « "mas1= ";
for ( int i=0; i<=14; i++)
{
mas1[i] = rand()% 15 +1 ;
mas2[i] = rand()% 15 +1 ;
mas3[i] = rand()% 15 +1 ;

cout « mas1[i] « " ";
}
cout « endl; 
cout « "mas2= ";
for (int i=0; i<=14; i++)
{
cout « mas2[i] « " ";
}
cout « endl; 
cout « "mas3= ";
for (int i=0; i<=14; i++)
{
cout « mas3[i] « " ";
}
cout « endl;
cout « "mas4= ";
for (int i=0; i<=14; i++)
{mas4[i]=mas3[i]-mas2[i]-mas1[i];
cout « mas4[i]« " ";
}
_getch();
}