#ifndef __MODULEPHYSICS_H__
#define __MODULEPHYSICS_H__

#include "ModuleApp.h"
#include "Globals.h"
#include "p2Point.h"
#include "p2List.h"
#include "Module.h"
#include "p2SString.h"

class vec3d					//Class that will be used to declare 3D Vectors.
{
public:
	float x;				//Value of the vector in the X axis.
	float y;				//Value of the vector in the Y axis.
	float z;				//Value of the vector in the Z axis.
};

class Object				//Class that will be used to declare objects / particles.
{
public:
	vec3d position;			//Position vector of the particle / body / object.
	vec3d velocity;			//Velocity vector of the particle / body / object.
	vec3d acceleration;		//Acceleration vector of the particle / body / object.
	vec3d gravity;			//Gravity vector of the particle / body / object.
	float mass;				//Mass value of the particle / body / object.
	float surface_area;		//Surface area of the particle / body / object. Used to calculate the drag forces being applied to the object.
	float drag_coefficient;	//Used to calculate the drag forces being applied to the object. Ball drag coefficient: 0.47f;

	p2SString name;			//Name of the object. Used mainly to classify different objects and allow for easy differentiation between them.
};

class ModulePhysics:public Module
{
public:
	ModulePhysics();
	~ModulePhysics();

	//bool Awake();
	bool Start();
	//bool PreUpdate();
	bool Update(float dt);
	//bool PostUpdate();
	bool CleanUp();

public:

	//Core function of the Integrator. Receives an initial position and velocity, and returns their final values. Moreover an acceleration and a time value is received as well.
	void EulerIntegrator(vec3d& iposition, vec3d& ivelocity, vec3d& fposition, vec3d& fvelocity, vec3d acceleration, float dt);
	
	bool touch_floor = false;
	bool rebound = false;
};

#endif // __MODULEPHYSICS_H__