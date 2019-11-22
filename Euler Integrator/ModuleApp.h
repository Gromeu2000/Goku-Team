#ifndef __MODULEAPP_H__
#define __MODULEAPP_H__

#include "p2List.h"
#include "Module.h"
#include "Timer.h"
#include "PerfTimer.h"


// Modules
class ModuleWindow;
class ModuleRender;
class ModuleTextures;
class ModulePhysics;

class ModuleApp
{
public:

	// Constructor
	ModuleApp(int argc, char* args[]);

	// Destructor
	virtual ~ModuleApp();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called each loop iteration
	bool Update();

	// Called before quitting
	bool CleanUp();

	// Add a new module to handle
	void AddModule(Module* module);

	// Exposing some properties for reading
	int GetArgc() const;
	const char* GetArgv(int index) const;

private:

	// Call modules before each loop iteration
	void PrepareUpdate();

	// Call modules before each loop iteration
	void FinishUpdate();

	// Call modules before each loop iteration
	bool PreUpdate();

	// Call modules on each loop iteration
	bool DoUpdate();

	// Call modules after each loop iteration
	bool PostUpdate();

public:

	// Modules
	ModuleWindow*		win;
	ModuleRender*		render;
	ModuleTextures*		tex;
	ModulePhysics*		physics;



private:

	p2List<Module*>		modules;
	uint				frames;

	int					argc;
	char**				args;

	float				dt;						//Keeps track of the amount of seconds that have passed in the span of a frame.
	Timer				frame_timer;			//Keeps track of everything time related in the span of a frame.
	uint				frame_cap = 60;			//Stores the frames per second cap to be applied.
};

extern ModuleApp* App;

#endif