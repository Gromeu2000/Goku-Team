
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
};

struct Object
{
	p2SString	name;
	iPoint		pos;
	iPoint		speed;
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
	iPoint IntegratorPos(iPoint pos_, iPoint vel_, int t_, iPoint acc_);
	iPoint IntegratorVel(int x_, int v_, int t_, int a_ = 0);
	int IntegratorResolver();

	void EulerIntegrator(vec3d& iposition, vec3d& ivelocity, vec3d& fposition, vec3d& fvelocity, vec3d acceleration, float dt);


private:
};





int integratorX(int x_, int v_, int t_, int a_ = 0)
{
	return (x_ + v_ * t_);
}
int integratorV(int x_, int v_, int t_, int a_ = 0)
{
	return (v_ + a_ * t_);
}
int main()
{

	int Xi = 0;
	int V = 3;
	int Tf = 5;
	int T = 1;
	std::cout << "xi:" << Xi << "  vi:" << V << "  a:0" << std::endl;

	for (T; T <= Tf; T++)
	{
		std::cout << "T:" << T << "  x:" << integratorX(Xi, V, T) << "  v:" << integratorV(Xi, V, T) << "  a:0" << std::endl;

	}

	system("pause");
	return 0;
}




#endif // __Physics_H__