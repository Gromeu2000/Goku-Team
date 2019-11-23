#include "p2Defs.h"
#include "p2Log.h"
#include "ModuleApp.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleScene.h"
#include "ModuleInput.h"

#include "SDL_image/include/SDL_image.h"
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )



ModuleScene::ModuleScene() : Module()
{
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

	return ret;
}

bool ModuleScene::PostUpdate()
{
	bool ret = true;

	if (App->input->GetKeyDown(SDLK_ESCAPE) == true) {
		LOG("ESCAPE");
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
