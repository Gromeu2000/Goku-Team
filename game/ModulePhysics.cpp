#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "ModulePhysics.h"
#include"Application.h"



ModulePhysics::ModulePhysics(Application*app, bool start_enabled) : Module(app, start_enabled)
{
	LOG("Constructor");
}

ModulePhysics::~ModulePhysics()
{
	LOG("Destructor");
}

update_status ModulePhysics::Update()
{




	return UPDATE_CONTINUE;
}

bool ModulePhysics::Start()
{
	LOG("Start Physics");
	return true;
}

bool ModulePhysics::CleanUp()
{
	LOG("Cleanup Physics");
	return true;
}

void ModulePhysics::EulerIntegrator(vec3d& iposition, vec3d& ivelocity, vec3d& fposition, vec3d& fvelocity, vec3d acceleration, float dt)
{
	//y = yo + vo * dt
	//v = vo + a * dt
	fposition.x = iposition.x + ivelocity.x * dt;		//Gets the object's final position in the X axis.
	fposition.y = iposition.y + ivelocity.y * dt;		//Gets the object's final position in the Y axis.
	fposition.z = iposition.z + ivelocity.z * dt;		//Gets the object's final position in the Z axis.

	iposition.x = fposition.x;							//Resets the object's initial position in the X axis to the new position.
	iposition.y = fposition.y;							//Resets the object's initial position in the Y axis to the new position.
	iposition.z = fposition.z;							//Resets the object's initial position in the Y axis to the new position.

	fvelocity.x = ivelocity.x + acceleration.x * dt;	//Gets the object's final velocity in the X axis.
	fvelocity.y = ivelocity.y + acceleration.y * dt;	//Gets the object's final velocity in the Y axis.
	fvelocity.z = ivelocity.z + acceleration.z * dt;	//Gets the object's final velocity in the Z axis.

	ivelocity.x = fvelocity.x;							//Resets the object's initial velocity in the X axis to the new velocity.
	ivelocity.y = fvelocity.y;							//Resets the object's initial velocity in the Y axis to the new velocity.
	ivelocity.z = fvelocity.z;							//Resets the object's initial velocity in the Z axis to the new velocity.
}


//iPoint IntegratorPos(iPoint pos_, iPoint vel_, int t_, iPoint acc_)
//{
//	iPoint newPos;
//	newPos.x = (pos_.x + vel_.x * t_ + 0.5*acc_.x*t_*t_);
//	newPos.y = (pos_.y + vel_.y * t_ + 0.5*acc_.y*t_*t_);
//
//	return newPos;
//}
//
//iPoint IntegratorVel(iPoint pos_, iPoint vel_, int t_, iPoint acc_)
//{
//	iPoint newVel;
//	newVel.x = vel_.x + acc_.x * t_;
//	newVel.y = vel_.y + acc_.y * t_;
//
//	return newVel;
//}
//
//int IntegratorResolver()
//{
//	int Xi = 0;
//	int V = 3;
//	int Tf = 5;
//	int T = 1;
//	std::cout << "xi:" << Xi << "  vi:" << V << "  a:0" << std::endl;
//
//	for (T; T <= Tf; T++)
//	{
//		std::cout << "T:" << T << "  x:" << IntegratorPos(Xi, V, T) << "  v:" << IntegratorVel(Xi, V, T) << "  a:0" << std::endl;
//
//	}
//}
