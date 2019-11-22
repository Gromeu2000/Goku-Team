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
	float x;
	float y;
	float z;
};

class particle				//Class that will be used to declare objects / particles.
{
public:
	vec3d position;
	vec3d speed;
	vec3d acceleration;
	vec3d gravity;
};

struct Object
{
	p2SString	name;
	iPoint		force;
	iPoint		acc;
	float		mass;
};


class ModulePhysics:public Module
{
public:
	ModulePhysics();
	~ModulePhysics();

	//bool Awake();
	bool Start();
	//bool PreUpdate();
	bool Update();
	//bool PostUpdate();
	bool CleanUp();

public:

	void EulerIntegrator(vec3d& iposition, vec3d& ivelocity, vec3d& fposition, vec3d& fvelocity, vec3d acceleration, float dt);
	bool touch_floor = false;

};



#endif // __MODULEPHYSICS_H__