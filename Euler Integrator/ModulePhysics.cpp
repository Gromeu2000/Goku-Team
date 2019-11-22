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

void ModulePhysics::EulerIntegrator(vec3d& iposition, vec3d& ivelocity, vec3d& fposition, vec3d& fvelocity, vec3d acceleration, float dt)
{
	if (acceleration.x == 0.0 && acceleration.y == 0.0 && acceleration.z == 0.0)
	{
		//y = yo + vo * dt
		//v = vo + a * dt
		fposition.x = iposition.x + ivelocity.x * dt;		//Gets the object's final position in the X axis.
		fposition.y = iposition.y + ivelocity.y * dt; 		//Gets the object's final position in the Y axis.
		fposition.z = iposition.z + ivelocity.z * dt;		//Gets the object's final position in the Z axis.

		iposition.x = fposition.x;							//Resets the object's initial position in the X axis to the new position.
		iposition.y = fposition.y;							//Resets the object's initial position in the Y axis to the new position.
		iposition.z = fposition.z;							//Resets the object's initial position in the Y axis to the new position.

		fvelocity.x = ivelocity.x ;							//Gets the object's final velocity in the X axis.
		fvelocity.y = ivelocity.y ;							//Gets the object's final velocity in the Y axis.
		fvelocity.z = ivelocity.z ;							//Gets the object's final velocity in the Z axis.

	}
	else
	{
		//y = yo + vo * dt + 0.5 * g * dt * dt
		//v = vo + a * dt
		fposition.x = iposition.x + ivelocity.x * dt + 0.5 * acceleration.x * dt * dt;		//Gets the object's final position in the X axis.
		if (!touch_floor) { fposition.y = iposition.y + ivelocity.y * dt + 0.5 * acceleration.y * dt * dt; }		//Gets the object's final position in the Y axis.
		fposition.z = iposition.z + ivelocity.z * dt + 0.5 * acceleration.z * dt * dt;		//Gets the object's final position in the Z axis.

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
}



