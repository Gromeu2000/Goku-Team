#ifndef __MODULESCENE_H__
#define __MODULESCENE_H__

#include "Module.h"
#include "ModulePhysics.h"

class vec3d;

class ModuleScene : public Module
{
public:

	ModuleScene();

	// Destructor
	virtual ~ModuleScene();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called each loop iteration
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect background;
	SDL_Texture* graphics_B = nullptr;
	SDL_Rect ball;

	vec3d InitPos;
	vec3d CurrentPos;
	vec3d InitVel;
	vec3d CurrentVel;
	vec3d InitAccel;

};

#endif // __MODULESCENE_H__