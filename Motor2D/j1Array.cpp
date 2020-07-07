
#include "j1Array.h"
#include "p2DynArray.h"

#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

j1Array::j1Array() : j1Module()
{
	name.create("array");
}

// Destructor
j1Array::~j1Array()
{}

// Called before render is available
bool j1Array::Awake(pugi::xml_node& config)
{
	bool ret = true;
	

	return ret;
}

bool j1Array::Start()
{
	return true;
}

bool j1Array::PreUpdate()
{
	return true;
}

bool j1Array::Update(float dt)
{
	return true;
}

// Called before quitting
bool j1Array::CleanUp()
{
	
	return true;
}

