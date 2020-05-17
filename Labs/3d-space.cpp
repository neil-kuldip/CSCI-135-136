/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 9 - Tasks E

This program uses the functions: Coord3D* createCoord3D(double x, double y, double z); and void deleteCoord3D(Coord3D *p);
that create, delete, and coordinate objects dynamically
*/

#include <iostream>
#include <cmath>
using namespace std;

class Coord3D { //Coordinates in the Cartesian coordinate system of a point
public:
	double x; 
	double y;
	double z;
};

//Task A - receives the coordinates of a point P passed as a pointer, and computes the distance from the origin to the point P
double length (Coord3D *p)
{
	double dist = sqrt(pow(p->x , 2) + pow(p->y, 2) + pow(p->z, 2)); //Length of the vector from the origin
	return dist;
}

//Task B - receives the coordinates of two points (passed as pointers), and returns the pointer of the point that is farther away from the origin
Coord3D* fartherFromOrigin(Coord3D* p1, Coord3D* p2)
{
	if (length(p1) >= length(p2)) //If distance of first point is longer, returns the first pointer
	{
		return p1;
	}
	return p2; //Else returns the second pointer
}

//Task C - gets the position and the velocity of an object and has to compute object’s new coordinates after the time interval dt
void move(Coord3D* ppos, Coord3D* pvel, double dt)
{
	ppos->x = ppos->x + (pvel->x * dt);//x' = x + vel.x * dt;
	ppos->y = ppos->y + (pvel->y * dt);//y' = y + vel.y * dt;
	ppos->z = ppos->z + (pvel->z * dt);//z' = z + vel.z * dt;
}

Coord3D* createCoord3D(double x, double y, double z)
{
	Coord3D* result = new Coord3D; //Dynamically allocates memory for Coord3D object
	*result = {x, y, z};
	return result;
}

void deleteCoord3D(Coord3D* p)
{
	delete p; //Deletes Coord3D object and frees memory
}

int main()
{
	double x, y, z, a, b, c, d = 0; //Asks for user's input of coordinates
	cout << "Enter position: ";
	cin >> x >> y >> z;
	cout << "Enter velocity: ";
	cin >> a >> b >> c;
	cout << "Elasped time: ";
	cin >> d;

	Coord3D* pos = createCoord3D(x, y, z);
	Coord3D* vel = createCoord3D(a, b, c);
	double dt = d;

	move(pos, vel, dt); //Calls the velocity function

	cout << "Coordinates after 10 seconds: ";
	cout << pos->x << " " << pos->y << " " << pos->z << endl;

	deleteCoord3D(pos); //Release memory
	deleteCoord3D(vel);
}