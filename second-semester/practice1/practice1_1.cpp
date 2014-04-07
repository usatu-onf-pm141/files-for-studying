#include <iostream> // for input/output
#include <conio.h> // for _getch()
#include <stdlib.h> // for srand()
#include <time.h> // for time()

using namespace std; // for <iostream>

class smile
{
	float radius_circle, x_r, y_r; // face of smile
	float radius_left_eye, x_le, y_le; // left eye of smile
	float radius_right_eye, x_re, y_re; // right eye of smile
	int rgb[3];
public:
	smile(float r = 25, float x = 320, float y = 240) // constructor
	{
		radius_circle = r;
		x_r = x;
		y_r = y;
		radius_left_eye = 0.3*r;
		x_le = x-0.5*r;
		y_le = y+0.5*r;
		radius_right_eye = 0.3*r;
		x_re = x+0.5*r;
		y_re = y+0.5*r;
		for (int i = 0; i < 3; i++)
			rgb[i] = 0;
	};
	void setColor(int r, int g, int b) // set the color of lines
	{
		rgb[0] = r;
		rgb[1] = g;
		rgb[2] = b;
	};
	void listLips(int flag) // the list of lips
	{
		switch(flag)
		{
			case 1 : // the happy lips
				{
					float x[4], y[4];
					x[0] = x_r-0.7*radius_circle;
					y[0] = y_r-0.5*radius_circle;
					x[1] = x_r-0.3*radius_circle;
					y[1] = y_r-0.8*radius_circle;
					x[2] = x_r+0.3*radius_circle;
					y[2] = y_r-0.8*radius_circle;
					x[3] = x_r+0.7*radius_circle;
					y[3] = y_r-0.5*radius_circle;

					cout << "Print the happy lips:\n\n";
					cout << "Line: coordinates - (" << x[0] << ", " << y[0];
					cout << ", " << x[1] << ", " << y[1] << ").\n";
					cout << "Line: coordinates - (" << x[1] << ", " << y[1];
					cout << ", " << x[2] << ", " << y[2] << ").\n";
					cout << "Line: coordinates - (" << x[2] << ", " << y[2];
					cout << ", " << x[3] << ", " << y[3] << ").\n\n";

					cout << "Delete the happy lips:\n\n";
					cout << "Line: coordinates - (" << x[0] << ", " << y[0];
					cout << ", " << x[1] << ", " << y[1] << ").\n";
					cout << "Line: coordinates - (" << x[1] << ", " << y[1];
					cout << ", " << x[2] << ", " << y[2] << ").\n";
					cout << "Line: coordinates - (" << x[2] << ", " << y[2];
					cout << ", " << x[3] << ", " << y[3] << ").\n\n";
					break;
				};
			case 2 : // the serious lips
				{
					float x[2], y[2];
					x[0] = x_r-0.7*radius_circle;
					y[0] = y_r-0.5*radius_circle;
					x[1] = x_r+0.7*radius_circle;
					y[1] = y_r-0.5*radius_circle;

					cout << "Print the serious lips:\n\n";
					cout << "Line: coordinates - (" << x[0] << ", " << y[0];
					cout << ", " << x[1] << ", " << y[1] << ").\n\n";

					cout << "Delete the serious lips:\n\n";
					cout << "Line: coordinates - (" << x[0] << ", " << y[0];
					cout << ", " << x[1] << ", " << y[1] << ").\n\n";
					break;
				};
			case 3 : // the sad lips
				{
					float x[4], y[4];
					x[0] = x_r-0.7*radius_circle;
					y[0] = y_r-0.5*radius_circle;
					x[1] = x_r-0.3*radius_circle;
					y[1] = y_r-0.2*radius_circle;
					x[2] = x_r+0.3*radius_circle;
					y[2] = y_r-0.2*radius_circle;
					x[3] = x_r+0.7*radius_circle;
					y[3] = y_r-0.5*radius_circle;

					cout << "Print the sad lips:\n\n";
					cout << "Line: coordinates - (" << x[0] << ", " << y[0];
					cout << ", " << x[1] << ", " << y[1] << ").\n";
					cout << "Line: coordinates - (" << x[1] << ", " << y[1];
					cout << ", " << x[2] << ", " << y[2] << ").\n";
					cout << "Line: coordinates - (" << x[2] << ", " << y[2];
					cout << ", " << x[3] << ", " << y[3] << ").\n\n";

					cout << "Delete the sad lips:\n\n";
					cout << "Line: coordinates - (" << x[0] << ", " << y[0];
					cout << ", " << x[1] << ", " << y[1] << ").\n";
					cout << "Line: coordinates - (" << x[1] << ", " << y[1];
					cout << ", " << x[2] << ", " << y[2] << ").\n";
					cout << "Line: coordinates - (" << x[2] << ", " << y[2];
					cout << ", " << x[3] << ", " << y[3] << ").\n\n";
					break;
				};
			case 4 : // the psycho lips
				{
					float x[5], y[5];
					x[0] = x_r-0.7*radius_circle;
					y[0] = y_r-0.5*radius_circle;
					x[1] = x_r-0.3*radius_circle;
					y[1] = y_r-0.2*radius_circle;
					x[2] = x_r;
					y[2] = y_r-0.8*radius_circle;
					x[3] = x_r+0.3*radius_circle;
					y[3] = y_r-0.2*radius_circle;
					x[4] = x_r+0.7*radius_circle;
					y[4] = y_r-0.5*radius_circle;

					cout << "Print the psyho lips:\n\n";
					cout << "Line: coordinates - (" << x[0] << ", " << y[0];
					cout << ", " << x[1] << ", " << y[1] << ").\n";
					cout << "Line: coordinates - (" << x[1] << ", " << y[1];
					cout << ", " << x[2] << ", " << y[2] << ").\n";
					cout << "Line: coordinates - (" << x[2] << ", " << y[2];
					cout << ", " << x[3] << ", " << y[3] << ").\n";
					cout << "Line: coordinates - (" << x[3] << ", " << y[3];
					cout << ", " << x[4] << ", " << y[4] << ").\n\n";

					cout << "Delete the psyho lips:\n\n";
					cout << "Line: coordinates - (" << x[0] << ", " << y[0];
					cout << ", " << x[1] << ", " << y[1] << ").\n";
					cout << "Line: coordinates - (" << x[1] << ", " << y[1];
					cout << ", " << x[2] << ", " << y[2] << ").\n";
					cout << "Line: coordinates - (" << x[2] << ", " << y[2];
					cout << ", " << x[3] << ", " << y[3] << ").\n";
					cout << "Line: coordinates - (" << x[3] << ", " << y[3];
					cout << ", " << x[4] << ", " << y[4] << ").\n\n";
					break;
				};
		};
	};
	void createBase() // create the base of smile
	{
		cout << "Print the base of smile:\n\n";
		
		cout << "The color of lines - (";
		cout << rgb[0];
		cout << ", " << rgb[1];
		cout << ", " << rgb[2] << ").\n";
		
		cout << "Circle (face): radius - " << radius_circle;
		cout << "; coordinates - (" << x_r;
		cout << ", " << y_r << ").\n";
		
		cout << "Circle (left eye): radius - " << radius_left_eye;
		cout << "; coordinates - (" << x_le;
		cout << ", " << y_le << ").\n";
		
		cout << "Circle (right eye): radius - " << radius_right_eye;
		cout << "; coordinates - (" << x_re;
		cout << ", " << y_re << ").\n\n";
	};
	void deleteBase() // delete the base of smile
	{
		cout << "Delete the base of smile:\n\n";
		
		cout << "The color of lines - (";
		cout << rgb[0];
		cout << ", " << rgb[1];
		cout << ", " << rgb[2] << ").\n";

		cout << "Circle (face): radius - " << radius_circle;
		cout << "; coordinates - (" << x_r;
		cout << ", " << y_r << ").\n";

		cout << "Circle (left eye): radius - " << radius_left_eye;
		cout << "; coordinates - (" << x_le;
		cout << ", " << y_le << ").\n";

		cout << "Circle (right eye): radius - " << radius_right_eye;
		cout << "; coordinates - (" << x_re;
		cout << ", " << y_re << ").\n\n";
	};
};

int main()
{
	srand(time(NULL)); // for rand()
	
	// limit of radius: 0..100
	// limit of coordinates: (0..640, 0..480)
	// limit of color: (0..255, 0..255, 0..255)
	
	const int N = 6; // the number of smiles on the screen
	smile objects[N];

	for (int i = 0; i < N; i++)
	{
		objects[i].setColor(rand()%256, rand()%256, rand()%256); // set the color of lines
		objects[i].createBase(); // create the base of smile
		objects[i].listLips(rand()%4+1); // create one of the "lips"
	};
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < 6; k++)
		{
			objects[i].listLips(rand()%4+1); // set the "smiles" of smile
			cout << "Waiting 1 or 2 seconds.\n\n";
		};
		objects[i].deleteBase(); // delete the base of smile
	};

	_getch();
	return 0;
}