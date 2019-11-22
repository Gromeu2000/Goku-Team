#ifndef __MODULEWINDOW_H__
#define __MODULEWINDOW_H__

#include "p2Defs.h"
#include "Module.h"

struct SDL_Window;
struct SDL_Surface;

class ModuleWindow : public Module
{
public:

	ModuleWindow();

	// Destructor
	virtual ~ModuleWindow();

	// Called before render is available
	bool Awake();

	// Called before quitting
	bool CleanUp();

	// Change title
	void SetTitle(const char* new_title);

	// Retrive window size
	void GetWindowSize(uint& width, uint& height) const;

	// Retrieve window scale
	uint GetScale() const;

public:
	//The window we'll be rendering to
	SDL_Window* window;

	//The surface contained by the window
	SDL_Surface* screen_surface;

private:
	uint		width;
	uint		height;
	uint		scale;
};

#endif // __MODULEWINDOW_H__