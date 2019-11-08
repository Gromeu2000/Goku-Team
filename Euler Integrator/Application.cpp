#include "Module.h"
#include "Application.h"
#include "Physics.h"
//include header of all existing modules

Application::Application()
{


	//Add module physics





}

Application::~Application()
{

}

bool Application::Init()
{
	return true;
}

// Call PreUpdate, Update and PostUpdate on all modules
update_status Application::Update()
{
	return UPDATE_CONTINUE;
}

bool Application::CleanUp()
{
	return true;
}

void Application::AddModule(Module* mod)
{
	
}