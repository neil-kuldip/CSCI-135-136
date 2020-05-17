/*
Author: Neil Kuldip
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 9 - Tasks F

This program models accelerated motion of a particle, which is done by making the velocity of the particle increase on each time step.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Particle {
public: //Particle class encompasses both coordinate positions and velocity
	double x;
	double y;
	double z;
	double vx;
	double vy;
	double vz;
};

Particle* createParticle(double x, double y, double z, double vx, double vy, double vz)
{
	Particle* particlePtr = new Particle; //Dynamically allocates memory for Particle pointer
	*particlePtr = {x, y, z};
	return particlePtr;
}

class Coord3D { //Coordinates in the Cartesian coordinate system of a point
public:
	double x;
	double y;
	double z;
};

void setVelocity(Particle* p, double vx, double vy, double vz)
{ //Assigns the velocity values to their respective variables
	p->vx = vx;
	p->vy = vy;
	p->vz = vz;
}

Coord3D getPosition(Particle* p)
{
	Coord3D result = {p->x, p->y, p->z}; //Returns a Coord3D object with the dereferenced values of the Particle
	return result;
}

void move(Particle* p, double dt)
{
	p->x = p->x + (p->vx * dt); //x' = x + vel.x * dt;
	p->y = p->y + (p->vy * dt); //y' = y + vel.y * dt;
	p->z = p->z + (p->vz * dt); //z' = z + vel.z * dt;
}

void deleteParticle(Particle* p)
{
	delete p; //Deletes Particle object and frees memory
}

int main()
{
	double x, y, z, vx, vy, vz, d = 0; //Asks for user's input 
	cout << "Enter position & velocity: ";
	cin >> x >> y >> z >> vx >> vy >> vz;
	cout << "Enter elasped time: ";
	cin >> d;
	
	// make new particle
	Particle* p = createParticle(x, y, z, vx, vy, vz);
	double time = 0.0;
	double dt = d;
	while (time < 3.0) 
	{
		// update its velocity
		setVelocity(p, vx, vy, vz);

		// move the particle
		move(p, dt);
		time += dt;

		// reporting its coordinates
		cout << "Time: " << time << " \t";
		cout << "Position: "
			<< getPosition(p).x << ", "
			<< getPosition(p).y << ", "
			<< getPosition(p).z << endl;
	}
	// remove the particle, deallocating its memory
	deleteParticle(p);
}
