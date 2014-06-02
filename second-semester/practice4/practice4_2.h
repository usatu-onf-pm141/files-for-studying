#pragma once

#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

class Room
{
private:
	float Area;

public:
	Room(float Area = 0.0)
	{
		setArea(Area);
	};
	void setArea(float Area)
	{
		this->Area = Area;
	};
	float getArea()
	{
		return Area;
	};
};

class SingleFlat
{
private:
	int Floor;

public:
	Room flat_room;
	Room kitchen;
	SingleFlat(float Area_1 = 0.0, float Area_2 = 0.0, int Floor = 1)
	{
		flat_room.setArea(Area_1);
		kitchen.setArea(Area_2);
		setFloor(Floor);
	};
	void setFloor(float Floor)
	{
		this->Floor = Floor;
	};
	float getFloor()
	{
		return Floor;
	};
};

class FlatsCity : public SingleFlat
{
private:
	char* NameCity;

public:
	FlatsCity(float Area_1 = 0.0, float Area_2 = 0.0, int Floor = 1, char* NameCity = "ERROR") : SingleFlat(Area_1, Area_2, Floor)
	{
		this->NameCity = NameCity;
	};
	void PrintFlatsCity()
	{
		cout << "Flat of " << NameCity << ":\n";
		cout << "The area of room - " << flat_room.getArea() << ";\n";
		cout << "The area of kitchen - " << kitchen.getArea() << ";\n";
		cout << "The floor of flat - " << getFloor() << ".\n";
	};
	~FlatsCity()
	{
	};
};