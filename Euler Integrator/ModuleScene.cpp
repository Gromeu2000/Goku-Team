#include "p2Defs.h"
#include "p2Log.h"
#include "ModuleApp.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleScene.h"
#include "ModuleInput.h"
#include "ModulePhysics.h"

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

	InitPos = {0, 0, 0};
	InitVel = {100, 0, 0};
	InitAccel = {0, 980, 0};
	CurrentPos = InitPos;
	CurrentVel = InitVel;
	CurrentAccel = InitAccel;
	
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
	LOG("Start Scene");

	graphics = App->tex->Load("Sprites/Back.jpg");
	graphics_B = App->tex->Load("Sprites/ball.png");

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

	App->physics->Forces(InitAccel, CurrentAccel);
	App->physics->EulerIntegrator(InitPos,InitVel,CurrentPos,CurrentVel,CurrentAccel,dt);

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
