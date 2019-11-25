#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "p2Log.h"
#include "ModuleApp.h"
#include "ModulePhysics.h"


ModulePhysics::ModulePhysics() : Module()
{
	LOG("Constructor");
}

ModulePhysics::~ModulePhysics()
{
	LOG("Destructor");
}

bool ModulePhysics::Start()
{
	LOG("Start Physics");
	return true;
}

bool ModulePhysics::Update(float dt)
{

	return true;
}


bool ModulePhysics::CleanUp()
{
	LOG("Cleanup Physics");
	return true;
}

vec3d ModulePhysics::Forces(vec3d& iacceleration, vec3d& facceleration)
{
	vec3d Ffregament = { 0.0f, 0.0f, 0.0f };
	vec3d Faeordinamica = { 0.0f, 0.0f, 0.0f }; //La y es negativa por la pantalla
	float mass = 1.0f;

	iacceleration.x = iacceleration.x*(-1) + Ffregament.x*(-1) + Faeordinamica.x*(-1);
	iacceleration.y = iacceleration.y + Ffregament.y + Faeordinamica.y;
	iacceleration.z = iacceleration.z*(-1) + Ffregament.z*(-1) + Faeordinamica.z*(-1);

	facceleration.x = iacceleration.x;
	facceleration.y = iacceleration.y;
	facceleration.z = iacceleration.z;

	return facceleration;
}

void ModulePhysics::EulerIntegrator(vec3d & iposition, vec3d & ivelocity, vec3d & fposition, vec3d & fvelocity, vec3d acceleration, float dt)
{

		//y = yo + vo * dt + 0.5 * g * dt * dt
		//v = vo + a * dt

		fposition.x = iposition.x + ivelocity.x * dt + 0.5 * acceleration.x * (dt * dt);		//Gets the object's final position in the X axis.
		fposition.y = iposition.y + ivelocity.y * dt + 0.5 * acceleration.y * (dt * dt); 		//Gets the object's final position in the Y axis.
		fposition.z = iposition.z + ivelocity.z * dt + 0.5 * acceleration.z * (dt * dt);		//Gets the object's final position in the Z axis.

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




