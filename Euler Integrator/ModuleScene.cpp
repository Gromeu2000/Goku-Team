#include "p2Defs.h"
#include "p2Log.h"
#include "ModuleApp.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleScene.h"
#include "ModuleInput.h"
#include "ModulePhysics.h"
#include "p2Log.h"

#include "SDL_image/include/SDL_image.h"
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )



ModuleScene::ModuleScene() : Module()
{
	background.x = 0;
	background.y = 0;
	background.w = 1024;
	background.h = 827;

	ball.x = 0;
	ball.y = 0;
	ball.w = 100;
	ball.h = 100;

	//Initial Position
	InitPos.x = 0.0f;			//Position in the 'x' axis
	InitPos.y = 0.0f;			//Position in the 'y' axis 
	InitPos.z = 0.0f;			//Position in the 'z' axis

	//Initial Velocity
	InitVel.x = 20.0f;			//Velocity in the 'x' axis
	InitVel.y = 1.0f;			//Velocity in the 'y' axis 
	InitVel.z = 0.0f;			//Velocity in the 'z' axis

	//Initial Acceleration
	float gravity = 50.0f;
	InitAccel.x = 2.0f;			//Acceleration in the 'x' axis
	InitAccel.y = gravity;		//Acceleration in the 'y' axis == gravity
	InitAccel.z = 0.0f;			//Acceleration in the 'z' axis

	CurrentPos = InitPos;
	CurrentVel = InitVel;
}

// Destructor
ModuleScene::~ModuleScene()
{}

// Called before render is available
bool ModuleScene::Awake()
{
	bool ret = true;

	return ret;
}

// Called before the first frame
bool ModuleScene::Start()
{
	//LOG("Start Scene");

	graphics = App->tex->Load("Sprites/Back.jpg");
	graphics_B = App->tex->Load("Sprites/ball.png");

	LOG("EULER INTEGRATOR:");
	LOG("Initial Position X = %f", InitPos.x);
	LOG("Initial Position Y = %f", InitPos.y);
	LOG("Initial Position Z = %f", InitPos.z);

	LOG("Initial Velocity X = %f", InitVel.x);
	LOG("Initial Velocity Y = %f", InitVel.y);
	LOG("Initial Velocity Z = %f", InitVel.z);

	LOG("Initial Acceleration X = %f", InitAccel.x);
	LOG("Initial Acceleration Y = %f", InitAccel.y);
	LOG("Initial Acceleration Z = %f", InitAccel.z);

	LOG("---------------------------------------------------------------------------------------------------");
	bool ret = true;
	return ret;
}

bool ModuleScene::PreUpdate()
{
	bool ret = true;
	return ret;
}

bool ModuleScene::Update(float dt)
{
	bool ret = true;

	App->physics->EulerIntegrator(InitPos, InitVel, CurrentPos, CurrentVel, InitAccel, dt);

	App->render->Blit(graphics, 0, 0, &background);
	App->render->Blit(graphics_B, CurrentPos.x, CurrentPos.y, &ball);

	return ret;
}

bool ModuleScene::PostUpdate()
{
	bool ret = true;

	if (App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
	{
		ret = false;
	}

	return ret;
}

// Called before quitting
bool ModuleScene::CleanUp()
{
	bool ret = true;
	return ret;
}
