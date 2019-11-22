
#ifndef __Physics_H__
#define __Physics_H__


#include "Application.h"
#include "Globals.h"
#include "p2Point.h"
#include "p2List.h"
#include "Module.h"
#include "p2String.h"


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
	ModulePhysics(Application* app, bool start_enabled = true);
	~ModulePhysics();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	void EulerIntegrator(vec3d& iposition, vec3d& ivelocity, vec3d& fposition, vec3d& fvelocity, vec3d acceleration, float dt);
	bool touch_floor = false;

};



#endif // __Physics_H__