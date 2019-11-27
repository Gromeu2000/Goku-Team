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
	vec3d Ffriction = { 25.0f, 0.0f, 0.0f };
	vec3d Faeordinamic = { 25.0f, 0.0f, 0.0f }; //La y es negativa por la pantalla
	float mass = 1.0f;

	facceleration.x = iacceleration.x*(-1) + Ffriction.x*(-1) + Faeordinamic.x*(-1);
	facceleration.y = iacceleration.y + Ffriction.y + Faeordinamic.y;
	facceleration.z = iacceleration.z*(-1) + Ffriction.z*(-1) + Faeordinamic.z*(-1);

	return facceleration;
}

void ModulePhysics::EulerIntegrator(vec3d & iposition, vec3d & ivelocity, vec3d & fposition, vec3d & fvelocity, vec3d acceleration, float dt)
{
	
		

		fposition.x = iposition.x + ivelocity.x * dt + 0.5 * acceleration.x * (dt * dt);		//Gets the object's final position in the X axis.
		fposition.y = iposition.y + ivelocity.y * dt + 0.5 * acceleration.y * (dt * dt); 		//Gets the object's final position in the Y axis.
		fposition.z = iposition.z + ivelocity.z * dt + 0.5 * acceleration.z * (dt * dt);		//Gets the object's final position in the Z axis.

		if (fvelocity.x <1 && fvelocity.x>-1 ) {
			LOG("STOOP");
			ivelocity.x = 0;
			fvelocity.x = 0;
			acceleration.x=0;
			
		}

		if (fposition.x <= 924 ) {
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
		

	    if (fposition.x >= 924 ){
				LOG("REBOUND RIGHT TO LEFT ");
			


				iposition.x = fposition.x;							//Resets the object's initial position in the X axis to the new position.
				iposition.y = fposition.y;							//Resets the object's initial position in the Y axis to the new position.
				iposition.z = fposition.z;							//Resets the object's initial position in the Y axis to the new position.

				fvelocity.x = (ivelocity.x - acceleration.x * dt)*(-0.7) ; //DRAG FORCE 0.9;	//Gets the object's final velocity in the X axis.
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

				//fvelocity.x = ivelocity.x + acceleration.x * dt;	//Gets the object's final velocity in the X axis.
				fvelocity.y = ivelocity.y + acceleration.y * dt;	//Gets the object's final velocity in the Y axis.
				fvelocity.z = ivelocity.z + acceleration.z * dt;	//Gets the object's final velocity in the Z axis.

				ivelocity.x = fvelocity.x;							//Resets the object's initial velocity in the X axis to the new velocity.
				ivelocity.y = fvelocity.y;							//Resets the object's initial velocity in the Y axis to the new velocity.
				ivelocity.z = fvelocity.z;							//Resets the object's initial velocity in the Z axis to the new velocity.

		}
		
}




