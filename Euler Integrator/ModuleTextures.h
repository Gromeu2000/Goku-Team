#ifndef __MODULETEXTURES_H__
#define __MODULETEXTURES_H__

#include "Module.h"
#include "p2List.h"

struct SDL_Texture;
struct SDL_Surface;

class ModuleTextures : public Module
{
public:

	ModuleTextures();

	// Destructor
	virtual ~ModuleTextures();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before quitting
	bool CleanUp();

	// Load Texture
	SDL_Texture* const	Load(const char* path);
	bool				UnLoad(SDL_Texture* texture);
	SDL_Texture* const	LoadSurface(SDL_Surface* surface);
	void				GetSize(const SDL_Texture* texture, uint& width, uint& height) const;

public:

	p2List<SDL_Texture*>	textures;
};


#endif // __MODULETEXTURES_H__