#pragma once

#include "Globals.h"
#include "p2Log.h"
#include "p2List.h"
#include "p2Defs.h"
#include "Timer.h"
#include "perfTimer.h"

class Module;
class ModulePhysics;

class Application
{
public:

	ModulePhysics* physics;

private:

	p2List<Module*> list_modules;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

private:

	void AddModule(Module* mod);

	j1PerfTimer			ptimer;
	uint				frame_count = 0;
	j1Timer				startup_time;
	j1Timer				frame_time;
	j1Timer				last_sec_frame_time;
	int					last_sec_frame_count = 0;
	int					prev_last_sec_frame_count = 0;

	j1PerfTimer			real_delay_timer;				//Timer that will be used to see the actual amount of time that was delayed to cap the framerate.
	uint				frame_cap;						//Stores the frames per second cap to be applied.
	float				dt;								//Stores the amount of milliseconds that have passed in a frame.
};