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
	//LOG("Destructor");
}

bool ModulePhysics::Start()
{
	//LOG("Start Physics");
	return true;
}

bool ModulePhysics::Update(float dt)
{

	return true;
}


bool ModulePhysics::CleanUp()
{
	//LOG("Cleanup Physics");
	return true;
}


void ModulePhysics::EulerIntegrator(vec3d& iposition, vec3d& ivelocity, vec3d& fposition, vec3d& fvelocity, vec3d acceleration, float dt)
{
	//-------------------------------------- EULER INTEGRATOR CORE --------------------------------------
	
	/*fposition.x = iposition.x + ivelocity.x * dt;		//Gets the object's final position in the X axis.
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
	ivelocity.z = fvelocity.z;							//Resets the object's initial velocity in the Z axis to the new velocity. */

	float mass = 5.0f;

	vec3d newacc;

	//Friction Force
	vec3d Ffriction{ 0,0,0 };
	float mu = 0.3f;  //Friction Coeficient
	Ffriction.x = -(mu * mass);

	//Aerodinamic Force
	vec3d Faerodinamic{ 0,0,0 };
	float d = 1.1455f;  //Air density
	float S = 4.0f * 3.14f * (2.0f*2.0f);  //Superficie of the object in this case a ball 4*pi*r^2;
	float C = 0.2f;  //Coeficient of the aerodinamic resistance

	Faerodinamic.y = C * (0.5f) * d * S * (ivelocity.y * ivelocity.y) * dt;   //Appling the aerodinamic formula C*1/2*d*(v^2)*S

	//Acceleration with applied forces;
	
	fposition.x = iposition.x + ivelocity.x * dt;		//Gets the object's final position in the X axis.
	fposition.y = iposition.y + ivelocity.y * dt;		//Gets the object's final position in the Y axis.
	
	iposition.x = fposition.x;							//Resets the object's initial position in the X axis to the new position.
	iposition.y = fposition.y;							//Resets the object's initial position in the Y axis to the new position.

	fvelocity.x = ivelocity.x + (acceleration.x * Ffriction.x) * dt;			//Gets the object's final velocity in the X axis.
	fvelocity.y = ivelocity.y + (acceleration.y * Faerodinamic.y) * dt;			//Gets the object's final velocity in the Y axis.
	
	ivelocity.x = fvelocity.x;							//Resets the object's initial velocity in the X axis to the new velocity.
	ivelocity.y = fvelocity.y;							//Resets the object's initial velocity in the Y axis to the new velocity.


	LOG("Dt %f", dt);

	LOG("Position X = %f", fposition.x);
	LOG("Position Y = %f", fposition.y);
	//LOG("Position Z = %f", fposition.z);

	LOG("Velocity X = %f", fvelocity.x);
	LOG("Velocity Y = %f", fvelocity.y);
	//LOG("Velocity Z = %f", fvelocity.z);

	LOG("Friction Force X = %f", Ffriction.x);
	LOG("Aerodinamic Force Y = %f", Faerodinamic.y);

	LOG("Acceleration X = %f", acceleration.x);
	LOG("Acceleration Y = %f", acceleration.y);
	//LOG("Acceleration Z = %f", acceleration.z);

	LOG("---------------------------------------------------------------------------------------------------");

	/* To delete?
	if (fvelocity.x <1 && fvelocity.x>-1) {
		LOG("STOOP");
		ivelocity.x = 0;
		fvelocity.x = 0;
	}

	if (fposition.x <= 924) {
		if (fposition.y >= 650)
		{
			fposition.y = 650;

			iposition.x = fposition.x;							//Resets the object's initial position in the X axis to the new position.
			iposition.y = fposition.y;							//Resets the object's initial position in the Y axis to the new position.
			iposition.z = fposition.z;							//Resets the object's initial position in the Y axis to the new position.

			fvelocity.x = ivelocity.x + acceleration.x * dt;	//Gets the object's final velocity in the X axis.
			if (fvelocity.y < 0) {

				fvelocity.y = 0;
			}
			fvelocity.y = -ivelocity.y + acceleration.y * dt;	//Gets the object's final velocity in the Y axis.
			fvelocity.z = ivelocity.z + acceleration.z * dt;	//Gets the object's final velocity in the Z axis.

			ivelocity.x = fvelocity.x;							//Resets the object's initial velocity in the X axis to the new velocity.
			ivelocity.y = fvelocity.y;							//Resets the object's initial velocity in the Y axis to the new velocity.
			ivelocity.z = fvelocity.z;							//Resets the object's initial velocity in the Z axis to the new velocity.

		}
	}


	if (fposition.x >= 924) {
		LOG("REBOUND RIGHT TO LEFT ");



		iposition.x = fposition.x;							//Resets the object's initial position in the X axis to the new position.
		iposition.y = fposition.y;							//Resets the object's initial position in the Y axis to the new position.
		iposition.z = fposition.z;							//Resets the object's initial position in the Y axis to the new position.

		fvelocity.x = (ivelocity.x - acceleration.x * dt)*(-0.7); //DRAG FORCE 0.9;	//Gets the object's final velocity in the X axis.
		if (fvelocity.y < 0) {

			fvelocity.y = 0;
		}
		fvelocity.y = -ivelocity.y + acceleration.y * dt;	//Gets the object's final velocity in the Y axis.
		fvelocity.z = ivelocity.z + acceleration.z * dt;	//Gets the object's final velocity in the Z axis.

		ivelocity.x = fvelocity.x;							//Resets the object's initial velocity in the X axis to the new velocity.
		ivelocity.y = fvelocity.y;							//Resets the object's initial velocity in the Y axis to the new velocity.
		ivelocity.z = fvelocity.z;							//Resets the object's initial velocity in the Z axis to the new velocity.
	}
	else if (fposition.x <= 0) {
		fposition.y = 650;
		LOG("REBOUND LEFT TO RIGHT");

		iposition.x = fposition.x;							//Resets the object's initial position in the X axis to the new position.
		iposition.y = fposition.y;							//Resets the object's initial position in the Y axis to the new position.
		iposition.z = fposition.z;							//Resets the object's initial position in the Y axis to the new position.

		fvelocity.x = -(ivelocity.x + acceleration.x * dt) *(0.7); //DRAG FORCE 0.9;	//Gets the object's final velocity in the X axis.
		if (fvelocity.y < 0) {

			fvelocity.y = 0;
		}
		fvelocity.y = -ivelocity.y + acceleration.y * dt;	//Gets the object's final velocity in the Y axis.
		fvelocity.z = ivelocity.z + acceleration.z * dt;	//Gets the object's final velocity in the Z axis.

		ivelocity.x = fvelocity.x;							//Resets the object's initial velocity in the X axis to the new velocity.
		ivelocity.y = fvelocity.y;							//Resets the object's initial velocity in the Y axis to the new velocity.
		ivelocity.z = fvelocity.z;
	}
	else
	{
		iposition.x = fposition.x;							//Resets the object's initial position in the X axis to the new position.
		iposition.y = fposition.y;							//Resets the object's initial position in the Y axis to the new position.
		iposition.z = fposition.z;							//Resets the object's initial position in the Y axis to the new position.

		fvelocity.x = ivelocity.x + acceleration.x * dt;	//Gets the object's final velocity in the X axis.
		fvelocity.y = ivelocity.y + acceleration.y * dt;	//Gets the object's final velocity in the Y axis.
		fvelocity.z = ivelocity.z + acceleration.z * dt;	//Gets the object's final velocity in the Z axis.

		ivelocity.x = fvelocity.x;							//Resets the object's initial velocity in the X axis to the new velocity.
		ivelocity.y = fvelocity.y;							//Resets the object's initial velocity in the Y axis to the new velocity.
		ivelocity.z = fvelocity.z;							//Resets the object's initial velocity in the Z axis to the new velocity.

	}*/		
}




