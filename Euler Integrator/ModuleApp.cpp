#include "p2Defs.h"
#include "p2Log.h"

#include "ModuleWindow.h"
#include "ModulePhysics.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleScene.h"
#include "ModuleInput.h"
#include "ModuleApp.h"

// Constructor
ModuleApp::ModuleApp(int argc, char* args[]) : argc(argc), args(args)
{
	frames = 0;

	win = new ModuleWindow();
	render = new ModuleRender();
	tex = new ModuleTextures();
	physics = new ModulePhysics();
	scene = new ModuleScene();
	input = new ModuleInput();

	// Ordered for awake / Start / Update
	// Reverse order of CleanUp
	AddModule(win);
	AddModule(tex);
	AddModule(physics);
	AddModule(scene);
	AddModule(input);

	// render last to swap buffer
	AddModule(render);
}

// Destructor
ModuleApp::~ModuleApp()
{
	// release modules
	p2List_item<Module*>* item = modules.end;

	while (item != NULL)
	{
		RELEASE(item->data);
		item = item->prev;
	}

	modules.clear();
}

void ModuleApp::AddModule(Module* module)
{
	module->Init();
	modules.add(module);
}

// Called before render is available
bool ModuleApp::Awake()
{
	
	bool ret = true;

	p2List_item<Module*>* item;
	item = modules.start;

	while (item != NULL && ret == true)
	{
		
		ret = item->data->Awake();
		item = item->next;
	}
	return ret;
}

// Called before the first frame
bool ModuleApp::Start()
{
	bool ret = true;
	p2List_item<Module*>* item;
	item = modules.start;

	while (item != NULL && ret == true)
	{
		ret = item->data->Start();
		item = item->next;
	}

	return ret;
}

// Called each loop iteration
bool ModuleApp::Update()
{
	bool ret = true;
	PrepareUpdate();

	if (input->GetWindowEvent(WE_QUIT) == true)
		ret = false;

	if (ret == true)
		ret = PreUpdate();

	if (ret == true)
		ret = DoUpdate();

	if (ret == true)
		ret = PostUpdate();

	FinishUpdate();

	return ret;
}

// ---------------------------------------------
void ModuleApp::PrepareUpdate()
{
	dt = frame_timer.ReadSec();								//Sets dt with the time returned by frame_timer.
	frame_timer.Start();									//Starts the frame_timer.
}

// ---------------------------------------------
void ModuleApp::FinishUpdate()
{
	float frame_cap_ms = 1000 / frame_cap;					//Frame cap in ms. (Ex: 30 fps --> 33,33 ms)
	float current_frame_ms = frame_timer.Read();			//Amount of ms in the span of a frame.

	if (current_frame_ms < frame_cap_ms)
	{
		SDL_Delay(frame_cap_ms - current_frame_ms);			//Applies delay so there is a frame cap.
	}
}

// Call modules before each loop iteration
bool ModuleApp::PreUpdate()
{
	bool ret = true;
	p2List_item<Module*>* item;
	item = modules.start;
	Module* pModule = NULL;

	for (item = modules.start; item != NULL && ret == true; item = item->next)
	{
		pModule = item->data;

		if (pModule->active == false) {
			continue;
		}

		ret = item->data->PreUpdate();
	}

	return ret;
}

// Call modules on each loop iteration
bool ModuleApp::DoUpdate()
{
	bool ret = true;
	p2List_item<Module*>* item;
	item = modules.start;
	Module* pModule = NULL;

	for (item = modules.start; item != NULL && ret == true; item = item->next)
	{
		pModule = item->data;

		if (pModule->active == false) {
			continue;
		}

		ret = item->data->Update(dt);
	}

	return ret;
}

// Call modules after each loop iteration
bool ModuleApp::PostUpdate()
{
	bool ret = true;
	p2List_item<Module*>* item;
	Module* pModule = NULL;

	for (item = modules.start; item != NULL && ret == true; item = item->next)
	{
		pModule = item->data;

		if (pModule->active == false) {
			continue;
		}

		ret = item->data->PostUpdate();
	}

	return ret;
}

// Called before quitting
bool ModuleApp::CleanUp()
{
	bool ret = true;
	p2List_item<Module*>* item;
	item = modules.end;

	while (item != NULL && ret == true)
	{
		ret = item->data->CleanUp();
		item = item->prev;
	}

	return ret;
}

// ---------------------------------------
int ModuleApp::GetArgc() const
{
	return argc;
}

// ---------------------------------------
const char* ModuleApp::GetArgv(int index) const
{
	if (index < argc)
		return args[index];
	else
		return NULL;
}

